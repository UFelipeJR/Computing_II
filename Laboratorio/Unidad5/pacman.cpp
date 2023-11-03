#include "pacman.h"

pacman::pacman()
{

}

pacman::pacman(unsigned short vidas, unsigned short velocidad, unsigned int eje_X, unsigned int eje_Y)
{
    this->vidas = vidas;
    this->velocidad = velocidad;
    this->eje_X = eje_X;
    this->eje_Y = eje_Y;

    pacmanVivo = new QPixmap;
    timerPacmanVivo = new QTimer;
    connect(timerPacmanVivo, SIGNAL(timeout()), this, SLOT(animacionVivo()));
    timerPacmanVivo->start(1000/5);
    setPos(eje_X, eje_Y);
    spritesPacman = ":/Recursos/PacMan.png";
    cambioSpriteVivo = 1;
    separarSprites(spritesPacman, 1);
}

pacman::~pacman()
{
    delete pacmanVivo;
    delete timerPacmanVivo;
}

void pacman::separarSprites(QString sprite, short int cantSprites)
{
    QPixmap vivo;
    vivo.load(sprite);
    *pacmanVivo = vivo.copy((cantSprites * basePacmanVivo) - basePacmanVivo, 0, basePacmanVivo, basePacmanVivo);
}

void pacman::animacionVivo()
{
    if (cambioSpriteVivo == 3) {
        cambioSpriteVivo = 1;
    } else {
        cambioSpriteVivo++;
    }

    separarSprites(spritesPacman, cambioSpriteVivo);

    setPixmap(*pacmanVivo);
}


// Métodos getter and setter

bool pacman::getVivo() const
{
    return vivo;
}

void pacman::setVivo(bool newVivo)
{
    vivo = newVivo;
}

bool pacman::getPowerUp() const
{
    return powerUp;
}

void pacman::setPowerUp(bool newPowerUp)
{
    powerUp = newPowerUp;
}

bool pacman::getEstadoMovimiento() const
{
    return estadoMovimiento;
}

void pacman::setEstadoMovimiento(bool newEstadoMovimiento)
{
    estadoMovimiento = newEstadoMovimiento;
}


