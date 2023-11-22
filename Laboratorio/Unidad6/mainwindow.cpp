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

    sistema.append(new cuerpo(posX,posY,masa,radio,velX,velY));
    scene->addItem(sistema.last());


}

void MainWindow::update()
{

    if(state){
        int j = 0, r = 0;

        for (r = 0; r < 11; r++)
        {
            for (j = 0; j < sistema.length(); j++)
            {
                for (int i = 0; i < sistema.length(); i++)
                {
                    if (sistema[i] != sistema[j])
                    {
                        float masa = sistema[i]->getMasa();
                        float posx = sistema[i]->getX();
                        float posy = sistema[i]->getY();
                        sistema[j]->aceleracion(masa, posx, posy);
                    }
                }

                sistema[j]->velocidades();
                sistema[j]->posiciones();

                sistema[j]->setAx(0);
                sistema[j]->setAy(0);
            }
        }
    }

}

void MainWindow::reset()
{
    cuerpo* elementoActual;
    for (QList<cuerpo*>::iterator it = sistema.begin(); it != sistema.end(); ++it) {
        elementoActual = *it;
        scene->removeItem(*it);
    }
    sistema.clear();
    state = false;
}



