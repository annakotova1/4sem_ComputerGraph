#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>

#include "MyPoint.hpp"
#include "MyGrid.hpp"
#include "MyAlgorithms.hpp"
#include "MyGraphicsItemGroup.hpp"

class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT

private:
    MyGraphicsItemGroup *lines;
    MyGraphicsItemGroup *spectors;
    QGraphicsScene *scene;
    QTimer *timer;

    MyGrid *grid;

    void prepeare_configuration();
    void prepeare_timer();
    void prepeare_groups();

protected:
    void resizeEvent(QResizeEvent *event);

public:
    void drawGrid();
    //void drawLine(MyPoint start, MyPoint end, int algorithm);


    explicit MyGraphicsView(QGraphicsView *parent = 0);
    ~MyGraphicsView();

public slots:
    void slotAlarmTimer();
/*    void slotBresenhemInt();
    void slotBresenhemFloat();
    void slotBresenhemSmooth();
    void slotVy();
    void slotCDA();
    void slotLibrary();*/
};

#endif