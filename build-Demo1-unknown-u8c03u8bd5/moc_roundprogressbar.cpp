/****************************************************************************
** Meta object code from reading C++ file 'roundprogressbar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Demo1/roundprogressbar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roundprogressbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RoundProgressBar_t {
    QByteArrayData data[12];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RoundProgressBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RoundProgressBar_t qt_meta_stringdata_RoundProgressBar = {
    {
QT_MOC_LITERAL(0, 0, 16), // "RoundProgressBar"
QT_MOC_LITERAL(1, 17, 8), // "setRange"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 3), // "min"
QT_MOC_LITERAL(4, 31, 3), // "max"
QT_MOC_LITERAL(5, 35, 8), // "setValue"
QT_MOC_LITERAL(6, 44, 3), // "val"
QT_MOC_LITERAL(7, 48, 20), // "setBaseCircleVisible"
QT_MOC_LITERAL(8, 69, 7), // "visible"
QT_MOC_LITERAL(9, 77, 20), // "setDataCircleVisible"
QT_MOC_LITERAL(10, 98, 22), // "setCenterCircleVisible"
QT_MOC_LITERAL(11, 121, 14) // "setTextVisible"

    },
    "RoundProgressBar\0setRange\0\0min\0max\0"
    "setValue\0val\0setBaseCircleVisible\0"
    "visible\0setDataCircleVisible\0"
    "setCenterCircleVisible\0setTextVisible"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RoundProgressBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x0a /* Public */,
       5,    1,   54,    2, 0x0a /* Public */,
       5,    1,   57,    2, 0x0a /* Public */,
       7,    1,   60,    2, 0x0a /* Public */,
       9,    1,   63,    2, 0x0a /* Public */,
      10,    1,   66,    2, 0x0a /* Public */,
      11,    1,   69,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,

       0        // eod
};

void RoundProgressBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RoundProgressBar *_t = static_cast<RoundProgressBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setRange((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->setValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->setBaseCircleVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setDataCircleVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->setCenterCircleVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->setTextVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject RoundProgressBar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RoundProgressBar.data,
      qt_meta_data_RoundProgressBar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RoundProgressBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RoundProgressBar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RoundProgressBar.stringdata0))
        return static_cast<void*>(const_cast< RoundProgressBar*>(this));
    return QWidget::qt_metacast(_clname);
}

int RoundProgressBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
