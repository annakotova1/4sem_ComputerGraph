#include "../inc/MyGraphicsView.h"


MyGraphicsView::MyGraphicsView(QWidget *parent): QGraphicsView(parent)
{
	scene = new QGraphicsScene();
	this->setScene(scene);

	this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);  
	this->setAlignment(Qt::AlignCenter);
	this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	this->setMinimumHeight(100);
	this->setMinimumWidth(100);

	body = new QGraphicsItemGroup();
	head = new QGraphicsItemGroup();
	eye = new QGraphicsItemGroup();
	mouth = new QGraphicsItemGroup();

	DrawFish::MyPoint p = DrawFish::MyPoint(0, 0);

	scene->addItem(body);
	scene->addItem(head);
	scene->addItem(eye);
	scene->addItem(mouth);

	fish = DrawFish::MyFish(p, 12, 6);


	timer = new QTimer();			   // Инициализируем Таймер
	timer->setSingleShot(true);


	DrawFish::MyPoint real_point1 = DrawFish::MyPoint(-20, -20);
	DrawFish::MyPoint real_point2 = DrawFish::MyPoint(20, 20);
	view.setViewPortReal(real_point1, real_point2);

	connect(timer, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));
	timer->start(50);	
}

void MyGraphicsView::slotAlarmTimer()
{
	QSize cur_size = this->size();
	int width = cur_size.width();
	int height = cur_size.height();


	DrawFish::MyPoint screen_point2 = DrawFish::MyPoint(width, height);

	view.setViewPortScreen(screen_point2);

	scene->setSceneRect(0,0,width,height);
	drawFish();
}
void MyGraphicsView::resizeEvent(QResizeEvent *event)
{
	timer->start(50);   // Как только событие произошло стартуем таймер для отрисовки
	QGraphicsView::resizeEvent(event);  // Запускаем событие родителького класса
}

MyGraphicsView::~MyGraphicsView()
{}
/*
void MyGraphicsView::
{}
*/
void MyGraphicsView::drawFish()
{
	QSize cur_size = this->size();
	int width = cur_size.width();
	int height = cur_size.height();
	scene->setSceneRect(0,0,width,height);

	DrawFish::MyPoint real_point1;
	real_point1.x = fish.body.center.x - fish.body.width / 2;
	real_point1.y = fish.body.center.y - fish.body.height / 2;
	DrawFish::MyPoint screen_point1 = view.getScreenCoordinatesByReal(real_point1);


	qreal screen_width = view.getScreenDistanceByReal(fish.body.width);
	qreal screen_height = view.getScreenDistanceByReal(fish.body.height);


	body->addToGroup(scene->addEllipse(screen_point1.x, screen_point1.y, screen_width, 
		screen_height));

	std::cout << width << " " << height << std::endl;


	real_point1.x = fish.head.main.center.x - fish.head.main.width / 2;
	real_point1.y = fish.head.main.center.y - fish.head.main.height / 2;
	screen_point1 = view.getScreenCoordinatesByReal(real_point1);


	screen_width = view.getScreenDistanceByReal(fish.head.main.width);
	screen_height = view.getScreenDistanceByReal(fish.head.main.height);

	head->addToGroup(scene->addEllipse(screen_point1.x, screen_point1.y, screen_width, 
		screen_height));
}