#ifndef MYGRID_H
#define MYGRID_H 

#include <QSize>
#include <QColor>
#include <QPen>
#include <QGraphicsLineItem>

#include "MyGraphicsItemGroup.hpp"

class MyGrid : public MyGraphicsItemGroup
{
private:
    QColor currentColor;
    QPen currentPen;
    //MyGraphicsItemGroup *group;

    void updatePen();
public:
    MyGrid();
    ~MyGrid();
    void setColor(QColor new_color);
    void drawGrid(QSize scene_size);
};

#endif