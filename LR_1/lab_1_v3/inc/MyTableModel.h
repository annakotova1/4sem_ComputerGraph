#ifndef MYTABLEMODEL_H
#define MYTABLEMODEL_H

#include <QModelIndex>
#include <QVariant>
#include <QVector>
#include "MyPoint.h"
#include "calculate.h"

#define OK 0
#define ERR_FILE 1
#define ERR_NO_FILE 2

#include <iostream>
#include <fstream>
#include <cmath>

#include <QKeyEvent>
/*
typedef struct vector_t vector_t;
typedef double angle_t;
struct vector_t
{
	qreal x;
	qreal y;
};
*/
class MyTableModel : public QAbstractTableModel
{
//	Q_OBJECT
public:
	MyTableModel(QAbstractTableModel *parent = 0);
	void addPoint(MyPoint a);
	void deletePoint(MyPoint a);
	int readFile(QString filename);
	int writeInFile(QString filename);
	void clearData();
	bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
	bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());
	bool solveData(MyPoint &a, MyPoint &b, MyPoint &c, MyPoint &bb, MyPoint &hb);
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
//signals:
//	void tableChanged();



	int rowCount(const QModelIndex &parent) const;
	int columnCount(const QModelIndex &parent) const;
private:/*
    void keyPressEvent(QKeyEvent *event) {
    	const QModelIndex parent;
        switch(event->key()) {
        case Qt::Key_Delete: {
            removeRows(currentIndex().row(), 1, parent)
            break;
        }
        case Qt::Key_Insert: {
            insertRows(currentIndex().row(), 1, parent)
            break;
        }
        default: QTableView::keyPressEvent(event);
        }
    }*/
	QVector<MyPoint> *points;
	
private:
	QVariant data(const QModelIndex &index, int role) const;
	QVariant getColorForRow(const QModelIndex &index, int role) const;

	int readPoint(std::ifstream &file, MyPoint &a);
	int writePoint(std::ofstream &file, MyPoint &a);

	Qt::ItemFlags flags(const QModelIndex &index) const;
	//qreal get_cut_len(MyPoint a, MyPoint b);
	//qreal get_angle_treag_by_points(MyPoint a, MyPoint b, MyPoint c);
	//void get_vector(MyPoint a, MyPoint b, vector_t *ab);
	//bool check_triag_exist(MyPoint a, MyPoint b, MyPoint c);
	//MyPoint get_height_base(MyPoint a, MyPoint b, MyPoint c);
	//MyPoint get_bisector_base(MyPoint a, MyPoint b, MyPoint c);
	//qreal solve_treag(MyPoint a, MyPoint b, MyPoint c);
};

#endif