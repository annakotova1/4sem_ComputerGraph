#ifndef MYALGORITHMS_H
#define MYALGORITHMS_H

#include <cmath>
#include <time.h>
#include <QtGlobal>

#include "MyPoint.hpp"
#include "MyGraphicsItemGroup.hpp"

#define BRESENHEM_INT 0
#define BRESENHEM_FLOAT 1
#define BRESENHEM_SMOOTH 2
#define VY 3
#define CDA 4
#define LIBRARY 5

#define REPEATS 100

class MyAlgorithms
{
private:
    int currentAlgorithm;
public:
    MyAlgorithms();
    ~MyAlgorithms();
    void performAlgorithm(MyPoint start, MyPoint end, MyGraphicsItemGroup *group, int algorithm);
    void performEmptyAlgorithm(MyPoint start, MyPoint end, int algorithm);
    int getTime(MyPoint start, MyPoint end, int algorithm);
    int getGradation(MyPoint start, MyPoint end);
};

// Draw
void drawCDA(qreal start_x, qreal start_y, qreal end_x, qreal end_y, MyGraphicsItemGroup *group);
void drawBrezenhemInt(qreal start_x, qreal start_y, qreal end_x, qreal end_y, MyGraphicsItemGroup *group);
void drawBrezenhemFloat(qreal start_x, qreal start_y, qreal end_x, qreal end_y, MyGraphicsItemGroup *group);
void drawBrezenhemSmooth(qreal start_x, qreal start_y, qreal end_x, qreal end_y, MyGraphicsItemGroup *group);
void drawVy(qreal start_x, qreal start_y, qreal end_x, qreal end_y, MyGraphicsItemGroup *group);
void drawLibrary(qreal start_x, qreal start_y, qreal end_x, qreal end_y, MyGraphicsItemGroup *group);

// Time
void timeCDA(qreal start_x, qreal start_y, qreal end_x, qreal end_y);
void timeBrezenhemInt(qreal start_x, qreal start_y, qreal end_x, qreal end_y);
void timeBrezenhemFloat(qreal start_x, qreal start_y, qreal end_x, qreal end_y);
void timeBrezenhemSmooth(qreal start_x, qreal start_y, qreal end_x, qreal end_y);
void timeVy(qreal start_x, qreal start_y, qreal end_x, qreal end_y);
void timeLibrary(qreal start_x, qreal start_y, qreal end_x, qreal end_y, MyGraphicsItemGroup *group);


#endif