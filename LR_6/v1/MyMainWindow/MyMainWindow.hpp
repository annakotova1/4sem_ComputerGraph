#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QRadioButton>
#include <QVBoxLayout>
#include "ui_main_window_ui.h"
#include "../MyPushButton/MyPushButton.hpp"
#include "../MyTableModel/MyTableModel.hpp"
#include "../MyLabel/MyLabel.hpp"

class MyMainWindow : public QMainWindow
{
private:
    Ui::MainWindow *ui;

    MyPushButton *FoneColorButton;
    MyPushButton *DrawColorButton;

    void setValidator();
    void setSplitters();
    void addWidgets();
    void constractWidgets();
    void setConnects();
public:
    explicit MyMainWindow(QMainWindow *parent = 0);
    ~MyMainWindow();

    QRadioButton *getTimeStopButton();
    QPushButton *getStartAddShapeButton();
    QPushButton *getEndAddShapeButton();
    QPushButton *getClearCanvasButton();
    QPushButton *getDrawButton();

    MyPushButton *foneColorButton();
    MyPushButton *drawColorButton();

    void setPicture(MyLabel *canvas);
    void setFoneButton();
    void setDrawButton();

    void setTable(MyTableModel *model);
    QLabel *getTimeLabel();
};

#endif