#ifndef MYHISTOGRAM_HPP
#define MYHISTOGRAM_HPP

#include <QChart>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QDialog>
#include <QGridLayout>


#include "../MyPoint/MyPoint.hpp"

using namespace QtCharts;

class MyHistogramView : public QChartView
{
    Q_OBJECT
    QVector<QBarSet *> sets;
    QBarSeries *series;
    QChart *chart;
    QBarCategoryAxis *axisX;

    void deleteSets();
    void deleteSeries();

    void setAxis(QStringList categories);
    void setDefaultSettings();
    void updateView();
public:
    explicit MyHistogramView(QWidget *parent = nullptr);
    ~MyHistogramView();
    void setSets(QVector<QBarSet *>sets);
    void drawHistogram(QVector<QBarSet *>sets, QStringList categories, QString plotName);
    void addWindow(QString string = tr("Временные характеристики"));
};

#endif