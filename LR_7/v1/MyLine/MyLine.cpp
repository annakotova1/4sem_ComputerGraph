#include "MyLine.hpp"

MyLine::MyLine()
{}

MyLine::MyLine(MyPoint n_start, MyPoint n_end) 
{
    points.append(n_start);
    points.append(n_end);
}

MyLine::~MyLine()
{}

QVector<MyPoint> MyLine::getPoints()
{
    return points;
}
void MyLine::addPoint(MyPoint point)
{
    points.append(point);
}