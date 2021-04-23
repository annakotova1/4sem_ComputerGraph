#include "../inc/MyFish.h"

using namespace DrawFish;

MyLine::MyLine(MyPoint c_start, MyPoint c_end) : start(c_start), end(c_end)
{}

void MyLine::draw(MyViewPort view, QGraphicsItemGroup *group, QGraphicsScene *scene)
{
	DrawFish::MyPoint screen_start, screen_end;
	screen_start = view.getScreenCoordinatesByReal(start);
	screen_end = view.getScreenCoordinatesByReal(end);

	QPen penBlack(Qt::black);
	penBlack.setWidth(3);

	group->addToGroup(scene->addLine(screen_start.x, screen_start.y, screen_end.x, screen_end.y, penBlack));
}

void MyLine::transfer(matrix_t transform_matrix)
{
	start.transfer(transform_matrix);
	end.transfer(transform_matrix);
}

MyEllipse::MyEllipse(MyPoint c_center, qreal c_width, qreal c_height): center(c_center), width(c_width), height(c_height)
{
	points = QVector<MyPoint>();
	makePoints();
}

qreal MyEllipse::makePoint(qreal x)
{
	qreal y = sqrt(1-(x - center.x)*(x - center.x)/width/width*4) * height/2 + center.y;
	if (y != y)
	{
		y = 0 + center.y;
	}
	//std::cout << x << " " << y << std::endl;
	return y;
}
void MyEllipse::makePoints()
{
	points.clear();
	MyPoint newPoint;
	qreal x = center.x-width/2;
	qreal shag = width/points_count * 2;
	for (; x < center.x+width/2; x += shag)
	{
		newPoint.x = x;
		newPoint.y = makePoint(x);
		points.append(newPoint);
	}
	for (x = center.x + width / 2; x > center.x - width / 2; x -= shag)
	{
		newPoint.x = x;
		newPoint.y = center.y * 2 - makePoint(x);
		points.append(newPoint);
	}
}
void MyEllipse::outputPoints()
{
	std::cout << std::endl << "start" << std::endl;
	for (int i = 0; i < points.size(); i++)
	{
		std::cout << points[i].x << " " << points[i].y << std::endl;
	}
	std::cout << "end" << std::endl << std::endl;
}
void MyEllipse::drawPoints(MyViewPort view, QGraphicsItemGroup *group, QGraphicsScene *scene)
{
	QPen penBlack(Qt::black);
	penBlack.setWidth(3);

	MyPoint real_point1, real_point2, screen_point1, screen_point2;
	for (int i = 0; i < points.size() - 1; i++)
	{
		real_point1 = points[i];
		real_point2 = points[i+1];
		screen_point1 = view.getScreenCoordinatesByReal(real_point1);
		screen_point2 = view.getScreenCoordinatesByReal(real_point2);

		group->addToGroup(scene->addLine(screen_point1.x, screen_point1.y, screen_point2.x,screen_point2.y, penBlack));
	}
	real_point1 = points[0];
	real_point2 = points[points.size() - 1];
	screen_point1 = view.getScreenCoordinatesByReal(real_point1);
	screen_point2 = view.getScreenCoordinatesByReal(real_point2);
	group->addToGroup(scene->addLine(screen_point1.x, screen_point1.y, screen_point2.x,screen_point2.y, penBlack));
}

void MyEllipse::draw(MyViewPort view, QGraphicsItemGroup *group, QGraphicsScene *scene)
{
	drawPoints(view, group, scene);

}
void MyEllipse::transfer(matrix_t transform_matrix)
{;
	for (int i = 0; i < points.size(); i++)
	{
		points[i].transfer(transform_matrix);
	}
}

MyHead::MyHead(MyPoint c_center, qreal c_size)
{
	main = MyEllipse(c_center, c_size, c_size);

	//std::cout << main.center.x << " " << main.center.y << " " << c_size/2 << std::endl;

	MyPoint eye_center = MyPoint(c_center.x, c_center.y + c_size / 4);
	MyPoint mouth_start = MyPoint(c_center.x - c_size / 8, c_center.y - c_size / 4);
	MyPoint mouth_end = MyPoint(c_center.x + c_size / 8, c_center.y - c_size / 4);
	//std::cout << "mouth_start " << mouth_start.x << " " << mouth_start.y << std::endl;
	//std::cout << "mouth_end " << mouth_end.x << " " << mouth_end.y << std::endl;
	//std::cout << "eye_center " << eye_center.x << " " << eye_center.y << std::endl;
	//std::cout << "head_center " << c_center.x << " " << c_center.y << std::endl;

	eye = MyEllipse(eye_center, c_size / 8, c_size / 8);
	mouth = MyLine(mouth_start, mouth_end);
}

void MyHead::draw(MyViewPort view, QGraphicsItemGroup *group, QGraphicsScene *scene)
{
	main.draw(view, group, scene);
	//main.outputPoints();
	eye.draw(view, group, scene);
	mouth.draw(view, group, scene);
}

void MyHead::transfer(matrix_t transform_matrix)
{
	main.transfer(transform_matrix);
	eye.transfer(transform_matrix);
	mouth.transfer(transform_matrix);
}

MySideFin::MySideFin(MyPoint start, MyPoint end, qreal angle, qreal height, bool down)
{
	MyPoint p2;
	if (down)
		p2 = MyPoint(start.x + tan(angle)*height, start.y - height);
	else
		p2 = MyPoint(start.x + tan(angle)*height, start.y + height);

	MyPoint p3 = MyPoint(end.x + tan(angle)*height, p2.y);

	left = MyLine(start, p2);
	main = MyLine(p2, p3);
	right = MyLine(p3, end);
}
void MySideFin::draw(MyViewPort view, QGraphicsItemGroup *group, QGraphicsScene *scene)
{
	main.draw(view, group, scene);
	left.draw(view, group, scene);
	right.draw(view, group, scene);
}
void MySideFin::transfer(matrix_t transform_matrix)
{
	main.transfer(transform_matrix);
	left.transfer(transform_matrix);
	right.transfer(transform_matrix);
}

MyBackFin::MyBackFin(MyPoint start, MyPoint end, qreal width, qreal height, qreal angle)
{
	MyPoint p2 = MyPoint(start.x + tan((angle - 0.01))*height/2, start.y + height/2);
	MyPoint p3 = MyPoint(p2.x + width, p2.y);
	MyPoint p4 = MyPoint(p3.x - tan(angle  + 0.2)*height/2, p3.y - height);
	MyPoint p5 = MyPoint(p3.x, end.y);

	side1 = MyLine(start, p2);
	side2 = MyLine(p2, p3);
	side3 = MyLine(p3, p4);
	side4 = MyLine(p4, p5);
	side5 = MyLine(p5, end);
}
void MyBackFin::draw(MyViewPort view, QGraphicsItemGroup *group, QGraphicsScene *scene)
{
	side1.draw(view, group, scene);
	side2.draw(view, group, scene);
	side3.draw(view, group, scene);
	side4.draw(view, group, scene);
	side5.draw(view, group, scene);
}
void MyBackFin::transfer(matrix_t transform_matrix)
{
	side1.transfer(transform_matrix);
	side2.transfer(transform_matrix);
	side3.transfer(transform_matrix);
	side4.transfer(transform_matrix);
	side5.transfer(transform_matrix);
}

MyFish::MyFish(MyPoint c_center, qreal c_width, qreal c_height): center(c_center)
	//height(c_height), width(c_width), fin_angle((52) * M_PI / 180)
{
	qreal height = c_height;
	qreal width = c_width;
	qreal fin_angle = (52) * M_PI / 180;
	body = MyEllipse(center, width, height);
	//std::cout << "body_center " << center.x << " " << center.y << std::endl;

	MyPoint head_center = MyPoint(center.x  - (width/10*4), center.y);
	head = MyHead(head_center, width/10*2);

	MyPoint f1_start;
	f1_start.x = -width/4;
	f1_start.y = height/2*sqrt(width*width/4 - (f1_start.x)*(f1_start.x))/6;
	MyPoint f1_end = MyPoint(-f1_start.x, -f1_start.y);
	MyPoint f2_start = MyPoint(f1_start.x, f1_start.y);
	MyPoint f2_end = MyPoint(-f1_start.x, f1_start.y);
	f1_start.y *= -1;

	f1 = MySideFin(f1_start, f1_end, fin_angle, height/4, true);
	f2 = MySideFin(f2_start, f2_end, fin_angle, height/4, false);

	MyPoint f3_start, f4_start;
	f3_start.x = width/15*7;
	f3_start.y = height/2*sqrt(width*width/4 - (f3_start.x)*(f3_start.x))/6;
	f4_start.x = width/10*4;
	f4_start.y = -height/2*sqrt(width*width/4 - (f4_start.x)*(f4_start.x))/6;

	f3 = MyBackFin(f3_start, f4_start, width/3, height/3, fin_angle);
}

void MyFish::draw(MyViewPort view, QGraphicsItemGroup *group, QGraphicsScene *scene)
{
	head.draw(view, group, scene);
	body.draw(view, group, scene);
	f1.draw(view, group, scene);
	f2.draw(view, group, scene);
	f3.draw(view, group, scene);
}
void MyFish::transfer(matrix_t transform_matrix)
{
	f1.transfer(transform_matrix);
	f2.transfer(transform_matrix);
	f3.transfer(transform_matrix);
	center.transfer(transform_matrix);
	head.transfer(transform_matrix);
	body.transfer(transform_matrix);
}