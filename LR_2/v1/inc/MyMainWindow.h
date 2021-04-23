#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include "mainwindow_ui.h" //включить файл сгенеренный QtDesiner

#include "MyGraphicsView.h"

#include <QMainWindow>

class MyMainWindow : public QMainWindow
{
public:
	explicit MyMainWindow(QWidget *arent = 0);
	~MyMainWindow();
private:
	Ui::MainWindow *ui; // Сгенеренный QtDesiner класс, описывающий внешность нашего окна (кастомайзер)
	MyGraphicsView *myPicture;
};

#endif
