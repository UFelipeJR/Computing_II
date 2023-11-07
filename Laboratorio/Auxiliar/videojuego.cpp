#include "videojuego.h"
#include "ui_videojuego.h"


videojuego::videojuego(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::videojuego)
{
    ui->setupUi(this);


    maze = new laberinto;
    pacMancito = new pacman(5,6);
    view = new QGraphicsView(this);
    scene = new QGraphicsScene(this);
    view->setScene(scene);
    setCentralWidget(view);


    setCustomBackgroundColor("black");

    construirTablero();
    renderizarTablero();

    pacMancito->setPos(212,411);
    pacMancito->setScale(0.8);
    scene->addItem(pacMancito);


    ui->main_scene->setScene(scene);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(movimiento_Automatico()));
    timer->start(100);

    direcciones = -1;
    this->setFixedSize(850,650);
    this->setWindowTitle("Pacman");


}

videojuego::~videojuego()
{
    delete maze;
    delete pacMancito;
    delete timer;
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

videojuego::setCustomBackgroundColor(string color)
{
    QString comando = QString::fromStdString("background-color: "+color+";");
    setStyleSheet(comando);
}

void videojuego::keyPressEvent(QKeyEvent *event)
{


    if (event->key() == Qt::Key_A) {
        direcciones = 0;

    } else if (event->key() == Qt::Key_W) {
        direcciones = 1;

    } else if (event->key() == Qt::Key_D) {
        direcciones = 2;

    } else if (event->key() == Qt::Key_S) {
        direcciones = 3;
    }
    else if(event->key() == Qt::Key_Space){
        direcciones = 40;
    }

}

/*
void videojuego::movimiento_Automatico()
{
    int cantPix = 12;
    int cantPixAux = 0;
    int minX = -255;
    int maxX = 230;
    int minY = -390;
    int maxY = 152;

    if(pacMancito->getVivo()){
        pacMancito->setEstadoMovimiento(true);
        //scene->addItem(blinky);
        //scene->addItem(pinky);
        //scene->addItem(clyde);
        //scene->addItem(inky);
    }

    if (direcciones == 0 && pacMancito->getEstadoMovimiento()) {
        if (pacMancito->x() - cantPix >= minX) {
            pacMancito->setRotation(180);
            pacMancito->setTransformOriginPoint(16, 16);
            pacMancito->moveBy(-cantPix, 0);
        }

        else {
            cantPixAux = pacMancito->x() - minX;
            pacMancito->setRotation(180);
            pacMancito->setTransformOriginPoint(16, 16);
            pacMancito->moveBy(-cantPixAux, 0);
        }

    }
    else if (direcciones == 1 && pacMancito->getEstadoMovimiento()) {
        if (pacMancito->y() - cantPix >= minY) {
            pacMancito->setRotation(-90);
            pacMancito->setTransformOriginPoint(16, 16);
            pacMancito->moveBy(0, -cantPix);
        }

        else {
            cantPixAux = pacMancito->y() - minY;
            pacMancito->setRotation(-90);
            pacMancito->setTransformOriginPoint(16, 16);
            pacMancito->moveBy(0, -cantPixAux);
        }

    }
    else if (direcciones == 2 && pacMancito->getEstadoMovimiento()) {
        if (pacMancito->x() + cantPix <= maxX) {
            pacMancito->setRotation(0);
            pacMancito->setTransformOriginPoint(16, 16);
            pacMancito->moveBy(cantPix, 0);
        }

        else {
            cantPixAux = maxX - pacMancito->x();
            pacMancito->setRotation(0);
            pacMancito->setTransformOriginPoint(16, 16);
            pacMancito->moveBy(cantPixAux, 0);
        }

    }
    else if (direcciones == 3 && pacMancito->getEstadoMovimiento()) {
        if (pacMancito->y() + cantPix <= maxY) {
            pacMancito->setRotation(90);
            pacMancito->setTransformOriginPoint(16, 16);
            pacMancito->moveBy(0, cantPix);
        }

        else {
            cantPixAux = maxY - pacMancito->y();
            pacMancito->setRotation(90);
            pacMancito->setTransformOriginPoint(16, 16);
            pacMancito->moveBy(0, cantPixAux);
        }

    }

    if(!pacMancito->getVivo()){
        direcciones = -1;
        //scene->removeItem(blinky);
        //scene->removeItem(pinky);
        //scene->removeItem(clyde);
        //scene->removeItem(inky);

    }
}
*/

void videojuego::movimiento_Automatico()
{
    int cantPix = 8;
    int cantPixAux = 0;
    int minX = -255;
    int maxX = 230;
    int minY = -390;
    int maxY = 152;

    if(pacMancito->getVivo()){
        pacMancito->setEstadoMovimiento(true);
        //scene->addItem(blinky);
        //scene->addItem(pinky);
        //scene->addItem(clyde);
        //scene->addItem(inky);
    }

    if (direcciones == 0 && pacMancito->getEstadoMovimiento()) {

            pacMancito->setRotation(180);
            pacMancito->setTransformOriginPoint(16, 16);
            pacMancito->moveBy(-cantPix, 0);

    }
    else if (direcciones == 1 && pacMancito->getEstadoMovimiento()) {

            pacMancito->setRotation(-90);
            pacMancito->setTransformOriginPoint(16, 16);
            pacMancito->moveBy(0, -cantPix);

    }
    else if (direcciones == 2 && pacMancito->getEstadoMovimiento()) {

            pacMancito->setRotation(0);
            pacMancito->setTransformOriginPoint(16, 16);
            pacMancito->moveBy(cantPix, 0);


    }
    else if (direcciones == 3 && pacMancito->getEstadoMovimiento()) {
            pacMancito->setRotation(90);
            pacMancito->setTransformOriginPoint(16, 16);
            pacMancito->moveBy(0, cantPix);
    }

    if(!pacMancito->getVivo()){
        direcciones = -1;
        //scene->removeItem(blinky);
        //scene->removeItem(pinky);
        //scene->removeItem(clyde);
        //scene->removeItem(inky);

    }

    qDebug() << "Coordenadas del sprite - x: " << int(pacMancito->x()*0.8) << ", y: " << int(pacMancito->y()*0.8);

}























