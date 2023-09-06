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
    void drawEdgesWithDelay(QVector<MyEdge>edges, MyImage *drawer);
    void drawWithDelay(QVector<MyShape>shapes, MyImage *drawer);
    QVector<MyEdge> prepareData(QVector<MyShape> shapes);
    QVector<MyEdge>makeEdges(int y_min, int y_max);
    void findMinMaxY(QVector<MyPoint> points, int &y_min, int &y_max);
    void drawEdges(QVector<MyEdge>edges, MyImage *drawer);
    void draw(QVector<MyShape>shapes, MyImage *drawer);
    void sort(QVector<MyEdge> *edges);
    void drawCDAforShape(QVector<MyEdge> *edges, QVector<MyPoint>points, int y_min);
    ~MyAlgorithmShortedEdges();
};

#endif