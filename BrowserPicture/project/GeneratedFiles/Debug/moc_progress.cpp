/****************************************************************************
** Meta object code from reading C++ file 'progress.h'
**
** Created: Fri Sep 2 16:19:43 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "..\..\..\sources\BrowsePicture\header\progress.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'progress.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Progress[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      27,    9,    9,    9, 0x0a,
      45,   39,    9,    9, 0x0a,
      70,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Progress[] = {
    "Progress\0\0updateProgress()\0cancelBtn()\0"
    "event\0closeEvent(QCloseEvent*)\0"
    "closeDlg()\0"
};

const QMetaObject Progress::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Progress,
      qt_meta_data_Progress, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Progress::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Progress::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Progress::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Progress))
        return static_cast<void*>(const_cast< Progress*>(this));
    return QWidget::qt_metacast(_clname);
}

int Progress::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateProgress(); break;
        case 1: cancelBtn(); break;
        case 2: closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 3: closeDlg(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
