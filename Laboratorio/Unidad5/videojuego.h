#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include "pacman.h"

QT_BEGIN_NAMESPACE
namespace Ui { class videojuego; }
QT_END_NAMESPACE

class videojuego : public QMainWindow
{
    Q_OBJECT

public:
    videojuego(QWidget *parent = nullptr);
    ~videojuego();
    setCustomBackgroundColor(string color);

protected:
    void keyPressEvent(QKeyEvent *event);
private:
    Ui::videojuego *ui;
    QGraphicsView *view;
    QGraphicsScene *scene;
    QGraphicsRectItem *rect;
    pacman *pacMancito;
};
