#include "MyGraphicsView.hpp"

MyGraphicsView::MyGraphicsView(QGraphicsView *parent) : QGraphicsView(parent), 
    scene(new QGraphicsScene()), grid(new MyGrid()), 
    circle(new MyGraphicsItemGroup()), manyCircles(new MyGraphicsItemGroup()),
    ellipse(new MyGraphicsItemGroup()), manyEllipses(new MyGraphicsItemGroup()),
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
    delete circle;
    delete manyCircles;
    delete ellipse;
    delete manyEllipses;
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
    scene->addItem(grid->getGroup());
    add_items_to_scene();
}

void MyGraphicsView::add_items_to_scene()
{
    scene->addItem(circle->getGroup());
    scene->addItem(manyCircles->getGroup());
    scene->addItem(ellipse->getGroup());
    scene->addItem(manyEllipses->getGroup());
}

void MyGraphicsView::remove_items_to_scene()
{
    scene->removeItem(circle->getGroup());
    printf("remove circles\n");
    scene->removeItem(manyCircles->getGroup());
    printf("remove MANY circles\n");
    scene->removeItem(ellipse->getGroup());
    printf("remove ellipses\n");
    scene->removeItem(manyEllipses->getGroup());
    printf("remove MANY ellipses\n");
}

QGraphicsScene *MyGraphicsView::getScene()
{
    return scene;
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
    if (gridExist)
        grid->drawGrid(cur_size);
    else 
        grid->cleanGrid();
}

void MyGraphicsView::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);
    timer->start(50);
}

MyGraphicsItemGroup *MyGraphicsView::getCircleDrawer()
{
    return circle;
}
MyGraphicsItemGroup *MyGraphicsView::getManyCirclesDrawer()
{
    return manyCircles;
}
MyGraphicsItemGroup *MyGraphicsView::getEllipseDrawer()
{
    return ellipse;
}
MyGraphicsItemGroup *MyGraphicsView::getManyEllipsesDrawer()
{
    return manyEllipses;
}

void MyGraphicsView::setCircleDrawer(MyGraphicsItemGroup *item)
{
    circle = item;
}
void MyGraphicsView::setManyCirclesDrawer(MyGraphicsItemGroup *item)
{
    manyCircles = item;
}
void MyGraphicsView::setEllipseDrawer(MyGraphicsItemGroup *item)
{
    ellipse = item;
}
void MyGraphicsView::setManyEllipsesDrawer(MyGraphicsItemGroup *item)
{
    manyEllipses = item;
}

void MyGraphicsView::drawGrid()
{
    gridExist = true;
    timer->start(1);
}
void MyGraphicsView::deleteGrid()
{
    gridExist = false;
    timer->start(1);
}