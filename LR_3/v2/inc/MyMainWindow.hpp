#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include "ui_main_window_ui.h"
#include "MyAlgorithms.hpp"
#include "MyGraphicsView.hpp"
#include "MyLocale.hpp"

class MyMainWindow : public QMainWindow
{
private:
    MyLocale *myLocale;
    MyAlgorithms *myPainter;
    MyGraphicsView *myPicture;
    Ui::MainWindow *ui;
public:
    explicit MyMainWindow(QMainWindow *parent = 0);
    ~MyMainWindow();
    void setValidator();
    
};

#endif