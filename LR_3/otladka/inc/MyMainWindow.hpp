#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include "MyPlot.hpp"

class MyMainWindow : public QMainWindow
{
private:
    MyPlot *myPlot;
public:
    explicit MyMainWindow(QMainWindow *parent = 0);
    ~MyMainWindow();
    void setValidator();
    
};

#endif