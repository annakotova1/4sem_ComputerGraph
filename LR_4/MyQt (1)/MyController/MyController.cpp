#include "MyController.hpp"


MyController::MyController(MyMainWindow *main): mainWindow(main), 
    myCircleAlgorithms(new MyAlgorithmsCircle), myEllipseAlgorithms(new MyAlgorithmsEllipse), plot1(new MyPlotView()), plot2(new MyPlotView()),
    inputCircleColor(new MyColorInput()), inputManyCirclesColor(new MyColorInput()),
    inputEllipseColor(new MyColorInput()), inputManyEllipsesColor(new MyColorInput())
{
    //mainWindow->addHistogram(histogram);

    connect(mainWindow->getCircleColorButton(), SIGNAL(clicked()), 
        this, SLOT(getCircleColor()));
    inputCircleColor->addObject((mainWindow->getCircleColorButton()));
    inputCircleColor->addObject((mainWindow->getCanvas()->getCircleDrawer()));

    connect(mainWindow->getManyCirclesColorButton(), SIGNAL(clicked()), 
        this, SLOT(getManyCirclesColor()));
    inputManyCirclesColor->addObject((mainWindow->getManyCirclesColorButton()));
    inputManyCirclesColor->addObject((mainWindow->getCanvas()->getManyCirclesDrawer()));


    connect(mainWindow->getEllipseColorButton(), SIGNAL(clicked()), 
        this, SLOT(getEllipseColor()));
    inputEllipseColor->addObject((mainWindow->getEllipseColorButton()));
    inputEllipseColor->addObject((mainWindow->getCanvas()->getEllipseDrawer()));

    connect(mainWindow->getManyEllipsesColorButton(), SIGNAL(clicked()), 
        this, SLOT(getManyEllipsesColor()));
    inputManyEllipsesColor->addObject((mainWindow->getManyEllipsesColorButton()));
    inputManyEllipsesColor->addObject((mainWindow->getCanvas()->getManyEllipsesDrawer()));



    connect(mainWindow->getCircleDrawButton(), SIGNAL(clicked()), this, SLOT(drawCircle()));
    connect(mainWindow->getManyCirclesDrawButton(), SIGNAL(clicked()), this, SLOT(drawManyCircles()));
    connect(mainWindow->getEllipseDrawButton(), SIGNAL(clicked()), this, SLOT(drawEllipse()));
    connect(mainWindow->getManyEllipsesDrawButton(), SIGNAL(clicked()), this, SLOT(drawManyEllipses()));

    //mainWindow->setCircleAlgorithmButton(myAlgorithms->getNames());
    //mainWindow->setManyCirclesAlgorithmButton(myAlgorithms->getNames());


    gridButton = mainWindow->getGridButton();
    connect(gridButton, SIGNAL(clicked()), this, SLOT(drawGrid()));

    mainWindow->setToolButtons(makeToolNames());

    connect(mainWindow->getCircleHistogramDrawButton(), SIGNAL(clicked()), this, SLOT(drawCircleHistogram()));
    connect(mainWindow->getEllipseHistogramDrawButton(), SIGNAL(clicked()), this, SLOT(drawEllipseHistogram()));
}

void MyController::drawCircle()
{
    MyGraphicsView *myCanvas = mainWindow->getCanvas();
    myCanvas->remove_items_to_scene();

    QVector<MyPoint> data = mainWindow->getCircleData();

    QAction *cur_action = mainWindow->getCircleAlgorithmsButton()->defaultAction();
    MyGraphicsItemGroup *painter = mainWindow->getCanvas()->getCircleDrawer();
    myCircleAlgorithms->performAlgorithm(data[0], data[1].getX(), painter, cur_action->text());

    myCanvas->add_items_to_scene();
}

void MyController::drawManyCircles()
{
    QVector<MyPoint> *data = mainWindow->getManyCirclesData();
    if (!data)
    {
        return;
    }
    MyGraphicsView *myCanvas = mainWindow->getCanvas();
    QAction *cur_action = mainWindow->getManyCirclesAlgorithmsButton()->defaultAction();
    MyGraphicsItemGroup *painter = myCanvas->getManyCirclesDrawer();
    

    myCanvas->remove_items_to_scene();

    for (double i = (*data)[1].getX(); i <= (*data)[1].getY(); i+= (*data)[2].getX())
    {
        myCircleAlgorithms->performAlgorithm((*data)[0], i, painter, cur_action->text());
    }
    myCanvas->add_items_to_scene();
    delete data;
}
void MyController::drawEllipse()
{
    MyGraphicsView *myCanvas = mainWindow->getCanvas();
    myCanvas->remove_items_to_scene();

    QVector<MyPoint> data = mainWindow->getEllipseData();

    QAction *cur_action = mainWindow->getEllipseAlgorithmsButton()->defaultAction();
    MyGraphicsItemGroup *painter = mainWindow->getCanvas()->getEllipseDrawer();
    myEllipseAlgorithms->performAlgorithm(data[0], data[1].getX(), data[1].getY(), painter, cur_action->text());

    myCanvas->add_items_to_scene();
}

void MyController::drawManyEllipses()
{
    QVector<MyPoint> *data = mainWindow->getManyEllipsesData();
    if(!data)
    {
        return;
    }
    MyGraphicsView *myCanvas = mainWindow->getCanvas();
    QAction *cur_action = mainWindow->getManyEllipsesAlgorithmsButton()->defaultAction();
    MyGraphicsItemGroup *painter = myCanvas->getManyEllipsesDrawer();
    

    myCanvas->remove_items_to_scene();

    double b = (*data)[2].getX();

    for (double a = (*data)[1].getX(); a <= ((*data)[1]).getY(); a+= (*data)[3].getX())
    {
        //printf("a = %lf, b = %lf, b_step = %lf\n", a, b, (*data)[3].getY());
        myEllipseAlgorithms->performAlgorithm((*data)[0], a, b, painter, cur_action->text());
        b+=(*data)[3].getY();
    }
    myCanvas->add_items_to_scene();
    delete data;
}

void MyController::getCircleColor()
{
    inputCircleColor->getNewColor();
}

void MyController::getManyCirclesColor()
{
    inputManyCirclesColor->getNewColor();
}
void MyController::getEllipseColor()
{
    inputEllipseColor->getNewColor();
}

void MyController::getManyEllipsesColor()
{
    inputManyEllipsesColor->getNewColor();
}


QVector<QString> MyController::makeToolNames()
{
    QVector<QString>names = myCircleAlgorithms->getNames();
    return names;
}

QVector<QVector<MyPoint>> MyController::makeCircleHistogramData()
{
    QVector<QString> names = myCircleAlgorithms->getNames();
    QVector<MyPoint> pointsForOneAlg;
    QVector<QVector<MyPoint>> pointsAll;


    for (int i = 0; i < names.size(); i++)
    {
        pointsForOneAlg.clear();
        for(int j = 1; j < 100; j+=10)
        {
            pointsForOneAlg.append(MyPoint(j, myCircleAlgorithms->getTime(MyPoint(0, 0), j, names[i])));
        }
        pointsAll.append(pointsForOneAlg);
    }
    return pointsAll;
}
QVector<QVector<MyPoint>> MyController::makeEllipseHistogramData()
{
    QVector<QString> names = myEllipseAlgorithms->getNames();
    QVector<MyPoint> pointsForOneAlg;
    QVector<QVector<MyPoint>> pointsAll;


    for (int i = 0; i < names.size(); i++)
    {
        pointsForOneAlg.clear();
        for(int j = 1; j < 100; j+=10)
        {
            pointsForOneAlg.append(MyPoint(j, myEllipseAlgorithms->getTime(MyPoint(0, 0), j, j, names[i])));
        }
        pointsAll.append(pointsForOneAlg);
    }
    return pointsAll;
}
void MyController::drawCircleHistogram()
{
    plot1->drawPlot(makeCircleHistogramData(), myCircleAlgorithms->getNames(), QString("Гистограмма для сравнения времени"));
    plot2->setTitle(QString(tr("Гистограмма для сравнения времени работы разных алгоритмов")));
    plot1->addWindow("Сравнение временных характеристик для окружности");
}

void MyController::drawEllipseHistogram()
{
    plot2->drawPlot(makeEllipseHistogramData(), myCircleAlgorithms->getNames(), QString("Гистограмма для сравнения времени работы разных алгоритмов"));
    plot2->setTitle(QString(tr("Гистограмма для сравнения времени работы разных алгоритмов")));
    plot2->addWindow("Сравнение временных характеристик для эллипса");
}


void MyController::drawGrid()
{
    if (gridButton->isChecked())
        mainWindow->getCanvas()->drawGrid();
    else
        mainWindow->getCanvas()->deleteGrid();
}