#ifndef LABERINTO_H
#define LABERINTO_H

#include <macros_videojuego.h>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <string.h>

using namespace std;

class laberinto : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:

    QPixmap *Laberinto;
    QString archivoLaberinto;
    QTimer *timerLaberinto;
    short int arregloColisiones[615][557];

public:
    laberinto();
    ~laberinto();

    void cargar_Sprite(QString sprite);

private slots:
    void mostrar_Laberinto();


};

#endif
