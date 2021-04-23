#ifndef MYVIEWPORT_H
#define MYVIEWPORT_H

//#include "MyFish.h"
#include <cmath>
#include <iostream>
#include <QtGlobal>

#include "MyMatrixWork.h"

namespace DrawFish
	{
	class MyPoint
	{
	public:
		void transfer(matrix_t transform_matrix);
		MyPoint(){};
		MyPoint(qreal c_x, qreal c_y):x(c_x), y(c_y) {};

		qreal x;
		qreal y;
	};
}
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
	DrawFish::MyPoint getRealCoordinatesByScreen(DrawFish::MyPoint point);
	qreal getRealDistanceByScreen(qreal screen_distance);
	void updateScale();

	DrawFish::MyPoint getRealCoordinateRightDownConner();
	DrawFish::MyPoint getRealCoordinateLeftUpConner();
	//DrawFish::MyPoint getScreenCoordinateRightDownConner();

private:
	DrawFish::MyPoint real_left_up;
	DrawFish::MyPoint real_right_down;
	DrawFish::MyPoint must_left_up;
	DrawFish::MyPoint must_right_down;
	DrawFish::MyPoint screen_right_down;
	qreal scale;
	void fixx();
	void fixy();
};

#endif