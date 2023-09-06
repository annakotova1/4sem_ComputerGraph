#include "MyMainWindow.hpp"

MyMainWindow::MyMainWindow(QMainWindow *parent): QMainWindow(parent), 
    ui(new Ui::MainWindow()),
    locale(new MyLocale()), check(new MyChecker())
{
    constractWidgets();
    ui->setupUi(this);
    setValidator();
    setSplitters();
    addWidgets();
    setConnects();
}

void MyMainWindow::setConnects()
{
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(clearCanvas()));
}

void MyMainWindow::setToolButtons(QVector<QString> names)
{

    CircleAlgorithmsButton = new MyToolButton(names);
    ManyCirclesAlgorithmsButton = new MyToolButton(names);
    EllipseAlgorithmsButton = new MyToolButton(names);
    ManyEllipsesAlgorithmsButton = new MyToolButton(names);


    ui->Circle_algorithm->addWidget(CircleAlgorithmsButton);
    ui->ManyCircles_algorithm->addWidget(ManyCirclesAlgorithmsButton);
    ui->Ellipse_algorithm->addWidget(EllipseAlgorithmsButton);
    ui->ManyEllipse_algorithm->addWidget(ManyEllipsesAlgorithmsButton);
}
void MyMainWindow::constractWidgets()
{
    graphicsCanvas = new MyGraphicsView();

    CircleColorButton = new MyPushButton();
    ManyCirclesColorButton = new MyPushButton();
    EllipseColorButton = new MyPushButton();
    ManyEllipsesColorButton = new MyPushButton();
    
}

void MyMainWindow::addWidgets()
{
    ui->GraphicsCanvas->addWidget(graphicsCanvas);

    ui->Circle_color->addWidget(CircleColorButton);
    ui->ManyCircles_color->addWidget(ManyCirclesColorButton);
    ui->Ellipse_color->addWidget(EllipseColorButton);
    ui->ManyEllipse_color->addWidget(ManyEllipsesColorButton);
}

void MyMainWindow::setValidator()
{
    ui->Circle_x->setValidator(locale->getIntValidator());
    ui->Circle_y->setValidator(locale->getIntValidator());
    ui->Circle_radius->setValidator(locale->getIntValidator());

    ui->ManyCircles_x->setValidator(locale->getIntValidator());
    ui->ManyCircles_y->setValidator(locale->getIntValidator());
    ui->ManyCircles_radius_start->setValidator(locale->getIntValidator());
    ui->ManyCircles_radius_end->setValidator(locale->getIntValidator());
    ui->ManyCircles_count->setValidator(locale->getIntValidator());


    ui->Ellipse_x->setValidator(locale->getIntValidator());
    ui->Ellipse_y->setValidator(locale->getIntValidator());
    ui->Ellipse_axis_a->setValidator(locale->getIntValidator());
    ui->Ellipse_axis_b->setValidator(locale->getIntValidator());

    ui->ManyEllipse_x->setValidator(locale->getIntValidator());
    ui->ManyEllipse_y->setValidator(locale->getIntValidator());
    ui->ManyEllipses_axis_a_start->setValidator(locale->getIntValidator());
    ui->ManyEllipses_axis_b_start->setValidator(locale->getIntValidator());
    ui->ManyEllipses_axis_a_end->setValidator(locale->getIntValidator());
    ui->ManyEllipses_axis_b_end->setValidator(locale->getIntValidator());
    ui->ManyEllipse_count->setValidator(locale->getIntValidator());
}
void MyMainWindow::setSplitters()
{
	QList<int> s1;
	s1.push_back(20);
	s1.push_back(1000);
	ui->splitter_3->setSizes(s1);
}
MyMainWindow::~MyMainWindow()
{
    delete ui;
    delete CircleColorButton;
    delete CircleAlgorithmsButton;
    delete ManyCirclesColorButton;
    delete ManyCirclesAlgorithmsButton;
    delete EllipseColorButton;
    delete EllipseAlgorithmsButton;
    delete ManyEllipsesColorButton;
    delete ManyEllipsesAlgorithmsButton;
    delete graphicsCanvas;
    delete locale;
}
MyGraphicsView *MyMainWindow::getCanvas()
{
    return graphicsCanvas;
}


MyPushButton *MyMainWindow::getCircleColorButton()
{
    return CircleColorButton;
}

MyPushButton *MyMainWindow::getManyCirclesColorButton()
{
    return ManyCirclesColorButton;
}
MyPushButton *MyMainWindow::getEllipseColorButton()
{
    return EllipseColorButton;
}

MyPushButton *MyMainWindow::getManyEllipsesColorButton()
{
    return ManyEllipsesColorButton;
}


QVector<MyPoint> MyMainWindow::getCircleData()
{
    MyPoint start, end;
    start.setX(locale->toInt(ui->Circle_x->text()));
    start.setY(locale->toInt(ui->Circle_y->text()));
    end.setX(locale->toInt(ui->Circle_radius->text()));
    end.setY(locale->toInt(ui->Circle_radius->text()));

    QVector<MyPoint> ans;
    ans.append(start);
    ans.append(end);
    return ans;
}

QVector<MyPoint> *MyMainWindow::getManyCirclesData()
{
    MyPoint p1, p2, p3;
    int step = locale->toInt(ui->ManyCircles_step->text()), count = locale->toInt(ui->ManyCircles_count->text());
    int x = locale->toInt(ui->ManyCircles_x->text()), y = locale->toInt(ui->ManyCircles_y->text());
    int radius_start = locale->toInt(ui->ManyCircles_radius_start->text()), radius_end = locale->toInt(ui->ManyCircles_radius_end->text());

    QVector<MyPoint> *ans = check->checkManyCirclesData(x, y, step, count,
        radius_start, radius_end);
    return ans;
}

QVector<MyPoint> MyMainWindow::getEllipseData()
{
    MyPoint start, end;
    start.setX(locale->toInt(ui->Ellipse_x->text()));
    start.setY(locale->toInt(ui->Ellipse_y->text()));
    end.setX(locale->toInt(ui->Ellipse_axis_a->text()));
    end.setY(locale->toInt(ui->Ellipse_axis_b->text()));

    QVector<MyPoint> ans;
    ans.append(start);
    ans.append(end);
    return ans;
}

QVector<MyPoint> *MyMainWindow::getManyEllipsesData()
{
    MyPoint p1, p2, p3, p4;
    int x = locale->toInt(ui->ManyEllipse_x->text());
    int y = locale->toInt(ui->ManyEllipse_y->text());
    int a_step = locale->toInt(ui->ManyEllipse_step->text());
    int count = locale->toInt(ui->ManyEllipse_count->text());
    int a_start = locale->toInt(ui->ManyEllipses_axis_a_start->text());
    int b_start = locale->toInt(ui->ManyEllipses_axis_b_start->text());
    int a_end = locale->toInt(ui->ManyEllipses_axis_a_end->text());
    int b_end = locale->toInt(ui->ManyEllipses_axis_b_end->text());

    QVector<MyPoint> *ans = check->checkManyEllipsesData(x, y, a_step, count,
        a_start, a_end, b_start, b_end);
    return ans;
}


QPushButton *MyMainWindow::getCircleDrawButton()
{
    return ui->Circle_draw;
}
QPushButton *MyMainWindow::getManyCirclesDrawButton()
{
    return ui->ManyCircles_draw;
}
QPushButton *MyMainWindow::getEllipseDrawButton()
{
    return ui->Ellipse_draw;
}
QPushButton *MyMainWindow::getManyEllipsesDrawButton()
{
    return ui->ManyEllipse_draw;
}
QPushButton *MyMainWindow::getCircleHistogramDrawButton()
{
    return ui->CirclePlot_draw;
}
QPushButton *MyMainWindow::getEllipseHistogramDrawButton()
{
    return ui->EllipsePlot_draw;
}


MyToolButton *MyMainWindow::getCircleAlgorithmsButton()
{
    return CircleAlgorithmsButton;
}
MyToolButton *MyMainWindow::getManyCirclesAlgorithmsButton()
{
    return ManyCirclesAlgorithmsButton;
}
MyToolButton *MyMainWindow::getEllipseAlgorithmsButton()
{
    return EllipseAlgorithmsButton;
}
MyToolButton *MyMainWindow::getManyEllipsesAlgorithmsButton()
{
    return ManyEllipsesAlgorithmsButton;
}


QRadioButton *MyMainWindow::getGridButton()
{
    return ui->radioButton;
}

void MyMainWindow::addHistogram(MyHistogramView *histogram)
{
    ui->Plot->addWidget(histogram);
}

void MyMainWindow::clearCanvas()
{
    printf("clean\n");
    //graphicsCanvas->remove_items_to_scene();
    printf("end remove\n");
    graphicsCanvas->getCircleDrawer()->clear();
    graphicsCanvas->getManyCirclesDrawer()->clear();
    graphicsCanvas->getEllipseDrawer()->clear();
    graphicsCanvas->getManyEllipsesDrawer()->clear();
    /*delete graphicsCanvas->getCircleDrawer();
    graphicsCanvas->setCircleDrawer(new MyGraphicsItemGroup());
    delete graphicsCanvas->getManyCirclesDrawer();
    graphicsCanvas->setManyCirclesDrawer(new MyGraphicsItemGroup());
    delete graphicsCanvas->getEllipseDrawer();
    graphicsCanvas->setEllipseDrawer(new MyGraphicsItemGroup());
    delete graphicsCanvas->getManyEllipsesDrawer();
    graphicsCanvas->setManyEllipsesDrawer(new MyGraphicsItemGroup());*/
    //graphicsCanvas->add_items_to_scene();
}
