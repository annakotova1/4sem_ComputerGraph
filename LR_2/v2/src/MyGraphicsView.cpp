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

	fish = new QGraphicsItemGroup();
	scene->addItem(fish);

	grid = new QGraphicsItemGroup();
	scene->addItem(grid);

	DrawFish::MyPoint p = DrawFish::MyPoint(0, 0);
	Fish = DrawFish::MyFish(p, 12, 6);
	FishTemplate = DrawFish::MyFish(p, 12, 6);
	myMatrixCurrentState = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

	myGrid = new MyCoordinateGrid();


	timer = new QTimer();			   // Инициализируем Таймер
	timer->setSingleShot(true);


	DrawFish::MyPoint real_point1 = DrawFish::MyPoint(-7, -8);
	DrawFish::MyPoint real_point2 = DrawFish::MyPoint(12, 8);
	view.setViewPortReal(real_point1, real_point2);

	connect(timer, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));
	timer->start(50);	
}

void MyGraphicsView::slotAlarmTimer()
{
	deleteItemsFromGroup(fish);
	deleteItemsFromGroup(grid);

	QSize cur_size = this->size();
	int width = cur_size.width();
	int height = cur_size.height();


	DrawFish::MyPoint screen_point2 = DrawFish::MyPoint(width, height);
	//std::cout << std::endl << screen_point2.x << " " << screen_point2.y << std::endl << std::endl;
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
	deleteItemsFromGroup(fish);
	deleteItemsFromGroup(grid);

	myGrid->draw(view, grid, scene);
	Fish.transfer(myMatrixCurrentState);
	Fish.draw(view, fish, scene);
	Fish = FishTemplate;
}
void MyGraphicsView::deleteItemsFromGroup(QGraphicsItemGroup *group)
{
	/*foreach( QGraphicsItem *item, group) {
	   if(item->group() == group ) {
		  delete item;
	   }
	}*/
	//scene->destroyItemGroup(group);
	foreach( QGraphicsItem *item, scene->items(group->boundingRect())) {
	   if(item->group() == group ) {
		  delete item;
	   }
	}
	/*)
	delete group;
	group = new QGraphicsItemGroup();
	scene->addItem(group);*/
}

void MyGraphicsView::mousePressEvent(QMouseEvent *event)
{
	emit pressMouse(event);
}

void MyGraphicsView::restartFish()
{
	//DrawFish::MyPoint p = DrawFish::MyPoint(0, 0);
	DrawFish::MyPoint real_point1 = DrawFish::MyPoint(-7, -8);
	DrawFish::MyPoint real_point2 = DrawFish::MyPoint(12, 8);
	view.setViewPortReal(real_point1, real_point2);
	myMatrixCurrentState = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
	timer->start(0);
}

void MyGraphicsView::updateMatrixCurrentState(matrix_t matrix, MyArhive *arhive)
{
	myMatrixCurrentState = multiplicateMatrixes(myMatrixCurrentState, matrix);
	arhive->writeAction(myMatrixCurrentState);
}

void MyGraphicsView::changeMatrixCurrentState(matrix_t matrix)
{
	myMatrixCurrentState = matrix;
}

/*
void MyGraphicsView::wheelEvent(QGraphicsSceneWheelEvent *wheelEvent)
{
	qreal scaleDelta = 1.2;
	DrawFish::MyPoint rlu, rrd;
	rlu = view.getRealCoordinateLeftUpConner();
	rrd = view.getRealCoordinateRightDownConner();
	if (wheelEvent->delta() > 0)
	{
		rrd.x *= scaleDelta;
		rlu.x *= scaleDelta;
		rrd.y *= scaleDelta;
		rlu.y *= scaleDelta;
	}
	else
	{
		rrd.x /= scaleDelta;
		rlu.x /= scaleDelta;
		rrd.y /= scaleDelta;
		rlu.y /= scaleDelta;
	}
	view.setViewPortReal(rlu, rrd);
	timer->start(0);
}*/