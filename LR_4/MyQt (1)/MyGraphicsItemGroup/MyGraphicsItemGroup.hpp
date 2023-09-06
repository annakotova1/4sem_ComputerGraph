#ifndef MYGRAPHICSITEMGROUP_H
#define MYGRAPHICSITEMGROUP_H

#include <QPen>
#include <QGraphicsItemGroup>
#include <QGraphicsItem>
#include "../MyPoint/MyPoint.hpp"
#include "../ObserverInterface.hpp"

class MyGraphicsItemGroup : public IObject
{
private:
    //QVector<QGraphicsItem *> data_pointers;
    
    QPen currentPen;
    QColor currentColor;

    QGraphicsItemGroup *group;

    //void addItem(QGraphicsItem *new_item);
public:
    explicit MyGraphicsItemGroup(QGraphicsItemGroup *parent = 0);
    ~MyGraphicsItemGroup();
    //void clean();
    QGraphicsLineItem *getPoint(qreal x, qreal y);
    QGraphicsLineItem *getPoint(qreal x, qreal y, qreal color);
    QGraphicsLineItem *getLine(qreal start_x, qreal start_y, qreal end_x, qreal end_y);

    QGraphicsLineItem *getPoint(MyPoint point);
    QGraphicsLineItem *getPoint(MyPoint point, qreal color);
    QGraphicsLineItem *getLine(MyPoint start, MyPoint end);

    QGraphicsItem *getCircle(qreal center_x, qreal center_y, qreal radius);
    QGraphicsItem *getEllipse(qreal center_x, qreal center_y, qreal a, qreal b);
    QGraphicsItem *getCircle(MyPoint center, qreal radius);
    QGraphicsItem *getEllipse(MyPoint center, qreal a, qreal b);

    void setCurrentColor(QColor newColor);
    void makePen();
    void update(QColor newColors);
    void clear();

    QGraphicsItemGroup *getGroup();
};

#endif