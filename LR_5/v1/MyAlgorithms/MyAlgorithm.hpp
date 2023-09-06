#ifndef MYALGORITHM_HPP
#define MYALGORITHM_HPP

#include <unistd.h>

#include <QVector>
#include "../MyShape/MyShape.hpp"
#include "../MyPoint/MyPoint.hpp"
#include "../MyImage/MyImage.hpp"

class MyAlgorithm
{
public:
    MyAlgorithm(){};
    virtual void draw(QVector<MyShape> shapes, MyImage *image){};
    virtual void drawWithDelay(QVector<MyShape> shapes, MyImage *image){};
    virtual ~MyAlgorithm(){};
};

#endif