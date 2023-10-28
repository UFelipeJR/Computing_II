#include "videojuego.h"
#include "ui_videojuego.h"


videojuego::videojuego(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::videojuego)
{

    // Para cambiar el color

    ui->setupUi(this);

    pacMancito = new pacman(5,4,0,0);
    view = new QGraphicsView(this);
    scene = new QGraphicsScene(this);
    view->setScene(scene);
    setCentralWidget(view);

    //scene->setSceneRect(0, 0, ui->main_scene->width()-2, ui->main_scene->height()-2); //Para que comience en origen

    scene->setSceneRect(0, 0, 0, -200);
    scene->addItem(pacMancito);

    scene->addItem(pacMancito);

    ui->main_scene->setScene(scene);
    setCustomBackgroundColor("grey");


    this->setFixedSize(800,600);
    this->setWindowTitle("Pacman");
}




videojuego::~videojuego()
{
    delete ui;
    delete view;
    delete scene;
    delete rect;
}

videojuego::setCustomBackgroundColor(string color)
{
    QString comando = QString::fromStdString("background-color: "+color+";");
    setStyleSheet(comando);
}


void videojuego::keyPressEvent(QKeyEvent *event)
{

    if (event->key() == Qt::Key_W) {
        pacMancito->setRotation(-90);
        pacMancito->setTransformOriginPoint(16, 16);
        pacMancito->moveBy(0, -10);

    } else if (event->key() == Qt::Key_A) {
        pacMancito->setRotation(180);
        pacMancito->setTransformOriginPoint(16, 16);
        pacMancito->moveBy(-10, 0);


    } else if (event->key() == Qt::Key_S) {
        pacMancito->setRotation(90);
        pacMancito->setTransformOriginPoint(16, 16);
        pacMancito->moveBy(0, 10);

    } else if (event->key() == Qt::Key_D) {
        pacMancito->setRotation(0);
        pacMancito->setTransformOriginPoint(16, 16);
        pacMancito->moveBy(10, 0);
    }

}













