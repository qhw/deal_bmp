/****************************************************************************
** Meta object code from reading C++ file 'splitdlg.h'
**
** Created: Thu Sep 1 17:58:56 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "..\..\..\sources\BrowsePicture\header\splitdlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'splitdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SplitDlg[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   10,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      55,    9,    9,    9, 0x08,
      71,    9,    9,    9, 0x08,
      92,    9,    9,    9, 0x08,
     114,    9,  109,    9, 0x08,
     128,    9,    9,    9, 0x08,
     135,    9,    9,    9, 0x08,
     146,    9,    9,    9, 0x08,
     167,    9,  159,    9, 0x08,
     187,  178,    9,    9, 0x08,
     213,  208,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SplitDlg[] = {
    "SplitDlg\0\0filename,arg\0"
    "startSplitPic(QString,SPLITArg)\0"
    "ButtonClicked()\0SpinBoxSetValue(int)\0"
    "setGreyBox(bool)\0bool\0DealPicture()\0"
    "Init()\0ShutDown()\0SetConnect()\0QString\0"
    "OpenFile()\0filename\0GetFileInfo(QString)\0"
    "path\0WriteFile(QString)\0"
};

const QMetaObject SplitDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SplitDlg,
      qt_meta_data_SplitDlg, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SplitDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SplitDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SplitDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SplitDlg))
        return static_cast<void*>(const_cast< SplitDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int SplitDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: startSplitPic((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< const SPLITArg(*)>(_a[2]))); break;
        case 1: ButtonClicked(); break;
        case 2: SpinBoxSetValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: setGreyBox((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: { bool _r = DealPicture();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: Init(); break;
        case 6: ShutDown(); break;
        case 7: SetConnect(); break;
        case 8: { QString _r = OpenFile();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 9: GetFileInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: WriteFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void SplitDlg::startSplitPic(QString _t1, const SPLITArg & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
