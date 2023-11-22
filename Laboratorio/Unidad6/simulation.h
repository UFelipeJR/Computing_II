#ifndef SIMULATION_H
#define SIMULATION_H

#include <QMainWindow>
#include <QTimer>
#include <body.h>
#include <string.h>
#include <fstream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class simulation : public QMainWindow
{
    Q_OBJECT

public:
    simulation(QWidget *parent = nullptr);
    ~simulation();
    void writeFile(float val1, float val2, bool nl);

private:
    Ui::MainWindow *ui;
    QList <body*> system;
    QGraphicsScene *scene;
    QTimer *timer;
    QTimer *timertwo;
    bool state;
    int numSimulation;

private slots:
    void iniciar_clicked();
    void add_instance();
    void update();
    void reset();
    void deleteLast();
    void system1();
    void system2();
    void repairButtons();
};

#endif // SIMULATION_H
