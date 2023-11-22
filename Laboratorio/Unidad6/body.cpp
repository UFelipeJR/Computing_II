#include "body.h"


body::body()
{

}

body::body(float _x, float _y, float _masa, float _rad, float _vx, float _vy)
{
    x = _x;
    y = _y;
    vx = _vx;
    vy = _vy;
    ax = 0;
    ay = 0;
    radio = _rad;
    masa = _masa;

    setPos((x/EX), (-y/EY));
}

QRectF body::boundingRect() const
{
    return QRect(-radio/EX, -radio/EX, (radio/EX)*2, (radio/EX)*2);
}

void body::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkRed);
    painter->drawEllipse(boundingRect());
}

float body::getX() const
{
    return x;
}
float body::getY() const
{
    return y;
}
float body::getVx() const
{
    return vx;
}
float body::getVy() const
{
    return vy;
}
float body::getAx() const
{
    return ax;
}
float body::getAy() const
{
    return ay;
}
float body::getRad() const
{
    return radio;
}
float body::getMasa() const
{
    return masa;
}


void body::setX(float value)
{
    x = value;
}
void body::setY(float value)
{
    y = value;
}
void body::setVx(float value)
{
    vx = value;
}
void body::setVy(float value)
{
    vy = value;
}
void body::setAx(float value)
{
    ax = value;
}
void body::setAy(float value)
{
    ay = value;
}
void body::setRad(float value)
{
    radio = value;
}
void body::setMasa(float value)
{
    masa = value;
}


void body::aceleracion(float m2, float x2, float y2)
{

    float r=0;
    float alpha=0;

    r = sqrt(pow((x2-x),2) + pow((y2-y),2));

    if (x2!=x) alpha = atan2((y2-y),(x2-x));
    else alpha = 0;


    ax += (G * m2 * cos(alpha)) / pow(r,2);
    ay += (G * m2 * sin(alpha)) / pow(r,2);
}

void body::velocidades()
{
    vx = vx + (ax*DT);
    vy = vy + (ay*DT);
}

void body::posiciones()
{
    x = x + (vx * DT) + (0.5 * ax * pow(DT,2));
    y = y + (vy * DT) + (0.5 * ay * pow(DT,2));

    setPos((x/EX), (-y/EY));
}
