#ifndef LABERINTO_H
#define LABERINTO_H

#include <macros_videojuego.h>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <string.h>
#include <fstream>
#include <cmath>
#include <iostream>

using namespace std;

class laberinto : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:

    QPixmap *Laberinto;
    QString archivoLaberinto;
    QTimer *timerLaberinto;
    short int** arregloColisiones;

public:
    laberinto();
    ~laberinto();
    void cargar_Sprite(QString sprite);

    /*
    void gen();
    bool comprobarPos(short int x, short int y);
    */


private slots:
    void mostrar_Laberinto();


};

#endif
