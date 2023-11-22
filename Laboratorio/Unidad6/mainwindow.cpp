#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->continue_2,SIGNAL(clicked(bool)),this,SLOT(iniciar_clicked()));
    connect(ui->add,SIGNAL(clicked(bool)),this,SLOT(add_instance()));
    connect(ui->continue_3,SIGNAL(clicked(bool)),this,SLOT(reset()));
    connect(ui->continue_4,SIGNAL(clicked(bool)),this,SLOT(deleteLast()));
    connect(ui->continue_5,SIGNAL(clicked(bool)),this,SLOT(system1()));
    connect(ui->continue_6,SIGNAL(clicked(bool)),this,SLOT(system2()));


    showMaximized();
    scene = new QGraphicsScene(-300, -400, 600, 800);
    ui->graphicsView->setScene(scene);
    timer = new QTimer(this);

    ui->Num_Xo->setMinimum(-1e20);
    ui->Num_Xo->setMaximum(1e20);
    ui->Num_Yo->setMinimum(-1e20);
    ui->Num_Yo->setMaximum(1e20);
    ui->masa_2->setMinimum(-1e20);
    ui->masa_2->setMaximum(1e20);
    ui->radio_2->setMinimum(-1e20);
    ui->radio_2->setMaximum(1e20);
    ui->velx->setMinimum(-1e20);
    ui->velx->setMaximum(1e20);
    ui->vely->setMinimum(-1e20);
    ui->vely->setMaximum(1e20);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    state = false;

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniciar_clicked()
{
    state = true;
}

void MainWindow::add_instance()
{
    timer->start(33);
    float posX = ui->Num_Xo->value();
    float posY = ui->Num_Yo->value();;
    float masa = ui->masa_2->value();
    float radio = ui->radio_2->value();
    float velX = ui->velx->value();
    float velY = ui->vely->value();

    qDebug() << posX;
    qDebug() << posY;
    qDebug() << masa;
    qDebug() << radio;
    qDebug() << velX;
    qDebug() << velY;

    system.append(new body(posX,posY,masa,radio,velX,velY));
    scene->addItem(system.last());


}

void MainWindow::update()
{

    if(state){
        for (int r = 0; r < 11; r++){
            for (int j = 0; j < system.length(); j++){
                for (int i = 0; i < system.length(); i++){
                    if (system[i] != system[j])
                    {
                        float masa = system[i]->getMasa();
                        float posx = system[i]->getX();
                        float posy = system[i]->getY();
                        system[j]->aceleracion(masa, posx, posy);
                    }
                }

                system[j]->velocidades();
                system[j]->posiciones();

                system[j]->setAx(0);
                system[j]->setAy(0);
            }
        }
    }
}

void MainWindow::reset()
{
    body* elementoActual;
    for (QList<body*>::iterator it = system.begin(); it != system.end(); ++it) {
        elementoActual = *it;
        scene->removeItem(*it);
    }
    system.clear();
    state = false;
}

void MainWindow::deleteLast()
{
    if (!system.isEmpty())
    {
        scene->removeItem(system.last());
        delete system.last();
        system.removeLast();
    }
}

void MainWindow::system1()
{
    qDebug() << "Sistema 1";
    timer->start(33);
    system.append(new body(0, -7000, 70, 120, 2, 0));
    scene->addItem(system.last());

    system.append(new body(0, 0, 70000, 300, 0, 0));
    scene->addItem(system.last());

    system.append(new body(4000, 5000, 25, 100, -1.6, 1.2));
    scene->addItem(system.last());

}

void MainWindow::system2()
{
    qDebug() << "Sistema 2";
    timer->start(33);
    system.append(new body(0, 0, 50000, 200, 0, 0));
    scene->addItem(system.last());

    system.append(new body(-5000, 0, 70, 70, 0, -2));
    scene->addItem(system.last());

    system.append(new body(5000, 0, 70, 70, 0, 2));
    scene->addItem(system.last());

    system.append(new body(0, -5000, 70, 70, 2, 0));
    scene->addItem(system.last());

    system.append(new body(0, 5000, 70, 70, -2, 0));
    scene->addItem(system.last());
}




