#ifndef MY_GRAPHIC_VIEW_H
#define MY_GRAPHIC_VIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include "MyPointsTableModel.h"

#include <QTimer>
 
class MyGraphicView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyGraphicView(QWidget *parent = 0);
    ~MyGraphicView();
    void drawPicture(point_t a, point_t b, point_t c);
 
 
private slots:
    void slotAlarmTimer();  // слот для обработчика переполнения таймера в нём будет производиться перерисовка виджета

    
private:
    QGraphicsScene      *scene;     // Объявляем сцену для отрисовки
    QGraphicsItemGroup  *group_1;   // Объявляем первую группу элементов
    QGraphicsItemGroup  *group_2;   // Объявляем вторую группу элементов


    QGraphicsEllipseItem  *point_a;   // Объявляем точки
    QGraphicsEllipseItem  *point_b;   // Объявляем точки
    QGraphicsEllipseItem  *point_c;   // Объявляем точки
    QGraphicsItemGroup  *triangle;   // Объявляем треугольник
    QGraphicsItemGroup  *height;   // Объявляем высоту
    QGraphicsItemGroup  *median;   // Объявляем медиану
 
    QTimer              *timer;
 
private:
    // Перегружаем событие изменения размера окна, чтобы перехватывать его
    
    void resizeEvent(QResizeEvent *event);
    // Метод для удаления всех элементов  из группы элементов
    void deleteItemsFromGroup(QGraphicsItemGroup *group);

    void drawPoint(QGraphicsEllipseItem  *group, qreal x, qreal y);
    void drawTriangle(QGraphicsItemGroup  *group, qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3);
    void drawLine(QGraphicsItemGroup *group, qreal x1, qreal y1, qreal x2, qreal y2);
};

#endif