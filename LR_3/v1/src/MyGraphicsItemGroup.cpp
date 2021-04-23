#include "../inc/MyGraphicsItemGroup.hpp"

MyGraphicsItemGroup::MyGraphicsItemGroup(QGraphicsItem *parent): QGraphicsItemGroup(parent)
{}

MyGraphicsItemGroup::~MyGraphicsItemGroup()
{
    clean();
}

void MyGraphicsItemGroup::clean()
{
    for (int i = 0; i < pointers.size(); i++)
    {
        this->removeFromGroup(pointers[i]);
        delete pointers[i];
    }
    pointers.clear();
}

void MyGraphicsItemGroup::addItem(QGraphicsItem *new_item)
{
    pointers.append(new_item);
    this->addToGroup(new_item);
}

QGraphicsLineItem *MyGraphicsItemGroup::getLine(qreal start_x, qreal start_y, qreal end_x, qreal end_y)
{
    QGraphicsLineItem *new_line = new QGraphicsLineItem(start_x, start_y , end_x, end_y);
    addItem(new_line);
    return new_line;
}
QGraphicsLineItem *MyGraphicsItemGroup::getPoint(qreal x, qreal y)
{
    return getLine(x, y, x, y);
}

QGraphicsLineItem *MyGraphicsItemGroup::getPoint(qreal x, qreal y, qreal color)
{
    int red = color * 16 * 16;
    QColor gray;
    gray.setRgb(QRgb(0xff000000 + red * 16*16*16*16 + red * 16*16 + red));
    QGraphicsLineItem *new_item = getLine(x, y, x, y);
    new_item->setPen(QPen(gray));
    return new_item;
}
