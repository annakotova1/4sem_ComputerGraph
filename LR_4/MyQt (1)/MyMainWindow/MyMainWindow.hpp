#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QRadioButton>
#include "../MyPlotView/MyPlotView.hpp"
#include "../MyHistogramView/MyHistogramView.hpp"
#include <QVBoxLayout>
#include "ui_main_window_ui.h"
#include "../MyPushButton/MyPushButton.hpp"
#include "../MyGraphicsView/MyGraphicsView.hpp"
#include "../MyToolButton/MyToolButton.hpp"
#include "../MyLocale/MyLocale.hpp"

#include "../MyChecker/MyChecker.hpp"

class MyMainWindow : public QMainWindow
{
Q_OBJECT
public slots:
    void clearCanvas();
private:
    Ui::MainWindow *ui;

    MyChecker *check;


    MyPushButton *CircleColorButton;
    MyPushButton *EllipseColorButton;
    MyPushButton *ManyCirclesColorButton;
    MyPushButton *ManyEllipsesColorButton;

    MyToolButton *CircleAlgorithmsButton;
    MyToolButton *EllipseAlgorithmsButton;
    MyToolButton *ManyCirclesAlgorithmsButton;
    MyToolButton *ManyEllipsesAlgorithmsButton;

    MyGraphicsView *graphicsCanvas;
    MyLocale *locale;

    void setValidator();
    void setSplitters();
    void addWidgets();
    void constractWidgets();
    void setConnects();
public:
    explicit MyMainWindow(QMainWindow *parent = 0);
    ~MyMainWindow();

    void setToolButtons(QVector<QString> names);

    MyGraphicsView *getCanvas();


    //void setCircleAlgorithmButton(QVector<QString> names);
    MyPushButton *getCircleColorButton();
    QPushButton *getCircleDrawButton();
    MyToolButton *getCircleAlgorithmsButton();
    QVector<MyPoint> getCircleData();


    //void setEllipsesAlgorithmButton(QVector<QString> names);
    QVector<MyPoint> getEllipseData();
    MyPushButton *getEllipseColorButton();
    QPushButton *getEllipseDrawButton();
    MyToolButton *getEllipseAlgorithmsButton();


    //void setManyCirclesAlgorithmButton(QVector<QString> names);
    QVector<MyPoint> *getManyCirclesData();
    MyPushButton *getManyCirclesColorButton();
    QPushButton *getManyCirclesDrawButton();
    MyToolButton *getManyCirclesAlgorithmsButton();


    //void setManyEllipsesAlgorithmButton(QVector<QString> names);
    QVector<MyPoint> *getManyEllipsesData();
    MyPushButton *getManyEllipsesColorButton();
    QPushButton *getManyEllipsesDrawButton();
    MyToolButton *getManyEllipsesAlgorithmsButton();


    QRadioButton *getGridButton();

    void addHistogram(MyHistogramView *histogram);
    QPushButton *getCircleHistogramDrawButton();
    QPushButton *getEllipseHistogramDrawButton();
};

#endif