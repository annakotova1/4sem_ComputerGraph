#include "MyMainWindow.hpp"

MyMainWindow::MyMainWindow(QMainWindow *parent): QMainWindow(parent), 
    ui(new Ui::MainWindow())
{
    //FoneColorButton = new MyPushButton();
    LineColorButton = new MyPushButton();
    CatLineColorButton = new MyPushButton();
    CatterColorButton = new MyPushButton();
    ui->setupUi(this);
    setColorButtons();
}

MyMainWindow::~MyMainWindow()
{
    //delete FoneColorButton;
    delete LineColorButton;
    delete CatLineColorButton;
    delete CatterColorButton;
    delete ui;
}
/*
QRadioButton *MyMainWindow::getTimeStopButton()
{
    return ui->TimeStop;
}*/
QPushButton *MyMainWindow::getEndAddShapeButton()
{
    return ui->endAddShape;
}
QPushButton *MyMainWindow::getClearCanvasButton()
{
    return ui->clearCanvas;
}
/*
QPushButton *MyMainWindow::getDrawButton()
{
    return ui->drawExistShapes;
}*/
/*
MyPushButton *MyMainWindow::foneColorButton()
{
    return FoneColorButton;
}*/
MyPushButton *MyMainWindow::catterColorButton()
{
    return CatterColorButton;
}
MyPushButton *MyMainWindow::lineColorButton()
{
    return LineColorButton;
}
MyPushButton *MyMainWindow::catLineColorButton()
{
    return CatLineColorButton;
}

void MyMainWindow::setPicture(MyLabel *canvas)
{
    ui->canvasPlace->addWidget(canvas);
}

void MyMainWindow::setColorButtons()
{
    //ui->FoneColorLayout->addWidget(FoneColorButton);
    ui->LineColorButton->addWidget(LineColorButton);
    ui->CatterColorLayout->addWidget(CatterColorButton);
    ui->CatLineColorButton->addWidget(CatLineColorButton);
}/*
void MyMainWindow::setTable(MyTableModel *model)
{
    ui->table->setModel(model);
}*/