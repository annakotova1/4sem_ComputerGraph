#include "MyMainWindow.hpp"

MyMainWindow::MyMainWindow(QMainWindow *parent): QMainWindow(parent), 
    ui(new Ui::MainWindow())
{
    FoneColorButton = new MyPushButton();
    DrawColorButton = new MyPushButton();
    ui->setupUi(this);
    setDrawButton();
    setFoneButton();
}

MyMainWindow::~MyMainWindow()
{
    delete FoneColorButton;
    delete DrawColorButton;
    delete ui;
}
QRadioButton *MyMainWindow::getTimeStopButton()
{
    return ui->TimeStop;
}
QPushButton *MyMainWindow::getStartAddShapeButton()
{
    return ui->startAddShape;
}
QPushButton *MyMainWindow::getEndAddShapeButton()
{
    return ui->endAddShape;
}
QPushButton *MyMainWindow::getClearCanvasButton()
{
    return ui->clearCanvas;
}
QPushButton *MyMainWindow::getDrawButton()
{
    return ui->drawExistShapes;
}

MyPushButton *MyMainWindow::foneColorButton()
{
    return FoneColorButton;
}
MyPushButton *MyMainWindow::drawColorButton()
{
    return DrawColorButton;
}

void MyMainWindow::setPicture(MyLabel *canvas)
{
    ui->canvasPlace->addWidget(canvas);
}
void MyMainWindow::setFoneButton()
{
    ui->FoneColorLayout->addWidget(FoneColorButton);
}
void MyMainWindow::setDrawButton()
{
    ui->drawColorLayout->addWidget(DrawColorButton);
}
void MyMainWindow::setTable(MyTableModel *model)
{
    ui->table->setModel(model);
}
QLabel *MyMainWindow::getTimeLabel()
{
    return ui->timeLabel;
}
