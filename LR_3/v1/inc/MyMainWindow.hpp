#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include "MyGraphicsView.hpp"
#include "QMainWindow"
#include "ui_main_window_ui.h"
#include "MyMenu.hpp"

#include "QtCharts"

class MyMainWindow : public QMainWindow
{
Q_OBJECT
public:
    explicit MyMainWindow(QWidget *parent = 0);
    ~MyMainWindow();
private:
    MyMenu *line_menu;
    MyMenu *spector_menu;
    
    QLocale *myLocale;
    QDoubleValidator *myValidator;
    QIntValidator *myIntValidator;

    QtCharts::QChart *histogram;
    QtCharts::QChart *plot;
    Ui::MainWindow *ui;
    MyGraphicsView *myPicture;
    void create_charts();
    void set_connections();
    void set_validator();
public slots:
    void slotLine();
    void slotSpector();
    void slotHistogram();
    void slotPlot();
};

#endif