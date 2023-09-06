#ifndef MYGRID_H
#define MYGRID_H 

#include <QSize>
#include <QColor>
#include <QPen>
#include <QGraphicsLineItem>

#include "../MyGraphicsItemGroup/MyGraphicsItemGroup.hpp"

class MyGrid : public MyGraphicsItemGroup
{
private:
    QColor currentColor;
    QPen currentPen;
    //MyGraphicsItemGroup *group;
    QVector<QGraphicsItem *> data_pointers;

    void updatePen();
public:
    MyGrid();
    ~MyGrid();
    void setColor(QColor new_color);
    void drawGrid(QSize scene_size);
    void cleanGrid();
    void addItem(QGraphicsItem *new_item);
    void clean();
};

#endif