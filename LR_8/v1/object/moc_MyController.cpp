/****************************************************************************
** Meta object code from reading C++ file 'MyController.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MyController/MyController.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyController.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyController_t {
    QByteArrayData data[12];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyController_t qt_meta_stringdata_MyController = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MyController"
QT_MOC_LITERAL(1, 13, 7), // "addLine"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 7), // "MyPoint"
QT_MOC_LITERAL(4, 30, 5), // "event"
QT_MOC_LITERAL(5, 36, 11), // "clearCanvas"
QT_MOC_LITERAL(6, 48, 12), // "getFoneColor"
QT_MOC_LITERAL(7, 61, 12), // "getLineColor"
QT_MOC_LITERAL(8, 74, 14), // "getCatterColor"
QT_MOC_LITERAL(9, 89, 15), // "getCatLineColor"
QT_MOC_LITERAL(10, 105, 13), // "addShapePoint"
QT_MOC_LITERAL(11, 119, 12) // "addLinePoint"

    },
    "MyController\0addLine\0\0MyPoint\0event\0"
    "clearCanvas\0getFoneColor\0getLineColor\0"
    "getCatterColor\0getCatLineColor\0"
    "addShapePoint\0addLinePoint"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,
      10,    1,   62,    2, 0x0a /* Public */,
      11,    1,   65,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void MyController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addLine((*reinterpret_cast< MyPoint(*)>(_a[1]))); break;
        case 1: _t->clearCanvas(); break;
        case 2: _t->getFoneColor(); break;
        case 3: _t->getLineColor(); break;
        case 4: _t->getCatterColor(); break;
        case 5: _t->getCatLineColor(); break;
        case 6: _t->addShapePoint((*reinterpret_cast< MyPoint(*)>(_a[1]))); break;
        case 7: _t->addLinePoint((*reinterpret_cast< MyPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyController::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_MyController.data,
    qt_meta_data_MyController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MyController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
