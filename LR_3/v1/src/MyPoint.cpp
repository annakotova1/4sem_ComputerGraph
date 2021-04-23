#include "../inc/MyPoint.hpp"

MyPoint::MyPoint()
{}

MyPoint::MyPoint(qreal new_x, qreal new_y) : x(new_x), y(new_y)
{}

qreal MyPoint::getX()
{
    return x;
}
qreal MyPoint::getY()
{
    return y;
}
void MyPoint::setX(qreal new_x)
{
    x = new_x;
}
void MyPoint::setY(qreal new_y)
{
    x = new_y;
}