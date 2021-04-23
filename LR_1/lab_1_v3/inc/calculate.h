#ifndef CALCULATE_H
#define CALCULATE_H

#include "MyPoint.h"
#include <cmath>

#include <QtGlobal>
#include <iostream>

bool check_triag_exist(MyPoint a, MyPoint b, MyPoint c);
qreal solve_problem_for_treag(MyPoint &a, MyPoint &b,  MyPoint &c);
void get_height_base(MyPoint a, MyPoint b, MyPoint c, MyPoint &h);
void get_bisector_base(MyPoint a, MyPoint b, MyPoint c, MyPoint &h);

class MyVector
{
public:
	qreal x;
	qreal y;
	explicit MyVector(MyPoint start, MyPoint end);
	~MyVector();
	void MakeSingleVector();
};

#endif