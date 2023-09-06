#ifndef MYSHAPE_HPP
#define MYSHAPE_HPP

#include <QVector>
#include "../MyPoint/MyPoint.hpp"

class MyShape
{
private:
    QVector<MyPoint> points;
public:
    MyShape();
    MyShape(QVector<MyPoint> newPoints);
    ~MyShape();
    
    void addPoint(MyPoint newPoint);
    void clean();

    MyPoint getPoint(int i);
    int getSize();
    bool isEmpty();

    //bool operator==(MyShape b);
    bool operator==(const MyShape b);

    MyPoint getFirstPoint();
    MyPoint getLastPoint();

    QVector<MyPoint> getPoints();
};

#endif