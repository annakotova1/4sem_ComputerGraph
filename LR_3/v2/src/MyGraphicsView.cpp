#include "../inc/MyGraphicsView.hpp"

MyGraphicsView::MyGraphicsView(QGraphicsView *parent) : QGraphicsView(parent), 
    scene(new QGraphicsScene()), grid(new MyGrid()), 
    lines(new MyGraphicsItemGroup()), spectors(new MyGraphicsItemGroup()),
    timer(new QTimer())
{
    prepeare_configuration();
    prepeare_groups();
    prepeare_timer();
    timer->start(50);	
}

MyGraphicsView::~MyGraphicsView()
{
    delete grid;
    delete lines;
    delete spectors;
    delete scene;
    delete timer;
}

void MyGraphicsView::prepeare_timer()
{
    timer->setSingleShot(true);
	connect(timer, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));
}

void MyGraphicsView::prepeare_groups()
{
    scene->addItem(grid);
    scene->addItem(lines);
    scene->addItem(spectors);
}

void MyGraphicsView::prepeare_configuration()
{
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);  
	setAlignment(Qt::AlignCenter);
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setMinimumHeight(100);
	setMinimumWidth(100);

    setScene(scene);
}

void MyGraphicsView::slotAlarmTimer()
{
	QSize cur_size = this->size();
	int width = cur_size.width();
	int height = cur_size.height();

	scene->setSceneRect(0,0,width,height);
    grid->drawGrid(cur_size);
}

void MyGraphicsView::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);
    timer->start(50);
}
