#ifndef LABERINTO_H
#define LABERINTO_H

#include <recursos.h>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <string.h>
#include <fstream>
#include <cmath>
#include <iostream>
#include <Qpainter>

using namespace std;

class laberinto : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    static const uint ancho = 28;
    static const uint largo = 36;
    unsigned int colisiones[ancho][largo];
    uint nada;
    uint punto;
    uint puntoGrande;

public:
    laberinto();

    unsigned int bloque(int x, int y);
    bool bloqueoEntidad(int x, int y);


    static uint getAncho();
    static uint getLargo();
};

#endif
