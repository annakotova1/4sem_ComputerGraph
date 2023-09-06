#include "mainwindow.h"
 
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
 
    /* Инициализируем виджет с графикой */
    //myPicture   = new MyGraphicView();
    /* и добавляем его на слой */
    //ui->gridLayout->addWidget(myPicture);

    MyTableModel *myModel = new MyTableModel();
    ui->tableView->setModel((QAbstractItemModel *)myModel);
}
 
MainWindow::~MainWindow()
{
    delete ui;
}