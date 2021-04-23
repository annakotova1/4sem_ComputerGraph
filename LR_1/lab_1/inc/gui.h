#ifndef GUI_H
#define GUI_H

#include <QFileDialog>
#include <QPushButton>
#include <QMainWindow>
#include <QWidget>
#include <iostream>

#include "main_window v1.h"

#include <QMainWindow>
#include "draw.h"
 
namespace Ui {
class MainWindow;
}
 
class MainWindow : public QMainWindow
{
    Q_OBJECT
 
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
 
private:
    Ui::MainWindow  *ui;
    MyGraphicView   *myPicture;     // Наш кастомный виджет
};

/*
class MyClass : public QWidget
{

	Q_OBJECT
	
public slots:

    void print()
    {
        std::cout << "Yes!" << std::endl;
    };
};
*/
#endif