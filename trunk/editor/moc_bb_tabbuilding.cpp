/****************************************************************************
** Meta object code from reading C++ file 'bb_tabbuilding.h'
**
** Created: Di Sep 6 16:14:54 2005
**      by: The Qt Meta Object Compiler version 58 (Qt 4.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "bb_tabbuilding.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bb_tabbuilding.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 58
#error "This file was generated using the moc from 4.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_BB_TabBuilding[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      23,   16,   15,   15, 0x08,
      46,   15,   15,   15, 0x08,
      71,   15,   15,   15, 0x08,
      92,   15,   15,   15, 0x08,
     116,  110,   15,   15, 0x08,
     141,   16,   15,   15, 0x08,
     168,   16,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BB_TabBuilding[] = {
    "BB_TabBuilding\0\0action\0slotZoomTool(QAction*)\0"
    "slotBuildingProperties()\0slotBuildingDelete()\0slotBuildingNew()\0"
    "index\0slotBuildingChanged(int)\0slotToolPointNew(QAction*)\0"
    "slotToolMove(QAction*)\0"
};

const QMetaObject BB_TabBuilding::staticMetaObject = {
    { &BB_Tab::staticMetaObject, qt_meta_stringdata_BB_TabBuilding,
      qt_meta_data_BB_TabBuilding, 0 }
};

const QMetaObject *BB_TabBuilding::metaObject() const
{
    return &staticMetaObject;
}

void *BB_TabBuilding::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BB_TabBuilding))
	return static_cast<void*>(const_cast<BB_TabBuilding*>(this));
    return BB_Tab::qt_metacast(_clname);
}

int BB_TabBuilding::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BB_Tab::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: slotZoomTool(*(QAction**)_a[1]); break;
        case 1: slotBuildingProperties(); break;
        case 2: slotBuildingDelete(); break;
        case 3: slotBuildingNew(); break;
        case 4: slotBuildingChanged(*(int*)_a[1]); break;
        case 5: slotToolPointNew(*(QAction**)_a[1]); break;
        case 6: slotToolMove(*(QAction**)_a[1]); break;
        }
        _id -= 7;
    }
    return _id;
}
