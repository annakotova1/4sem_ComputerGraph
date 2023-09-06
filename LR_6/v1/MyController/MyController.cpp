#include "MyController.hpp"


MyController::MyController(MyMainWindow *main): mainWindow(main), inputDrawColor(new MyColorInput), inputFoneColor(new MyColorInput), 
    image(new MyImage), table(new MyTableModel())
{
    curAlg = new MyAlgorithmShortedEdges();
    setConnections();
    setLabel();
    mainWindow->setTable(table);
    shapes.setAlgorithm(curAlg);
}

MyController::~MyController()
{
    delete inputDrawColor;
    delete inputFoneColor;
    delete mainWindow;
}

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
}

void MyController::endAddShape()
{
    if (curShape.isEmpty())
    {
        MyException().makeException("Введите область\n");
        return;
    }
    image->setChanged(false);
    image->setLine(curShape.getFirstPoint(), curShape.getLastPoint());
    curShape.addPoint(curShape.getFirstPoint());
    shapes.addShape(curShape);
    curShape = MyShape();
    image->updateDisplay();
}
void MyController::clearCanvas()
{
    shapes.clean();
    image->clean();
    curShape = MyShape();
    table->clean();
    isFilling = false;
    QLabel *allTime = mainWindow->getTimeLabel();
    allTime->setText(QString(""));
}

void MyController::draw(MyPoint event)
{
    if (mainWindow->getTimeStopButton()->isChecked() == true)
    {
        printf("delay\n");
        curAlg->drawWithDelay(image, event);
    }
    else
    {
        printf("not delay\n");
        curAlg->draw(image, event);
    }
    isFilling = true;
    image->updateDisplay();
}

void MyController::drawShapes()
{
    if (!curShape.isEmpty())
    {
        endAddShape();
    }
    isDraw = true;
}
void MyController::setLabel()
{
    mainWindow->setPicture(image->getDisplay());
}

void MyController::setConnections()
{
    connect(mainWindow->drawColorButton(), SIGNAL(clicked()),this, SLOT(getDrawColor()));
    connect(mainWindow->foneColorButton(), SIGNAL(clicked()),this, SLOT(getFoneColor()));
    inputFoneColor->addObject(mainWindow->foneColorButton());
    inputDrawColor->addObject(mainWindow->drawColorButton());

    inputFoneColor->addObject(image);
    inputDrawColor->addObject(image);
    inputFoneColor->setFone(true);
    inputFoneColor->setNewColor(Qt::white);
    inputDrawColor->setNewColor(Qt::darkRed);

    connect(mainWindow->getStartAddShapeButton(), SIGNAL(clicked()), this, SLOT(startAddShape()));
    connect(mainWindow->getEndAddShapeButton(), SIGNAL(clicked()), this, SLOT(endAddShape()));
    connect(mainWindow->getClearCanvasButton(), SIGNAL(clicked()), this, SLOT(clearCanvas()));
    connect(mainWindow->getDrawButton(), SIGNAL(clicked()), this, SLOT(drawShapes()));


    connect(image->getDisplay(), SIGNAL(mouseAddPointEvent(MyPoint)), this, SLOT(addLine(MyPoint)));

}

void MyController::getFoneColor()
{
    inputFoneColor->getNewColor();
}

void MyController::getDrawColor()
{
    inputDrawColor->getNewColor();
}

void MyController::inputPoint(MyPoint event)
{

    MyPoint newpoint = event;
    if (!curShape.isEmpty())
    {
        MyPoint lastPoint = curShape.getLastPoint();
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
    if (!curShape.isEmpty())
    {
        image->setLine(newpoint, curShape.getLastPoint());
    }
    curShape.addPoint(newpoint);
    table->addPoint(newpoint);
}

void MyController::addLine(MyPoint event)
{
    if (isFilling)
    {
        return;
    }
    if (isDraw)
    {
        draw(event);
        isDraw = false;
    }
    else
    {
        inputPoint(event);
    }
    image->updateDisplay();
}

