#include "MyAlgorithmShotEdges.hpp"

#define LEFT  1  /* двоичное 0001 */
#define RIGHT 2  /* двоичное 0010 */
#define BOT   4  /* двоичное 0100 */
#define TOP   8  /* двоичное 1000 */

MyPoint getMaxPointFromShape(QVector<MyPoint> shape)
{
    int x_max = shape[0].getX(), y_max = shape[0].getY();
    for (int i = 1; i < shape.size(); i++)
    {
        if (shape[i].getX() > x_max)
        {
            x_max = shape[i].getX();
        }
        if (shape[i].getY() > y_max)
        {
            y_max = shape[i].getY();
        } 
    }
    return MyPoint(x_max, y_max);
}

MyPoint getMinPointFromShape(QVector<MyPoint> shape)
{
    int x_min = shape[0].getX(), y_min = shape[0].getY();
    for (int i = 1; i < shape.size(); i++)
    {
        if (shape[i].getX() < x_min)
        {
            x_min = shape[i].getX();
        }
        if (shape[i].getY() < y_min)
        {
            y_min = shape[i].getY();
        } 
    }
    return MyPoint(x_min, y_min);
}

/* точка */
struct point {
	double x, y;
};

/* прямоугольник */
struct rect {
	double x_min, y_min, x_max, y_max;
};

/* вычисление кода точки
   r : указатель на struct rect; p : указатель на struct point */

int vcode(const rect *r, point *p)
{
    int ans = 0;
    printf("rect %lf, %lf, %lf, %lf\n", r->x_min, r->x_max, r->y_min, r->y_max);
    if (r->x_min > p->x)
        ans += LEFT;
    if (r->x_max < p->x)
        ans += RIGHT;
    if (r->y_min > p->y)
        ans += BOT;
    if (r->y_max < p->y)
        ans += TOP;
    printf("%d, %d, %d, %d\n", LEFT &ans, RIGHT &ans, BOT &ans, TOP &ans);
    return ans;
}


int cohen_sutherland (const struct rect *r, struct point *a, struct point *b)
{
	int code_a, code_b, code; /* код концов отрезка */
	struct point *c; /* одна из точек */

	code_a = vcode(r, a);
	code_b = vcode(r, b);
    printf("x = %lf, y = %lf, x = %lf, y = %lf\n", a->x, a->y, b->x, b->y);
    printf("a_code = %d, b_code = %d\n", code_a, code_b);
	
	/* пока одна из точек отрезка вне прямоугольника */
	while (code_a | code_b) {
		/* если обе точки с одной стороны прямоугольника, то отрезок не пересекает прямоугольник */
		if (code_a & code_b)
			return -1;

		/* выбираем точку c с ненулевым кодом */
		if (code_a) {
			code = code_a;
			c = a;
		} else {
			code = code_b;
			c = b;
		}

		/* если c левее r, то передвигаем c на прямую x = r->x_min
		   если c правее r, то передвигаем c на прямую x = r->x_max */
		if (code & LEFT) {
			c->y += (a->y - b->y) * (r->x_min - c->x) / (a->x - b->x);
			c->x = r->x_min;
		} else if (code & RIGHT) {
			c->y += (a->y - b->y) * (r->x_max - c->x) / (a->x - b->x);
			c->x = r->x_max;
		}/* если c ниже r, то передвигаем c на прямую y = r->y_min
		    если c выше r, то передвигаем c на прямую y = r->y_max */
		else if (code & BOT) {
			c->x += (a->x - b->x) * (r->y_min - c->y) / (a->y - b->y);
			c->y = r->y_min;
		} else if (code & TOP) {
			c->x += (a->x - b->x) * (r->y_max - c->y) / (a->y - b->y);
			c->y = r->y_max;
		}

		/* обновляем код */
		if (code == code_a) {
                        a = c;
			code_a = vcode(r,a);
		} else {
                        b = c;
			code_b = vcode(r,b);
                }
	}

	/* оба кода равны 0, следовательно обе точки в прямоугольнике */
	return 0;
}

void MyAlgorithmShortedEdges::draw(MyImage *drawer, MyShape shape, MyLine line)
{
    /*MyPoint maxp = getMaxPointFromShape(shape.getPoints());
    MyPoint minp = getMinPointFromShape(shape.getPoints());

    MyPoint start = line.getPoints()[0];
    MyPoint end = line.getPoints()[1];

    int b_code1 = getBinaryCode(start, maxp, minp);
    int b_code2 = getBinaryCode(end, maxp, minp);

    if (b_code1 == b_code2 && b_code2 == 0)
    {
        return;
    }
    if (b_code1 && b_code2 != 0)
    {
        drawer->setCatLine(start, end);
        return;
    }*/
    printf("start work\n");
    MyPoint maxp = getMaxPointFromShape(shape.getPoints());
    MyPoint minp = getMinPointFromShape(shape.getPoints());
    printf("min_p = %lf, %lf, max_p = %lf, %lf\n", minp.getX(), minp.getY(), maxp.getX(), maxp.getY());
    struct rect s;
    s.x_min = minp.getX(); 
    s.y_min = minp.getY(); 
    s.x_max = maxp.getX();
    s.y_max = maxp.getY();

    struct point a, b;
    a.x = line.getPoints()[0].getX();
    a.y = line.getPoints()[0].getY();
    b.x = line.getPoints()[1].getX();
    b.y = line.getPoints()[1].getY();

    int rc = cohen_sutherland(&s, &a, &b);
    if (rc == 0)
    {
        printf("draw\n");
        drawer->setCatLine(MyPoint(a.x, a.y), MyPoint(b.x, b.y));
        drawer->setLine(MyPoint(a.x, a.y), line.getPoints()[0]);
        drawer->setLine(MyPoint(b.x, b.y), line.getPoints()[1]);
        printf("%lf, %lf, %lf, %lf", a.x, a.y, b.x, b.y);
    }
    else
    {
        drawer->setLine(line.getPoints()[0], line.getPoints()[1]);
    }
    printf("end work %d\n", rc);
}


MyAlgorithmShortedEdges::MyAlgorithmShortedEdges()
{}

MyAlgorithmShortedEdges::~MyAlgorithmShortedEdges()
{}


/*
void MyAlgorithmShortedEdges::findMinMaxY(QVector<MyPoint> points, int &y_min, int &y_max)
{
    y_min = points[0].getY();
    y_max = y_min;
    int y;
    for (int i = 1; i < points.size(); i++)
    {
        y = points[i].getY();
        if (y < y_min)
        {
            y_min = y;
        }
        if (y > y_max)
        {
            y_max = y;
        }
    }
}
void MyAlgorithmShortedEdges::sort(QVector<MyEdge> *edges)
{
    for (int i = 0; i < edges->size(); i++)
    {
        (*edges)[i].sort();
    }
}

void iteration(MyImage *drawer, MyPoint point)
{
    //printf("stack.size() = %d\n", stack->size());
    //index++;
    //printf("%d\n", index);
    QVector<MyPoint> stack;
    QColor fone = drawer->getFone(), curColor;
    int x, y, x_max, x_min;
    bool flag;

    stack.push_back(point);

    while (stack.size() != 0)
    {
        MyPoint curPoint = stack.last();
        stack.pop_back();
        x = curPoint.getX(); 
        y = curPoint.getY(); 
        x_max = x;
        x_min = x;
        curColor = drawer->getPixel(x, y);

        while (curColor.value() == fone.value())
        {
            drawer->setPoint(MyPoint(x, y));
            x_max = x;
            x++;
            curColor = drawer->getPixel(x, y);
        }

        x = curPoint.getX()-1;
        curColor = drawer->getPixel(x, y);
        while (curColor.value() == fone.value())
        {
            drawer->setPoint(MyPoint(x, y));
            x_min = x;
            x--;
            curColor = drawer->getPixel(x, y);
        }

        int m[2] = {1, -1};

        for (int i = 0; i < 2; i++)
        {
            x = x_max;
            flag = false;
            while (x_min <= x)
            {
                if (drawer->getPixel(x, y + m[i]).value() == fone.value())
                {
                    flag = true;
                    break;
                }
                x--;
            }
            if (flag)
                stack.push_back(MyPoint(x, y + m[i]));
        }

        //drawer->updateDisplay();
        //QCoreApplication::processEvents();
    }
    //printf("not draw\n");
}


void iterationWithDelay(MyImage *drawer, MyPoint point)
{
    //printf("stack.size() = %d\n", stack->size());
    //index++;
    //printf("%d\n", index);
    QVector<MyPoint> stack;
    QColor fone = drawer->getFone(), curColor;
    int x, y, x_max, x_min;
    bool flag;

    stack.push_back(point);

    while (stack.size() != 0)
    {
        MyPoint curPoint = stack.last();
        stack.pop_back();
        x = curPoint.getX(); 
        y = curPoint.getY(); 
        x_max = x;
        x_min = x;
        curColor = drawer->getPixel(x, y);

        while (curColor.value() == fone.value())
        {
            drawer->setPoint(MyPoint(x, y));
            x_max = x;
            x++;
            curColor = drawer->getPixel(x, y);
        }

        x = curPoint.getX()-1;
        curColor = drawer->getPixel(x, y);
        while (curColor.value() == fone.value())
        {
            drawer->setPoint(MyPoint(x, y));
            x_min = x;
            x--;
            curColor = drawer->getPixel(x, y);
        }

        int m[2] = {1, -1};

        for (int i = 0; i < 2; i++)
        {
            x = x_max;
            flag = false;
            while (x_min <= x)
            {
                if (drawer->getPixel(x, y + m[i]).value() == fone.value())
                {
                    flag = true;
                    break;
                }
                x--;
            }
            if (flag)
                stack.push_back(MyPoint(x, y + m[i]));
        }

        drawer->updateDisplay();
        QCoreApplication::processEvents();
    }
    //printf("not draw\n");
}


void MyAlgorithmShortedEdges::draw(MyImage *drawer, MyPoint point)
{
    //printf("stack.size() = %d\n", stack.size());
    iteration(drawer, point);
    printf("finish\n");
}
void MyAlgorithmShortedEdges::drawWithDelay(MyImage *drawer, MyPoint point)
{
    //printf("stack.size() = %d\n", stack.size());
    iterationWithDelay(drawer, point);
    printf("finish\n");
}
*/
/*
MyPoint getMaxPointFromShape(QVector<MyPoint> shape)
{
    int x_max = shape[0].getX(), y_max = shape[0].getX();
    for (int i = 1; i < shape.size(); i++)
    {
        if (shape[i].getX() < x_max)
        {
            x_max = shape[i].getX();
        }
        if (shape[i].getY() < y_max)
        {
            y_max = shape[i].getY();
        } 
    }
    return MyPoint(x_max, y_max);
}

MyPoint getMinPointFromShape(QVector<MyPoint> shape)
{
    int x_min = shape[0].getX(), y_min = shape[0].getX();
    for (int i = 1; i < shape.size(); i++)
    {
        if (shape[i].getX() < x_min)
        {
            x_min = shape[i].getX();
        }
        if (shape[i].getY() < y_min)
        {
            y_min = shape[i].getY();
        } 
    }
    return MyPoint(x_min, y_min);
}

int getBinaryCode(MyPoint point, MyPoint maxConor, MyPoint minConor)
{
    int b_code = 0;
    int x = point.getX(), x_min = minConor.getX(), x_max = maxConor.getX();
    int y = point.getY(), y_min = minConor.getY(), y_max = maxConor.getY();
    if (x < x_min)
    {
        b_code = b_code||8;
    }
    if (x > x_max)
    {
        b_code = b_code||4;
    }
    if (y < y_min)
    {
        b_code = b_code||2;
    }
    if (y > y_max)
    {
        b_code = b_code||1;
    }
    return b_code;
}

void getLineCoefs(MyPoint start, MyPoint end, double &k, double &b, double &s)
{
    int x1 = start.getX(), x2 = end.getX(), 
        y1 = start.getY(), y2 = end.getY();
    if (x1 == x2)
    {
        s = 0;
        b = x1;
        k = 1;
    }
    if (y1 == y2)
    {
        k = 0;
        b = y1;
        s = 1;
    }
    s = 1;
    k = ((double)(y2-y1))/((double)(x2 - x1));
}

double getDistance(MyPoint p1, MyPoint p2)
{
    return sqrt((p2.getY()-p1.getX())*(p2.getY()-p1.getX())+(p2.getY() - p1.getY())*(p2.getY() - p1.getY()));
}
// start двигаю к end
void movePoint(MyPoint start, MyPoint end, int b_code1, int b_code2, MyPoint max, MyPoint min)
{
    int x_delta = start.getX() - start.getX(), y_delta = end.getY() - start.getY();
    if (x_delta > y_delta)
    {
        if (b_code1&&8 == 0)
        {}
        else 
        {}
        
    }
}

double analisXSituation(MyPoint start, MyPoint end, int b_code1, int b_code2, MyPoint max, MyPoint min)
{
    if (b_code1 != 0)
    {move}
    if (b_code2 != 0)
    {move}
}
*/