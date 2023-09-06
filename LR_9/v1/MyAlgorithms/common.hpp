#ifndef COMMON_HPP
#define COMMON_HPP

#include <cmath>
#include "../MyPoint/MyPoint.hpp"
#include <QVector>

// Точка
struct point
{
    double x;
    double y;
};

// Вектор
struct vector 
{
    point start;
    point end;
};
// Прямая, заданная параметрическим уравнением вида: p = a+b*t 
struct param_line
{
    point a;
    point b;
};
// Отрезок, заданный параметрическим уравнением
struct param_cut
{
    param_line line;
    double t_a;
    double t_b;
};
#endif