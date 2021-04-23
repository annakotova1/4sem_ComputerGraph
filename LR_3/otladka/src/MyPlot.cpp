#include "../inc/MyPlot.hpp"

MyPlot::MyPlot(QGraphicsItem *parent, Qt::WindowFlags wFlags) : QChart(parent, wFlags), series(new QLineSeries()), view(new QChartView())
{
}

MyPlot::clear()
{}