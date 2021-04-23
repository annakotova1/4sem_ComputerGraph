#ifndef MYFISH_H
#define MYFISH_H

#include <iostream>

#include <QtGlobal>

namespace DrawFish
{
	class MyPoint
	{
	public:
		MyPoint(){};
		MyPoint(qreal c_x, qreal c_y);

		qreal x;
		qreal y;
	};

	class MyLine
	{
	public:
		MyLine(){};
		MyLine(MyPoint c_start, MyPoint c_end);

		MyPoint start;
		MyPoint end;
	};

	class MyEllipse
	{
	public:
		MyEllipse(){};
		MyEllipse(MyPoint c_center, qreal c_width, qreal c_height);

		MyPoint center;
		qreal width;
		qreal height;
	};

	class MyHead
	{
	public:
		MyHead(){};
		MyHead(MyPoint c_center, qreal c_size);

		MyEllipse main;
		MyEllipse eye;
		MyLine mouth;
	};

	class MySideFin
	{
	public:
		MySideFin(){};

		MyLine left;
		MyLine right;
		MyLine main;
	};

	class MyBackFin
	{
	public:
		MyBackFin(){};

		MyLine side1;
		MyLine side2;
		MyLine side3;
		MyLine side4;
		MyLine side5;
	};

	class MyFish
	{
	public:
		MyFish(){};
		MyFish(MyPoint c_center, qreal c_width, qreal c_height);

		MyPoint center;
		MyEllipse body;
		MyHead head;

		MySideFin f1;
		MySideFin f2;
		MyBackFin f3;
		
		qreal height;
		qreal width;
		qreal fin_angle;
	};
};

#endif