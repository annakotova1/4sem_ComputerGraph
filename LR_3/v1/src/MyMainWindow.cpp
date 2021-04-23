#include "../inc/MyMainWindow.hpp"

MyMainWindow::MyMainWindow(QWidget *parent) : QMainWindow(parent), 
    ui(new Ui::MainWindow()), myPicture(new MyGraphicsView())
{
    ui->setupUi(this);
    ui->graphic->addWidget(myPicture);
    create_charts();
    set_validator();
    line_menu = new MyMenu();
    spector_menu = new MyMenu();

    ui->line_algorithm->setPopupMode(QToolButton::MenuButtonPopup);
    ui->line_algorithm->setMenu(line_menu);
    ui->line_algorithm->setDefaultAction(line_menu->bresenhem_int);
    //ui->line_algorithm->setPopupMode(QToolButton::MenuButtonPopup);
    connect(ui->line_algorithm, SIGNAL(triggered()),
                     ui->line_algorithm, SLOT(setDefaultAction()));
    ui->spector_algorithm->setMenu(spector_menu);
    ui->spector_algorithm->setDefaultAction(spector_menu->bresenhem_int);
    ui->spector_algorithm->setPopupMode(QToolButton::MenuButtonPopup);
    connect(ui->spector_algorithm, SIGNAL(triggered()),
                     ui->spector_algorithm, SLOT(setDefaultAction()));
}
/*
void MyMainWindow::set_menu()
{}*/

void MyMainWindow::create_charts()
{}

void MyMainWindow::set_connections()
{}

void MyMainWindow::set_validator()
{
	myValidator = new QDoubleValidator();
	myValidator->setNotation(QDoubleValidator::StandardNotation);
	myLocale = new QLocale();
    myIntValidator = new QIntValidator();
	//QLocale::setDefault(*myLocale);
	myValidator->setLocale(*myLocale);
	
	ui->start_x->setValidator(myValidator);
	ui->start_y->setValidator(myValidator);
	ui->end_x->setValidator(myValidator);
	ui->end_y->setValidator(myValidator);
	ui->spector_center_x->setValidator(myValidator);
	ui->spector_center_y->setValidator(myValidator);
	ui->spector_line_lenght->setValidator(myIntValidator);
	ui->spector_lines_amount->setValidator(myIntValidator);
}

MyMainWindow::~MyMainWindow()
{
    delete ui;
    delete myPicture;
    delete histogram;
    delete plot;
}

void MyMainWindow::slotLine()
{
    //qreal start_x = myLocal->toDouble(ui->start_x);
    //qreal start_y = myLocal->ui->start_y);
    //myPicture->draw_line();
}
void MyMainWindow::slotSpector()
{}
void MyMainWindow::slotHistogram()
{}
void MyMainWindow::slotPlot()
{}