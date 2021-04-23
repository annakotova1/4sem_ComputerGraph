#include "../inc/calculate.h"
MyVector::MyVector(MyPoint start, MyPoint end)
{
	x = end.x - start.x;
	y = end.y - start.y;
}
MyVector::~MyVector()
{}

void MyVector::MakeSingleVector()
{
	qreal delit = sqrt(x*x + y*y); 
	x = x / delit;
	y = y / delit;
}

// Получить длину отрезка по координатам концов
qreal get_cut_len(MyPoint a, MyPoint b)
{
	qreal len = sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
	return len;
}

// Получить угол треугольника по троем сторонам
qreal get_angle_treag_by_points(MyPoint a, MyPoint b, MyPoint c)
{
	qreal ab = get_cut_len(a, b);
	qreal bc = get_cut_len(b, c);
	qreal ac = get_cut_len(a, c);
	std::cout << "ab " << ab << " bc " << bc << " ac " << ac << std::endl; 
	qreal a_angle = (ab*ab + ac*ac - bc*bc)/2/ab/ac;
	std::cout << "a_angle " << a_angle << std::endl; 
	return acos(a_angle);
}

// Получить вектор
void get_vector(MyPoint a, MyPoint b, MyVector *ab)
{
	ab->x = b.x - a.x;
	ab->y = b.y - a.y;
}

// Проверить существование треугольника
bool check_triag_exist(MyPoint a, MyPoint b, MyPoint c)
{
	qreal ab = get_cut_len(a, b);
	qreal ac = get_cut_len(a, c);
	qreal bc = get_cut_len(b, c);
	if (ab + ac > bc && ab + bc > ac && bc + ac > ab)
	{
	//if (a.x * b.y * 1 + a.y * 1 * c.x + 1 * b.x * c.y == 0)
		//std::cout << "Good" << std::endl;
		if (ab == 0 || ac == 0 || bc == 0)
		{
			//std::cout << "Bad" << std::endl;
			return false;
		}
		return true;
	}
	else
		return false;
}

// Решить задачу для треугольника (вершина a главная)
qreal solve_treag(MyPoint a, MyPoint b, MyPoint c)
{
	qreal a_angle = get_angle_treag_by_points(a, b, c);
	qreal b_angle = get_angle_treag_by_points(b, a, c);
	/*if (b_angle > M_PI/2)
	{
		b_angle = M_PI - b_angle;
	}*/
	qreal alpha_angle;
	std::cout << "a_angle" << a_angle << std::endl; 
	if (a_angle < M_PI/2)
		alpha_angle = fabs((a_angle / 2) - (M_PI / 2 - b_angle)); 
	else
		alpha_angle = (b_angle - M_PI / 2) + (a_angle / 2);
	std::cout << "alpha_angle" << alpha_angle << std::endl; 
	return alpha_angle; 
}

// Получить точку - координаты основания высоты
void get_height_base(MyPoint a, MyPoint b, MyPoint c, MyPoint &h)
{
	qreal ac_side = get_cut_len(a, c);
	qreal c_angle = get_angle_treag_by_points(c, b, a);
	qreal ch;
	MyVector cb = MyVector(c, b);
	cb.MakeSingleVector();
	if (c_angle < M_PI/2)
	{
		ch = ac_side*cos(c_angle);
		h.x = c.x + cb.x * ch;
		h.y = c.y + cb.y * ch;
	}
	else
	{
		ch = ac_side * cos(M_PI - c_angle);
		h.x = c.x - cb.x * ch;
		h.y = c.y - cb.y * ch;
	}
}

// Получить точку - координаты основания биссектрисы
void get_bisector_base(MyPoint a, MyPoint b, MyPoint c, MyPoint &h)
{
	qreal ab_side = get_cut_len(a, b);
	qreal bc_side = get_cut_len(b, c);
	qreal ac_side = get_cut_len(a, c);
	qreal bh = ab_side * bc_side / (ac_side + ab_side);
	MyVector bc = MyVector(b, c);
	bc.MakeSingleVector();
	h.x = b.x + bc.x * bh;
	h.y = b.y + bc.y * bh;
}


qreal solve_problem_for_treag(MyPoint &a, MyPoint &b,  MyPoint &c)
{
	/*
	if (check_triag_exist(a, b, c))
	{
		return false;
	}*/
	std::cout << "solve problem" << std::endl;
	MyPoint _a = a;
	MyPoint _b = b;
	MyPoint _c = c;
	MyPoint _d;
	

	std::cout << "a " << _a.x << " " << _a.y << std::endl;
	std::cout << "b " << _b.x << " " << _b.y << std::endl;
	std::cout << "c " << _c.x << " " << _c.y << std::endl;

	qreal max_angle = 0, angle = 0;

	for (int i = 0; i < 3; i++)
	{
		_d = _a;
		_a = _b;
		_b = _c;
		_c = _d;

		angle = solve_treag(_a, _b, _c);
		std::cout << "angle" << angle << std::endl;
		if (angle > max_angle)
		{
			a = _a;
			b = _b;
			c = _c;
			max_angle = angle;
		}
	}
	return max_angle;
}