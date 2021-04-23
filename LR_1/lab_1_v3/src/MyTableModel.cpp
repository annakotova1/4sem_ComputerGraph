#include "../inc/MyTableModel.h"

MyTableModel::MyTableModel(QAbstractTableModel *parent) : QAbstractTableModel(parent)
{
	points = new QVector<MyPoint>();
}

void MyTableModel::addPoint(MyPoint a)
{
	const QModelIndex parent;
	beginInsertRows(parent, rowCount(parent), rowCount(parent));
	(*points).append(a);
	endInsertRows();

	//(*points).resize(points->length() + 1);
	//insertRows(rowCount(), 1);
}

bool MyTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
	beginInsertRows(parent, row, row + count - 1);
	MyPoint a = MyPoint(0, 0);
	(*points).insert(row, a);
	endInsertRows();
	return true;
}

bool MyTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
	beginRemoveRows(parent, row, row + count - 1);
	points->remove(row, count);
	endRemoveRows();
	return true;
}

void MyTableModel::deletePoint(MyPoint a)
{
	//(*points).resize(points->length() + 1);
	const MyPoint b = a;
	int s = points->indexOf(b);
	const QModelIndex parent;
	beginRemoveRows(parent, s, s);
	points->remove(s);
	endRemoveRows();
}

void MyTableModel::clearData()
{
	const QModelIndex parent;
	beginRemoveRows(parent, 0, rowCount(parent) - 1);
	//std::cout << rowCount(parent);
	while (points->length() != 0)
	{
		points->pop_back();
	}
	endRemoveRows();
}
int MyTableModel::rowCount(const QModelIndex &parent) const
{
	//std::cout << points->length() << std::endl;
	return points->length(); // сделаем фиксированно 5 строк в таблице
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
		if (index.column() == 0)
			answer = QString::number((points->value(index.row()).x));
		else
			answer = QString::number((points->value(index.row()).y));
		return QVariant(answer);
	}
	return QVariant();
}

bool MyTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if (role == Qt::EditRole) {
		QString answer;
		bool ok;
		qreal ans = value.toReal(&ok);

		if (!ok)
			return false;
		MyPoint &p = (*points)[index.row()];//->value(index.row());
		if (index.column() == 0)
			p.x = ans;
		else
			p.y = ans;
		//emit tableChanged();
	}
	return true;
}

int MyTableModel::readPoint(std::ifstream &file, MyPoint &a)
{
	a.x = 0;
	a.y = 0;
	file >> a.x;
	file >> a.y;
	if (file.fail())
		return ERR_FILE;
	return OK;
}

int MyTableModel::readFile(QString filename)
{
	MyPoint a;
	std::ifstream file (filename.toStdString());
	//clearData();
	if (!file)
		return ERR_NO_FILE;
	int rc = OK;
	while (rc == OK)
	{
		rc = readPoint(file, a);
		if (rc == OK)
		{
			addPoint(a);
			std::cout << "a " << a.x << " " << a.y << std::endl;
		}
	}
	if (file.eof())
		return OK;
	file.close();
	//if (rc != OK)
	//	return rc;
	//std::cout << std::endl << "a " << a.x << " " << a.y << std::endl;
	return ERR_FILE;
}
int MyTableModel::writePoint(std::ofstream &file, MyPoint &a)
{
	file << a.x << " ";
	file << a.y;
	file << std::endl;
	if (file.fail())
		return ERR_FILE;
	return OK;
}

int MyTableModel::writeInFile(QString filename)
{
	std::ofstream file (filename.toStdString());
	if (!file)
		return ERR_NO_FILE;
	int i = 0;
	MyPoint a = points->value(i);
	while (i < points->length())
	{
		writePoint(file, a);
		i++;
	}
	if (file.eof())
		return OK;
	file.close();
	//if (rc != OK)
	//	return rc;
	//std::cout << std::endl << "a " << a.x << " " << a.y << std::endl;
	return ERR_FILE;
}

bool MyTableModel::solveData(MyPoint &a, MyPoint &b, MyPoint &c, MyPoint &bb, MyPoint &hb)
{
	qreal angle = 0, max_angle = 0;
	MyPoint _a, _b, _c;
	bool solveExist = false;
	//std::cout << "points->length " << points->length() << std::endl;
	for (int i = 0; i < points->length(); i++)
	{
		_a = points->value(i);
		for (int j = i + 1; j < points->length(); j++)
		{
			_b = points->value(j);
			for (int k = j + 1; k < points->length(); k++)
			{
				std::cout << "start" << std::endl;
				_c = points->value(k);
				if (!check_triag_exist(_a, _b, _c))
					continue;
				angle = solve_problem_for_treag(_a, _b, _c);
				//std::cout << "a " << _a.x << " " << _a.y << std::endl;
				//std::cout << "b " << _b.x << " " << _b.y << std::endl;
				//std::cout << "c " << _c.x << " " << _c.y << std::endl;
				//std::cout << "angle " << angle << std::endl << std::endl;
				if (angle > max_angle)
				{
					max_angle = angle;
					get_height_base(_a, _b, _c, hb);
					get_bisector_base(_a, _b, _c, bb);
					a = _a;
					b = _b;
					c = _c;
					solveExist = true;
				}
			}
		}
	}
	std::cout << solveExist << std::endl;
	return solveExist;
}

Qt::ItemFlags MyTableModel::flags(const QModelIndex &index) const
{
	return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}