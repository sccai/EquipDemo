/****************************************************************************
** Meta object code from reading C++ file 'imageswitch.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Demo1/control/imageswitch.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageswitch.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ImageSwitch_t {
    QByteArrayData data[12];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageSwitch_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageSwitch_t qt_meta_stringdata_ImageSwitch = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ImageSwitch"
QT_MOC_LITERAL(1, 12, 7), // "setSize"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 10), // "setChecked"
QT_MOC_LITERAL(4, 32, 9), // "isChecked"
QT_MOC_LITERAL(5, 42, 14), // "setButtonStyle"
QT_MOC_LITERAL(6, 57, 24), // "ImageSwitch::ButtonStyle"
QT_MOC_LITERAL(7, 82, 11), // "buttonStyle"
QT_MOC_LITERAL(8, 94, 11), // "ButtonStyle"
QT_MOC_LITERAL(9, 106, 13), // "ButtonStyle_1"
QT_MOC_LITERAL(10, 120, 13), // "ButtonStyle_2"
QT_MOC_LITERAL(11, 134, 13) // "ButtonStyle_3"

    },
    "ImageSwitch\0setSize\0\0setChecked\0"
    "isChecked\0setButtonStyle\0"
    "ImageSwitch::ButtonStyle\0buttonStyle\0"
    "ButtonStyle\0ButtonStyle_1\0ButtonStyle_2\0"
    "ButtonStyle_3"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageSwitch[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       2,   40, // properties
       1,   46, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x0a /* Public */,
       3,    1,   34,    2, 0x0a /* Public */,
       5,    1,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // properties: name, type, flags
       4, QMetaType::Bool, 0x00095003,
       7, 0x80000000 | 8, 0x0009510b,

 // enums: name, flags, count, data
       8, 0x0,    3,   50,

 // enum data: key, value
       9, uint(ImageSwitch::ButtonStyle_1),
      10, uint(ImageSwitch::ButtonStyle_2),
      11, uint(ImageSwitch::ButtonStyle_3),

       0        // eod
};

void ImageSwitch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageSwitch *_t = static_cast<ImageSwitch *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setSize((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->setChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setButtonStyle((*reinterpret_cast< const ImageSwitch::ButtonStyle(*)>(_a[1]))); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ImageSwitch *_t = static_cast<ImageSwitch *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->getChecked(); break;
        case 1: *reinterpret_cast< ButtonStyle*>(_v) = _t->getButtonStyle(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        ImageSwitch *_t = static_cast<ImageSwitch *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setChecked(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setButtonStyle(*reinterpret_cast< ButtonStyle*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject ImageSwitch::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ImageSwitch.data,
      qt_meta_data_ImageSwitch,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ImageSwitch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageSwitch::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ImageSwitch.stringdata0))
        return static_cast<void*>(const_cast< ImageSwitch*>(this));
    return QWidget::qt_metacast(_clname);
}

int ImageSwitch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
