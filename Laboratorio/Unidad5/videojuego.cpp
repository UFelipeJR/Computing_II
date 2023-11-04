#include "videojuego.h"
#include "ui_videojuego.h"


videojuego::videojuego(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::videojuego)
{
    ui->setupUi(this);
    pacMancito = new pacman(5, 4, 0, 0);
    maze = new laberinto;
    view = new QGraphicsView(this);
    scene = new QGraphicsScene(this);
    view->setScene(scene);
    setCentralWidget(view);

    sceneWidth = scene->width();
    sceneHeight = scene->height();

    scaleFactor = 2.4;
    maze->setScale(scaleFactor);
    maze->setPos(-275, -410);

    pacMancito->setPos(-10,-23);
    scene->addItem(maze);
    scene->addItem(pacMancito);

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
        qDebug() << "Se presiono espacio";
        pacMancito->setVivo(false);
    }

}


void videojuego::movimiento_Automatico()
{
    int cantPix = 10;
    int minX = -258;
    int maxX = 232;
    int minY = -393;
    int maxY = 155;

    if(pacMancito->getVivo()){
        pacMancito->setEstadoMovimiento(true);
    }

    if(direcciones == 0 && pacMancito->getEstadoMovimiento()){
        if (pacMancito->x() - cantPix >= minX) {
            pacMancito->setRotation(180);
            pacMancito->setTransformOriginPoint(16, 16);
            pacMancito->moveBy(-cantPix, 0);
        }

    }
    else if(direcciones == 1 && pacMancito->getEstadoMovimiento()){
        if (pacMancito->y() - cantPix >= minY) {
            pacMancito->setRotation(-90);
            pacMancito->setTransformOriginPoint(16, 16);
            pacMancito->moveBy(0, -cantPix);
        }

    }
    else if(direcciones == 2 && pacMancito->getEstadoMovimiento()){
        if (pacMancito->x() + cantPix <= maxX) {
            pacMancito->setRotation(0);
            pacMancito->setTransformOriginPoint(16, 16);
            pacMancito->moveBy(cantPix, 0);
        }
    }
    else if(direcciones == 3 && pacMancito->getEstadoMovimiento()){
        if (pacMancito->y() + cantPix <= maxY) {
            pacMancito->setRotation(90);
            pacMancito->setTransformOriginPoint(16, 16);
            pacMancito->moveBy(0, cantPix);
        }
    }

    if(!pacMancito->getVivo()){
        direcciones = -1;
        pacMancito->setPos(-10,-23);
    }

    qDebug() << "Coordenadas del sprite - x: " << pacMancito->x() << ", y: " << pacMancito->y();

}








