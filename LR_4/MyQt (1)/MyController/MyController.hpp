#ifndef MYCONTROLLER_HPP
#define MYCONTROLLER_HPP

#include "../MyMainWindow/MyMainWindow.hpp"
#include "../MyAlgorithms/MyAlgorithmsCircle.hpp"
#include "../MyAlgorithms/MyAlgorithmsEllipse.hpp"
#include "../MyColorInput/MyColorInput.hpp"

class MyController : QObject
{
Q_OBJECT
private:
    MyMainWindow *mainWindow;
    MyAlgorithmsCircle *myCircleAlgorithms;
    MyAlgorithmsEllipse *myEllipseAlgorithms;
    MyPlotView *plot1;
    MyPlotView *plot2;

    MyColorInput *inputCircleColor;
    MyColorInput *inputManyCirclesColor;
    MyColorInput *inputEllipseColor;
    MyColorInput *inputManyEllipsesColor;

    QRadioButton *gridButton;
    
    QVector<QVector<MyPoint>> makePlotPoints();    
    QStringList makeHistogramNames();
    QVector<QVector<MyPoint>> makeCircleHistogramData();
    QVector<QVector<MyPoint>> makeEllipseHistogramData();
public:
    MyController(MyMainWindow *main);
    QVector<QString> makeNames();
    QVector<QString> makeToolNames();

public slots:
    void getCircleColor();
    void drawCircle();

    void getManyCirclesColor();
    void drawManyCircles();

    void getEllipseColor();
    void drawEllipse();

    void getManyEllipsesColor();
    void drawManyEllipses();
    
    void drawCircleHistogram(); 
    void drawEllipseHistogram();  
    void drawGrid();
};

#endif