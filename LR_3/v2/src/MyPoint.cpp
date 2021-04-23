#include "../inc/MyPoint.hpp"

MyPoint::MyPoint()
{}
MyPoint::MyPoint(int c_x, int c_y): x(c_x), y(c_y)
{}
MyPoint::~MyPoint()
{}

int MyPoint::getX()
{
    return x;
}
int MyPoint::getY()
{
    return y;
}

void MyPoint::setX(int c_x)
{
    x = c_x;
}
void MyPoint::setY(int c_y)
{
    x = c_y;
}