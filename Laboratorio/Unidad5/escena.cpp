#include "escena.h"

escena::escena()
{
    scene = new QGraphicsScene;
}

escena::~escena()
{
    delete scene;
}

void escena::set_graphicsview(QGraphicsView *graphics)
{
    this->graphics = graphics;
    scene->setSceneRect(0, 0, graphics->width()-2, graphics->height()-2);
    graphics->setScene(scene);
}

void escena::set_pac(pacman *pac)
{
    scene->addItem(pac);
}
