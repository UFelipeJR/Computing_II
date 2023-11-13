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
    cambioSpriteAsustado = 1;
    separarSprites(":/Recursos/Sprites/cuerpoFantasmaAsus.png",":/Recursos/Sprites/ojosFantasma.png",":/Recursos/Sprites/cuerpoFantasma.png",1,1,1);
    pintarFantasma();

}

ghost::~ghost()
{
    delete fantasmaVivo;
    delete fantasmaOjos;
    delete timerFantasma;
    delete fantasmaAsustado;
}


void ghost::separarSprites(QString sprite1,QString sprite2, QString sprite3 ,short int cantSprites, short int cantSpritesOjos,short int cantSpritesAsustado)
{
    QPixmap auxiliar;
    QPixmap auxiliar2;
    QPixmap auxiliar3;

    if(vivo && !asustado){
        auxiliar.load(sprite1);
        auxiliar2.load(sprite2);
        auxiliar.load(sprite3);

        *fantasmaVivo = auxiliar.copy((cantSprites*baseFantasma)-baseFantasma,0,baseFantasma,largoFantasma);
        *fantasmaOjos = auxiliar2.copy((cantSpritesOjos*baseFantasma)-baseFantasma,0,baseFantasma,largoFantasma);
        *fantasmaAsustado = auxiliar3.copy((cantSprites*baseFantasma)-baseFantasma,0,baseFantasma,largoFantasma);
    }

}

void ghost::pintarFantasma()
{
    QImage original = fantasmaVivo->toImage();
    QColor colorPixel;
    for(int i = 0; i<baseFantasma; i++){
        for(int j = 0; j<largoFantasma; j++){
            colorPixel = original.pixelColor(i,j);
            if(colorPixel == nativo){
                original.setPixelColor(i,j,modificado);
            }
        }
    }

    *fantasmaVivo = QPixmap::fromImage(original);

}


void ghost::animacionVivo()
{
    const float escala = 0.875;
    QPixmap fusion(*fantasmaVivo);
    QPainter fusionador(&fusion);


    if (cambioSpriteVivo == 6) {
        cambioSpriteVivo = 1;
    } else {
        cambioSpriteVivo++;
    }
    separarSprites(":/Recursos/Sprites/cuerpoFantasmaAsus.png",":/Recursos/Sprites/ojosFantasma.png",":/Recursos/Sprites/cuerpoFantasma.png",cambioSpriteVivo,cambioSpriteOjos,cambioSpriteAsustado);
    pintarFantasma();
    fusionador.drawPixmap(0,0,*fantasmaOjos);
    fusionador.end();
    fusion = fusion.scaled(fusion.width() * escala,fusion.height() * escala);
    *fantasmaAsustado = fantasmaAsustado->scaled(fantasmaAsustado->width()*escala,fantasmaAsustado->height() * escala);
    setPixmap(fusion);
    //setPixmap(*fantasmaAsustado);


}

void ghost::setAsustado(bool newAsustado)
{
    asustado = newAsustado;
}

void ghost::animacion()
{
    if(vivo && !asustado){
        animacionVivo();
    }

}
