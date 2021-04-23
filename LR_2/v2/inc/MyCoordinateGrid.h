#ifndef MYCOORDINATEGRID_H
#define MYCOORDINATEGRID_H

#include <QGraphicsItemGroup>
#include "MyViewPort.h"
#include <QGraphicsScene>
#include <cmath>
class MyCoordinateGrid
{
public:
	MyCoordinateGrid();
	~MyCoordinateGrid();
	void makeGridStep(MyViewPort viewPort);
	void draw(MyViewPort viewPort, QGraphicsItemGroup *group, QGraphicsScene *scene);
private:
	int lineCount = 10;
	//int gridDelta = 2.5;
	int currentGridStep;
};

#endif