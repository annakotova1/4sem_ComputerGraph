#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>

#include "MyPoint.hpp"
#include "MyGraphicsItemGroup.hpp"
#include "Algorithms.hpp"

class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    MyGraphicsView(QWidget *parent = 0);
    ~MyGraphicsView(){};
    void draw_line(MyPoint start, MyPoint end, int algorithm);
private:

    MyGraphicsItemGroup *grid;
    MyGraphicsItemGroup *lines;
    MyGraphicsItemGroup *spectors;

    QGraphicsScene *scene;
    QTimer *timer;

private:    
    void start_configuration();
    void start_timer();
    void start_groups();

    void draw_grid();
    void delete_group(MyGraphicsItemGroup *group);

    void resizeEvent(QResizeEvent *event);

public slots:
    void slotAlarmTimer();
};

#endif