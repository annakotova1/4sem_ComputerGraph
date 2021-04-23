#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include "ui_mainwindow.h" //включить файл сгенеренный QtDesiner
#include "MyTableModel.h"
#include "MyGraphicView.h"
#include <QMainWindow>
#include <QWidget>
#include <QFileDialog>

class MyMainWindow : public QMainWindow
{
public:
	explicit MyMainWindow(QWidget *parent = 0);
	~MyMainWindow();
    void makeLegend(MyPoint &a, MyPoint &b, MyPoint &c, MyPoint &d, MyPoint &e);
private:
	Ui::MainWindow *ui; // Сгенеренный QtDesiner класс, описывающий внешность нашего окна (кастомайзер)
	// Указатели на наши виджеты
	MyTableModel *myModel;
	MyGraphicView *myPicture;
    void keyPressEvent(QKeyEvent *event) 
    {
    	const QModelIndex parent;
    	int row = ui->tableView->currentIndex().row();
        if (row < 0 && event->key() == Qt::Key_Insert)
            row = 0;
    	if (row < 0)
    	{
    		return;
    	}
        switch(event->key()) {
        case Qt::Key_Delete: {
            myModel->removeRows(row, 1, parent);
            break;
        }
        case Qt::Key_Insert: {
            myModel->insertRows(row, 1, parent);
            break;
        }
        //default: keyPressEvent(event);
        }
    }
	QVector<MyPoint> *points;

Q_OBJECT

public slots:
	//void slotAddTableChanges();
	void slotDownloadPoints();
	void slotSavePoints();

	//void slotAddPointInTable();
	//void slotDelPointInTable();
    void slotUpdate();
//signals:
//    void mysignal(int i, int j);
};

#endif