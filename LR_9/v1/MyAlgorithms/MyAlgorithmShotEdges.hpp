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
    ~MyAlgorithmShortedEdges();
    
    void draw(MyImage *drawer, MyShape catter, MyShape shape);
    bool check_poligon(QVector<MyPoint> &poligon);
};

#endif