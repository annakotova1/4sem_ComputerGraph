#include "MyImage.hpp"

MyImage::MyImage()
{
    display = new MyLabel();
    setSizes(display->size().width(), display->size().height());
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

void MyImage::changeColors(QColor newFone, QColor newDraw)
{
    for (int i = 0; i < image->size().width(); i++)
    {
        for (int j = 0; j < image->size().height(); j++)   
        {
            if (image->pixelColor(i, j).value() == foneColor.value())
            {
                image->setPixelColor(i, j, newFone);
            }
            else
            {
                image->setPixelColor(i, j, newDraw);
            }
        }
    }
    printf("fone %u %u %u %u\n", drawColor.value(), foneColor.value(), newDraw.value(), newFone.value());
                
    foneColor = newFone;
    drawColor = newDraw;
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
    QPen pen(drawColor);
    painter.setPen(pen);
    painter.drawLine(QPoint(start.getX(), start.getY()), QPoint(end.getX(), end.getY()));
}

void MyImage::setPoint(MyPoint center)
{
    if (!image)
        return;
    image->setPixelColor(center.getX(), center.getY(), drawColor);
    updateDisplay();
/*    QPainter painter(image);
    QPen pen(drawColor);
    painter.setPen(pen);
    painter.drawEllipse(center.getX(), center.getY(), 1, 1);
*/}

void MyImage::update(ISubject *subject)
{
    MyException *exp = new MyException();
    QColor newFone, newDraw;
    printf("update\n");
    printf("%d\n", subject->isFone());
    printf("fone %u %u %u \n", drawColor.value(), foneColor.value(), subject->getColor().value());
                
    if (subject->isFone())
    {
        newFone = subject->getColor();
        if (newFone.value() == drawColor.value())
        {
            subject->setNewColor(foneColor);
            exp->makeException(QString("Цвет заливки и цвет фона должны различаться.\n"));
            return;
        }
        changeColors(newFone, drawColor);
    }
    else
    {
        newDraw = subject->getColor();
        if (newDraw.value() == foneColor.value())
        {
            subject->setNewColor(drawColor);
            exp->makeException(QString("Цвет заливки и цвет фона должны различаться.\n"));
            return;
        }
        changeColors(foneColor, newDraw);
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