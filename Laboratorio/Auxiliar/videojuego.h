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

    int direcciones;
public:
    videojuego(QWidget *parent = nullptr);
    ~videojuego();
    setCustomBackgroundColor(string color);
    void construirTablero();
    void renderizarTablero();

public slots:
    void movimiento_Automatico();

protected:
    void keyPressEvent(QKeyEvent *event);

};
