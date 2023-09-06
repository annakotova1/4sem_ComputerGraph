#ifndef MYCHECKER_HPP
#define MYCHECKER_HPP

#include "../MyException/MyException.hpp"
#include "../MyPoint/MyPoint.hpp"

class MyChecker : QObject
{
    Q_OBJECT
private:
    MyException *messageBox;
public:
    MyChecker();
    ~MyChecker();
    QVector<MyPoint> * checkManyCirclesData(int x, int y, int step, int count, int radius_start, int radius_end);
    QVector<MyPoint> * checkManyEllipsesData(int x, int y, int step, int count, int a_start, int a_end, int b_start, int b_end);
};

#endif