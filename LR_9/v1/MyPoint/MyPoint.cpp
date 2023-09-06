#include "MyPoint.hpp"

MyPoint::MyPoint()
{}
MyPoint::MyPoint(double c_x, double c_y): x(c_x), y(c_y)
{}
MyPoint::~MyPoint()
{}

double MyPoint::getX()
{
    return x;
}
double MyPoint::getY()
{
    return y;
}

void MyPoint::setX(double c_x)
{
    x = c_x;
}
void MyPoint::setY(double c_y)
{
    y = c_y;
}
/*
bool MyPoint::operator==(MyPoint a)
{
    if (a.getX() == getX() && a.getY() == getY())
        return true;
    return false;
}*/
bool MyPoint::operator==(const MyPoint a)
{
    MyPoint b = a;
    if (b.getX() == getX() && b.getY() == getY())
        return true;
    return false;
}