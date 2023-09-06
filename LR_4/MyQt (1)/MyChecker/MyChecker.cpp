#include "MyChecker.hpp"

MyChecker::MyChecker()
{
    messageBox = new MyException();
}

MyChecker::~MyChecker()
{}


// QVector :
//     - x, y
//     - radius_start, radius_end
//     - step, step
QVector<MyPoint> *MyChecker::checkManyCirclesData(int x, int y, int step, int count, int radius_start, int radius_end)
{
    if (radius_end == radius_start || radius_start < 0 || step < 0 || count < 0)
    {
        messageBox->makeException(tr("Конечный радиус не может быть меньше начального или равен ему.\n") + 
            tr("Начальный радиус не может быть меньше 1.\n") + 
            tr("Шаг не может быть меньше 1.\n") + tr("Кол-во окружностей не может быть меньше 1."));
        return NULL;
    }
    QVector<MyPoint> *ans = new QVector<MyPoint>();
    MyPoint p1, p2, p3;
    p1.setX(x);
    p1.setY(y);
    ans->append(p1);

    if (step == 0)
    {
        if (radius_start == 0 || radius_end == 0 || count == 0 || radius_end <= radius_start)
        {
            messageBox->makeException(tr("При вводе возможен только 1 параметр равный 0 или отсутствующий.\n"));
            delete ans; 
            return NULL;
        }
        p2.setX(radius_start);
        p2.setY(radius_end);
        p3.setX((float)(radius_end - radius_start)/(float)(count - 1));
        //printf("count = %d, step = %f\n", count, (float)(radius_end - radius_start)/(float)count);
        p3.setY((float)(radius_end - radius_start)/(float)(count - 1));
        ans->append(p2);
        ans->append(p3);
        return ans;
    }
    else if (count == 0)
    {
        if (radius_start == 0 || radius_end == 0 || step == 0 || radius_end <= radius_start)
        {
            messageBox->makeException(tr("При вводе возможен только 1 параметр равный 0 или отсутствующий.\n"));
            delete ans; 
            return NULL;
        }
        p2.setX(radius_start);
        p2.setY(radius_end);
        p3.setX(step);
        p3.setY(step);
        ans->append(p2);
        ans->append(p3);
        return ans;
    }
    else if (radius_start == 0)
    {
        if (step == 0 || radius_end == 0 || count == 0)
        {
            messageBox->makeException(tr("При вводе возможен только 1 параметр равный 0 или отсутствующий.\n"));
            delete ans; 
            return NULL;
        }
        if (radius_end - count*step <= 0)
        {
            messageBox->makeException(tr("При расчетах по введенным значениям начальный радиус оказался меньше 1, что невозможно.\n"));
            delete ans; 
            return NULL;
        }
        p2.setX(radius_end - count*step);
        p2.setY(radius_end);
        p3.setX(step);
        p3.setY(step);
        ans->append(p2);
        ans->append(p3);
        return ans;
    }
    else if (radius_end == 0)
    {
        if (radius_start == 0 || step == 0 || count == 0)
        {
            messageBox->makeException(tr("При вводе возможен только 1 параметр равный 0 или отсутствующий.\n"));
            delete ans; 
            return NULL;
        }
        p2.setX(radius_start);
        p2.setY(radius_start + step * count);
        p3.setX(step);
        p3.setY(step);
        ans->append(p2);
        ans->append(p3);
        return ans;
    }
    messageBox->makeException(tr("Нельзя задавать все параметры сразу.\n"));  
    delete ans; 
    return NULL;
}

// QVector :
//     - x, y
//     - a_start, a_end
//     - b_start, b_end
//     - step_a, step_b 

QVector<MyPoint> * MyChecker::checkManyEllipsesData(int x, int y, int step, int count, int a_start, int a_end, int b_start, int b_end)
{
    if (a_start == a_end || b_start == b_end || a_start < 0 || b_start < 0 || step < 0 || count < 0)
    {
        messageBox->makeException(tr("Конечная полуось a не может быть меньше начальной или равна ее.\n") + 
            tr("Конечная полуось b не может быть меньше начальной или равна ее.\n") +
            tr("Начальная полуось a не может быть меньше 1.\n") + 
            tr("Начальная полуось b не может быть меньше 1.\n") + 
            tr("Шаг не может быть меньше 1.\n") + tr("Кол-во окружностей не может быть меньше 1."));
        return NULL;
    }
    QVector<MyPoint> *ans = new QVector<MyPoint>();
    MyPoint p1, a_data, b_data, step_p;
    int a, b;
    p1.setX(x);
    p1.setY(y);
    ans->append(p1);


    if (count == 0)
    {
        if (step == 0 || a_start == 0 || a_end == 0 || b_start == 0 || b_end == 0 || a_start >= a_end || b_start >= b_end)
        {
            messageBox->makeException(tr("При вводе возможен только 1 параметр равный 0 или отсутствующий.\n"));
            delete ans; 
            return NULL;
        }
        a_data.setX(a_start);
        a_data.setY(a_end);
        b_data.setX(b_start);
        b_data.setY(b_end);
        
        step_p.setX(step);
        step_p.setY(step);

        ans->append(a_data);
        ans->append(b_data);
        ans->append(step_p);
        return ans;
    }
    else if (step == 0)
    {
        if (count == 0 || a_start == 0 || a_end == 0 || b_start == 0 || b_end == 0 || a_start >= a_end || b_start >= b_end)
        {
            messageBox->makeException(tr("При вводе возможен только 1 параметр равный 0 или отсутствующий.\n"));
            delete ans; 
            return NULL;
        }
        a_data.setX(a_start);
        a_data.setY(a_end);
        b_data.setX(b_start);
        b_data.setY(b_end);
        
        step_p.setX((float)(a_end - a_start)/(float)count);
        step_p.setY((float)(b_end - b_start)/(float)count);
        //printf("step = %lf, %lf, a_diff = %d, b_diff = %d, b_end = %d, b_start = %d\n", step_p.getX(), step_p.getY(), a_end - a_start, b_end - b_start, b_end, b_start);

        ans->append(a_data);
        ans->append(b_data);
        ans->append(step_p);
        return ans;
    }
    else if(a_start == 0 && b_start == 0)
    {
        if (count == 0 || step == 0 || a_end == 0 || b_end == 0)
        {
            messageBox->makeException(tr("При вводе возможен только 1 параметр равный 0 или отсутствующий.\n"));
            delete ans; 
            return NULL;
        }
        if (a_end > b_end)
        {
            if(a_end - step*count <= 0 || (b_end - step*count/a_end*b_end) <= 0)
            {
                messageBox->makeException(tr("При расчетах по введенным значениям начальные полуоси получились меньше 1.\n"));
                delete ans;
                return NULL;
            }
            b_data.setX((float)(b_end - step*count)/(float)a_end*(float)b_end);
            step_p.setX((float)step);
            step_p.setY((float)step/(float)a_end*(float)b_end);
            a_data.setX(a_end - step*count);
        }
        else
        {
            if(b_end - step*count/b_end*a_end <= 0 || (b_end - step*count) <= 0)
            {
                messageBox->makeException(tr("При расчетах по введенным значениям начальные полуоси получились меньше 1.\n"));
                delete ans;
                return NULL;
            }
            b_data.setX(b_end - step*count);
            step_p.setX((float)step/(float)b_end*(float)a_end);
            step_p.setY(step);
            a_data.setX(a_end - (float)step*(float)count/(float)b_end*(float)a_end);
        }
        b_data.setY(b_end); 
        a_data.setY(a_end);

        ans->append(a_data);
        ans->append(b_data);
        ans->append(step_p);
        return ans;
    }
    else if(a_end == 0 && b_end == 0)
    {
        if (count == 0 || step == 0 || a_start == 0 || b_start == 0)
        {
            messageBox->makeException(tr("При вводе возможен только 1 параметр равный 0 или отсутствующий.\n"));
            delete ans; 
            return NULL;
        }
        if (a_start > b_start)
        {
            b_data.setY(b_start + (float)step*(float)count/(float)a_start*(float)b_start);
            step_p.setX(step);
            step_p.setY((float)step/(float)a_start*(float)b_start);
            a_data.setY(a_start + step*count);
        }
        else
        {
            b_data.setY(b_start + step*count);
            step_p.setX((float)step/(float)b_start*(float)a_start);
            step_p.setY((float)step);
            a_data.setY(a_start + (float)step*(float)count/(float)b_start*(float)a_start);
        }
        b_data.setX(b_start); 
        a_data.setX(a_start);

        ans->append(a_data);
        ans->append(b_data);
        ans->append(step_p);
        return ans;
    }
    messageBox->makeException(tr("Нельзя задавать все параметры сразу.\n") + 
        tr("И задавая начальную полуось a надо также задать начальную полуось b. Тоже самое с конечными полуосями\n"));
    delete ans; 
    return NULL;
}
