#include "MyHistogramView.hpp"

MyHistogramView::MyHistogramView(QWidget *parent) : QChartView(parent), series(new QBarSeries()), chart(new QChart(nullptr,  Qt::WindowFlags())), axisX(new QBarCategoryAxis())
{
    setChart(chart);
}

MyHistogramView::~MyHistogramView()
{
    deleteSeries();
}
void MyHistogramView::setDefaultSettings()
{    
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    //legend()->hide();
    chart->setTitle("Simple histogram chart example");   
}

void MyHistogramView::deleteSets()
{
    for (int i = 0; i < sets.size(); i++)
    {
        delete sets[i];
    }
    sets.clear();
}

void MyHistogramView::deleteSeries()
{
    deleteSets();
    series->clear();
}

void MyHistogramView::updateView()
{
    setChart(chart);
}

void MyHistogramView::setSets(QVector<QBarSet *>sets)
{
    series->clear();
    this->sets = sets;
    for (int i = 0; i < sets.size();i++)
    {
        series->append(sets[i]);
    }
}

void MyHistogramView::drawHistogram(QVector<QBarSet *>sets, QStringList categories, QString plotName)
{
    setSets(sets);
    setAxis(categories);
    chart->addSeries(series);
    chart->setTitle(plotName);  
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->createDefaultAxes();
    updateView();
}

void MyHistogramView::setAxis(QStringList categories)
{
    chart->removeAxis(axisX);
    axisX->clear();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
}

void MyHistogramView::addWindow(QString string)
{
    QDialog *d = new QDialog();
    
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(this);
    d->setLayout(mainLayout);

    d->setWindowTitle(string);
    d->show();
}