#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include "pacman.h"
#include "laberinto.h"
#include "ghost.h"
#include <QColor>

QT_BEGIN_NAMESPACE
namespace Ui { class videojuego; }
QT_END_NAMESPACE

class videojuego : public QMainWindow
{
    Q_OBJECT

private:
    int sceneWidth;
    int sceneHeight;
    int direcciones;
    Ui::videojuego *ui;
    QGraphicsView *view;
    QGraphicsScene *scene;
    QGraphicsRectItem *rect;
    qreal scaleFactor;
    QTimer *timer;

    pacman *pacMancito;
    laberinto *maze;
    ghost *blinky;
    ghost *clyde;
    ghost *inky;
    ghost *pinky;


public:
    videojuego(QWidget *parent = nullptr);
    ~videojuego();
    setCustomBackgroundColor(string color);

public slots:
    void movimiento_Automatico();

protected:
    void keyPressEvent(QKeyEvent *event);


};
