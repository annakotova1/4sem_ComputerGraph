#ifndef MYGRAPHICSITEMGROUP_H
#define MYGRAPHICSITEMGROUP_H

#include <QGraphicsItemGroup>
#include <QGraphicsScene>

#include <iostream>

class MyGraphicsItemGroup : public QGraphicsItemGroup
{
public:
    MyGraphicsItemGroup(QGraphicsItem *parent = nullptr);
    ~MyGraphicsItemGroup();
    QGraphicsLineItem *getLine(qreal start_x, qreal start_y, qreal end_x, qreal end_y);
    QGraphicsLineItem *getPoint(qreal x, qreal y);
    QGraphicsLineItem *getPoint(qreal x, qreal y, qreal color);
    void clean();
    void addItem(QGraphicsItem *new_item);
private:
    QVector<QGraphicsItem *> pointers;
};

#endif