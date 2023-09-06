#include "MyAlgorithms.hpp"

void timeCDA(qreal start_x, qreal start_y, qreal end_x, qreal end_y)
{
    qreal dx = end_x - start_x;
    qreal dy = end_y - start_y;

    qreal steps_amount;

    if (fabs(dx) - fabs(dy) > 0)
        steps_amount = fabs(dx);
    else
        steps_amount = fabs(dy);

    dx = dx / steps_amount;
    dy = dy / steps_amount;
    qreal x = start_x, y = start_y;

    for (int i = 0; i <= steps_amount; i++)
    {
        x += dx;
        y += dy;
    }
}

void timeBrezenhemInt(qreal start_x, qreal start_y, qreal end_x, qreal end_y)
{
    int dx = end_x - start_x;
    int dy = end_y - start_y;
    int x = start_x, y = start_y;
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

void timeBrezenhemFloat(qreal start_x, qreal start_y, qreal end_x, qreal end_y)
{
    int dx = end_x - start_x;
    int dy = end_y - start_y;
    int x = start_x, y = start_y;
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
void timeBrezenhemSmooth(qreal start_x, qreal start_y, qreal end_x, qreal end_y)
{
    int dx = end_x - start_x;
    int dy = end_y - start_y;
    int x = start_x, y = start_y;
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
void timeVy(qreal start_x, qreal start_y, qreal end_x, qreal end_y)
{
    int dx = end_x - start_x;
    int dy = end_y - start_y;
    int x = start_x, y = start_y;
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
            //group->getPoint(x, y, error);
            //group->getPoint(x, y + sign_y, 1 - error);
        }
        else
        {
            //group->getPoint(x, y, error);
            //group->getPoint(x + sign_x, y, 1 - error);
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

void timeLibrary(qreal start_x, qreal start_y, qreal end_x, qreal end_y, MyGraphicsItemGroup *group)
{
    group->getLine(start_x, start_y, end_x, end_y);
}