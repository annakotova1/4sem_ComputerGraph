#include "MyShape.hpp"

MyShape::MyShape()
{}
MyShape::MyShape(QVector<MyPoint> newPoints)
{
    points = newPoints;
}
MyShape::~MyShape()
{
}

void MyShape::addPoint(MyPoint newPoint)
{
    points.append(newPoint);
}

int MyShape::getSize()
{
    return points.size();
}
MyPoint MyShape::getPoint(int i)
{
    return points.value(i);
}
QVector<MyPoint> MyShape::getPoints()
{
    return points;
}
/*
bool MyShape::operator==(MyShape*b)
{
    if (getSize() != b->getSize())
    {
        return false;
    }
    for (int i = 0; i < points.size();i++)
    {
        if (getPoint(i) == b->getPoint(i));
    }
    return true;
}*/
bool MyShape::operator==(const MyShape b)
{
    MyShape a = b, c = *this;
    if (c.getSize() != a.getSize())
    {
        return false;
    }
    for (int i = 0; i < points.size();i++)
    {
        if (c.getPoint(i) == a.getPoint(i));
    }
    return true;
}

bool MyShape::isEmpty()
{
    if (points.size() == 0)
    {
        return true;
    }
    return false;
}

MyPoint MyShape::getLastPoint()
{
    return points[points.size() - 1];
}
MyPoint MyShape::getFirstPoint()
{
    if (points.size())
    {
        return points[0];
    }
}
