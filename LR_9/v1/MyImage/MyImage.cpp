#include "MyImage.hpp"

MyImage::MyImage()
{
    display = new MyLabel();
    setSizes(display->size().width(), display->size().height());
    makeStartFone();
    display->setImage(image);
}

void MyImage::updateDisplay()
{
    display->setImage(image);
}

MyImage::~MyImage()
{
    if (image)
        delete image;
}

QColor MyImage::getFone()
{
    return foneColor;
}

void MyImage::makeStartFone()
{
    for (int i = 0; i < image->size().width(); i++)
    {
        for (int j = 0; j < image->size().height(); j++)   
        {
            image->setPixelColor(i, j, QColor(foneColor));
        }
    }
}

void MyImage::changeColors(QColor newCatter, QColor newCatLine, QColor newLine)
{
    for (int i = 0; i < image->size().width(); i++)
    {
        for (int j = 0; j < image->size().height(); j++)   
        {
            if (image->pixelColor(i, j).value() == lineColor.value())
            {
                image->setPixelColor(i, j, newLine);
            }
            else if (image->pixelColor(i, j).value() == catLineColor.value())
            {
                image->setPixelColor(i, j, newCatLine);
            }
            else if (image->pixelColor(i, j).value() == catterColor.value())
            {
                image->setPixelColor(i, j, newCatter);
            }
            //else
            //{
            //    image->setPixelColor(i, j, foneColor);
            //}
        }
    }
                
    lineColor = newLine;
    catterColor = newCatter;
    catLineColor = newCatLine;
}

void MyImage::setSizes(int width,int height)
{
    if (image)
        delete image;
    image = new QImage(QSize(width, height), QImage::Format_RGB32);
}

void MyImage::setPixel(int x, int y, QColor color)
{
    image->setPixelColor(x, y, color);
}

QColor MyImage::getPixel(int x, int y)
{
    return image->pixelColor(x, y);
}
QImage *MyImage::getImage()
{
    return image;
}
void MyImage::setLine(MyPoint start, MyPoint end)
{
    if (!image)
        return;
    QPainter painter(image);
    QPen pen(lineColor);
    painter.setPen(pen);
    painter.drawLine(QPoint(start.getX(), start.getY()), QPoint(end.getX(), end.getY()));
}
void MyImage::setCatLine(MyPoint start, MyPoint end)
{
    if (!image)
        return;
    QPainter painter(image);
    QBrush brush;
    QPen pen(catLineColor);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(QPoint(start.getX(), start.getY()), QPoint(end.getX(), end.getY()));
}
void MyImage::setCatterLine(MyPoint start, MyPoint end)
{
    if (!image)
        return;
    QPainter painter(image);
    QPen pen(catterColor);
    painter.setPen(pen);
    painter.drawLine(QPoint(start.getX(), start.getY()), QPoint(end.getX(), end.getY()));
}

void MyImage::setRect(MyPoint start, MyPoint end)
{
    if (!image)
        return;
    QPainter painter(image);
    QPen pen(catterColor);
    painter.setPen(pen);
    painter.drawLine(QPoint(start.getX(), start.getY()), QPoint(start.getX(), end.getY()));
    painter.drawLine(QPoint(start.getX(), start.getY()), QPoint(end.getX(), start.getY()));
    painter.drawLine(QPoint(end.getX(), end.getY()), QPoint(end.getX(), start.getY()));
    painter.drawLine(QPoint(end.getX(), end.getY()), QPoint(start.getX(), end.getY()));
}
void MyImage::setPoint(MyPoint center)
{
    if (!image)
        return;
    image->setPixelColor(center.getX(), center.getY(), lineColor);
    //updateDisplay();
/*    QPainter painter(image);
    QPen pen(drawColor);
    painter.setPen(pen);
    painter.drawEllipse(center.getX(), center.getY(), 1, 1);
*/}

void MyImage::update(ISubject *subject)
{
    MyException *exp = new MyException();
    QColor newFone, newLine, newCatLine, newCatter;
//QColor newFone, QColor newCatter, QColor newCatLine, QColor newLine
    if (subject->isLine())
    {
        newLine = subject->getColor();
        if (newLine.value() == foneColor.value())
        {
            subject->setNewColor(lineColor);
            exp->makeException(QString("Цвета должны различаться.\n"));
            return;
        }
        changeColors(catterColor, catLineColor, newLine);
    }
    else if (subject->isCatter())
    {
        newCatter = subject->getColor();
        if (newCatter.value() == foneColor.value())
        {
            subject->setNewColor(catterColor);
            exp->makeException(QString("Цвета должны различаться.\n"));
            return;
        }
        changeColors(newCatter, catLineColor, lineColor);
    }
    else if (subject->isCatLine())
    {
        newCatLine = subject->getColor();
        if (newCatLine.value() == foneColor.value())
        {
            subject->setNewColor(catLineColor);
            exp->makeException(QString("Цвета должны различаться.\n"));
            return;
        }
        changeColors(catterColor, newCatLine, lineColor);
    }
    display->setImage(image);
}

MyLabel *MyImage::getDisplay()
{
    return display;
}

bool MyImage::isChanged()
{
    return changed;
}
void MyImage::setChanged(bool condition)
{
    changed = condition;
}

void MyImage::newMouseEvent(MyPoint event)
{
    setPoint(MyPoint(event.getX(), event.getY()));
    if(lastEvent)
    {
        setLine(MyPoint(lastEvent->getX(), lastEvent->getY()), MyPoint(event.getX(), event.getY()));
    }
    lastEvent = new MyPoint(event.getX(), event.getY());
}

void MyImage::clean()
{
    for (int i = 0; i < image->size().width(); i++)
    {
        for (int j = 0; j < image->size().height(); j++)   
        {
            image->setPixelColor(i, j, foneColor);
        }
    }
    display->setImage(image);
}