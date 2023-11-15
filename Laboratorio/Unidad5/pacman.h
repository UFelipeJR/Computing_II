#ifndef PACMAN_H
#define PACMAN_H

#include <recursos.h>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <string.h>
#include <QApplication>
#include <QSoundEffect>
#include <QList>
#include "ghost.h"
#include <QtMultimedia/QMediaPlayer>

using namespace std;

class pacman : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:

    //Atributos de Pacman

    unsigned short int vidas;
    unsigned short int velocidad;

    // Estados
    bool vivo = true;
    bool powerUp = false;
    bool estadoMovimiento = true;
    bool confirmacionPowerUp = false;

    //Uso de sprites
    QPixmap *pacmanVivo;
    QPixmap *pacmanMuerto;
    QTimer *timerPacman;

    //Cambio de sprites
    unsigned short int cambioSpriteVivo;
    unsigned short int cambioSpriteMuerto;

    //Sonidos
    QSoundEffect *audio;

    //Colisiones
    QList <QGraphicsItem*> colisionadores;

    //Power Up
    QTimer* tiempoPoder;



public:
    pacman();
    pacman(unsigned short int vidas,unsigned short int velocidad);
    void separarSprites(QString sprite,short int cantSprites);
    ~pacman();

    void sfx(QString ruta,bool Switch);

    //Getter and setter
    bool getVivo() const;
    void setVivo(bool newVivo);
    bool getPowerUp() const;
    void setPowerUp(bool newPowerUp);
    bool getEstadoMovimiento() const;
    void setEstadoMovimiento(bool newEstadoMovimiento);
    void animacionVivo();
    void animacionM();
    void iniciarPowerUp();

private slots:
    void animacion();
    void terminarPowerUp();
signals:
    void tranquilizar();
    void restablecer();

};

#endif // PACMAN_H
