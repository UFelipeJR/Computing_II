#ifndef RECURSOS_H
#define RECURSOS_H

#include <QString>

#define basePacmanVivo 32
#define largoPacmanVivo 32
#define basePacmanMuerto 32
#define largoPacmanMuerto 32
#define baseFantasma 32
#define largoFantasma 32

#define constanteLaberinto 16
#define tam_bloque 30


class recursos {

public:
    recursos();
    static const QString ruta_laberinto;
    static const QString RpacmanVivo;
    static const QString RpacmanMuerto;
    static const QString sonidoM;
    static const QString sonidoV;
    static const QString RpowerUP;
    static const QString RFantasmaV;
    static const QString RFantasmaO;
    static const QString RFantasmaA;
    static const QString icoN;

};

#endif // RECURSOS_H

