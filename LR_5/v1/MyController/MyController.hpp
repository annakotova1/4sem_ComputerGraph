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

class MyController : QObject
{
Q_OBJECT
private:
    MyContainer shapes;
    MyMainWindow *mainWindow;
    MyAlgorithm *curAlg;

    MyColorInput *inputDrawColor;
    MyColorInput *inputFoneColor;

    //MyLabel *picture;
    MyImage *image;

    MyShape curShape;

    MyTableModel *table;

    bool isFilling = false;

    void setConnections();
    void setLabel();
public:
    MyController(MyMainWindow *main);
    ~MyController();

public slots:
    void addLine(MyPoint event);

    void startAddShape();
    void endAddShape();
    void drawShapes();
    void clearCanvas();

    void getFoneColor();
    void getDrawColor();

};

#endif