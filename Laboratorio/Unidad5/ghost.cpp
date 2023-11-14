#include "ghost.h"

ghost::ghost()
{

}

ghost::ghost(const QColor &nativo, const QColor &modificado, unsigned short velocidad)
{
    this->velocidad = velocidad;
    this-> nativo = nativo;
    this-> modificado = modificado;

    fantasmaVivo = new QPixmap;
    fantasmaOjos = new QPixmap;
    fantasmaAsustado = new QPixmap;
    timerFantasma = new QTimer;


    timerFantasma->start(1000/velocidad);
    connect(timerFantasma, SIGNAL(timeout()), this, SLOT(animacion()));
    cambioSpriteVivo = 1;
    cambioSpriteOjos = 1;
    //separarSprites(":/Recursos/Sprites/cuerpoFantasma.png",":/Recursos/Sprites/ojosFantasma.png",":/Recursos/Sprites/cuerpoFantasmaAsus.png",1,1);
    pintarFantasma();

}

ghost::~ghost()
{
    delete fantasmaVivo;
    delete fantasmaOjos;
    delete timerFantasma;
    delete fantasmaAsustado;
}


void ghost::separarSprites(QString sprite1,QString sprite2, QString sprite3 ,short int cantSprites, short int cantSpritesOjos)
{
    QPixmap auxiliar;
    QPixmap auxiliar2;
    QPixmap auxiliar3;
    const float escala = 0.875;

    if(vivo && !asustado){
        auxiliar.load(sprite1);
        auxiliar2.load(sprite2);
        auxiliar3.load(sprite3);

        *fantasmaVivo = auxiliar.copy((cantSprites*baseFantasma)-baseFantasma,0,baseFantasma,largoFantasma);
        *fantasmaOjos = auxiliar2.copy((cantSpritesOjos*baseFantasma)-baseFantasma,0,baseFantasma,largoFantasma);
        *fantasmaAsustado = auxiliar3.copy((cantSprites*baseFantasma)-baseFantasma,0,baseFantasma,largoFantasma);

        *fantasmaVivo = fantasmaVivo->scaled(fantasmaVivo->width()*escala,fantasmaVivo->height() * escala);
        *fantasmaOjos = fantasmaOjos->scaled(fantasmaOjos->width()*escala,fantasmaOjos->height() * escala);
        *fantasmaAsustado = fantasmaAsustado->scaled(fantasmaAsustado->width()*escala,fantasmaAsustado->height() * escala);
    }

    pintarFantasma();

}

void ghost::pintarFantasma()
{


    QImage original = fantasmaVivo->toImage();
    QColor colorPixel;

    int width = original.width();
    int height = original.height();

    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            colorPixel = original.pixelColor(i, j);
            if(colorPixel == nativo) {
                original.setPixelColor(i, j, modificado);
            }
        }
    }

    *fantasmaVivo = QPixmap::fromImage(original);

}


void ghost::animacionVivo()
{

    QPixmap fusion(*fantasmaVivo);
    QPainter fusionador(&fusion);
    const float escala = 0.875;

    if (cambioSpriteVivo == 6) {
        cambioSpriteVivo = 1;
    } else {
        cambioSpriteVivo++;
    }
    separarSprites(":/Recursos/Sprites/cuerpoFantasma.png",":/Recursos/Sprites/ojosFantasma.png",":/Recursos/Sprites/cuerpoFantasmaAsus.png",cambioSpriteVivo,cambioSpriteOjos);
    fusionador.drawPixmap(0,0,*fantasmaOjos);
    fusionador.end();


    if(vivo && !asustado){
        setPixmap(fusion);
    }
    else if(vivo && asustado){
        setPixmap(*fantasmaAsustado);
    }


}

void ghost::setAsustado(bool newAsustado)
{
    asustado = newAsustado;
}

void ghost::animacion()
{
    animacionVivo();

}
