/****************************************************************************
** Meta object code from reading C++ file 'bb_workarea.h'
**
** Created: Di Sep 6 16:15:16 2005
**      by: The Qt Meta Object Compiler version 58 (Qt 4.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "bb_workarea.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bb_workarea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 58
#error "This file was generated using the moc from 4.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_BB_WorkArea[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets

       0        // eod
};

static const char qt_meta_stringdata_BB_WorkArea[] = {
    "BB_WorkArea\0"
};

const QMetaObject BB_WorkArea::staticMetaObject = {
    { &QScrollArea::staticMetaObject, qt_meta_stringdata_BB_WorkArea,
      qt_meta_data_BB_WorkArea, 0 }
};

const QMetaObject *BB_WorkArea::metaObject() const
{
    return &staticMetaObject;
}

void *BB_WorkArea::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BB_WorkArea))
	return static_cast<void*>(const_cast<BB_WorkArea*>(this));
    return QScrollArea::qt_metacast(_clname);
}

int BB_WorkArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
