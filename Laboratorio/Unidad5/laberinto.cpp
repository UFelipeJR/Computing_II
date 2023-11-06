#include <laberinto.h>

laberinto::laberinto()
{
    Laberinto = new QPixmap;
    LaberintoI = new QImage(":/Recursos/Archivos/laberinto.png");
    archivoLaberinto = ":/Recursos/Sprites/laberinto.png";
    timerLaberinto = new QTimer;
    connect(timerLaberinto, SIGNAL(timeout()), this, SLOT(mostrar_Laberinto()));
    timerLaberinto->start(1000/5);
    gen();
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


bool laberinto::comprobarPosicion(int x, int y)
{
    if(colisiones[y][x] == 1){
        return true;
    }
    else{
        return false;
    }
}

void laberinto::gen()
{

    QColor colorPixel;
    QColor transparente(0,0,0,0);

    for(int i = 0; i < LaberintoI->width();i++){
        for(int j = 0; j < LaberintoI->height();j++){
            colorPixel = LaberintoI->pixelColor(i, j);

            if(colorPixel == transparente){
                colisiones[i][j] = 1;
            }
            else{
                colisiones[i][j] = 0;;
            }
        }
    }

}

void laberinto::mostrar_Laberinto()
{
    cargar_Sprite(archivoLaberinto);
    setPixmap(*Laberinto);
    //listarColores();

}






