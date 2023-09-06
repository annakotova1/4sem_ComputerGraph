#include "MyTableModel.hpp"
/*
MyTableModel::MyTableModel(QAbstractTableModel *parent) : QAbstractTableModel(parent)
{
}

void MyTableModel::addShape(MyShape newShape)
{
	const QModelIndex parent = QModelIndex(); //= createIndex(rowCount() - 1, columnCount() - 1);
	insertRows(rowCount(), newShape.getSize(),parent);
	objects.append(newShape);
}

bool MyTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
	beginInsertRows(parent, row, row + count - 1);
	endInsertRows();
	return true;
}

bool MyTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
	beginRemoveRows(parent, row, row + count - 1);
	objects.remove(row, count);
	endRemoveRows();
	return true;
}

void MyTableModel::deleteShape(MyShape oldShape)
{
	//(*points).resize(points->length() + 1);
	int s = objects.indexOf(oldShape);
	const QModelIndex parent;
	beginRemoveRows(parent, s, s);
	objects.remove(s);
	endRemoveRows();
}

void MyTableModel::clearData()
{
	const QModelIndex parent;
	beginRemoveRows(parent, 0, rowCount(parent) - 1);
	//std::cout << rowCount(parent);
	MyShape curObj;
	while (objects.length() != 0)
	{
		curObj = objects.value(objects.size() - 1);
		delete &curObj;
		objects.pop_back();
	}
	endRemoveRows();
}
int MyTableModel::rowCount(const QModelIndex &parent) const
{
	//std::cout << points->length() << std::endl;
	int size = 0;
	for (int i = 0; i < objects.size(); i++)
	{
		size += (objects.value(i)).getSize();
	}
	return objects.length();
	//если вы станете использовать скажем QList, то пишите return list.size();
}

int MyTableModel::columnCount(const QModelIndex &parent) const
{
	return 2; // количество колонок сделаем также фиксированным
}

QVariant MyTableModel::data(const QModelIndex &index, int role) const
{
	printf("start display\n");
	if (role == Qt::DisplayRole) {
		printf("displayRole\n");
		QString answer;
		int size = 0;
		MyShape curShape;
		for (int i = 0; i < objects.size(); i++)
		{
			curShape = objects.value(i);
			printf("%d, %d, %d\n", index.row(),index.column(), size,  size+(curShape.getSize()));
			if (index.row() < size+(curShape).getSize())
			{
				for (int j = 0; j < (curShape).getSize(); j++)
				{
					printf("i = %d, j = %d\n", i, j);
					if (index.row() == size + i)
					{
						if (index.column() == 0)
							answer = QString::number((curShape.getPoint(j)).getX());
						else
							answer = QString::number((curShape.getPoint(j)).getY());
						break;
						printf("i = %d, j = %d, x = %f, y = %f\n", index.row(), index.column(), curShape.getPoint(j).getX(), curShape.getPoint(j).getY());
					}
				}
				break;
			}
			size += (curShape).getSize();
		}
		return QVariant(answer);
	}
	return QVariant();
}


Qt::ItemFlags MyTableModel::flags(const QModelIndex &index) const
{
	return QAbstractTableModel::flags(index);
}
*/


MyTableModel::MyTableModel(QAbstractTableModel *parent) : QAbstractTableModel(parent)
{
}

void MyTableModel::addPoint(MyPoint newPoint)
{
	beginInsertRows(QModelIndex(), points.size(), points.size());
	points.append(newPoint);
	endInsertRows();
}
void MyTableModel::removePoint(MyPoint oldPoint)
{
	beginInsertRows(QModelIndex(), points.size(), points.size());
	points.remove(points.indexOf(oldPoint));
	endInsertRows();
}

bool MyTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
	beginInsertRows(parent, row, row + count - 1);
	points.insert(row, count, MyPoint(-1, -1));
	endInsertRows();
	return true;
}

bool MyTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
	beginRemoveRows(parent, row, row + count - 1);
	points.remove(row, count);
	endRemoveRows();
	return true;
}
int MyTableModel::rowCount(const QModelIndex &parent) const
{
	//std::cout << points->length() << std::endl;
	return points.size();
	//если вы станете использовать скажем QList, то пишите return list.size();
}

int MyTableModel::columnCount(const QModelIndex &parent) const
{
	return 2; // количество колонок сделаем также фиксированным
}

QVariant MyTableModel::data(const QModelIndex &index, int role) const
{
	if (role == Qt::DisplayRole) {
		QString answer;
		if (points.value(index.row()).getX() < 0)
			answer = QString("---");
		else if (index.column() == 0)
			answer = QString::number(points.value(index.row()).getX());
		else
			answer = QString::number(points.value(index.row()).getY());
		return QVariant(answer);
	}
	return QVariant();
}

void MyTableModel::clean()
{
	removeRows(0, points.size(), QModelIndex());
}