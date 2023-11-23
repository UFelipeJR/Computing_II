#ifndef BODY_H
#define BODY_H

/*
#define EY 20
#define EX 10
#define G 1
#define DT 1
*/

#include <QGraphicsItem>
#include <QPainter>
#include <cmath>
#include <qcolor.h>
#include<stdlib.h>
#include<time.h>

class body : public QGraphicsItem
{
private:
    float x, y, vx, vy, ax, ay, rad, mass;
    int EY, EX,G,DT;
    QColor color;

public:
    body();
    body(float x, float y, float mass, float rad, float vx, float vy);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    float getX() const;
    float getY() const;
    float getVx() const;
    float getVy() const;
    float getAx() const;
    float getAy() const;
    float getRad() const;
    float getMasa() const;
    bool getCentro() const;

    void setX(float val);
    void setY(float val);
    void setVx(float val);
    void setVy(float val);
    void setAx(float val);
    void setAy(float val);
    void setRad(float val);
    void setMasa(float val);

    void acceleration(float m2, float x2, float y2);
    void vels();
    void positions();

    QColor genRandomColor();
};

#endif // BODY_H
