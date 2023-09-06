#ifndef OBSERVERINTERFACE_HPP
#define OBSERVERINTERFACE_HPP

#include <QColor>

class IObject
{
public:
    virtual void update(QColor color) = 0;
};
class ISubject
{
    virtual void addObject(IObject *obj) = 0;
    virtual void removeObject(IObject *obj) = 0;
    virtual void update() = 0;
};

#endif