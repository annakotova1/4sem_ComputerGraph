#ifndef MYALGORITHMSELLIPSE_HPP
#define MYALGORITHMSELLIPSE_HPP

#include <cmath>
#include <QElapsedTimer>
#include <time.h>
#include <QtGlobal>

#include "../MyPoint/MyPoint.hpp"
#include "../MyGraphicsItemGroup/MyGraphicsItemGroup.hpp"

#define BRESENHEM 0
#define MIDDLE_POINT 1
#define PARAM 2
#define CANON 3
#define LIBRARY 4


#define REPEATS_ELLIPSE 100

class MyAlgorithmsEllipse
{
private:
    int currentAlgorithm;
    QVector<QString> names;
    void makeNames();
public:
    MyAlgorithmsEllipse();
    ~MyAlgorithmsEllipse();
    void performAlgorithm(MyPoint center, int a, int b, MyGraphicsItemGroup *group, QString algorithm);

//    void performAlgorithm(MyPoint start, MyPoint end, MyGraphicsItemGroup *group, QString algorithm);
//    void performEmptyAlgorithm(MyPoint start, MyPoint end, MyGraphicsItemGroup *group, QString algorithm);
    int getTime(MyPoint center, int a, int b, QString algorithm);
    QVector<QString> getNames();

};

// Draw
// Ellipse
void drawEllipseCanon(int center_x, int center_y, int a, int b, MyGraphicsItemGroup *group);
void drawEllipseParam(int center_x, int center_y, int a, int b, MyGraphicsItemGroup *group);
void drawEllipseBresenhem(int center_x, int center_y, int a, int b, MyGraphicsItemGroup *group);
void drawEllipseMiddlePoint(int center_x, int center_y, int a, int b, MyGraphicsItemGroup *group);
void drawEllipseLibrary(int center_x, int center_y, int a, int b, MyGraphicsItemGroup *group);



#endif