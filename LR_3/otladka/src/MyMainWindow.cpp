#include "../inc/MyMainWindow.hpp"

MyMainWindow::MyMainWindow(QMainWindow *parent): QMainWindow(parent), myPlot(new MyPlot())
    //myPicture(new MyGraphicsView()), myPainter(new MyAlgorithms()),
    //ui(new Ui::MainWindow()), myLocale(new MyLocale())
{
    //ui->setupUi(this);
    //ui->graphic->addWidget(myPicture);
}

MyMainWindow::~MyMainWindow()
{
}

