#ifndef MYGRAPHICVIEW_H
#define MYGRAPHICVIEW_H

#include <QGraphicsItemGroup>
#include <QGraphicsSceneWheelEvent>
#include <QGraphicsView>
#include <QTimer>

#include "MyFish.h"
#include "MyViewPort.h"
#include "MyArhive.h"
#include "MyCoordinateGrid.h"


class MyGraphicsView: public QGraphicsView
{
	Q_OBJECT
public: 
	explicit MyGraphicsView(QWidget *parent = 0);
	~MyGraphicsView();
	MyViewPort view;

	void updateMatrixCurrentState(matrix_t matrix, MyArhive *arhive);

	void drawFish();
	void mousePressEvent(QMouseEvent *event);
	void changeMatrixCurrentState(matrix_t matrix);
	//void wheelEvent(QGraphicsSceneWheelEvent *wheelEvent);
	void restartFish();

signals:
	void pressMouse(QMouseEvent *event);

private:
	DrawFish::MyFish Fish;
	DrawFish::MyFish FishTemplate;
	matrix_t myMatrixCurrentState;

	MyCoordinateGrid *myGrid;

	QGraphicsScene *scene;

	QGraphicsItemGroup *fish;
	QGraphicsItemGroup *grid;

	void resizeEvent(QResizeEvent *event);

	QTimer *timer;

	void deleteItemsFromGroup(QGraphicsItemGroup *group);

private slots:
	void slotAlarmTimer();  // слот для обработчика переполнения таймера в нём будет производиться перерисовка виджета
};

#endif