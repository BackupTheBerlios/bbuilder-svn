/****************************************************************************
** Meta object code from reading C++ file 'bb_tablevel.h'
**
** Created: Di Sep 6 16:15:05 2005
**      by: The Qt Meta Object Compiler version 58 (Qt 4.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "bb_tablevel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bb_tablevel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 58
#error "This file was generated using the moc from 4.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_BB_TabLevel[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      20,   13,   12,   12, 0x08,
      35,   13,   12,   12, 0x08,
      58,   12,   12,   12, 0x08,
      73,   12,   12,   12, 0x08,
      95,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BB_TabLevel[] = {
    "BB_TabLevel\0\0action\0test(QAction*)\0slotZoomTool(QAction*)\0"
    "slotLevelNew()\0slotLevelProperties()\0slotLevelDelete()\0"
};

const QMetaObject BB_TabLevel::staticMetaObject = {
    { &BB_Tab::staticMetaObject, qt_meta_stringdata_BB_TabLevel,
      qt_meta_data_BB_TabLevel, 0 }
};

const QMetaObject *BB_TabLevel::metaObject() const
{
    return &staticMetaObject;
}

void *BB_TabLevel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BB_TabLevel))
	return static_cast<void*>(const_cast<BB_TabLevel*>(this));
    return BB_Tab::qt_metacast(_clname);
}

int BB_TabLevel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BB_Tab::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: test(*(QAction**)_a[1]); break;
        case 1: slotZoomTool(*(QAction**)_a[1]); break;
        case 2: slotLevelNew(); break;
        case 3: slotLevelProperties(); break;
        case 4: slotLevelDelete(); break;
        }
        _id -= 5;
    }
    return _id;
}
