#ifndef MYCONTAINERS_HPP
#define MYCONTAINERS_HPP

#include "../MyAlgorithms/MyAlgorithm.hpp"
#include "../MyShape/MyShape.hpp"
#include <QVector>

class MyContainer
{
private:
    QVector<MyShape> shapes;
    MyAlgorithm *alg = nullptr;
public:
    MyContainer();
    ~MyContainer();

    void addShape(MyShape newShape);
    void setAlgorithm(MyAlgorithm *newDrawer);
    void clean();
    void draw(MyImage *drawer);
    void drawWithDelay(MyImage *drawer);
};

#endif