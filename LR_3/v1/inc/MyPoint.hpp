#ifndef MYPOINT_H
#define MYPOINT_H

#include <QtGlobal>

class MyPoint
{
public:
    MyPoint();
    MyPoint(qreal new_x, qreal new_y);
    ~MyPoint(){};
    qreal getX();
    qreal getY();
    void setX(qreal new_x);
    void setY(qreal new_y);
private:
    qreal x;
    qreal y;
};

#endif