#include "../inc/MyMenu.hpp"

MyMenu::MyMenu()
{
    makeActions();
    this->addAction(bresenhem_int);
    this->addAction(bresenhem_float);
    this->addAction(bresenhem_smooth);
    this->addAction(lib);
    this->addAction(vy);
    this->addAction(cda);
}

void MyMenu::makeActions()
{
    bresenhem_int = new QAction(QString("Брезенхем (int)"));
    bresenhem_float = new QAction(QString("Брезенхем (float)"));
    bresenhem_smooth = new QAction(QString("Брезенхем (сглаживание)"));
    vy = new QAction(QString("Ву"));
    cda = new QAction(QString("ЦДА"));
    lib = new QAction(QString("Библиотечная функция"));
}

MyMenu::~MyMenu()
{
    delete bresenhem_int;
    delete bresenhem_float;
    delete bresenhem_smooth;
    delete vy;
    delete cda;
    delete lib;
}