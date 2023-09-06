#include "MyAlgorithmShotEdges.hpp"

MyAlgorithmShortedEdges::MyAlgorithmShortedEdges()
{}

MyAlgorithmShortedEdges::~MyAlgorithmShortedEdges()
{}

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
