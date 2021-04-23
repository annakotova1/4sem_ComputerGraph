#ifndef MYFISH_H
#define MYFISH_H


#include "MyViewPort.h"
#include <QtGlobal>
#include <QGraphicsItemGroup>
#include <QGraphicsScene>


namespace DrawFish
{
	class MyLine
	{
	public:
		MyLine(){};
		MyLine(MyPoint c_start, MyPoint c_end);

		void transfer(matrix_t transform_matrix);
		void draw(MyViewPort view, QGraphicsItemGroup *group, QGraphicsScene *scene);

		MyPoint start;
		MyPoint end;
	};

	class MyEllipse
	{
	public:
		MyEllipse(){};
		MyEllipse(MyPoint c_center, qreal c_width, qreal c_height);

		void transfer(matrix_t transform_matrix);
		void draw(MyViewPort view, QGraphicsItemGroup *group, QGraphicsScene *scene);

		void outputPoints();

	private:
		qreal makePoint(qreal x);
		void makePoints();
		void drawPoints(MyViewPort view, QGraphicsItemGroup *group, QGraphicsScene *scene);

		MyPoint center;
		qreal width;
		qreal height;

		int points_count = 200;

		QVector<MyPoint> points;
	};

	class MyHead
	{
	public:
		MyHead(){};
		MyHead(MyPoint c_center, qreal c_size);

		void transfer(matrix_t transform_matrix);
		void draw(MyViewPort view, QGraphicsItemGroup *group, QGraphicsScene *scene);

		MyEllipse main;
		MyEllipse eye;
		MyLine mouth;
	};

	class MySideFin
	{
	public:
		MySideFin(){};
		MySideFin(MyPoint start, MyPoint end, qreal height, qreal angle, bool down);

		void transfer(matrix_t transform_matrix);
		void draw(MyViewPort view, QGraphicsItemGroup *group, QGraphicsScene *scene);

		MyLine left;
		MyLine right;
		MyLine main;
	};

	class MyBackFin
	{
	public:
		MyBackFin(){};
		MyBackFin(MyPoint start, MyPoint end, qreal width, qreal height, qreal fin_angle);

		void transfer(matrix_t transform_matrix);
		void draw(MyViewPort view, QGraphicsItemGroup *group, QGraphicsScene *scene);

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

		void transfer(matrix_t transform_matrix);
		void draw(MyViewPort view, QGraphicsItemGroup *group, QGraphicsScene *scene);

		MyEllipse body;
		MyHead head;

		MySideFin f1;
		MySideFin f2;
		MyBackFin f3;
		
		MyPoint center;
		//qreal height;
		//qreal width;
		//qreal fin_angle;
	};
};

#endif