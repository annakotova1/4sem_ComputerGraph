#include "MyGrid.hpp"

MyGrid::MyGrid()
{
    QColor new_color = QColor(155, 219, 221, 255);
    setColor(new_color);
}
MyGrid::~MyGrid()
{}
void MyGrid::updatePen()
{
    currentPen = QPen(currentColor);
}

void MyGrid::setColor(QColor new_color)
{
    currentColor = new_color;
    updatePen();
}

void MyGrid::drawGrid(QSize scene_size)
{
    clean();

	int width = scene_size.width();
	int height = scene_size.height();

    QGraphicsLineItem *new_line;
    
    for (int i = 0; i < width; i+=50)
    {
        new_line = getLine(i, 0, i, height);
        new_line->setPen(currentPen);
        addItem(new_line);
    }
    for (int i = 0; i < height; i+=50)
    {
        new_line = getLine(0, i, width, i);
        new_line->setPen(currentPen);
        addItem(new_line);
    }
}

void MyGrid::cleanGrid()
{
    clean();
}
void MyGrid::clean()
{
    for (int i = 0; i < data_pointers.size(); i++)
    {
        delete data_pointers[i];
    }
    data_pointers.clear();
}
void MyGrid::addItem(QGraphicsItem *new_item)
{
    data_pointers.append(new_item);
    //this->addToGroup(new_item);
}
