#include "MyGraphicsItemGroup.hpp"

MyGraphicsItemGroup::MyGraphicsItemGroup(QGraphicsItemGroup *parent): group(new QGraphicsItemGroup())
{}

MyGraphicsItemGroup::~MyGraphicsItemGroup()
{
    delete group;
}

void MyGraphicsItemGroup::clear()
{
    delete group;
    group = new QGraphicsItemGroup();
    //for (int i = 0; i < data_pointers.size(); i++)
    //{
    //    delete data_pointers[i];
    //}
    //data_pointers.clear();
}
/*
void MyGraphicsItemGroup::addItem(QGraphicsItem *new_item)
{
    data_pointers.append(new_item);
    this->addToGroup(new_item);
}*/

QGraphicsLineItem *MyGraphicsItemGroup::getPoint(qreal x, qreal y)
{
    return getLine(x, y, x, y);
}

QGraphicsItemGroup *MyGraphicsItemGroup::getGroup()
{
    return group;
}

QGraphicsLineItem *MyGraphicsItemGroup::getPoint(qreal x, qreal y, qreal color)
{
    int red, blue, green;
    QColor cur_color = currentPen.color();
    color = 1 - color;
    red = (0xff - cur_color.red())*color;
    blue = (0xff - cur_color.blue())*color;
    green = (0xff - cur_color.green())*color;
    cur_color.setRed(0xff - red);
    cur_color.setBlue(0xff - blue);
    cur_color.setGreen(0xff - green);
    QGraphicsLineItem *new_item = new QGraphicsLineItem(x, y , x, y);
    group->addToGroup(new_item);
    //addItem(new_item);
    new_item->setPen(QPen(cur_color));
    return new_item;
}

QGraphicsLineItem *MyGraphicsItemGroup::getLine(qreal start_x, qreal start_y, qreal end_x, qreal end_y)
{
    QGraphicsLineItem *new_line = new QGraphicsLineItem(start_x, start_y , end_x, end_y);
    group->addToGroup(new_line);
    //addItem(new_line);
    new_line->setPen(currentPen);
    return new_line;
}


QGraphicsLineItem *MyGraphicsItemGroup::getPoint(MyPoint point)
{
    return getLine(point, point);
}

QGraphicsLineItem *MyGraphicsItemGroup::getPoint(MyPoint point, qreal color)
{
    int red, blue, green;
    QColor cur_color = currentPen.color();
    red = (0xff - cur_color.red())*color;
    blue = (0xff - cur_color.blue())*color;
    green = (0xff - cur_color.green())*color;
    cur_color.setRed(0xff - red);
    cur_color.setBlue(0xff - blue);
    cur_color.setGreen(0xff - green);
    QGraphicsLineItem *new_item = new QGraphicsLineItem(point.getX(), point.getY() , point.getX(), point.getY());
    group->addToGroup(new_item);
    //addItem(new_item);
    new_item->setPen(QPen(cur_color));
    return new_item;
}

QGraphicsLineItem *MyGraphicsItemGroup::getLine(MyPoint start, MyPoint end)
{
    return getLine(start.getX(), start.getY(), end.getX(), end.getY());
}


void MyGraphicsItemGroup::setCurrentColor(QColor newColor)
{
    currentColor = newColor;
}

void MyGraphicsItemGroup::makePen()
{
    currentPen = QPen(currentColor);
}

void MyGraphicsItemGroup::update(QColor newColors)
{
    setCurrentColor(newColors);
    makePen();
}


QGraphicsItem *MyGraphicsItemGroup::getCircle(qreal center_x, qreal center_y, qreal radius)
{
    QGraphicsEllipseItem *new_line = new QGraphicsEllipseItem(center_x - radius, center_y - radius, radius * 2, radius * 2);
    group->addToGroup(new_line);
    //addItem(new_line);
    new_line->setPen(currentPen);
    return new_line;
}

QGraphicsItem *MyGraphicsItemGroup::getCircle(MyPoint center, qreal radius)
{
    QGraphicsEllipseItem *new_line = new QGraphicsEllipseItem(center.getX() - radius, center.getY() - radius, radius * 2, radius * 2);
    group->addToGroup(new_line);
    //addItem(new_line);
    new_line->setPen(currentPen);
    return new_line;
}
QGraphicsItem *MyGraphicsItemGroup::getEllipse(qreal center_x, qreal center_y, qreal a, qreal b)
{
    QGraphicsEllipseItem *new_line = new QGraphicsEllipseItem(center_x - a, center_y - b, a*2, b*2);
    //addItem(new_line);
    group->addToGroup(new_line);
    new_line->setPen(currentPen);
    return new_line;
}

QGraphicsItem *MyGraphicsItemGroup::getEllipse(MyPoint center, qreal a, qreal b)
{
    QGraphicsEllipseItem *new_line = new QGraphicsEllipseItem(center.getX() - a, center.getY() - b, a*2, b*b);
    //addItem(new_line);
    group->addToGroup(new_line);
    new_line->setPen(currentPen);
    return new_line;
}