#include "MyAlgorithmShotEdges.hpp"

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
// Координаты вектора
struct vector_coordinates
{
    double x;
    double y;
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
    double delta_y = (p2.getY() - p1.getY());
    vector_coordinates ans;
    ans.x = delta_x;
    ans.y = delta_y;
    return ans;
}
// Скалярное произведение
double get_skalar_composition(vector v1, vector v2)
{
    vector_coordinates vc1 = get_vector_coordinates(v1);
    vector_coordinates vc2 = get_vector_coordinates(v2);
    double ans = vc1.x * vc2.x + vc1.y*vc2.y;
    return ans;
}
double get_skalar_composition(vector_coordinates vc1, vector_coordinates vc2)
{
    double ans = vc1.x * vc2.x + vc1.y * vc2.y;
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
    pl.line = get_param_line(p1, p2);
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
    if (vc1.y == 0)
    {
        ans.x = 0;
        ans.y = 1;
    }
    else
    {
        ans.x = 1;
        ans.y = -vc1.x*ans.x/vc1.y;
    }
    vc2 = get_vector_coordinates(p1, p3);
    double dir = get_skalar_composition(ans, vc2);
    printf("ans(%lf, %lf), vc2(%lf, %lf), dir(%lf)\n", ans.x, ans.y, vc2.x, vc2.y, dir);
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

bool makeAlg(QVector<MyPoint> poligon, MyPoint &p1, MyPoint &p2)
{
    vector_coordinates D = get_vector_coordinates(p1, p2);
    param_cut cut = get_param_cut(p1, p2);
    param_line edge_i;

    vector_coordinates n_i, check_right_side;
    double t_i, direction, composition;
    printf("\n\n\nstart\n");
    printf("D = %lf, %lf; \n", D.x, D.y);
    printf("cut.t_a = %lf, cut.t_b = %lf\n", cut.t_a, cut.t_b);

    MyPoint pe1, pe2, pe3;

    for (int i = 0; i < poligon.size(); i++)
    {
        printf("\n\ni=%d\n", i);
        if (i == 0)
        {
            pe1 = poligon[poligon.size()-1];
            pe2 = poligon[i];
            pe3 = poligon[i + 1];
        }
        else if (i == poligon.size()-1)
        {
            pe1 = poligon[i - 1];
            pe2 = poligon[i];
            pe3 = poligon[0];
        }
        else 
        {
            pe1 = poligon[i - 1];
            pe2 = poligon[i];
            pe3 = poligon[i + 1];
        }
        n_i = get_inside_normal(pe1, pe2, pe3);
        edge_i = get_param_line(pe1, pe2);
        t_i = get_param_lines_intersection(cut.line, edge_i);
        composition = get_skalar_composition(D, n_i);
        printf("composition = %lf\n", composition);
        printf("D = %lf, %lf; n_i = %lf, %lf, t_i = %lf\n", D.x, D.y, n_i.x, n_i.y, t_i);
        printf("Cut line: a(%lf, %lf) b(%lf, %lf) t_a(%lf) t_b(%lf)\n", cut.line.a.x , cut.line.a.y, cut.line.b.x, cut.line.b.y, cut.t_a, cut.t_b);
        printf("edge_i: a(%lf, %lf) b(%lf, %lf)\n", edge_i.a.x, edge_i.a.y, edge_i.b.x, edge_i.b.y);
        if (composition > 0)
        {
            if (t_i > cut.t_a)
            {
                cut.t_a = t_i;
            }
        }
        else if (composition < 0)
        {
            if (t_i < cut.t_b)
            {
                cut.t_b = t_i;
            }
        }
        else
        {
            check_right_side = get_vector_coordinates(pe1, p1);
            direction = get_skalar_composition(check_right_side, n_i);
            if (direction < 0)
            {
                return false;
            }
        }
        printf("cut.t_a = %lf, cut.t_b = %lf\n", cut.t_a, cut.t_b);
    }
    printf("cut.t_a = %lf, cut.t_b = %lf\n", cut.t_a, cut.t_b);
    if (cut.t_a < cut.t_b)
    {
        printf("p1 = %lf, %lf, p2 = %lf, %lf \n", p1.getX(), p1.getY(), p2.getX(), p2.getY());
        p1.setX(cut.t_a*cut.line.b.x+cut.line.a.x);
        p1.setY(cut.t_a*cut.line.b.y+cut.line.a.y);
        p2.setX(cut.t_b*cut.line.b.x+cut.line.a.x);
        p2.setY(cut.t_b*cut.line.b.y+cut.line.a.y);
        printf("p1 = %lf, %lf, p2 = %lf, %lf \n", p1.getX(), p1.getY(), p2.getX(), p2.getY());
        return true;
    }
    return false;
}

void MyAlgorithmShortedEdges::draw(MyImage *drawer, MyShape shape, MyLine line)
{
    MyPoint p1 = line.getPoints()[0], p2 = line.getPoints()[1];
    bool condition = makeAlg(shape.getPoints(), p1, p2);
    if (condition)
    {
        drawer->setLine(line.getPoints()[0], p1);
        drawer->setLine(line.getPoints()[1], p2);
        drawer->setCatLine(p1, p2);
    }
    else
    {
        drawer->setLine(line.getPoints()[0], line.getPoints()[1]);
    }
}

MyAlgorithmShortedEdges::MyAlgorithmShortedEdges()
{}

MyAlgorithmShortedEdges::~MyAlgorithmShortedEdges()
{}


struct point_t
{
    double x;
    double y;
};

struct edge_t
{
    double x;
    double y;
};

edge_t get_edge_by_points(MyPoint start, MyPoint end)
{
    edge_t ab;
    ab.x = end.getX() - start.getX();
    ab.y = end.getY() - start.getY();
    return ab;
}

bool get_direction_of_edges(edge_t ab, edge_t bc)
{
    double direction = ab.x * bc.y - ab.y * bc.x;
    if (direction/fabs(direction) > 0)
        return true;
    else
        return false;
}
// Точек ровно столко сколько вершин
bool MyAlgorithmShortedEdges::check_poligon(QVector<MyPoint> &poligon)
{
    if (poligon.size() < 3)
        return false;
    edge_t e1, e2;
    bool direction, control_direction;
    // Проверяем первую точку
    e1 = get_edge_by_points(poligon[poligon.size() - 1], poligon[0]);
    e2 = get_edge_by_points(poligon[0], poligon[1]);
    control_direction = get_direction_of_edges(e1, e2);

    for (int i = 1; i < poligon.size() - 1;i++)
    {
        e1 = get_edge_by_points(poligon[i - 1], poligon[i]);
        e2 = get_edge_by_points(poligon[i], poligon[i + 1]);
        direction = get_direction_of_edges(e1, e2);
        if (direction != control_direction)
            return false;
    }
    // Проверяем последнюю точку
    e1 = get_edge_by_points(poligon[poligon.size() - 2], poligon[poligon.size() - 1]);
    e2 = get_edge_by_points(poligon[poligon.size() - 1], poligon[0]);
    direction = get_direction_of_edges(e1, e2);
    if (direction != control_direction)
        return false;
    if (control_direction < 0)
    {
        QVector<MyPoint> poligon2;
        for (int i = poligon.size() - 1; i >= 0; i--)
        {
            poligon2.append(poligon[i]);
        }
        poligon = poligon2;
    }
    return true;
}

