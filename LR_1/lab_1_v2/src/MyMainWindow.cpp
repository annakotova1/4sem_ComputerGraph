#include "../inc/MyMainWindow.h"


MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
 
    /* Инициализируем виджет с графикой */
    myPicture   = new MyGraphicView();
    //ui->tableView->setHorizontalHeader();
    /* и добавляем его на слой */
    ui->graphic->addWidget(myPicture);
}
 
MyMainWindow::~MyMainWindow()
{
    delete ui;
}