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
#include <cmath>
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

    ghost *blinky;
    ghost *clyde;
    ghost *inky;
    ghost *pinky;

    int direcciones;
    float pacmanLaberintoX;
    float pacmanLaberintoY;
    float blinkyLaberintoX;
    float blinkyLaberintoY;
    float inkyLaberintoX;
    float inkyLaberintoY;

    QGraphicsTextItem* texto;
    QGraphicsTextItem* texto2;
    string textoPuntaje;
    string textoVida;

public:

    videojuego(QWidget *parent = nullptr);
    ~videojuego();
    void setCustomBackgroundColor(string color);
    void dibujarCuadricula();
    void posRelativa();
    void actualizarTexto();
    void tp();
    void movimiento_Automatico();
    float cal_distancia(float xF, float yF ,int dirX, int dirY);

public slots:
    void juegoPrincipal();
    void manejarSen();
    void tranqui();
    void restablecimiento();
    void movimiento_blinky();
    //void movimiento_inky();

protected:
    void keyPressEvent(QKeyEvent *event);

};
