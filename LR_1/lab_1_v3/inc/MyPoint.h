#ifndef MYPOINT_H
#define MYPOINT_H

#include <QtGlobal>

class MyPoint
{
public:
	MyPoint();
	MyPoint(qreal c_x, qreal c_y);
	~MyPoint();
	qreal x;
	qreal y;
};
bool operator== (const MyPoint &a, const MyPoint &b);

#endif