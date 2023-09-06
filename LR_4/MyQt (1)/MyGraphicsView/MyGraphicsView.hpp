#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>

#include "../MyPoint/MyPoint.hpp"
#include "../MyGrid/MyGrid.hpp"
#include "../MyGraphicsItemGroup/MyGraphicsItemGroup.hpp"

class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT

private:
    MyGraphicsItemGroup *circle;
    MyGraphicsItemGroup *manyCircles;
    MyGraphicsItemGroup *ellipse;
    MyGraphicsItemGroup *manyEllipses;
    QGraphicsScene *scene;
    QTimer *timer;

    MyGrid *grid;
    bool gridExist = false;

    void prepeare_configuration();
    void prepeare_timer();
    void prepeare_groups();

protected:
    void resizeEvent(QResizeEvent *event);

public:
    explicit MyGraphicsView(QGraphicsView *parent = 0);
    ~MyGraphicsView();

    void drawGrid();
    void deleteGrid();

    MyGraphicsItemGroup *getCircleDrawer();
    MyGraphicsItemGroup *getManyCirclesDrawer();
    MyGraphicsItemGroup *getEllipseDrawer();
    MyGraphicsItemGroup *getManyEllipsesDrawer();

    void setCircleDrawer(MyGraphicsItemGroup *item);
    void setManyCirclesDrawer(MyGraphicsItemGroup *item);
    void setEllipseDrawer(MyGraphicsItemGroup *item);
    void setManyEllipsesDrawer(MyGraphicsItemGroup *item);

    void add_items_to_scene();
    void remove_items_to_scene();

    QGraphicsScene *getScene();

public slots:
    void slotAlarmTimer();
};

#endif