#include "../inc/MyMainWindow.h"

MyMainWindow::MyMainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
//                         В header'e мы задали parent = 0 по умолчанию
//                                            Вызываем конструктор родителя (он инициализирует свойства родителя)
//                                                                 инициализируем переменную ui как укаатель на объект Ui::MainWindow
{
	ui->setupUi(this); // ui содает виджеты на нашем окне
	myPicture = new MyGraphicsView();
	ui->verticalLayout->addWidget(myPicture);
	// Инициализируем все наши виджеты
}

MyMainWindow::~MyMainWindow()
{
	delete ui;
	delete myPicture;
	// Удаляем все наши виджеты
}
