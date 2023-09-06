#ifndef MYTABLEMODEL_H
#define MYTABLEMODEL_H

#include "QModelIndex"
#include "QVariant"

class MyTableModel: QAbstractTableModel
{
private:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
};
#endif