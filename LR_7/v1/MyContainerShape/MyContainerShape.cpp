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
