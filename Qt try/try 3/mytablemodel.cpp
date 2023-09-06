#include "mytablemodel.h"

int MyTableModel::rowCount(const QModelIndex &parent) const
{
    return 5; // сделаем фиксированно 5 строк в таблице
    //если вы станете использовать скажем QList, то пишите return list.size();
}
int MyTableModel::columnCount(const QModelIndex &parent) const
{
    return 4; // количество колонок сделаем также фиксированным
}
QVariant MyTableModel::data(const QModelIndex &index, int role) const
{

    if (role == Qt::DisplayRole) {
        QString unswer = QString("row = ") + QString::number(index.row()) + "  col = " + QString::number(index.column());
        // строкой выше мы формируем ответ. QString::number преобразует число в текст
        return QVariant(unswer);
    }
    return QVariant();
}