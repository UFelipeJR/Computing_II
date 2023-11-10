#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include "laberinto.h"
#include <QColor>
#include <pacman.h>
#include <QLabel>
#include <QFontDatabase>
#include <cstdlib>
#include <ctime>

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
    QGraphicsTextItem* texto;

    ghost *blinky;
    ghost *clyde;
    ghost *inky;
    ghost *pinky;

    int direcciones;
    float pacmanLaberintoX;
    float pacmanLaberintoY;
    float blinkyLaberintoX;
    float blinkyLaberintoY;

    string textoPuntaje;


public:
    videojuego(QWidget *parent = nullptr);
    ~videojuego();
    setCustomBackgroundColor(string color);
    void construirTablero();
    void renderizarTablero();
    void dibujarCuadricula();
    void posRelativa();
    void actualizarTexto();
    void tp();

public slots:
    void movimiento_Automatico();
    void movimiento_blinky();

protected:
    void keyPressEvent(QKeyEvent *event);

};
