#include "../inc/Algorithms.hpp"


void drawCDA(MyPoint start, MyPoint end, MyGraphicsItemGroup *group)
{
    qreal dx = end.getX() - start.getX();
    qreal dy = end.getY() - start.getY();

    qreal steps_amount;

    if (fabs(dx) - fabs(dy) > 0)
        steps_amount = fabs(dx);
    else
        steps_amount = fabs(dy);

    dx = dx / steps_amount;
    dy = dy / steps_amount;
    qreal x = start.getX(), y = start.getY();

    for (int i = 0; i <= steps_amount; i++)
    {
        group->getPoint(x, y);
        x += dx;
        y += dy;
    }
}

void drawBrezenhemInt(MyPoint start, MyPoint end, MyGraphicsItemGroup *group)
{
    int dx = end.getX() - start.getX();
    int dy = end.getY() - start.getY();
    int x = start.getX(), y = start.getY();
    int sign_x = dx / fabs(dx), sign_y = dy / fabs(dy);
    dx = fabs(dx);
    dy = fabs(dy);

    int swap = 0, buf, error;

    if (dy > dx)
    {
        swap = 1;
        buf = dx;
        dx = dy;
        dy = buf;
    }
    error = 2 * dy - dx;

    for (int i = 0; i <= dx; i++)
    {
        group->getPoint(x, y);
        if (error >= 0)
        {
            if (swap == 0)
                y += sign_y;
            else
                x += sign_x;
            error -= (2 * dx);
        }
        if (swap == 0)
            x += sign_x;
        else
            y += sign_y;
        error += 2 *dy;
    }
}

void drawBrezenhemFloat(MyPoint start, MyPoint end, MyGraphicsItemGroup *group)
{
    int dx = end.getX() - start.getX();
    int dy = end.getY() - start.getY();
    int x = start.getX(), y = start.getY();
    int sign_x = dx / fabs(dx), sign_y = dy / fabs(dy);
    dx = fabs(dx);
    dy = fabs(dy);

    int swap = 0, buf;
    qreal error, diff;

    if (dy > dx)
    {
        swap = 1;
        buf = dx;
        dx = dy;
        dy = buf;
    }
    diff = dy/dx;
    error = diff - 0.5;

    for (int i = 0; i <= dx; i++)
    {
        group->getPoint(x, y);
        if (error >= 0)
        {
            if (swap == 0)
                y += sign_y;
            else
                x += sign_x;
            error -= 1;
        }
        if (swap == 0)
            x += sign_x;
        else
            y += sign_y;
        error += diff;
    }
}
void drawBrezenhemSmooth(MyPoint start, MyPoint end, MyGraphicsItemGroup *group)
{
    int dx = end.getX() - start.getX();
    int dy = end.getY() - start.getY();
    int x = start.getX(), y = start.getY();
    int sign_x = dx / fabs(dx), sign_y = dy / fabs(dy);
    dx = fabs(dx);
    dy = fabs(dy);

    int swap = 0, buf;
    qreal error, diff;

    if (dy > dx)
    {
        swap = 1;
        buf = dx;
        dx = dy;
        dy = buf;
    }
    diff = dy/dx;
    error = 0.5;

    for (int i = 0; i <= dx; i++)
    {
        group->getPoint(x, y, 1 - error);
        if (error >= 1)
        {
            if (swap == 0)
                y += sign_y;
            else
                x += sign_x;
            error -= 1;
        }
        if (swap == 0)
            x += sign_x;
        else
            y += sign_y;
        error += diff;
    }
}
void drawVy(MyPoint start, MyPoint end, MyGraphicsItemGroup *group)
{
    int dx = end.getX() - start.getX();
    int dy = end.getY() - start.getY();
    int x = start.getX(), y = start.getY();
    int sign_x = dx / fabs(dx), sign_y = dy / fabs(dy);
    dx = fabs(dx);
    dy = fabs(dy);

    int swap = 0, buf;
    qreal error, diff, wy;

    if (dy > dx)
    {
        swap = 1;
        buf = dx;
        dx = dy;
        dy = buf;
    }
    diff = dy/dx;
    error = 0.5;
    wy = 1;

    for (int i = 0; i <= dx; i++)
    {
        if (swap == 0)
        {
            group->getPoint(x, y, error);
            group->getPoint(x, y + sign_y, 1 - error);
        }
        else
        {
            group->getPoint(x, y, error);
            group->getPoint(x + sign_x, y, 1 - error);
        }
        if (error >= wy - diff)
        {
            if (swap == 0)
                y += sign_y;
            else
                x += sign_x;
            error -= 1;
        }
        if (swap == 0)
            x += sign_x;
        else
            y += sign_y;
        error += diff;
    }
}
void drawLibrary(MyPoint start, MyPoint end, MyGraphicsItemGroup *group)
{
    group->getLine(start.getX(), start.getY(), end.getX(), end.getY());
}