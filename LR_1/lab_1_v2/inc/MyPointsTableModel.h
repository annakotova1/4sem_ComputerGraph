#ifndef MY_POINTS_TABLE_H
#define MY_POINTS_TABLE_H

#include "QAbstractTableModel"
#include "cmath"
#include <iostream>


typedef double real_t;
typedef struct point_t point_t;
typedef struct point_t vector_t;
typedef double angle_t;
struct point_t
{
	int x;
	int y;
};

class MyPointsTableModel : QAbstractTableModel
{
public:
	explicit MyPointsTableModel(QWidget *parent = 0);
    ~MyPointsTableModel();
	void add_point(point_t a);
	void delete_point(point_t a);
	point_t *solve();
	void read_file(char *filename);
	

private:
	point_t *points;

	// Вычисления

	// Получить длину отрезка по координатам концов
	real_t get_cut_len(point_t a, point_t b);
	// Получить угол треугольника по троем сторонам
	real_t get_angle_treag_by_points(point_t a, point_t b, point_t c);
	// Получить вектор
	void get_vector(point_t a, point_t b, vector_t *ab);
	// Проверить существование треугольника
	bool check_triag_exist(point_t a, point_t b, point_t c);
	// Решить задачу для треугольника (вершина b главная)
	real_t solve_treag(point_t a, point_t b, point_t c);
	// Получить точку - координаты основания высоты
	void get_height_base(point_t a, point_t b, point_t c, point_t *h);
	// Получить точку - координаты основания биссектрисы
	void get_bisector_base(point_t a, point_t b, point_t c, point_t *h);
};


#endif