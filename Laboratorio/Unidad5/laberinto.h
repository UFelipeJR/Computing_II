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
#include <pacman.h>
#include <QGraphicsScene>
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
    uint puntaje;

    QPixmap arregloLaberinto[32];
    QPixmap imagenLaberinto;
    QGraphicsPixmapItem* LaberintoPixmaItems[28][36];


public:
    laberinto();
    unsigned int bloque(int x, int y);
    bool bloqueoEntidad(int x, int y);
    bool comerPunto(int x, int y);
    static uint getAncho();
    static uint getLargo();
    uint getPuntaje() const;
    void construirTablero(QGraphicsScene* escena);
    void renderizarTablero();

signals:
    void comPuntoGrande();

};

#endif
