#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <body.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QList <body*> system;
    QGraphicsScene *scene;
    QTimer *timer;
    bool state;

private slots:
    void iniciar_clicked();
    void add_instance();
    void update();
    void reset();
    void deleteLast();
    void system1();
    void system2();
};

#endif // MAINWINDOW_H
