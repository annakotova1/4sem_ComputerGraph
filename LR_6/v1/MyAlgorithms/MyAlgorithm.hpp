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
    virtual void draw(MyImage *image, MyPoint point){};
    virtual void drawWithDelay(MyImage *image, MyPoint point){};
    virtual ~MyAlgorithm(){};
};

#endif