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
    pacmanMuerto = new QPixmap;
    timerPacman = new QTimer;
    audioVivo = new QSoundEffect;


    timerPacman->start(1000/6);
    connect(timerPacman, SIGNAL(timeout()), this, SLOT(animacion()));
    setPos(eje_X, eje_Y);
    spritesPacman = ":/Recursos/Sprites/vivo.png";
    spritesPacmanM = ":/Recursos/Sprites/muerte.png";
    cambioSpriteVivo = 1;
    cambioSpriteMuerto = 1;
    separarSprites(spritesPacman, 1);
}

pacman::~pacman()
{
    delete pacmanVivo;
    delete timerPacman;
    delete audioVivo;
    delete pacmanMuerto;
}

void pacman::separarSprites(QString sprite, short int cantSprites)
{
    QPixmap auxiliar;
    if(vivo){
        auxiliar.load(sprite);
        *pacmanVivo = auxiliar.copy((cantSprites * basePacmanVivo) - basePacmanVivo, 0, basePacmanVivo, basePacmanVivo);
    }
    else{
        auxiliar.load(sprite);
        *pacmanMuerto = auxiliar.copy((cantSprites * basePacmanMuerto) - basePacmanMuerto, 0, basePacmanMuerto, basePacmanMuerto);
    }


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
    sfx(":/Recursos/Sonidos/vivo.wav");
}

void pacman::animacionM()
{
    if (cambioSpriteMuerto == 10) {
        cambioSpriteMuerto = 1;
        vivo = true;
    } else {
        cambioSpriteMuerto++;
    }
    separarSprites(spritesPacmanM,cambioSpriteMuerto);
    setPixmap(*pacmanMuerto);
    sfx(":/Recursos/Sonidos/muerto.wav");
    estadoMovimiento = false;

}

void pacman::animacion()
{
    if(vivo){
        animacionVivo();
    }
    else{
        animacionM();
    }
}


void pacman::sfx(QString ruta)
{
    audioVivo->setSource(QUrl::fromLocalFile(ruta));
    audioVivo->setVolume(0.1);
    audioVivo->play();

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




