#include <laberinto.h>

laberinto::laberinto()
{
    Laberinto = new QPixmap;
    archivoLaberinto = ":/Recursos/Sprites/laberinto.png";
    timerLaberinto = new QTimer;
    connect(timerLaberinto, SIGNAL(timeout()), this, SLOT(mostrar_Laberinto()));
    timerLaberinto->start(1000/5);
    //gen();
}

laberinto::~laberinto()
{
    delete Laberinto;
    delete timerLaberinto;
    //delete arregloColisiones;
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

/*
void laberinto::gen()
{

    QColor azul = QColor(0.866667, 0, 0.501961, 0.972549);
    QColor rosado = QColor(0.301961, 1, 0.631373, 0.803922);
    QColor defecto = QColor(0,0,0,0);
    QImage original(":/Recursos/Archivos/laberinto.png");
    QColor colorPixel;

    arregloColisiones = new short int*[original.height()];
    for (int i = 0; i < original.height(); i++) {
        arregloColisiones[i] = new short int[original.width()];
    }



    for(int i = 0; i<original.height(); i++){
        for(int j = 0; j<original.width(); j++){
            colorPixel = original.pixelColor(j,i);
            if(colorPixel == azul){
                 arregloColisiones[i][j] = 1;
            }
            else if(colorPixel == rosado){
                arregloColisiones[i][j] = 1;
            }
            else{
                arregloColisiones[i][j] = 0;
            }
        }
    }

}
*/


