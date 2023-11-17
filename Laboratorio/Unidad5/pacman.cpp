#include "pacman.h"

pacman::pacman()
{
    this->vidas = 3;
    this->velocidad = 1;

    pacmanVivo = new QPixmap;
    pacmanMuerto = new QPixmap;
    timerPacman = new QTimer;
    tiempoPoder = new QTimer;

    timerPacman->start(1000/velocidad);
    connect(timerPacman, SIGNAL(timeout()), this, SLOT(animacion()));
    cambioSpriteVivo = 1;
    cambioSpriteMuerto = 1;
    separarSprites(recursos::RpacmanVivo, 1);
    separarSprites(recursos::RpacmanMuerto, 1);

    tiempoPoder->setSingleShot(true);
    tiempoPoder->setInterval(5000);
    connect(tiempoPoder,SIGNAL(timeout()),this,SLOT(terminarPowerUp()));

}

pacman::pacman(unsigned short vidas,unsigned short velocidad)
{
    this->vidas = vidas;
    this->velocidad = velocidad;

    pacmanVivo = new QPixmap;
    pacmanMuerto = new QPixmap;
    timerPacman = new QTimer;
    tiempoPoder = new QTimer;

    timerPacman->start(1000/velocidad);
    connect(timerPacman, SIGNAL(timeout()), this, SLOT(animacion()));
    cambioSpriteVivo = 1;
    cambioSpriteMuerto = 1;
    separarSprites(recursos::RpacmanVivo, 1);
    separarSprites(recursos::RpacmanMuerto, 1);

    tiempoPoder->setSingleShot(true);
    tiempoPoder->setInterval(5000);
    connect(tiempoPoder,SIGNAL(timeout()),this,SLOT(terminarPowerUp()));
}

pacman::~pacman()
{
    delete pacmanVivo;
    delete timerPacman;
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

    separarSprites(recursos::RpacmanVivo, cambioSpriteVivo);

    *pacmanVivo = pacmanVivo->scaled(pacmanVivo->width() * escala, pacmanVivo->height() * escala);

    setPixmap(*pacmanVivo);
}


void pacman::animacionM()
{

    const float escala = 0.8125;
    if (cambioSpriteMuerto == 10) {
        cambioSpriteMuerto = 1;
        vivo = true;
        setPos(211,410.45);
    } else {
        cambioSpriteMuerto++;
    }
    separarSprites(recursos::RpacmanMuerto,cambioSpriteMuerto);
    *pacmanMuerto = pacmanMuerto->scaled(pacmanMuerto->width() * escala, pacmanMuerto->height()*escala);
    setPixmap(*pacmanMuerto);
    estadoMovimiento = false;

}

void pacman::animacion()
{
    colisionadores = collidingItems();
    if(vivo && !confirmacionPowerUp){
        animacionVivo();
        for(int i = 0; i< colisionadores.size(); i++){
            if(typeid(*colisionadores[i]) == typeid(ghost)){
                vivo = false;
                qDebug() << "Se ha colisionado un pacman con un fantasma";
                sfx(recursos::sonidoM,true);
                vidas--;
                return;
            }
        }
    }
    else if(vivo && confirmacionPowerUp){
        animacionVivo();
        for(int i = 0; i< colisionadores.size(); i++){
            if(typeid(*colisionadores[i]) == typeid(ghost)){
                qDebug() << "Se ha colisionado un pacman con un fantasma en modo power";
                emit restablecer();
                return;
            }
        }

    }
    else{
        animacionM();
    }

    if(vivo && powerUp){
        iniciarPowerUp();
    }
}

void pacman::sfx(QString ruta,bool Switch)
{
    QSoundEffect* audio = new QSoundEffect(this);
    audio->setSource(QUrl::fromLocalFile(ruta));
    audio->setVolume(1);

    if(Switch){
        audio->play();
    }
    else{
        audio->stop();
    }

}


void pacman::iniciarPowerUp()
{
    qDebug() << "Se ha iniciado el PowerUp";
    tiempoPoder->start(8000);
    sfx(recursos::RpowerUP,true);
    powerUp = false;
    confirmacionPowerUp = true;
}



void pacman::terminarPowerUp()
{
    qDebug() << "powerUp Finalizado";
    emit tranquilizar();
    confirmacionPowerUp = false;
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

unsigned short pacman::getVidas() const
{
    return vidas;
}

void pacman::setVidas(unsigned short newVidas)
{
    vidas = newVidas;
}


