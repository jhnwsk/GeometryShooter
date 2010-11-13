/****************************************************************************
** Meta object code from reading C++ file 'moving_target.h'
**
** Created: Sat Nov 13 01:20:01 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "moving_target.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'moving_target.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MovingTarget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_MovingTarget[] = {
    "MovingTarget\0\0timeOutSlot()\0"
};

const QMetaObject MovingTarget::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MovingTarget,
      qt_meta_data_MovingTarget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MovingTarget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MovingTarget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MovingTarget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MovingTarget))
        return static_cast<void*>(const_cast< MovingTarget*>(this));
    return QObject::qt_metacast(_clname);
}

int MovingTarget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: timeOutSlot(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_Triangle[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_Triangle[] = {
    "Triangle\0"
};

const QMetaObject Triangle::staticMetaObject = {
    { &MovingTarget::staticMetaObject, qt_meta_stringdata_Triangle,
      qt_meta_data_Triangle, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Triangle::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Triangle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Triangle::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Triangle))
        return static_cast<void*>(const_cast< Triangle*>(this));
    return MovingTarget::qt_metacast(_clname);
}

int Triangle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MovingTarget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
