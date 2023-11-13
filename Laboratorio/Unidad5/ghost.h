#ifndef GHOST_H
#define GHOST_H

#include <recursos.h>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <string.h>
#include <QApplication>
#include <QSoundEffect>
#include <QPainter>
#include <QColor>

class ghost : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:

    //Atributos de fantasma

    unsigned short int velocidad;

    // Estados
    bool vivo = true;
    bool asustado = false;

    //Uso de sprites
    QPixmap *fantasmaVivo;
    QPixmap *fantasmaOjos;
    QPixmap *fantasmaAsustado;
    QTimer *timerFantasma;

    //Cambio de sprites
    unsigned short int cambioSpriteVivo;
    unsigned short int cambioSpriteOjos;
    unsigned short int cambioSpriteAsustado;

    //Colores
    QColor nativo;
    QColor modificado;


public:
    ghost();
    ghost(const QColor &nativo, const QColor &modificado, unsigned short velocidad);
    ~ghost();

    void animacionVivo();
    void separarSprites(QString sprite1,QString sprite2, QString sprite3 ,short int cantSprites, short int cantSpritesOjos,short int cantSpritesAsustado);
    void pintarFantasma();
    void setAsustado(bool newAsustado);

private slots:
    void animacion();
};

#endif // GHOST_H
