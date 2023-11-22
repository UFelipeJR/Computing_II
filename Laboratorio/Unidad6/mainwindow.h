#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <body.h>
#include <string.h>
#include <fstream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
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

#endif // MAINWINDOW_H
