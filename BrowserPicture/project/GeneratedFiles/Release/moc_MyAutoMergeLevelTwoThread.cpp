/****************************************************************************
** Meta object code from reading C++ file 'MyAutoMergeLevelTwoThread.h'
**
** Created: Thu Sep 1 17:58:57 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "..\..\..\sources\BrowsePicture\header\MyAutoMergeLevelTwoThread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyAutoMergeLevelTwoThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyAutoMergeLevelTwoThread[] = {

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
      27,   26,   26,   26, 0x05,
      34,   26,   26,   26, 0x05,
      41,   26,   26,   26, 0x05,
      58,   26,   26,   26, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_MyAutoMergeLevelTwoThread[] = {
    "MyAutoMergeLevelTwoThread\0\0done()\0"
    "fail()\0showpic(QString)\0showDoingPic(QString)\0"
};

const QMetaObject MyAutoMergeLevelTwoThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_MyAutoMergeLevelTwoThread,
      qt_meta_data_MyAutoMergeLevelTwoThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyAutoMergeLevelTwoThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyAutoMergeLevelTwoThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyAutoMergeLevelTwoThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyAutoMergeLevelTwoThread))
        return static_cast<void*>(const_cast< MyAutoMergeLevelTwoThread*>(this));
    return QThread::qt_metacast(_clname);
}

int MyAutoMergeLevelTwoThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void MyAutoMergeLevelTwoThread::done()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MyAutoMergeLevelTwoThread::fail()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MyAutoMergeLevelTwoThread::showpic(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyAutoMergeLevelTwoThread::showDoingPic(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
