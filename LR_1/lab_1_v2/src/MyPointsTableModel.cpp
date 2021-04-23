#include "../inc/MyPointsTableModel.h"



// PRIVATE
// Получить длину отрезка по координатам концов
real_t MyPointsTableModel::get_cut_len(point_t a, point_t b)
{
	real_t len = sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
	return len;
}

// Получить угол треугольника по троем сторонам
real_t MyPointsTableModel::get_angle_treag_by_points(point_t a, point_t b, point_t c)
{
	real_t ab = get_cut_len(a, b);
	real_t bc = get_cut_len(b, c);
	real_t ac = get_cut_len(a, c);
	real_t a_angle = (ab*ab + ac*ac - bc*bc)/2/ab/ac;
	return acos(a_angle);
}

// Получить вектор
void MyPointsTableModel::get_vector(point_t a, point_t b, vector_t *ab)
{
	ab->x = b.x - a.x;
	ab->y = b.y - a.y;
}

// Проверить существование треугольника
bool MyPointsTableModel::check_triag_exist(point_t a, point_t b, point_t c)
{
	if (a.x * b.y * 1 + a.y * 1 * c.x + 1 * b.x * c.y == 0)
		return true;
	else
		return false;
}

// Получить точку - координаты основания высоты
void MyPointsTableModel::get_height_base(point_t a, point_t b, point_t c, point_t *h)
{
	real_t ab_side = get_cut_len(a, b);
	angle_t a_angle = get_angle_treag_by_points(a, b, c);
	real_t ah = ab_side*cos(a_angle);
	vector_t ab, e;
	get_vector(a, b, &ab);
	e.x = ab.x / ab_side;
	e.y = ab.y / ab_side;
	h->x = b.x + e.x * ah;
	h->y = b.y + e.y * ah;
}

// Получить точку - координаты основания биссектрисы
void MyPointsTableModel::get_bisector_base(point_t a, point_t b, point_t c, point_t *h)
{
	real_t ab_side = get_cut_len(a, b);
	real_t bc_side = get_cut_len(b, c);
	real_t ac_side = get_cut_len(a, c);
	//angle_t a_angle = get_angle_treag_by_points(a, b, c);
	real_t ch = bc_side * ac_side / (ab_side + ac_side);
	vector_t bc, e;
	get_vector(c, b, &bc);
	e.x = bc.x / bc_side;
	e.y = bc.y / bc_side;
	std::cout << "ch: " << ch << std::endl;
	std::cout << "bc: " << bc.x << ' ' << bc.y << ' ' << bc_side << std::endl;
	std::cout << "e: " << e.x << ' ' << e.y << std::endl;
	std::cout << "e_side: " << sqrt(e.x * e.x + e.y * e.y) << std::endl;
	h->x = c.x + e.x * ch;
	h->y = c.y + e.y * ch;
}

// Решить задачу для треугольника (вершина b главная)
real_t MyPointsTableModel::solve_treag(point_t a, point_t b, point_t c)
{
	real_t a_angle = get_angle_treag_by_points(a, b, c);
	real_t b_angle = get_angle_treag_by_points(b, a, c);
	if (a_angle > 90)
	{
		a_angle = 180 - a_angle;
	}
	real_t alpha_angle = fabs(fabs(90 - a_angle) - (b_angle/2)); 
	return alpha_angle; 
}