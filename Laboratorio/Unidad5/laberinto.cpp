#include <laberinto.h>

laberinto::laberinto()
{
    Laberinto = new QPixmap;
    archivoLaberinto = ":/Recursos/Sprites/laberinto.png";
    timerLaberinto = new QTimer;
    connect(timerLaberinto, SIGNAL(timeout()), this, SLOT(mostrar_Laberinto()));
    timerLaberinto->start(1000/5);
}

laberinto::~laberinto()
{
    delete Laberinto;
    delete timerLaberinto;
}

void laberinto::cargar_Sprite(QString sprite)
{
    QPixmap mapaAuxiliar;
    mapaAuxiliar.load(sprite);
    *Laberinto = mapaAuxiliar;
}

void laberinto::mostrar_Laberinto()
{
    cargar_Sprite(archivoLaberinto);
    setPixmap(*Laberinto);

}


