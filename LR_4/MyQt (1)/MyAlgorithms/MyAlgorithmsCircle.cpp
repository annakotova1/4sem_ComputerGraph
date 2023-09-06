#include "MyAlgorithmsCircle.hpp"

MyAlgorithmsCircle::MyAlgorithmsCircle()
{
    makeNames();
}

MyAlgorithmsCircle::~MyAlgorithmsCircle()
{}

void MyAlgorithmsCircle::makeNames()
{
    names.append("Брезенхем");
    names.append("Метод средней точки");
    names.append("Параметрическое уравнение");
    names.append("Каноническое уравнение");
    names.append("Библиотечный метод");
}

void MyAlgorithmsCircle::performAlgorithm(MyPoint center, int radius, MyGraphicsItemGroup *group, QString algorithm)
{
    int index = names.indexOf(algorithm);
    switch (index)
    {
        case BRESENHEM:
            drawCircleBresenhem(center.getX(), center.getY(), radius, group);
            break;
        case MIDDLE_POINT:
            drawCircleMiddlePoint(center.getX(), center.getY(), radius, group);
            break;
        case PARAM:
            drawCircleParam(center.getX(), center.getY(), radius, group);
            break;
        case CANON:
            drawCircleCanon(center.getX(), center.getY(), radius, group);
            break;
        case LIBRARY:
            drawCircleLibrary(center.getX(), center.getY(), radius, group);
            break;
    }
}

int MyAlgorithmsCircle::getTime(MyPoint center, int radius, QString algorithm)
{
    int start_time, end_time;
    MyGraphicsItemGroup *group = new MyGraphicsItemGroup();
    start_time = clock();
    for (int i = 0; i < REPEATS_CIRCLE; i++)
    {
        performAlgorithm(center, radius, group, algorithm);
    }
    end_time = clock();
    delete group;
    return (end_time - start_time)/REPEATS_CIRCLE;
}

double MyAlgorithmsCircle::getGradation(MyPoint start, MyPoint end)
{
    qreal dx = fabs(start.getX() - end.getX());
    qreal dy = fabs(start.getY() - end.getY());
    
    if (dx/dy < dy/dx)
        return dx;
    else
        return dy;
}

QVector<QString> MyAlgorithmsCircle::getNames()
{
    return names;
}
