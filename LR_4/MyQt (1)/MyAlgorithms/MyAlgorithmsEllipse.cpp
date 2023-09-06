#include "MyAlgorithmsEllipse.hpp"

MyAlgorithmsEllipse::MyAlgorithmsEllipse()
{
    makeNames();
}

MyAlgorithmsEllipse::~MyAlgorithmsEllipse()
{}

void MyAlgorithmsEllipse::makeNames()
{
    names.append("Брезенхем");
    names.append("Метод средней точки");
    names.append("Параметрическое уравнение");
    names.append("Каноническое уравнение");
    names.append("Библиотечный метод");
}

void MyAlgorithmsEllipse::performAlgorithm(MyPoint center, int a, int b, MyGraphicsItemGroup *group, QString algorithm)
{
    int index = names.indexOf(algorithm);
    switch (index)
    {
        case BRESENHEM:
            drawEllipseBresenhem(center.getX(), center.getY(), a, b, group);
            break;
        case MIDDLE_POINT:
            drawEllipseMiddlePoint(center.getX(), center.getY(), a, b, group);
            break;
        case PARAM:
            drawEllipseParam(center.getX(), center.getY(), a, b, group);
            break;
        case CANON:
            drawEllipseCanon(center.getX(), center.getY(), a, b, group);
            break;
        case LIBRARY:
            drawEllipseLibrary(center.getX(), center.getY(), a, b, group);
            break;
    }
}

int MyAlgorithmsEllipse::getTime(MyPoint center, int a, int b, QString algorithm)
{
    int start_time, end_time;
    MyGraphicsItemGroup *group = new MyGraphicsItemGroup();
    start_time = clock();
    for (int i = 0; i < REPEATS_ELLIPSE; i++)
    {
        performAlgorithm(center, a, b, group, algorithm);
    }
    end_time = clock();
    delete group;
    return (end_time - start_time)/REPEATS_ELLIPSE;
}

QVector<QString> MyAlgorithmsEllipse::getNames()
{
    return names;
}
