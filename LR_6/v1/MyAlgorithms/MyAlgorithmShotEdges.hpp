#ifndef MYALGORITHMSHOTEDGES_HPP
#define MYALGORITHMSHOTEDGES_HPP

#include <iostream>
#include <unistd.h>
#include "MyAlgorithm.hpp"
#include "../MyEdge/MyEdge.hpp"
//#using namespace std;

class MyAlgorithmShortedEdges: public MyAlgorithm
{
public:
    MyAlgorithmShortedEdges();
    
    void findMinMaxY(QVector<MyPoint> points, int &y_min, int &y_max);
    
    void drawWithDelay(MyImage *drawer, MyPoint point);
    void draw(MyImage *drawer, MyPoint point);
    void sort(QVector<MyEdge> *edges);
    
    ~MyAlgorithmShortedEdges();
};

#endif