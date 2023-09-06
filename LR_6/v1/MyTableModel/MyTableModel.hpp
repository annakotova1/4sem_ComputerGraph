#ifndef MYTABLEMODEL_HPP
#define MYTABLEMODEL_HPP

#include <QModelIndex>
#include <QVariant>
#include <QVector>
#include "../MyPoint/MyPoint.hpp"
#include "../MyShape/MyShape.hpp"

#include <QKeyEvent>

class MyTableModel : public QAbstractTableModel
{
	/*
public:
	MyTableModel(QAbstractTableModel *parent = 0);
	void addShape(MyShape a);
	void deleteShape(MyShape a);
	void clearData();
	bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
	bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());

	int rowCount(const QModelIndex &parent =  QModelIndex()) const;
	int columnCount(const QModelIndex &parent =  QModelIndex()) const;
private:
	QVector<MyShape> objects;
	QVector<MyPoint> *point;
	
protected:
	QVariant data(const QModelIndex &index, int role) const;
	QVariant getColorForRow(const QModelIndex &index, int role) const;

	Qt::ItemFlags flags(const QModelIndex &index) const;
	*/
private:
	QVector<MyPoint> points;
public:
	MyTableModel(QAbstractTableModel *parent = 0);

	void addPoint(MyPoint newPoint);
	void removePoint(MyPoint oldPoint);
	
	bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
	bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());


	int rowCount(const QModelIndex &parent) const;
	int columnCount(const QModelIndex &parent) const;

    void clean();

protected:
	QVariant data(const QModelIndex &index, int role) const;

};

#endif