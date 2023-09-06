#include "MyEdge.hpp"

MyEdge::MyEdge(int ny): Y(ny)
{}

MyEdge::MyEdge()
{}
MyEdge::~MyEdge()
{}

bool MyEdge::check()
{
    if (X.size() %  2)
        return false;
    return true;
}

void MyEdge::addX(int x)
{
    X.append(x);
}
int MyEdge::y()
{
    return Y;
}
void MyEdge::draw(MyImage *drawer)
{
    for (int i = 0; i < X.size() - 1; i += 2)
    {
        drawer->setLine(MyPoint(X[i], Y), MyPoint(X[i+1], Y));
    }
}
void MyEdge::drawWithDelay(MyImage *drawer)
{
    for (int i = 0; i < X.size() - 1; i += 2)
    {
        for (int j = X[i]; j < X[i+1] + 1; j++)
        {
            drawer->setPoint(MyPoint(j, Y));
        }
        //drawer->setLine(MyPoint(X[i], Y), MyPoint(X[i+1], Y));
    }
}
int partition(QVector<int> *arr, int left, int right)
{
    int opora = (*arr)[left];
    int o_i = left;
    int buf;
    for (int i = left+1; i <= right; i++)
    {
        //printf("i=%d;arr[i]=%d;",i,(*arr)[i]);
        if (opora > (*arr)[i])
        {
            //printf("moved to %d",left);
            o_i++;
            buf = (*arr)[i];
            (*arr).remove(i);
            (*arr).insert(left, buf);
        }
        //printf("\n");
    }
    return o_i;
}
void quick_sort(QVector<int> *arr, int left, int right)
{
    if (left < right)
    {
        int part = partition(arr, left, right);
        quick_sort(arr, left, part - 1);
        quick_sort(arr, part + 1, right);
    }
}

void MyEdge::sort()
{
    quick_sort(&X, 0, X.size()-1);
    output();
}

void MyEdge::output()
{
    /*printf("%4d | ", Y);
    printf("size = %d | ", X.size());
    for (int i = 0; i < X.size(); i++)
    {
        printf("%d ", X[i]);
    }
    printf("\n");*/
}

