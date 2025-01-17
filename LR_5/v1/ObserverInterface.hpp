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
    bool isFone()
    {
        return fone;
    };
};

#endif