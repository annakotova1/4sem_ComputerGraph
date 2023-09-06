#include "common.hpp"

// Координаты вектора
struct vector_coordinates
{
    int x;
    int y;
};
// Размер вектора
double get_vector_size(vector v)
{
    double delta_x = (v.end.x - v.start.x);
    double delta_y = (v.end.y - v.start.y);
    double ans = delta_x*delta_x + delta_y*delta_y;
    return sqrt(ans);
}
// Координаты веткора вектора
vector_coordinates get_vector_coordinates(vector v)
{
    double delta_x = (v.end.x - v.start.x);
    double delta_y = (v.end.y - v.start.y);
    vector_coordinates ans;
    ans.x = delta_x;
    ans.y = delta_y;
    return ans;
}
vector_coordinates get_vector_coordinates(MyPoint p1, MyPoint p2)
{
    double delta_x = (p2.getX() - p1.getX());
    double delta_y = (p2.getY() - p2.getY());
    vector_coordinates ans;
    ans.x = delta_x;
    ans.y = delta_y;
    return ans;
}
// Скалярное произведение
int make_skalar_composition(vector v1, vector v2)
{
    vector_coordinates vc1 = get_vector_coordinates(v1);
    vector_coordinates vc2 = get_vector_coordinates(v2);
    double ans = vc1.x * vc2.x + vc1.y*vc2.y;
    return ans;
}
int get_skalar_composition(vector_coordinates vc1, vector_coordinates vc2)
{
    double ans = vc1.x * vc2.x + vc1.y*vc2.y;
    return ans;
}

param_line get_param_line(MyPoint p1, MyPoint p2)
{
    param_line pl;
    pl.a.x = p1.getX();
    pl.a.y = p1.getY();

    pl.b.x = p2.getX() - p1.getX();
    pl.b.y = p2.getY() - p1.getY();
    return pl;
}
param_cut get_param_cut(MyPoint p1, MyPoint p2)
{
    param_cut pl;
    pl.line.a.x = p1.getX();
    pl.line.a.y = p1.getY();

    pl.line.b.x = p2.getX() - p1.getX();
    pl.line.b.y = p2.getY() - p1.getY();

    pl.t_a = 0;
    pl.t_b = 1;
    return pl;
}
// Возвращает параметр точки пересечения для первой прямой
double get_param_lines_intersection(param_line l1, param_line l2)
{
    double t_i;
    t_i = (l2.a.y*l2.b.x - l2.a.x*l2.b.y - l1.a.y * l2.b.x + l1.a.x * l2.b.y) / (l1.b.y * l2.b.x -l1.b.x * l2.b.y);
    return t_i;
}

vector_coordinates get_inside_normal(MyPoint p1, MyPoint p2, MyPoint p3)
{
    vector_coordinates vc1, vc2, ans;
    vc1 = get_vector_coordinates(p1, p2);
    ans.x = 1;
    ans.y = vc1.x/vc1.y;
    vc2 = get_vector_coordinates(p1, p3);
    int dir = get_skalar_composition(ans, vc2);
    if (dir < 0)
    {
        ans.x *= -1;
        ans.y *= -1;
    }
    return ans;
}

MyPoint get_point_by_param_line(param_line line, double t)
{
    MyPoint p;
    p.setX(line.a.x + line.b.x*t);
    p.setY(line.a.y + line.b.y*t);
    return p;
}

bool makeALg(QVector<MyPoint> poligon, MyPoint p1, MyPoint p2)
{
    vector_coordinates D = get_vector_coordinates(p1, p2);
    param_cut cut = get_param_cut(p1, p2);
    param_line edge_i;

    vector_coordinates n_i, check_right_side;
    double t_i, direction, composition;

    for (int i = 1; i < poligon.size() - 1; i++)
    {
        n_i = get_inside_normal(poligon[i - 1], poligon[i], poligon[i + 1]);
        edge_i = get_param_line(poligon[i - 1], poligon[i]);
        t_i = get_param_lines_intersection(cut.line, edge_i);
        composition = get_skalar_composition(D, n_i);
        if (composition < 0)
        {
            if (t_i > cut.t_a)
            {
                cut.t_a = t_i;
            }
        }
        else if (composition > 0)
        {
            if (t_i < cut.t_b)
            {
                cut.t_b = t_i;
            }
        }
        else
        {
            check_right_side = get_vector_coordinates(p1, p2);
            direction = get_skalar_composition(check_right_side, n_i);
            if (direction < 0)
            {
                return;
            }
        }
        t_i = get_param_lines_intersection(cut.line, edge_i);
    }
    if (cut.t_a < cut.t_b)
        return true;
    return false;
}
