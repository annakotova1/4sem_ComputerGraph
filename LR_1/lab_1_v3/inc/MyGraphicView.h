#ifndef MYGRAPHICVIEW_H
#define MYGRAPHICVIEW_H

#include "my_functions.h"
#include "MyPoint.h"

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QGraphicsView>

#include "iostream"
#include <algorithm>

#include <QTimer>

class MyGraphicView : public QGraphicsView
{
	Q_OBJECT
public:
	explicit MyGraphicView(QWidget *parent = 0);
	~MyGraphicView();
	void drawPicture();
	void changePicture(MyPoint a, MyPoint b, MyPoint c, MyPoint d, MyPoint e);

	void cleanScene();
 
 
private slots:
	void slotAlarmTimer();  // слот для обработчика переполнения таймера в нём будет производиться перерисовка виджета

	
private:
	QGraphicsScene	  *scene;	 // Объявляем сцену для отрисовки
	QGraphicsItemGroup  *group_1;   // Объявляем первую группу элементов
	QGraphicsItemGroup  *group_2;   // Объявляем вторую группу элементов


	QGraphicsItemGroup  *point_a;   // Объявляем точки
	QGraphicsItemGroup  *point_b;   // Объявляем точки
	QGraphicsItemGroup  *point_c;   // Объявляем точки
	QGraphicsItemGroup  *point_e;   // Объявляем точки
	QGraphicsItemGroup  *point_d;   // Объявляем точки
	QGraphicsItemGroup  *triangle;   // Объявляем треугольник
	QGraphicsItemGroup  *height;   // Объявляем высоту
	QGraphicsItemGroup  *bissector;   // Объявляем медиану
 
	QTimer			  *timer;

	MyPoint A;
	MyPoint B;
	MyPoint C;
	MyPoint D;
	MyPoint E;

	bool PictureExist;
	bool PictureNeedToDelete;

private:
	// Перегружаем событие изменения размера окна, чтобы перехватывать его
	
	void resizeEvent(QResizeEvent *event);
	// Метод для удаления всех элементов  из группы элементов
	void deleteItemsFromGroup(QGraphicsItemGroup *group);

	void drawPoint(QGraphicsItemGroup  *group, qreal x, qreal y, int size, QPen pen);
	void drawTriangle(QGraphicsItemGroup  *group, qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3);
	void drawLine(QGraphicsItemGroup *group, qreal x1, qreal y1, qreal x2, qreal y2, QPen pen);
};


#endif