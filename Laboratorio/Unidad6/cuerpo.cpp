#include "cuerpo.h"


cuerpo::cuerpo()
{

}

cuerpo::cuerpo(float _x, float _y, float _masa, float _rad, float _vx, float _vy)
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

QRectF cuerpo::boundingRect() const
{
    return QRect(-radio/EX, -radio/EX, (radio/EX)*2, (radio/EX)*2);
}

void cuerpo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkRed);
    painter->drawEllipse(boundingRect());
}

float cuerpo::getX() const
{
    return x;
}
float cuerpo::getY() const
{
    return y;
}
float cuerpo::getVx() const
{
    return vx;
}
float cuerpo::getVy() const
{
    return vy;
}
float cuerpo::getAx() const
{
    return ax;
}
float cuerpo::getAy() const
{
    return ay;
}
float cuerpo::getRad() const
{
    return radio;
}
float cuerpo::getMasa() const
{
    return masa;
}


void cuerpo::setX(float value)
{
    x = value;
}
void cuerpo::setY(float value)
{
    y = value;
}
void cuerpo::setVx(float value)
{
    vx = value;
}
void cuerpo::setVy(float value)
{
    vy = value;
}
void cuerpo::setAx(float value)
{
    ax = value;
}
void cuerpo::setAy(float value)
{
    ay = value;
}
void cuerpo::setRad(float value)
{
    radio = value;
}
void cuerpo::setMasa(float value)
{
    masa = value;
}


void cuerpo::aceleracion(float m2, float x2, float y2)
{

    float r=0;
    float alpha=0;

    r = sqrt(pow((x2-x),2) + pow((y2-y),2));

    if (x2!=x) alpha = atan2((y2-y),(x2-x));
    else alpha = 0;


    ax += (G * m2 * cos(alpha)) / pow(r,2);
    ay += (G * m2 * sin(alpha)) / pow(r,2);
}

void cuerpo::velocidades()
{
    vx = vx + (ax*DT);
    vy = vy + (ay*DT);
}

void cuerpo::posiciones()
{
    x = x + (vx * DT) + (0.5 * ax * pow(DT,2));
    y = y + (vy * DT) + (0.5 * ay * pow(DT,2));

    setPos((x/EX), (-y/EY));
}
