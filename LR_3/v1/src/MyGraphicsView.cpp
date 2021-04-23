#include "../inc/MyGraphicsView.hpp"

MyGraphicsView::MyGraphicsView(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene())
{
    start_configuration();
    start_groups();
    start_timer();
    timer->start(50);	
}

void MyGraphicsView::start_groups()
{
    grid = new MyGraphicsItemGroup();
    lines = new MyGraphicsItemGroup();
    spectors = new MyGraphicsItemGroup();
    scene->addItem(grid);
    scene->addItem(lines);
    scene->addItem(spectors);
}
void MyGraphicsView::start_configuration()
{
	this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);  
	this->setAlignment(Qt::AlignCenter);
	this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	this->setMinimumHeight(100);
	this->setMinimumWidth(100);

    this->setScene(scene);
}
void MyGraphicsView::start_timer()
{
	timer = new QTimer();			   // Инициализируем Таймер
	timer->setSingleShot(true);
	connect(timer, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));
}

void MyGraphicsView::slotAlarmTimer()
{

	QSize cur_size = this->size();
	int width = cur_size.width();
	int height = cur_size.height();

	scene->setSceneRect(0,0,width,height);
    draw_grid();
}

void MyGraphicsView::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);
    timer->start(50);
}
void MyGraphicsView::delete_group(MyGraphicsItemGroup *group)
{
    scene->removeItem(group);
    group->clean();
}

void MyGraphicsView::draw_grid()
{
    delete_group(grid);

	QSize cur_size = this->size();
	int width = cur_size.width();
	int height = cur_size.height();
    QGraphicsLineItem *new_line;
    QPen penGray(Qt::gray);
    for (int i = 0; i < width; i+=50)
    {
        new_line = grid->getLine(i, 0, i, height);
        new_line->setPen(penGray);
    }
    for (int i = 0; i < height; i+=50)
    {
        new_line = grid->getLine(0, i, width, i);
        new_line->setPen(penGray);
    }
    scene->addItem(grid);
}

void MyGraphicsView::draw_line(MyPoint start, MyPoint end, int algorithm)
{
    switch (algorithm)
    {
        case BRESENHEMINT:
            drawBrezenhemInt(start, end, lines);
            break;
        case BRESENHEMFLOAT:
            drawBrezenhemFloat(start, end, lines);
            break;
        case BRESENHEMSMOOTH:
            drawBrezenhemSmooth(start, end, lines);
            break;
        case VY:
            drawVy(start, end, lines);
            break;
        case CDA:
            drawCDA(start, end, lines);
            break;
        case LIBRARY:
            drawLibrary(start, end, lines);
    }
}
