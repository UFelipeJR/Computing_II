#ifndef ESCENA_H
#define ESCENA_H

#include "pacman.h"
#include <QGraphicsView>
#include <QGraphicsScene>

class escena
{
private:
    QGraphicsView *graphics;
    QGraphicsScene *scene;
public:
    escena();
    ~escena();
    void set_graphicsview(QGraphicsView *graphics);
    void set_pac(pacman *pac);
};

#endif // ESCENA_H

