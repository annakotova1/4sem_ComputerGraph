#ifndef MYLINE_HPP
#define MYLINE_HPP

#include "../MyPoint/MyPoint.hpp"
#include <QVector>

class MyLine
{
private:
    QVector<MyPoint> points;
public:
    MyLine();
    MyLine(MyPoint n_start, MyPoint n_end);
    ~MyLine();
    QVector<MyPoint> getPoints();
    void addPoint(MyPoint point);
};

#endif