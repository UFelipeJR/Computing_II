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
    connect(timer, SIGNAL(timeout()), this, SLOT(movimiento_Automatico()));
    connect(timer, SIGNAL(timeout()), this, SLOT(movimiento_blinky()));
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

    srand(time(0));

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


videojuego::setCustomBackgroundColor(string color)
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
}

void videojuego::actualizarTexto()
{
    textoPuntaje = "Puntaje:" + to_string(maze->getPuntaje());
    texto->setPlainText(QString::fromStdString(textoPuntaje));
    view->update();
}

void videojuego::tp()
{
    qDebug() << pacMancito->x() << pacMancito->y();

    if((pacMancito->x() == -5)&&(pacMancito->y() == 266.45)){
        pacMancito->setPos(425,266.45);
    }
    else if((pacMancito->x() == 427)&&(pacMancito->y() == 266.45)){
        pacMancito->setPos(-1,266.45);
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
    float izquierda = -0.75;
    float arriba = -0.12499;
    float derecha = 0.375;
    float abajo = 1.125;
    posRelativa();
    tp();
    if(pacMancito->getVivo()){
        pacMancito->setEstadoMovimiento(true);
        scene->addItem(blinky);
        scene->addItem(pinky);
        scene->addItem(clyde);
        scene->addItem(inky);
    }

    // Izquierda
    if (direcciones == 0 && pacMancito->getEstadoMovimiento() &&!maze->bloqueoEntidad(pacmanLaberintoX+izquierda,pacmanLaberintoY)) {
        pacMancito->setRotation(180);
        pacMancito->setTransformOriginPoint(13.5, 13.5);
        pacMancito->moveBy(-cantPix, 0);
    }

    // Arriba
    else if (direcciones == 1 && pacMancito->getEstadoMovimiento()&& !maze->bloqueoEntidad(pacmanLaberintoX,pacmanLaberintoY+arriba)) {

        pacMancito->setRotation(-90);
        pacMancito->setTransformOriginPoint(13.5, 13.5);
        pacMancito->moveBy(0, -cantPix);

    }

    // Derecha
    else if (direcciones == 2 && pacMancito->getEstadoMovimiento()&& !maze->bloqueoEntidad(pacmanLaberintoX+derecha,pacmanLaberintoY)) {
        pacMancito->setRotation(0);
        pacMancito->setTransformOriginPoint(13.5, 13.5);
        pacMancito->moveBy(cantPix, 0);


    }

    //Abajo
    else if (direcciones == 3 && pacMancito->getEstadoMovimiento()&& !maze->bloqueoEntidad(pacmanLaberintoX,pacmanLaberintoY+abajo)) {
        pacMancito->setRotation(90);
        pacMancito->setTransformOriginPoint(13.5, 13.5);
        pacMancito->moveBy(0, cantPix);
    }


    if(!pacMancito->getVivo()){
        direcciones = -1;
        scene->removeItem(blinky);
        scene->removeItem(pinky);
        scene->removeItem(clyde);
        scene->removeItem(inky);
        blinky->setPos(211,218);

    }


    if(maze->comerPunto(pacmanLaberintoX,pacmanLaberintoY) && pacMancito->getVivo()){
        pacMancito->sfx(":/Recursos/Sonidos/vivo.wav");
        actualizarTexto();
    }


    renderizarTablero();
    //qDebug() << "DEBUG";
    //qDebug() << "EL puntaje actual es: " << maze->getPuntaje();
    movimiento_blinky();


}



void videojuego::movimiento_blinky()
{

    short int cantPix = 3;
    float izquierda = -0.75;
    float arriba = -0.12499;
    float derecha = 0.375;
    float abajo = 1.125;

    if ((pacMancito->x() < blinky->x())&&!maze->bloqueoEntidad(blinkyLaberintoX+izquierda,blinkyLaberintoY)) {
        blinky->moveBy(-cantPix, 0);
    } else if ((pacMancito->x() > blinky->x())&& !maze->bloqueoEntidad(blinkyLaberintoX,blinkyLaberintoY+arriba)) {

        blinky->moveBy(cantPix, 0);
    } else if ((pacMancito->y() < blinky->y())&& !maze->bloqueoEntidad(blinkyLaberintoX+derecha,blinkyLaberintoY)) {

        blinky->moveBy(0, -cantPix);
    } else if ((pacMancito->y() > blinky->y())&& !maze->bloqueoEntidad(blinkyLaberintoX,blinkyLaberintoY+abajo)) {

        blinky->moveBy(0, cantPix);
    }


    qDebug() << cantPix;
}






























