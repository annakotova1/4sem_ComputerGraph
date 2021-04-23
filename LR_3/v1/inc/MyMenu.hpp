#ifndef MYMENU_HPP
#define MYMENU_HPP

#include <QMenu>

class MyMenu : public QMenu
{
public:
    QAction *bresenhem_int;
    QAction *bresenhem_float;
    QAction *bresenhem_smooth;
    QAction *vy;
    QAction *cda;
    QAction *lib;
    void makeActions();
public:
    //getDefault
    MyMenu();
    ~MyMenu();
};

#endif