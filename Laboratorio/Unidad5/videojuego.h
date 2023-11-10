#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include "laberinto.h"
#include <QColor>
#include <pacman.h>

QT_BEGIN_NAMESPACE
namespace Ui { class videojuego; }
QT_END_NAMESPACE

class videojuego : public QMainWindow
{
    Q_OBJECT

private:
    Ui::videojuego *ui;
    QGraphicsView *view;
    QGraphicsScene *scene;

    pacman *pacMancito;
    laberinto* maze;
    QTimer *timer;
    QPixmap arregloLaberinto[32];
    QPixmap imagenLaberinto;
    QGraphicsPixmapItem* LaberintoPixmaItems[28][36];

    ghost *blinky;
    ghost *clyde;
    ghost *inky;
    ghost *pinky;

    int direcciones;
    float pacmanLaberintoX;
    float pacmanLaberintoY;
    float blinkyLaberintoX;
    float blinkyLaberintoY;


public:
    videojuego(QWidget *parent = nullptr);
    ~videojuego();
    setCustomBackgroundColor(string color);
    void construirTablero();
    void renderizarTablero();
    void dibujarCuadricula();
    void posRelativa();

public slots:
    void movimiento_Automatico();
    void movimiento_blinky();

protected:
    void keyPressEvent(QKeyEvent *event);

};
