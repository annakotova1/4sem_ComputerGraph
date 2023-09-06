#ifndef MYALGORITHMSHOTEDGES_HPP
#define MYALGORITHMSHOTEDGES_HPP

#include <cmath>
#include <iostream>
#include <unistd.h>
#include "MyAlgorithm.hpp"
#include "../MyEdge/MyEdge.hpp"
//#using namespace std;

class MyAlgorithmShortedEdges: public MyAlgorithm//, QObject
{
    //Q_OBJECT
public:
    MyAlgorithmShortedEdges();
    
    //void findMinMaxY(QVector<MyPoint> points, int &y_min, int &y_max);
    
    //void drawWithDelay(MyImage *drawer, MyLine line, MyShape shape);
    void draw(MyImage *drawer, MyShape shape, MyLine line);
    //void sort(QVector<MyEdge> *edges);
    
    ~MyAlgorithmShortedEdges();
};

#endif