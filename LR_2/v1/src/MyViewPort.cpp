#include "../inc/MyViewPort.h"

MyViewPort::MyViewPort(DrawFish::MyPoint rlu, DrawFish::MyPoint rrd, DrawFish::MyPoint srd): 
	real_left_up(rlu), real_right_down(rrd), screen_right_down(srd)
{
	updateScale();
}

void MyViewPort::setViewPortScreen(DrawFish::MyPoint srd)
{
	screen_right_down = srd;
	updateScale();
}

void MyViewPort::setViewPortReal(DrawFish::MyPoint rlu, DrawFish::MyPoint rrd)
{
	real_left_up = rlu;
	real_right_down = rrd;
	updateScale();
}

void MyViewPort::setViewPort(DrawFish::MyPoint rlu, DrawFish::MyPoint rrd, DrawFish::MyPoint srd)
{
	real_left_up = rlu;
	real_right_down = rrd;
	screen_right_down = srd;
	updateScale();
}

void MyViewPort::updateScale()
{
	qreal scalex = fabs((real_left_up.x - real_right_down.x) / (0 - screen_right_down.x));
	qreal scaley = fabs((real_left_up.y - real_right_down.y) / (0 - screen_right_down.y));
	scale = std::max(scalex, scaley);
}

DrawFish::MyPoint MyViewPort::getScreenCoordinatesByReal(DrawFish::MyPoint point)
{

	std::cout << point.x - real_left_up.x << " " << point.y - real_left_up.y << std::endl;
	DrawFish::MyPoint screen_point = DrawFish::MyPoint((point.x - real_left_up.x) / scale, 
		(point.y - real_left_up.y) / scale);
	std::cout << screen_point.x << " " << screen_point.y << std::endl << std::endl;
	return screen_point;
}
qreal MyViewPort::getScreenDistanceByReal(qreal real_distance)
{
	return real_distance/scale;
}