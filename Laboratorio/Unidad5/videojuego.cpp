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

    // Personajes
    pacMancito = new pacman(5, 6);
    blinky = new ghost(defecto,blinkyColor,20);
    clyde = new ghost(defecto,clydeColor,20);
    inky = new ghost(defecto,inkyColor,20);
    pinky = new ghost(defecto,pinkyColor,20);
    maze = new laberinto;


    // Escena
    view = new QGraphicsView(this);
    scene = new QGraphicsScene(this);
    view->setScene(scene);
    setCentralWidget(view);

    sceneWidth = scene->width();
    sceneHeight = scene->height();

    // Escala de laberinto
    scaleFactor = 2.4;
    maze->setScale(scaleFactor);
    maze->setPos(-275, -410);

    // Posiciones
    pacMancito->setPos(-10,-23);
    blinky->setPos(-10,-195);
    pinky->setPos(-10,-126);
    clyde->setPos(26,-126);
    inky->setPos(-46,-126);

    // Agregado de items
    scene->addItem(maze);
    scene->addItem(pacMancito);
    scene->addItem(blinky);
    scene->addItem(pinky);
    scene->addItem(clyde);
    scene->addItem(inky);

    ui->main_scene->setScene(scene);
    setCustomBackgroundColor("black");

    this->setFixedSize(850,650);
    this->setWindowTitle("Pacman");

    direcciones = -1;

    //prueba
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(movimiento_Automatico()));
    timer->start(100);

}

videojuego::~videojuego()
{
    delete ui;
    delete view;
    delete scene;
    delete rect;
    delete maze;
    delete timer;
    delete blinky;
    delete clyde;
    delete inky;
    delete pinky;
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


void videojuego::movimiento_Automatico()
{
    int cantPix = 12;
    int cantPixAux = 0;
    int minX = -255;
    int maxX = 230;
    int minY = -390;
    int maxY = 152;

    int x = 0;
    int y = 0;


    if(pacMancito->getVivo()){
        pacMancito->setEstadoMovimiento(true);
        scene->addItem(blinky);
        scene->addItem(pinky);
        scene->addItem(clyde);
        scene->addItem(inky);
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
        scene->removeItem(blinky);
        scene->removeItem(pinky);
        scene->removeItem(clyde);
        scene->removeItem(inky);

    }

    //485
    //542

    qDebug() << "Coordenadas del sprite - x: " << pacMancito->x() << ", y: " << pacMancito->y();
    x = (pacMancito->x()+255)/29;
    y = (pacMancito->y()+390)/32;
    qDebug() << "Coordenadas del spriteM - x: " << x << ", y: " << y ;
}











