/****************************************************************************
** Meta object code from reading C++ file 'MyMergeLevelTwoThread.h'
**
** Created: Thu Sep 1 17:58:57 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "..\..\..\sources\BrowsePicture\header\MyMergeLevelTwoThread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyMergeLevelTwoThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyMergeLevelTwoThread[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x05,
      30,   22,   22,   22, 0x05,
      37,   22,   22,   22, 0x05,
      54,   22,   22,   22, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_MyMergeLevelTwoThread[] = {
    "MyMergeLevelTwoThread\0\0done()\0fail()\0"
    "showpic(QString)\0showDoingPic(QString)\0"
};

const QMetaObject MyMergeLevelTwoThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_MyMergeLevelTwoThread,
      qt_meta_data_MyMergeLevelTwoThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyMergeLevelTwoThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyMergeLevelTwoThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyMergeLevelTwoThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyMergeLevelTwoThread))
        return static_cast<void*>(const_cast< MyMergeLevelTwoThread*>(this));
    return QThread::qt_metacast(_clname);
}

int MyMergeLevelTwoThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void MyMergeLevelTwoThread::done()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MyMergeLevelTwoThread::fail()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MyMergeLevelTwoThread::showpic(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyMergeLevelTwoThread::showDoingPic(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
