#ifndef MYCONTROLLER_HPP
#define MYCONTROLLER_HPP

#include <cmath>
#include <time.h>
#include <QPicture>
#include <QPixmap>
#include <QApplication>
#include <QtGlobal>
#include "../MyAlgorithms/MyAlgorithmShotEdges.hpp"
#include "../MyMainWindow/MyMainWindow.hpp"
#include "../MyColorInput/MyColorInput.hpp"
#include "../MyContainerShape/MyContainerShape.hpp"
#include "../MyTableModel/MyTableModel.hpp"
#include "../MyImage/MyImage.hpp"
#include "../MyLine/MyLine.hpp"

class MyController : QObject
{
Q_OBJECT
private:
    MyMainWindow *mainWindow;
    MyAlgorithmShortedEdges *curAlg;

    //MyColorInput *inputFoneColor;
    MyColorInput *inputLineColor;
    MyColorInput *inputCatterColor;
    MyColorInput *inputCatLineColor;

    //bool isLine = false;
    bool isCatter = true;
    bool isShape = true;

    MyImage *image;
    
    MyShape Catter;
    MyShape Shape;

    void setConnections();
    void setLabel();
public:
    MyController(MyMainWindow *main);
    ~MyController();

public slots:
    void addLine(MyPoint event);

//    void startAddShape();
    void endAddCatter();
    void endAddShape();
//    void drawShapes();
    void clearCanvas();

    //void getFoneColor();
    void getLineColor();
    void getCatterColor();
    void getCatLineColor();

    //void draw(MyPoint event);

    void addShapePoint(MyPoint event);
    void addCatterPoint(MyPoint event);
};

#endif