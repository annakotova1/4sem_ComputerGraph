#ifndef MYPLOT_H
#define MYPLOT_H

#include <QChart>
#include <QChartView>
#include <QLineSeries>

using namespace QtCharts;

class MyPlot : public QChart
{
    Q_OBJECT
    QLineSeries *series;// = new QLineSeries();
    QChartView *view;
public:
    explicit MyPlot(QGraphicsItem *parent = nullptr, Qt::WindowFlags wFlags = Qt::WindowFlags());
    ~MyPlot();
    void clear();
    void makeSeries();
    void updateView();
};

#endif