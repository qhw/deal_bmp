/****************************************************************************
** Meta object code from reading C++ file 'MyAutoMergeThread.h'
**
** Created: Thu Sep 1 17:58:57 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "..\..\..\sources\BrowsePicture\header\MyAutoMergeThread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyAutoMergeThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyAutoMergeThread[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,
      26,   18,   18,   18, 0x05,
      43,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      65,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyAutoMergeThread[] = {
    "MyAutoMergeThread\0\0done()\0showpic(QString)\0"
    "showDoingPic(QString)\0autoMergePic()\0"
};

const QMetaObject MyAutoMergeThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_MyAutoMergeThread,
      qt_meta_data_MyAutoMergeThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyAutoMergeThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyAutoMergeThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyAutoMergeThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyAutoMergeThread))
        return static_cast<void*>(const_cast< MyAutoMergeThread*>(this));
    return QThread::qt_metacast(_clname);
}

int MyAutoMergeThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: done(); break;
        case 1: showpic((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: showDoingPic((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: autoMergePic(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void MyAutoMergeThread::done()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MyAutoMergeThread::showpic(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyAutoMergeThread::showDoingPic(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
