#include <laberinto.h>

laberinto::laberinto()
{
    Laberinto = new QPixmap;
    LaberintoI = new QImage(":/Recursos/Archivos/laberinto.png");
    archivoLaberinto = ":/Recursos/Sprites/laberinto.png";
    timerLaberinto = new QTimer;
    connect(timerLaberinto, SIGNAL(timeout()), this, SLOT(mostrar_Laberinto()));
    timerLaberinto->start(1000/5);
}

laberinto::~laberinto()
{
    delete Laberinto;
    delete timerLaberinto;
    delete LaberintoI;
}

void laberinto::cargar_Sprite(QString sprite)
{
    QPixmap mapaAuxiliar;
    qreal escala = 2.4;
    mapaAuxiliar.load(sprite);
    QSize nuevaTaman(mapaAuxiliar.width() * escala, mapaAuxiliar.height() * escala);
    QPixmap laberintoEscalado = mapaAuxiliar.scaled(nuevaTaman, Qt::KeepAspectRatio);
    *Laberinto = laberintoEscalado;
}




void laberinto::mostrar_Laberinto()
{
    cargar_Sprite(archivoLaberinto);
    setPixmap(*Laberinto);
    //listarColores();

}






