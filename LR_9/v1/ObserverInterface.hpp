#ifndef OBSERVERINTERFACE_HPP
#define OBSERVERINTERFACE_HPP

#include <QColor>

class ISubject;

class IObject
{
public:
    virtual void update(ISubject *subject) = 0;
};
class ISubject
{
protected:
    bool fone = false;
    bool catter = false;
    bool catLine = false;
    bool line = false;
public:
    virtual void addObject(IObject *obj) = 0;
    virtual void removeObject(IObject *obj) = 0;
    virtual void update() = 0;

    virtual void setNewColor(QColor color) = 0;

    virtual QColor getColor() = 0;
    void setFone(bool isFone) 
    {
        fone = isFone;
    };
    void setCatter(bool isCatter) 
    {
        catter = isCatter;
    };
    void setCatLine(bool isCatLine) 
    {
        catLine = isCatLine;
    };
    void setLine(bool isLine) 
    {
        line = isLine;
    };
    bool isFone()
    {
        return fone;
    };
    bool isCatter()
    {
        return catter;
    };
    bool isCatLine()
    {
        return catLine;
    };
    bool isLine()
    {
        return line;
    };
};

#endif