#include "../inc/MyCoordinateGrid.h"

MyCoordinateGrid::MyCoordinateGrid()
{
}

MyCoordinateGrid::~MyCoordinateGrid()
{
}

void MyCoordinateGrid::draw(MyViewPort viewPort, QGraphicsItemGroup *group, QGraphicsScene *scene)
{
	DrawFish::MyPoint rrd = viewPort.getRealCoordinateRightDownConner();
	DrawFish::MyPoint rlu = viewPort.getRealCoordinateLeftUpConner();
	makeGridStep(viewPort);

	QPen penGray;
	penGray.setWidth(2);
	QPen penLightgray;
	penLightgray.setWidth(2);
	penLightgray.setStyle(Qt::DotLine);

	QRgb gray = 0xff555555;
	QRgb lightgray = 0xffc8c8c8;

	QColor gray_color;
	QColor lightgray_color;

	gray_color.setRgb(gray);
	lightgray_color.setRgb(lightgray);

	penGray.setColor(gray_color);
	penLightgray.setColor(lightgray_color);


	DrawFish::MyPoint r1, r2, r3, s1, s2, s3;

	qreal i, j;
	for (i = 0; i < fabs(rlu.x); i+=currentGridStep);
	for (j = 0; j < fabs(rlu.y); j+=currentGridStep);

	if (rlu.x < 0)
		i = -i;
	if (rlu.y < 0)
		j = -j;

	std::cout << i << " " << j << std::endl;

	QGraphicsTextItem *text;
	QGraphicsItem *item;


	for (; i < rrd.x; i+=currentGridStep)
	{
		r1 = DrawFish::MyPoint(i, rrd.y);
		r2 = DrawFish::MyPoint(i, rlu.y);
		r3 = DrawFish::MyPoint(i, (rrd.y-rlu.y)/2);
		s1 = viewPort.getScreenCoordinatesByReal(r1);
		s2 = viewPort.getScreenCoordinatesByReal(r2);
		s3 = viewPort.getScreenCoordinatesByReal(r3);

		text = scene->addText(QString::number(i));
		text->setPos(s3.x - 20 - 10, s3.y);
		group->addToGroup(text);

		if (i == 0)
			item = scene->addLine(s1.x, s1.y, s2.x, s2.y, penGray);
		else
			item = scene->addLine(s1.x, s1.y, s2.x, s2.y, penLightgray);
		item->setZValue(1);
		group->addToGroup(item);
	}

	for (; j < rrd.y; j+=currentGridStep)
	{
		r1 = DrawFish::MyPoint(rlu.x, j);
		r2 = DrawFish::MyPoint(rrd.x, j);
		r3 = DrawFish::MyPoint(rlu.x, j);
		s1 = viewPort.getScreenCoordinatesByReal(r1);
		s2 = viewPort.getScreenCoordinatesByReal(r2);
		s3 = viewPort.getScreenCoordinatesByReal(r3);

		text = scene->addText(QString::number(j));
		text->setPos(s3.x + 10, s3.y - 5);
		group->addToGroup(text);

		if (j == 0)
			item = scene->addLine(s1.x, s1.y, s2.x, s2.y, penGray);
		else
			item = scene->addLine(s1.x, s1.y, s2.x, s2.y, penLightgray);
		item->setZValue(1);
		group->addToGroup(item);
	}

	group->setZValue(1);
}


void MyCoordinateGrid::makeGridStep(MyViewPort viewPort)
{
	DrawFish::MyPoint rrd = viewPort.getRealCoordinateRightDownConner();
	DrawFish::MyPoint rlu = viewPort.getRealCoordinateLeftUpConner();

	qreal gap_x = rrd.x - rlu.x;
	qreal gap_y = rrd.y - rlu.y;
	currentGridStep = std::max(gap_x/lineCount, gap_y/lineCount);
}