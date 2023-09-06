#ifndef MYEDGE_HPP
#define MYEDGE_HPP

#include <unistd.h>
#include "../MyPoint/MyPoint.hpp"
#include "../MyImage/MyImage.hpp"
#include <QVector>

class MyEdge
{
    int Y;
    QVector<int>X;
public:
    MyEdge();
    MyEdge(int y);
    void addX(int x);
    int y();
    bool check();
    ~MyEdge();
    void draw(MyImage *drawer);
    void drawWithDelay(MyImage *drawer);
    void sort();
    void output();
};

#endif