#include "MyContainerShape.hpp"

MyContainer::MyContainer()
{}

MyContainer::~MyContainer()
{}


void MyContainer::addShape(MyShape newShape)
{
    shapes.append(newShape);
}

void MyContainer::clean()
{
    shapes.clear();
}

void MyContainer::setAlgorithm(MyAlgorithm *algorithm)
{
    alg = algorithm;
}

void MyContainer::draw(MyImage *draw)
{
    alg->draw(shapes, draw);
}
void MyContainer::drawWithDelay(MyImage *draw)
{
    printf("delay");
    alg->drawWithDelay(shapes, draw);
}