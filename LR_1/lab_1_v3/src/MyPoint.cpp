#include "../inc/MyPoint.h"
MyPoint::MyPoint()
{}
MyPoint::MyPoint(qreal c_x, qreal c_y) : x(c_x), y(c_y)
{}

MyPoint::~MyPoint()
{}

bool operator== (const MyPoint &a, const MyPoint &b)
{
    return (a.x == b.x && a.y == b.y);
}