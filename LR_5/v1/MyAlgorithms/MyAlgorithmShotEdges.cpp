#include "MyAlgorithmShotEdges.hpp"

MyAlgorithmShortedEdges::MyAlgorithmShortedEdges()
{}

MyAlgorithmShortedEdges::~MyAlgorithmShortedEdges()
{}

void drawCDA(int start_x, int start_y, int end_x, int end_y, QVector<MyEdge> *edges, int y_min)
{
    //printf("x_start = %f, y_start = %f; x_end = %f, y_end = %f;\t", start_x, start_y, end_x, end_y);
    
    /*if (start_y == end_y)
    {
        return;
    }*/

    int buf;
    if(start_y > end_y)
    {
        buf = start_y;
        start_y = end_y;
        end_y = buf;

        buf = start_x;
        start_x = end_x;
        end_x = buf;
    }
    int len;
    double dx = end_x - start_x;
    double dy = end_y - start_y;

    if (dy == 0) {
        //(*edges)[start_y-y_min].addX(start_x);
        return;
    }
    len = abs(dy);

    dx = dx / len;
    dy = dy / len;
    double x = start_x, y = start_y;
    //printf("len = %d\n", len);

    for (int i = 0; i < len; i++)
    {
        //printf("%d | %f, %f\n", i, x, y);
        (*edges)[y - y_min].addX(x);
        x += dx;
        y += dy;
    }
}

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
QVector<MyEdge> MyAlgorithmShortedEdges::makeEdges(int y_min, int y_max)
{
    QVector<MyEdge> edges = QVector<MyEdge>();
    for (int i = y_min; i < y_max+1;i++)
    {
        edges.append(MyEdge(i));
    }
    return edges;
}

void MyAlgorithmShortedEdges::sort(QVector<MyEdge> *edges)
{
    for (int i = 0; i < edges->size(); i++)
    {
        (*edges)[i].sort();
    }
}

void MyAlgorithmShortedEdges::drawCDAforShape(QVector<MyEdge> *edges, QVector<MyPoint>points, int y_min)
{
    double ly, lx, ry, rx, my, mx;
    for (int i = 0; i < points.size() - 1; i++)
    {
        ry = points[i + 1].getY();
        rx = points[i + 1].getX();
        if(i == 0)
        {
            ly = points[points.size() - 2].getY();
            lx = points[points.size() - 2].getX();
        }
        else
        {
            ly = points[i - 1].getY();
            lx = points[i - 1].getX();

        }
        my = points[i].getY();
        mx = points[i].getX();
        
        drawCDA(mx, my, rx, ry, edges, y_min);

        /*if (((my < ly) && (my < ry)) || ((my > ly) && (my > ry)))
        {
            (*edges)[my-y_min].addX(mx);
        
        }*/

        /*if (ly > my && my == ry)
        {
            (*edges)[my-y_min].addX(mx);
        }*/
        
    }
}

void MyAlgorithmShortedEdges::drawEdges(QVector<MyEdge>edges, MyImage *drawer)
{
    //printf("start draw\n");
    //printf("size = %d\n",edges.size());
    for (int i = 0; i < edges.size(); i++)
    {
        edges[i].draw(drawer);
    }
    //printf("end draw\n");
}

void MyAlgorithmShortedEdges::draw(QVector<MyShape> shapes, MyImage *drawer)
{
    QVector<MyEdge> edges = prepareData(shapes);
    drawEdges(edges, drawer);
}

void MyAlgorithmShortedEdges::drawEdgesWithDelay(QVector<MyEdge>edges, MyImage *drawer)
{
    //printf("start draw\n");
    //printf("size = %d\n",edges.size());
    int k;

    for (int i = 0; i < edges.size(); i++)
    {
        printf("i = %d\n", i);
        edges[i].draw(drawer);
        QCoreApplication::processEvents();
        drawer->updateDisplay();
        usleep(10);
    }
    //printf("end draw\n");
}

void MyAlgorithmShortedEdges::drawWithDelay(QVector<MyShape> shapes, MyImage *drawer)
{
    QVector<MyEdge> edges = prepareData(shapes);
    drawEdgesWithDelay(edges, drawer);
}

QVector<MyEdge> MyAlgorithmShortedEdges::prepareData(QVector<MyShape> shapes)
{
    QVector<MyPoint> points = QVector<MyPoint>();
    for (int i = 0; i < shapes.size(); i++)
    {
        points.append(shapes[i].getPoints());
    }
    int y_min, y_max;
    findMinMaxY(points, y_min, y_max);
    QVector<MyEdge> edges = makeEdges(y_min, y_max);
    points.clear();
    for (int i = 0; i < shapes.size(); i++)
    {
        points = shapes[i].getPoints();
        drawCDAforShape(&edges, points, y_min);
    }
    sort(&edges);
    //printf("edges = %d\n", edges.size());
    return edges;
}