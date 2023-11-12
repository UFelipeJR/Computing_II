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
    timerFantasma = new QTimer;

    timerFantasma->start(1000/velocidad);
    connect(timerFantasma, SIGNAL(timeout()), this, SLOT(animacion()));
    spritesFantasma = ":/Recursos/Sprites/cuerpoFantasma.png";
    spritesOjos = ":/Recursos/Sprites/ojosFantasma.png";
    cambioSpriteVivo = 1;
    separarSprites(spritesFantasma,spritesOjos,1,1);
    pintarFantasma();

    //gen();
}

ghost::~ghost()
{
    delete fantasmaVivo;
    delete fantasmaOjos;
    delete timerFantasma;
}


void ghost::separarSprites(QString sprite1,QString sprite2,short int cantSprites, short int cantSpritesOjos)
{
    QPixmap auxiliar;
    QPixmap auxiliar2;

    if(vivo && !asustado){
        auxiliar.load(sprite1);
        auxiliar2.load(sprite2);

        *fantasmaVivo = auxiliar.copy((cantSprites*baseFantasma)-baseFantasma,0,baseFantasma,largoFantasma);
        *fantasmaOjos = auxiliar2.copy((cantSpritesOjos*baseFantasma)-baseFantasma,0,baseFantasma,largoFantasma);
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
    const float escala = 0.8;
    QPixmap fusion(*fantasmaVivo);
    QPainter fusionador(&fusion);


    if (cambioSpriteVivo == 6) {
        cambioSpriteVivo = 1;
    } else {
        cambioSpriteVivo++;
    }
    separarSprites(spritesFantasma,spritesOjos,cambioSpriteVivo,cambioSpriteOjos);
    pintarFantasma();

    fusionador.drawPixmap(0,0,*fantasmaOjos);
    fusionador.end();

    fusion = fusion.scaled(fusion.width() * escala,fusion.height() * escala);

    setPixmap(fusion);

}


void ghost::animacion()
{
    if(vivo){
        animacionVivo();
    }

}
