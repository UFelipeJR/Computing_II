#ifndef BODY_H
#define BODY_H

#define EY 20
#define EX 10

#define G 1
#define DT 1

#include <QGraphicsItem>
#include <QPainter>
#include <cmath>
#include<stdlib.h>
#include<time.h>

class body : public QGraphicsItem
{
private:
    float x, y, vx, vy, ax, ay, radio, masa;
    bool centro;

public:
    body();
    body(float _x, float _y, float _masa, float _radio, float _vx, float _vy);

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

    void setX(float value);
    void setY(float value);
    void setVx(float value);
    void setVy(float value);
    void setAx(float value);
    void setAy(float value);
    void setRad(float value);
    void setMasa(float value);

    void aceleracion(float m2, float x2, float y2);
    void velocidades();
    void posiciones();
};

#endif // BODY_H
