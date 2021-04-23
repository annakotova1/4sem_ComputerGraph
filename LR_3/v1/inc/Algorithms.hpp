#ifndef ALGORITHMSDRAW_H
#define ALGORITHMSDRAW_H

#include <time.h>
#include <cmath>
#include "MyPoint.hpp"
#include "MyGraphicsItemGroup.hpp"

// ALGORITM KEYS
#define CDA 0
#define BRESENHEMINT 1
#define BRESENHEMFLOAT 2
#define BRESENHEMSMOOTH 3
#define VY 4
#define LIBRARY 5

// Draw
void drawCDA(MyPoint start, MyPoint end, MyGraphicsItemGroup *group);
void drawBrezenhemInt(MyPoint start, MyPoint end, MyGraphicsItemGroup *group);
void drawBrezenhemFloat(MyPoint start, MyPoint end, MyGraphicsItemGroup *group);
void drawBrezenhemSmooth(MyPoint start, MyPoint end, MyGraphicsItemGroup *group);
void drawVy(MyPoint start, MyPoint end, MyGraphicsItemGroup *group);
void drawLibrary(MyPoint start, MyPoint end, MyGraphicsItemGroup *group);

// Time
void timeCDA(qreal start_x, qreal start_y, qreal end_x, qreal end_y);
void timeBrezenhemInt(qreal start_x, qreal start_y, qreal end_x, qreal end_y);
void timeBrezenhemFloat(qreal start_x, qreal start_y, qreal end_x, qreal end_y);
void timeBrezenhemSmooth(qreal start_x, qreal start_y, qreal end_x, qreal end_y);
void timeVy(qreal start_x, qreal start_y, qreal end_x, qreal end_y);
void timeLibrary(qreal start_x, qreal start_y, qreal end_x, qreal end_y);

void times(qreal start_x, qreal start_y, qreal end_x, qreal end_y, int repeats);
// Gradation
void gradation(const qreal &angle, qreal &ans);
#endif 