#ifndef MYALGORITHMSCIRCLE_HPP
#define MYALGORITHMSCIRCLE_HPP

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

#define REPEATS_CIRCLE 100

class MyAlgorithmsCircle
{
private:
    int currentAlgorithm;
    QVector<QString> names;
    void makeNames();
public:
    MyAlgorithmsCircle();
    ~MyAlgorithmsCircle();
    void performAlgorithm(MyPoint center, int radius, MyGraphicsItemGroup *group, QString algorithm);

//    void performAlgorithm(MyPoint start, MyPoint end, MyGraphicsItemGroup *group, QString algorithm);
//    void performEmptyAlgorithm(MyPoint start, MyPoint end, MyGraphicsItemGroup *group, QString algorithm);
    int getTime(MyPoint center, int radius, QString algorithm);
    double getGradation(MyPoint start, MyPoint end);
    QVector<QString> getNames();

};

// Draw
// Circle
void drawCircleCanon(int center_x, int center_y, int radius, MyGraphicsItemGroup *group);
void drawCircleParam(int center_x, int center_y, int radius, MyGraphicsItemGroup *group);
void drawCircleBresenhem(int center_x, int center_y, int radius, MyGraphicsItemGroup *group);
void drawCircleMiddlePoint(int center_x, int center_y, int radius, MyGraphicsItemGroup *group);
void drawCircleLibrary(int center_x, int center_y, int radius, MyGraphicsItemGroup *group);


#endif