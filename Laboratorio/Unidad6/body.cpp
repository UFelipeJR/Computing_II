#include "body.h"


body::body()
{
    x = 0;
    y = 0;
    vx = 0;
    vy = 0;
    ax = 0;
    ay = 0;
    rad = 0;
    mass = 0;

    setPos(0,0);

    color = genRandomColor();
}

body::body(float x, float y, float mass, float rad, float vx, float vy)
{
    this->x = x;
    this->y = y;
    this->vx = vx;
    this->vy = vy;
    this->ax = 0;
    this->ay = 0;
    this->rad = rad;
    this->mass = mass;

    setPos((x/EX), (-y/EY));

    color = genRandomColor();


}

QRectF body::boundingRect() const
{
    return QRect(-rad/EX, -rad/EX, (rad/EX)*2, (rad/EX)*2);
}

void body::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setBrush(color);
    painter->drawEllipse(boundingRect());
}

void body::acceleration(float m2, float x2, float y2)
{

    float r=0;
    float alpha=0;

    r = sqrt(pow((x2-x),2) + pow((y2-y),2));

    if (x2!=x) alpha = atan2((y2-y),(x2-x));
    else alpha = 0;


    ax += (G * m2 * cos(alpha)) / pow(r,2);
    ay += (G * m2 * sin(alpha)) / pow(r,2);
}

void body::vels()
{
    vx = vx + (ax*DT);
    vy = vy + (ay*DT);
}

void body::positions()
{
    x = x + (vx * DT) + (0.5 * ax * pow(DT,2));
    y = y + (vy * DT) + (0.5 * ay * pow(DT,2));

    setPos((x/EX), (-y/EY));
}

QColor body::genRandomColor()
{
    int red = std::rand() % 256;
    int green = std::rand() % 256;
    int blue = std::rand() % 256;

    return QColor(red, green, blue);
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
    return rad;
}
float body::getMasa() const
{
    return mass;
}


void body::setX(float val)
{
    x = val;
}
void body::setY(float val)
{
    y = val;
}
void body::setVx(float val)
{
    vx = val;
}
void body::setVy(float val)
{
    vy = val;
}
void body::setAx(float val)
{
    ax = val;
}
void body::setAy(float val)
{
    ay = val;
}
void body::setRad(float val)
{
    rad = val;
}
void body::setMasa(float val)
{
    mass = val;
}
