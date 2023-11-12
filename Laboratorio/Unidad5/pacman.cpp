#include "pacman.h"

pacman::pacman()
{
    this->vidas = 5;
    this->velocidad = 6;

    pacmanVivo = new QPixmap;
    pacmanMuerto = new QPixmap;
    timerPacman = new QTimer;
    audio = new QSoundEffect;

    timerPacman->start(1000/velocidad);
    connect(timerPacman, SIGNAL(timeout()), this, SLOT(animacion()));
    spritesPacman = ":/Recursos/Sprites/vivo.png";
    spritesPacmanM = ":/Recursos/Sprites/muerte.png";
    cambioSpriteVivo = 1;
    cambioSpriteMuerto = 1;
    separarSprites(spritesPacman, 1);
    separarSprites(spritesPacmanM, 1);

}

pacman::pacman(unsigned short vidas, unsigned short velocidad)
{
    this->vidas = vidas;
    this->velocidad = velocidad;

    pacmanVivo = new QPixmap;
    pacmanMuerto = new QPixmap;
    timerPacman = new QTimer;
    audio = new QSoundEffect;

    timerPacman->start(1000/velocidad);
    connect(timerPacman, SIGNAL(timeout()), this, SLOT(animacion()));
    spritesPacman = ":/Recursos/Sprites/vivo.png";
    spritesPacmanM = ":/Recursos/Sprites/muerte.png";
    cambioSpriteVivo = 1;
    cambioSpriteMuerto = 1;
    separarSprites(spritesPacman, 1);
    separarSprites(spritesPacmanM, 1);
}

pacman::~pacman()
{
    delete pacmanVivo;
    delete timerPacman;
    delete audio;
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
    const float escala = 0.84375;
    if (cambioSpriteVivo == 3) {
        cambioSpriteVivo = 1;
    } else {
        cambioSpriteVivo++;
    }

    separarSprites(spritesPacman, cambioSpriteVivo);

    *pacmanVivo = pacmanVivo->scaled(pacmanVivo->width() * escala, pacmanVivo->height() * escala);

    setPixmap(*pacmanVivo);
}


void pacman::animacionM()
{

    //const float escala = 0.84375;
    const float escala = 0.8125;
    if (cambioSpriteMuerto == 10) {
        cambioSpriteMuerto = 1;
        vivo = true;
        setPos(211,410.45);
    } else {
        cambioSpriteMuerto++;
    }
    separarSprites(spritesPacmanM,cambioSpriteMuerto);
    *pacmanMuerto = pacmanMuerto->scaled(pacmanMuerto->width() * escala, pacmanMuerto->height()*escala);
    setPixmap(*pacmanMuerto);
    estadoMovimiento = false;

}


void pacman::animacion()
{
    colisionadores = collidingItems();
    if(vivo){
        animacionVivo();
        for(int i = 0; i< colisionadores.size(); i++){
            if(typeid(*colisionadores[i]) == typeid(ghost)){
                vivo = false;
                qDebug() << "Se ha colisionado un pacman con un fantasma";
                sfx(":/Recursos/Sonidos/muerto.wav");
                return;
            }
        }
    }
    else{
        animacionM();
    }

}

void pacman::sfx(QString ruta)
{
    audio->setSource(QUrl::fromLocalFile(ruta));
    audio->setVolume(1);
    audio->play();
}



// Métodos getter y setter

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




