#include "videojuego.h"
#include "ui_videojuego.h"


videojuego::videojuego(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::videojuego)
{
    ui->setupUi(this);


    // Colores fantasmas
    QColor defecto = QColor(255,255,255);
    QColor blinkyColor = QColor(255,0,0);
    QColor clydeColor = QColor(250,169,30);
    QColor inkyColor = QColor(147,215,247);
    QColor pinkyColor = QColor(239,176,198);


    QFont customFont;
    customFont.setPointSize(16);
    customFont.setFamily("Arcadepix");


    maze = new laberinto;
    pacMancito = new pacman(5,6);
    view = new QGraphicsView(this);
    scene = new QGraphicsScene(this);
    blinky = new ghost(defecto,blinkyColor,6);
    clyde = new ghost(defecto,clydeColor,6);
    inky = new ghost(defecto,inkyColor,6);
    pinky = new ghost(defecto,pinkyColor,6);

    view->setScene(scene);
    setCentralWidget(view);


    setCustomBackgroundColor("black");

    construirTablero();
    renderizarTablero();

    pacMancito->setPos(211,410.45);
    blinky->setPos(211,218);
    pinky->setPos(211,275);
    clyde->setPos(242,275);
    inky->setPos(180,275);

    // Agregado de items

    scene->addItem(pacMancito);
    scene->addItem(blinky);
    scene->addItem(pinky);
    scene->addItem(clyde);
    scene->addItem(inky);


    ui->main_scene->setScene(scene);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(juegoPrincipal()));
    connect(maze, SIGNAL(comPuntoGrande()),this, SLOT(manejarSen()));
    connect(pacMancito,SIGNAL(tranquilizar()),this, SLOT(tranqui()));
    connect(pacMancito,SIGNAL(restablecer()),this, SLOT(restablecimiento()));
    timer->start(100);

    direcciones = -1;
    this->setFixedSize(800,600);
    this->setWindowTitle("Pacman");
    scene->setSceneRect(0, 0, maze->getAncho() * constanteLaberinto, maze->getLargo() * constanteLaberinto);

    pacmanLaberintoX = 0.0;
    pacmanLaberintoY = 0.0;
    textoPuntaje = "Puntaje: 0";

    //dibujarCuadricula();
    texto = new QGraphicsTextItem(QString::fromStdString(textoPuntaje));
    texto->setFont(customFont);
    texto->setDefaultTextColor(Qt::white);
    scene->addItem(texto);

}

videojuego::~videojuego()
{
    delete maze;
    delete pacMancito;
    delete timer;
    delete blinky;
    delete clyde;
    delete inky;
    delete pinky;
    delete texto;
}


void videojuego::construirTablero()
{
    imagenLaberinto.load(":/Recursos/Sprites/labyrinth.png");
    int indice = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 4; j++){
            arregloLaberinto[indice] = imagenLaberinto.copy(i*constanteLaberinto,j*constanteLaberinto,constanteLaberinto,constanteLaberinto);
            indice ++;
        }
    }

    for (int i = 0; i < maze->getAncho(); i++){
        for (int j = 0; j < maze->getLargo(); j++){
            LaberintoPixmaItems[i][j] = new QGraphicsPixmapItem();
            LaberintoPixmaItems[i][j]->setPixmap(arregloLaberinto[maze->bloque(i,j)]);
            LaberintoPixmaItems[i][j]->setPos(i*constanteLaberinto,j*constanteLaberinto);
            scene->addItem(LaberintoPixmaItems[i][j]);
        }
    }

}

void videojuego::renderizarTablero()
{
    for (int i = 0; i < maze->getAncho(); i++){
        for (int j = 0; j < maze->getLargo(); j++){
            LaberintoPixmaItems[i][j]->setPixmap(arregloLaberinto[maze->bloque(i,j)]);
        }
    }
}

void videojuego::dibujarCuadricula() {
    QPen redPen(Qt::red);

    for (int i = 0; i < maze->getAncho(); i++) {
        for (int j = 0; j < maze->getLargo(); j++) {

            QGraphicsLineItem *lineHorizontal = new QGraphicsLineItem(i * constanteLaberinto, j * constanteLaberinto, (i + 1) * constanteLaberinto, j * constanteLaberinto);
            lineHorizontal->setPen(redPen);
            scene->addItem(lineHorizontal);

            QGraphicsLineItem *lineVertical = new QGraphicsLineItem(i * constanteLaberinto, j * constanteLaberinto, i * constanteLaberinto, (j + 1) * constanteLaberinto);
            lineVertical->setPen(redPen);
            scene->addItem(lineVertical);
        }
    }
}


void videojuego::setCustomBackgroundColor(string color)
{
    QString comando = QString::fromStdString("background-color: "+color+";");
    setStyleSheet(comando);
}

void videojuego::posRelativa()
{
    pacmanLaberintoX = ((pacMancito->x()-1)/constanteLaberinto)+1;
    pacmanLaberintoY = (pacMancito->y()+7)/constanteLaberinto;
    blinkyLaberintoX = ((blinky->x()-1)/constanteLaberinto)+1;
    blinkyLaberintoY = (blinky->y()+7)/constanteLaberinto;
    clydeLaberintoX = ((clyde->x()-1)/constanteLaberinto)+1;
    clydeLaberintoY = (clyde->y()-1)/constanteLaberinto;
}

void videojuego::actualizarTexto()
{
    textoPuntaje = "Puntaje:" + to_string(maze->getPuntaje());
    texto->setPlainText(QString::fromStdString(textoPuntaje));
    view->update();
}



void videojuego::tp() {
    if (pacMancito->x() <= 0) {
       pacMancito->setPos(420,266.45);
    } else if (pacMancito->x() >= 426) {
        pacMancito->setPos(2,266.45);
    }
}


void videojuego::keyPressEvent(QKeyEvent *event)
{

    const float izquierda = -0.75;
    const float arriba = -0.12499;
    const float derecha = 0.375;
    const float abajo = 1.125;


    if (event->key() == Qt::Key_A) {
        if (!maze->bloqueoEntidad(pacmanLaberintoX+izquierda, pacmanLaberintoY)) {
            direcciones = 0;
        }
    } else if (event->key() == Qt::Key_W) {
        if (!maze->bloqueoEntidad(pacmanLaberintoX, pacmanLaberintoY+arriba)) {
            direcciones = 1;
        }
    } else if (event->key() == Qt::Key_D) {
        if (!maze->bloqueoEntidad(pacmanLaberintoX+derecha, pacmanLaberintoY)) {
            direcciones = 2;
        }
    } else if (event->key() == Qt::Key_S) {
        if (!maze->bloqueoEntidad(pacmanLaberintoX, pacmanLaberintoY+abajo)) {
            direcciones = 3;
        }
    } else if (event->key() == Qt::Key_Space) {
        direcciones = 40;
    }
}


void videojuego::movimiento_Automatico()
{
    int cantPix = 8;

    const float izquierda = -0.75;
    const float arriba = -0.12499;
    const float derecha = 0.375;
    const float abajo = 1.125;


    // Izquierda
    if (direcciones == 0 && pacMancito->getEstadoMovimiento() && !maze->bloqueoEntidad(pacmanLaberintoX+izquierda,pacmanLaberintoY)) {
        pacMancito->setRotation(180);
        pacMancito->setTransformOriginPoint(13, 13);
        pacMancito->moveBy(-cantPix, 0);
    }

    // Arriba
    else if (direcciones == 1 && pacMancito->getEstadoMovimiento()&& !maze->bloqueoEntidad(pacmanLaberintoX,pacmanLaberintoY+arriba)){

        pacMancito->setRotation(-90);
        pacMancito->setTransformOriginPoint(13, 13);
        pacMancito->moveBy(0, -cantPix);
    }

    // Derecha
    else if (direcciones == 2 && pacMancito->getEstadoMovimiento()&& !maze->bloqueoEntidad(pacmanLaberintoX+derecha,pacmanLaberintoY)) {
        pacMancito->setRotation(0);
        pacMancito->setTransformOriginPoint(13, 13);
        pacMancito->moveBy(cantPix, 0);

    }

    //Abajo
    else if (direcciones == 3 && pacMancito->getEstadoMovimiento()&& !maze->bloqueoEntidad(pacmanLaberintoX,pacmanLaberintoY+abajo)) {
        pacMancito->setRotation(90);
        pacMancito->setTransformOriginPoint(13, 13);
        pacMancito->moveBy(0, cantPix);
    }

}


void videojuego::movimiento_blinky()
{
    short int cantPix = 5;

    const float Tizquierda = -0.75;
    const float Tarriba = -0.12499;
    const float Tderecha = 0.375;
    const float Tabajo = 1.125;

    float derecha = cal_distancia(blinkyLaberintoX,blinkyLaberintoY,1,0);
    float izquierda = cal_distancia(blinkyLaberintoX,blinkyLaberintoY,-1,0);
    float arriba = cal_distancia(blinkyLaberintoX,blinkyLaberintoY,0,-1);
    float abajo = cal_distancia(blinkyLaberintoX,blinkyLaberintoY,0,1);

    if ((derecha < izquierda && derecha < arriba && derecha < abajo)&& !maze->bloqueoEntidad(blinkyLaberintoX + Tderecha, blinkyLaberintoY)){
        //Derecha
        blinky->moveBy(cantPix, 0);
    }
    else if ((izquierda < derecha && izquierda < arriba && izquierda < abajo)&& !maze->bloqueoEntidad(blinkyLaberintoX + Tizquierda, blinkyLaberintoY)){
        //Izquierda
        blinky->moveBy(-cantPix, 0);
    }
    else if ((arriba < izquierda && arriba < derecha && arriba < abajo)&& !maze->bloqueoEntidad(blinkyLaberintoX, blinkyLaberintoY + Tarriba)){
        //Arriba
        blinky->moveBy(0, -cantPix);
    }
    else if ((abajo < izquierda && abajo < arriba && abajo < derecha)&& !maze->bloqueoEntidad(blinkyLaberintoX, blinkyLaberintoY + Tabajo)){
        //Abajo
        blinky->moveBy(0, cantPix);
    }
}
void videojuego::movimiento_clyde()
{
    short int cantPix = 5;
    short int direccionAleatoria = 0;
    const float Tizquierda = -0.75;
    const float Tarriba = -0.12499;
    const float Tderecha = 0.375;
    const float Tabajo = 1.125;
    bool movimientoExitoso = false;

    while (!movimientoExitoso) {
        direccionAleatoria = rand() % 4;

        switch (direccionAleatoria) {
        case 0:
            if (!maze->bloqueoEntidad(clydeLaberintoX + Tderecha, clydeLaberintoY)) {
                clyde->moveBy(cantPix, 0);
                movimientoExitoso = true;
            }
            break;
        case 1:
            if (!maze->bloqueoEntidad(clydeLaberintoX + Tizquierda, clydeLaberintoY)) {
                clyde->moveBy(-cantPix, 0);
                movimientoExitoso = true;
            }
            break;
        case 2:
            if (!maze->bloqueoEntidad(clydeLaberintoX, clydeLaberintoY + Tarriba)) {
                clyde->moveBy(0, -cantPix);
                movimientoExitoso = true;
            }
            break;
        case 3:
            if (!maze->bloqueoEntidad(clydeLaberintoX, clydeLaberintoY + Tabajo)) {
                clyde->moveBy(0, cantPix);
                movimientoExitoso = true;
            }
            break;
        }
    }
}

void videojuego::juegoPrincipal()
{
    posRelativa();
    tp();
        scene->removeItem(pinky);
        scene->removeItem(clyde);
        scene->removeItem(inky);

    if(pacMancito->getVivo()){
        pacMancito->setEstadoMovimiento(true);
        scene->addItem(blinky);
        scene->addItem(pinky);
        scene->addItem(clyde);
        scene->addItem(inky);
    }

    movimiento_Automatico();


    if(!pacMancito->getVivo()){
        direcciones = -1;
        scene->removeItem(blinky);
        scene->removeItem(pinky);
        scene->removeItem(clyde);
        scene->removeItem(inky);
        blinky->setPos(211,218);

    }

    if(maze->comerPunto(pacmanLaberintoX,pacmanLaberintoY) && pacMancito->getVivo()){
        pacMancito->sfx(":/Recursos/Sonidos/vivo.wav",true);
    }

    renderizarTablero();
    movimiento_blinky();
    //movimiento_clyde();
    actualizarTexto();

    qDebug() << "DEBUG";
    qDebug() << maze->bloqueoEntidad(pacmanLaberintoX,pacmanLaberintoY);
    qDebug() << "X: " << pacmanLaberintoX << "Y:" << pacmanLaberintoY;

}


void videojuego::manejarSen()
{
    pacMancito->setPowerUp(true);
    blinky->setAsustado(true);
    blinky->setAsustado(true);
    pinky->setAsustado(true);
    clyde->setAsustado(true);
    inky->setAsustado(true);
}

void videojuego::tranqui()
{
    blinky->setAsustado(false);
    blinky->setAsustado(false);
    blinky->setAsustado(false);
    pinky->setAsustado(false);
    clyde->setAsustado(false);
    inky->setAsustado(false);
}

void videojuego::restablecimiento()
{
    blinky->setPos(211,218);
}

float videojuego::cal_distancia(float xF, float yF ,int dirX, int dirY)
{
    float distancia = 1000000.0f;
    if(!maze->bloqueoEntidad(xF+dirX,yF+dirY)){
        distancia = (float) sqrt(pow((pacmanLaberintoX - (xF + dirX)), 2) + pow((pacmanLaberintoY - (yF + dirY)), 2));

    }
    return distancia;
}























