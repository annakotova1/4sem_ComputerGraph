#include "../inc/MyViewPort.h"

void DrawFish::MyPoint::transfer(matrix_t transform_matrix)
{
	vector_t start_vector = make_vector(x, y);
	vector_t end_vector = multiplicateVectorAndMatrix(transform_matrix, start_vector);
	x = end_vector[0];
	y = end_vector[1];
}

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
	must_left_up = rlu;
	must_right_down = rrd;
	updateScale();
}

void MyViewPort::setViewPort(DrawFish::MyPoint rlu, DrawFish::MyPoint rrd, DrawFish::MyPoint srd)
{
	must_left_up = rlu;
	must_right_down = rrd;
	screen_right_down = srd;
	updateScale();
}

void MyViewPort::updateScale()
{
	qreal scalex = fabs((must_left_up.x - must_right_down.x) / (0 - screen_right_down.x));
	qreal scaley = fabs((must_left_up.y - must_right_down.y) / (0 - screen_right_down.y));

	real_left_up = must_left_up;
	real_right_down = must_right_down;
	//scale = std::max(scalex, scaley);
	
	/*std::cout << must_left_up.x << " " << must_left_up.y << std::endl;
	std::cout << must_right_down.x << " " << must_right_down.y << std::endl;
	std::cout << real_left_up.x << " " << real_left_up.y << std::endl;
	std::cout << real_right_down.x << " " << real_right_down.y << std::endl;
	std::cout <<(real_left_up.x - real_right_down.x)<< " " << (0 - screen_right_down.x) << std::endl;
	std::cout <<(real_left_up.y - real_right_down.y)<< " " << (0 - screen_right_down.y) << std::endl;*/
	if (scalex > scaley)
	{
		scale = scalex;
		fixy();
	}
	else
	{
		scale = scaley;
		fixx();
	}
	/*std::cout << screen_right_down.x << " " << screen_right_down.y << std::endl;
	std::cout << scale << " " << scalex << " " << scaley << " " << std::endl;
	std::cout << real_left_up.x << " " << real_left_up.y << std::endl;
	std::cout << real_right_down.x << " " << real_right_down.y << std::endl;*/
}

DrawFish::MyPoint MyViewPort::getScreenCoordinatesByReal(DrawFish::MyPoint point)
{
	DrawFish::MyPoint screen_point = DrawFish::MyPoint((point.x - real_left_up.x) / scale, 
		(real_right_down.y - point.y) / scale);
	return screen_point;
}
qreal MyViewPort::getScreenDistanceByReal(qreal real_distance)
{
	return real_distance/scale;
}
DrawFish::MyPoint MyViewPort::getRealCoordinatesByScreen(DrawFish::MyPoint point)
{
	DrawFish::MyPoint real_point = DrawFish::MyPoint(point.x * scale + real_left_up.x, 
		real_right_down.y - (point.y) * scale);
	return real_point;
}

qreal MyViewPort::getRealDistanceByScreen(qreal screen_distance)
{
	return screen_distance*scale;
}

void MyViewPort::fixx()
{
	DrawFish::MyPoint real_lu = must_left_up;
	real_lu.x = (real_left_up.x - (screen_right_down.x - (must_right_down.x - must_left_up.x) / scale)* scale / 2);
	real_left_up = real_lu;

	DrawFish::MyPoint real_rd = must_right_down;
	real_rd.x = (real_right_down.x + (screen_right_down.x - (must_right_down.x - must_left_up.x) / scale)* scale / 2);
	real_right_down = real_rd;
}

void MyViewPort::fixy()
{
	DrawFish::MyPoint real_lu = must_left_up;
	real_lu.y = (must_left_up.y - (screen_right_down.y - (must_right_down.y - must_left_up.y) / scale)* scale / 2);
	real_left_up = real_lu;

	DrawFish::MyPoint real_rd = must_right_down;
	real_rd.y = (must_right_down.y + (screen_right_down.y - (must_right_down.y - must_left_up.y) / scale)* scale / 2);
	real_right_down = real_rd;
}

DrawFish::MyPoint MyViewPort::getRealCoordinateRightDownConner()
{
	return real_right_down;
}
DrawFish::MyPoint MyViewPort::getRealCoordinateLeftUpConner()
{
	return real_left_up;
}