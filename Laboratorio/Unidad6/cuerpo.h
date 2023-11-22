#ifndef CUERPO_H
#define CUERPO_H

#define EY 20
#define EX 10

#define G 1
#define DT 1

#include <QGraphicsItem>
#include <QPainter>
#include <cmath>

class cuerpo : public QGraphicsItem
{
private:
    float x, y, vx, vy, ax, ay, radio, masa;
    bool centro;

public:
    cuerpo();
    cuerpo(float _x, float _y, float _masa, float _radio, float _vx, float _vy);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    // get
    float getX() const;
    float getY() const;
    float getVx() const;
    float getVy() const;
    float getAx() const;
    float getAy() const;
    float getRad() const;
    float getMasa() const;
    bool getCentro() const;

    // set
    void setX(float value);
    void setY(float value);
    void setVx(float value);
    void setVy(float value);
    void setAx(float value);
    void setAy(float value);
    void setRad(float value);
    void setMasa(float value);

    // Funciones mvto
    void aceleracion(float m2, float x2, float y2);
    void velocidades();
    void posiciones();
};

#endif // CUERPO_H
