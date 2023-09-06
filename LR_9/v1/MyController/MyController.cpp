#include "MyController.hpp"


MyController::MyController(MyMainWindow *main): mainWindow(main), 
    inputLineColor(new MyColorInput), inputCatterColor(new MyColorInput),
    inputCatLineColor(new MyColorInput),// inputFoneColor(new MyColorInput), 
    image(new MyImage)//, table(new MyTableModel()), Catter(new MyShape())
{
    curAlg = new MyAlgorithmShortedEdges();
    setConnections();
    setLabel();
    //mainWindow->setTable(table);
}

MyController::~MyController()
{
    delete inputCatterColor;
    delete inputCatLineColor;
    delete inputLineColor;
    //delete inputFoneColor;
    delete mainWindow;
}
/*
void MyController::startAddShape()
{
    int start, end;
    start = clock();
    for (int i = 0; i < 1; i++)
    {
        drawShapes();
    }
    end = clock();
    QLabel *allTime = mainWindow->getTimeLabel();
    allTime->setText(QString(QString::number(end-start)+" микросек"));
    image->setChanged(true);
}*/

void MyController::endAddCatter()
{
    if (Catter.isEmpty())
    {
        MyException *exp = new MyException();
        exp->makeException(QString("Введите область\n"));
        return;
    }
    QVector<MyPoint> catter = Catter.getPoints();
    //QVector<MyPoint> shape = Shape.getPoints();
    image->setCatterLine(catter[0], catter[catter.size()-1]);
    if (!curAlg->check_poligon(catter))
    {
        MyException *exp = new MyException();
        exp->makeException(QString("Некорректный многоугольник. Повторите ввод учитывая, что многоугольник выпуклый, и кол-во вершин больше 2\n"));
        clearCanvas();
        return;
    }
    image->setChanged(false);
    image->updateDisplay();
    isCatter = false;
    isShape = true;
}
void MyController::endAddShape()
{
    if (Shape.isEmpty())
    {
        MyException *exp = new MyException();
        exp->makeException(QString("Введите область\n"));
        clearCanvas();
        return;
    }
    QVector<MyPoint> shape = Shape.getPoints();
    //QVector<MyPoint> shape = Shape.getPoints();
    image->setLine(shape[0], shape[shape.size()-1]);
    if (shape.size() < 3)
    {
        MyException *exp = new MyException();
        exp->makeException(QString("Некорректный многоугольник. Повторите ввод учитывая, что кол-во вершин должно больше 2\n"));
        clearCanvas();
        return;
    }
    curAlg->draw(image, Catter.getPoints(), shape);
    image->setChanged(false);
    image->updateDisplay();
    isShape = false;
}

void MyController::clearCanvas()
{
    image->clean();
    Catter.clean();
    Shape.clean();
    isCatter = true;
    isShape = false;
}

void MyController::setLabel()
{
    mainWindow->setPicture(image->getDisplay());
}

void MyController::setConnections()
{
    connect(mainWindow->lineColorButton(), SIGNAL(clicked()),this, SLOT(getLineColor()));
    connect(mainWindow->catLineColorButton(), SIGNAL(clicked()),this, SLOT(getCatLineColor()));
    connect(mainWindow->catterColorButton(), SIGNAL(clicked()),this, SLOT(getCatterColor()));
    //connect(mainWindow->foneColorButton(), SIGNAL(clicked()),this, SLOT(getFoneColor()));
    //inputFoneColor->addObject(mainWindow->foneColorButton());
    inputCatLineColor->addObject(mainWindow->catLineColorButton());
    inputCatterColor->addObject(mainWindow->catterColorButton());
    inputLineColor->addObject(mainWindow->lineColorButton());

    //inputFoneColor->addObject(image);
    inputLineColor->addObject(image);
    inputCatterColor->addObject(image);
    inputCatLineColor->addObject(image);
    //inputFoneColor->setFone(true);
    inputCatterColor->setCatter(true);
    inputCatLineColor->setCatLine(true);
    inputLineColor->setLine(true);

    //inputFoneColor->setNewColor(Qt::white);
    inputCatterColor->setNewColor(Qt::black);
    inputCatLineColor->setNewColor(Qt::darkRed);
    inputLineColor->setNewColor(Qt::darkGreen);

    connect(mainWindow->getEndAddShapeButton(), SIGNAL(clicked()), this, SLOT(endAddShape()));
    connect(mainWindow->getEndAddCatterButton(), SIGNAL(clicked()), this, SLOT(endAddCatter()));
    connect(mainWindow->getClearCanvasButton(), SIGNAL(clicked()), this, SLOT(clearCanvas()));
    //connect(mainWindow->getDrawButton(), SIGNAL(clicked()), this, SLOT(drawShapes()));


    connect(image->getDisplay(), SIGNAL(mouseAddPointEvent(MyPoint)), this, SLOT(addLine(MyPoint)));

}
/*
void MyController::getFoneColor()
{
    inputFoneColor->getNewColor();
}*/

void MyController::getLineColor()
{
    inputLineColor->getNewColor();
}
void MyController::getCatLineColor()
{
    inputCatLineColor->getNewColor();
}
void MyController::getCatterColor()
{
    inputCatterColor->getNewColor();
}

void MyController::addCatterPoint(MyPoint event)
{
    MyPoint newpoint = event;
    if (!Catter.isEmpty())
    {
        MyPoint lastPoint = Catter.getLastPoint();
        if (QGuiApplication::keyboardModifiers().testFlag(Qt::ShiftModifier))
        {
            if (fabs((lastPoint.getY() - newpoint.getY())) > fabs((lastPoint.getX() - newpoint.getX())))
            {
                newpoint.setX(lastPoint.getX());
            }
            else
            {
                newpoint.setY(lastPoint.getY());
            }
        }
    }
    image->setPoint(newpoint);
    if (!Catter.isEmpty())
    {
        image->setCatterLine(newpoint, Catter.getLastPoint());
    }
    Catter.addPoint(newpoint);
}

void MyController::addShapePoint(MyPoint event)
{
    MyPoint newpoint = event;
    if (!Shape.isEmpty())
    {
        MyPoint lastPoint = Shape.getLastPoint();
        if (QGuiApplication::keyboardModifiers().testFlag(Qt::ShiftModifier))
        {
            if (fabs((lastPoint.getY() - newpoint.getY())) > fabs((lastPoint.getX() - newpoint.getX())))
            {
                newpoint.setX(lastPoint.getX());
            }
            else
            {
                newpoint.setY(lastPoint.getY());
            }
        }
    }
    image->setPoint(newpoint);
    if (!Shape.isEmpty())
    {
        image->setLine(newpoint, Shape.getLastPoint());
    }
    Shape.addPoint(newpoint);
}
void MyController::addLine(MyPoint event)
{
    if (isCatter)
    {
        addCatterPoint(event);
    }
    else if (isShape)
    {
        addShapePoint(event);
    }
    image->updateDisplay();
}

