#ifndef MYGRAPHICVIEW_H
#define MYGRAPHICVIEW_H

#include <QGraphicsItemGroup>
#include <QGraphicsView>
#include <QTimer>

#include "MyFish.h"
#include "MyViewPort.h"


class MyGraphicsView: public QGraphicsView
{
	Q_OBJECT
public: 
	explicit MyGraphicsView(QWidget *parent = 0);
	~MyGraphicsView();

	DrawFish::MyFish fish;

	void drawFish();

private:
	QGraphicsScene *scene;

	QGraphicsItemGroup *body;
	QGraphicsItemGroup *head;
	QGraphicsItemGroup *eye;
	QGraphicsItemGroup *mouth;

	void resizeEvent(QResizeEvent *event);

	QTimer *timer;

	MyViewPort view;

private slots:
	void slotAlarmTimer();  // слот для обработчика переполнения таймера в нём будет производиться перерисовка виджета
};

#endif