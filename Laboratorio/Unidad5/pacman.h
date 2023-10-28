#ifndef PACMAN_H
#define PACMAN_H

#include <macros_videojuego.h>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <string.h>

using namespace std;

class pacman : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:

    //Atributos de Pacman

    unsigned short int vidas;
    unsigned short int velocidad;
    unsigned int eje_X;
    unsigned int eje_Y;

    // Estados
    bool vivo = true;
    bool powerUp = false;
    bool estadoMovimiento = false;

    //Uso de sprites
    QPixmap *pacmanVivo;
    QTimer *timerPacmanVivo;

    //Cambio de sprites
    unsigned short int cambioSpriteVivo = 1;
    QString spritesPacman = ":/Recursos/PacMan.png";




public:
    pacman();
    pacman(unsigned short int vidas,unsigned short int velocidad,unsigned int eje_X,unsigned int eje_Y);
    void separarSprites(QString sprite,short int cantSprites);
    ~pacman();


    //Getter and setter
    bool getVivo() const;
    void setVivo(bool newVivo);
    bool getPowerUp() const;
    void setPowerUp(bool newPowerUp);
    bool getEstadoMovimiento() const;
    void setEstadoMovimiento(bool newEstadoMovimiento);

private slots:
    void animacionVivo();


};

#endif // PACMAN_H
