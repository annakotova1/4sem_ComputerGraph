#include "../inc/MyAlgorithms.hpp"

MyAlgorithms::MyAlgorithms()
{}

MyAlgorithms::~MyAlgorithms()
{}

void MyAlgorithms::performAlgorithm(MyPoint start, MyPoint end, MyGraphicsItemGroup *group, int algorithm)
{
    switch (algorithm)
    {
        case BRESENHEM_INT:
            drawBrezenhemInt(start.getX(), start.getY(), end.getX(), end.getY(), group);
            break;
        case BRESENHEM_FLOAT:
            drawBrezenhemFloat(start.getX(), start.getY(), end.getX(), end.getY(), group);
            break;
        case BRESENHEM_SMOOTH:
            drawBrezenhemSmooth(start.getX(), start.getY(), end.getX(), end.getY(), group);
            break;
        case VY:
            drawVy(start.getX(), start.getY(), end.getX(), end.getY(), group);
            break;
        case CDA:
            drawCDA(start.getX(), start.getY(), end.getX(), end.getY(), group);
            break;
        case LIBRARY:
            drawLibrary(start.getX(), start.getY(), end.getX(), end.getY(), group);
            break;
    }
}

void MyAlgorithms::performEmptyAlgorithm(MyPoint start, MyPoint end, int algorithm)
{
    switch (algorithm)
    {
        case BRESENHEM_INT:
            timeBrezenhemInt(start.getX(), start.getY(), end.getX(), end.getY());
            break;
        case BRESENHEM_FLOAT:
            timeBrezenhemFloat(start.getX(), start.getY(), end.getX(), end.getY());
            break;
        case BRESENHEM_SMOOTH:
            timeBrezenhemSmooth(start.getX(), start.getY(), end.getX(), end.getY());
            break;
        case VY:
            timeVy(start.getX(), start.getY(), end.getX(), end.getY());
            break;
        case CDA:
            timeCDA(start.getX(), start.getY(), end.getX(), end.getY());
            break;
        case LIBRARY:
            MyGraphicsItemGroup *group = new MyGraphicsItemGroup();
            timeLibrary(start.getX(), start.getY(), end.getX(), end.getY(), group);
            delete group;
            break;
    }
}

int MyAlgorithms::getTime(MyPoint start, MyPoint end, int algorithm)
{
    int start_time, end_time;
    start_time = clock();
    for (int i = 0; i < REPEATS; i++)
    {
        performEmptyAlgorithm(start, end, algorithm);
    }
    end_time = clock();
    return end_time - start_time;
}

int MyAlgorithms::getGradation(MyPoint start, MyPoint end)
{
    qreal dx = fabs(start.getX() - end.getX());
    qreal dy = fabs(start.getY() - end.getY());

    if (dx/dy < dy/dx)
        return dx/dy;
    else
        return dy/dx;
}