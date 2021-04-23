#ifndef MY_MAIN_WINDOW_H
#define MY_MAIN_WINDOW_H

#include "ui_main_window v1.h"
#include "MyGraphicView.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MyMainWindow : public QMainWindow
{
public:
    explicit MyMainWindow(QWidget *parent = 0);
    ~MyMainWindow();
 
private:
    Ui::MainWindow  *ui;
    MyGraphicView   *myPicture;     // Наш кастомный виджет
};

#endif