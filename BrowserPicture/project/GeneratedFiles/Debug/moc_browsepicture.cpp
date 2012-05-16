/****************************************************************************
** Meta object code from reading C++ file 'browsepicture.h'
**
** Created: Fri Sep 2 16:19:44 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "..\..\..\sources\BrowsePicture\header\browsepicture.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'browsepicture.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BrowsePicture[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      34,   14,   14,   14, 0x0a,
      53,   14,   14,   14, 0x0a,
      73,   14,   14,   14, 0x0a,
      94,   14,   14,   14, 0x0a,
     117,   14,   14,   14, 0x0a,
     140,   14,   14,   14, 0x0a,
     178,  165,   14,   14, 0x0a,
     205,   14,   14,   14, 0x0a,
     230,   14,   14,   14, 0x0a,
     244,   14,   14,   14, 0x0a,
     269,  260,  255,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_BrowsePicture[] = {
    "BrowsePicture\0\0OpenActTriggered()\0"
    "ExitActTriggered()\0OpenButtonClicked()\0"
    "SplitButtonClicked()\0OpenDirButtonClicked()\0"
    "ShowPicButtonClicked()\0AutoMergeButtonClicked()\0"
    "filename,arg\0splitPic(QString,SPLITArg)\0"
    "ShowDonePicture(QString)\0doneSuccess()\0"
    "doneFail()\0bool\0filename\0"
    "ShowThumbnail(QString)\0"
};

const QMetaObject BrowsePicture::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BrowsePicture,
      qt_meta_data_BrowsePicture, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BrowsePicture::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BrowsePicture::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BrowsePicture::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BrowsePicture))
        return static_cast<void*>(const_cast< BrowsePicture*>(this));
    return QWidget::qt_metacast(_clname);
}

int BrowsePicture::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: OpenActTriggered(); break;
        case 1: ExitActTriggered(); break;
        case 2: OpenButtonClicked(); break;
        case 3: SplitButtonClicked(); break;
        case 4: OpenDirButtonClicked(); break;
        case 5: ShowPicButtonClicked(); break;
        case 6: AutoMergeButtonClicked(); break;
        case 7: splitPic((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< const SPLITArg(*)>(_a[2]))); break;
        case 8: ShowDonePicture((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: doneSuccess(); break;
        case 10: doneFail(); break;
        case 11: { bool _r = ShowThumbnail((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
