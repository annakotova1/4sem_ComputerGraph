#include "../inc/MyFish.h"

using namespace DrawFish;

MyPoint::MyPoint(qreal c_x, qreal c_y) : x(c_x), y(c_y)
{}

MyLine::MyLine(MyPoint c_start, MyPoint c_end) : start(c_start), end(c_end)
{}
/*
MyLine::MyLine(MyPoint center, qreal angle, qreal len) :
{
	start.x = center.x - len/2 * cos(angle);
	start.y = center.y - len/2 * sin(angle);
	end.x   = center.x + len/2 * cos(angle);
	end.y   = center.y + len/2 * sin(angle);
}
*/
MyEllipse::MyEllipse(MyPoint c_center, qreal c_width, qreal c_height) : 
	center(c_center), width(c_width), height(c_height)
{
}

MyHead::MyHead(MyPoint c_center, qreal c_size)
{
	main = MyEllipse(c_center, c_size/2, c_size/2);

	std::cout << main.center.x << " " << main.center.y << " " << c_size/2 << std::endl;

	MyPoint eye_center = MyPoint(c_center.x, c_center.y + c_size / 2);
	MyPoint mouth_start = MyPoint(c_center.x - c_size / 4, c_center.y - c_size / 2);
	MyPoint mouth_end = MyPoint(c_center.x + c_size / 4, c_center.y - c_size / 2);

	eye = MyEllipse(eye_center, c_size / 8, c_size / 8);
	mouth = MyLine(mouth_start, mouth_end);
}

MyFish::MyFish(MyPoint c_center, qreal c_width, qreal c_height): center(c_center), 
	height(c_height), width(c_width)
{
	body = MyEllipse(center, width, height);
	MyPoint head_center = MyPoint(center.x  - (width/10*4), center.y);
	head = MyHead(head_center, width/10*4);
}