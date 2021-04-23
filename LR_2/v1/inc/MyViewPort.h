#ifndef MYVIEWPORT_H
#define MYVIEWPORT_H

#include "MyFish.h"
#include <cmath>

class MyViewPort
{
public:
	MyViewPort(){};
	MyViewPort(DrawFish::MyPoint rlu, DrawFish::MyPoint rrd, DrawFish::MyPoint srd);
	void setViewPortScreen(DrawFish::MyPoint srd);
	void setViewPortReal(DrawFish::MyPoint rlu, DrawFish::MyPoint rrd);
	void setViewPort(DrawFish::MyPoint rlu, DrawFish::MyPoint rrd, DrawFish::MyPoint srd);
	DrawFish::MyPoint getScreenCoordinatesByReal(DrawFish::MyPoint real_point);
	qreal getScreenDistanceByReal(qreal real_distance);
private:
	DrawFish::MyPoint real_left_up;;
	DrawFish::MyPoint real_right_down;
	DrawFish::MyPoint screen_right_down;
	qreal scale;
	void updateScale();
};

#endif