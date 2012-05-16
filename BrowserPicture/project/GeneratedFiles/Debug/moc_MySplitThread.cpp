/****************************************************************************
** Meta object code from reading C++ file 'MySplitThread.h'
**
** Created: Fri Sep 2 16:19:43 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "..\..\..\sources\BrowsePicture\header\MySplitThread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MySplitThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MySplitThread[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      22,   14,   14,   14, 0x05,
      29,   14,   14,   14, 0x05,
      46,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      68,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MySplitThread[] = {
    "MySplitThread\0\0done()\0fail()\0"
    "showpic(QString)\0showDoingPic(QString)\0"
    "SplitPic()\0"
};

const QMetaObject MySplitThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_MySplitThread,
      qt_meta_data_MySplitThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MySplitThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MySplitThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MySplitThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MySplitThread))
        return static_cast<void*>(const_cast< MySplitThread*>(this));
    return QThread::qt_metacast(_clname);
}

int MySplitThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: done(); break;
        case 1: fail(); break;
        case 2: showpic((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: showDoingPic((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: SplitPic(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void MySplitThread::done()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MySplitThread::fail()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MySplitThread::showpic(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MySplitThread::showDoingPic(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
