#include "../inc/MyMainWindow.hpp"

MyMainWindow::MyMainWindow(QMainWindow *parent): QMainWindow(parent), 
    myPicture(new MyGraphicsView()), myPainter(new MyAlgorithms()),
    ui(new Ui::MainWindow()), myLocale(new MyLocale())
{
    ui->setupUi(this);
    ui->graphic->addWidget(myPicture);
}

MyMainWindow::~MyMainWindow()
{

    delete myPainter;
    delete myPicture;
}

void MyMainWindow::setValidator()
{
	ui->spector_line_lenght->setValidator(myLocale->getIntValidator());
	ui->spector_lines_amount->setValidator(myLocale->getIntValidator());

	ui->start_x->setValidator(myLocale->getDoubleValidator());
	ui->start_y->setValidator(myLocale->getDoubleValidator());
	ui->end_x->setValidator(myLocale->getDoubleValidator());
	ui->end_y->setValidator(myLocale->getDoubleValidator());
	ui->spector_center_x->setValidator(myLocale->getDoubleValidator());
	ui->spector_center_y->setValidator(myLocale->getDoubleValidator());
}

