#ifndef MYPOINT_H
#define MYPOINT_H

class MyPoint
{
private:
    int x;
    int y;
public:
    MyPoint();
    MyPoint(int c_x, int c_y);
    ~MyPoint();
    int getX();
    int getY();
    void setX(int c_x);
    void setY(int c_y);
};

#endif