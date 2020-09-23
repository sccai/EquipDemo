/****************************************************************************
** Meta object code from reading C++ file 'batterynew.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Demo1/batterynew.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'batterynew.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BatteryNew_t {
    QByteArrayData data[29];
    char stringdata0[367];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BatteryNew_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BatteryNew_t qt_meta_stringdata_BatteryNew = {
    {
QT_MOC_LITERAL(0, 0, 10), // "BatteryNew"
QT_MOC_LITERAL(1, 11, 12), // "valueChanged"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5), // "value"
QT_MOC_LITERAL(4, 31, 11), // "updateValue"
QT_MOC_LITERAL(5, 43, 8), // "setRange"
QT_MOC_LITERAL(6, 52, 8), // "minValue"
QT_MOC_LITERAL(7, 61, 8), // "maxValue"
QT_MOC_LITERAL(8, 70, 11), // "setMinValue"
QT_MOC_LITERAL(9, 82, 11), // "setMaxValue"
QT_MOC_LITERAL(10, 94, 8), // "setValue"
QT_MOC_LITERAL(11, 103, 13), // "setAlarmValue"
QT_MOC_LITERAL(12, 117, 10), // "alarmValue"
QT_MOC_LITERAL(13, 128, 7), // "setStep"
QT_MOC_LITERAL(14, 136, 4), // "step"
QT_MOC_LITERAL(15, 141, 19), // "setBorderColorStart"
QT_MOC_LITERAL(16, 161, 16), // "borderColorStart"
QT_MOC_LITERAL(17, 178, 17), // "setBorderColorEnd"
QT_MOC_LITERAL(18, 196, 14), // "borderColorEnd"
QT_MOC_LITERAL(19, 211, 18), // "setAlarmColorStart"
QT_MOC_LITERAL(20, 230, 15), // "alarmColorStart"
QT_MOC_LITERAL(21, 246, 16), // "setAlarmColorEnd"
QT_MOC_LITERAL(22, 263, 13), // "alarmColorEnd"
QT_MOC_LITERAL(23, 277, 19), // "setNormalColorStart"
QT_MOC_LITERAL(24, 297, 16), // "normalColorStart"
QT_MOC_LITERAL(25, 314, 17), // "setNormalColorEnd"
QT_MOC_LITERAL(26, 332, 14), // "normalColorEnd"
QT_MOC_LITERAL(27, 347, 10), // "setDefault"
QT_MOC_LITERAL(28, 358, 8) // "defvalue"

    },
    "BatteryNew\0valueChanged\0\0value\0"
    "updateValue\0setRange\0minValue\0maxValue\0"
    "setMinValue\0setMaxValue\0setValue\0"
    "setAlarmValue\0alarmValue\0setStep\0step\0"
    "setBorderColorStart\0borderColorStart\0"
    "setBorderColorEnd\0borderColorEnd\0"
    "setAlarmColorStart\0alarmColorStart\0"
    "setAlarmColorEnd\0alarmColorEnd\0"
    "setNormalColorStart\0normalColorStart\0"
    "setNormalColorEnd\0normalColorEnd\0"
    "setDefault\0defvalue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BatteryNew[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
      11,  168, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  112,    2, 0x08 /* Private */,
       5,    2,  113,    2, 0x0a /* Public */,
       5,    2,  118,    2, 0x0a /* Public */,
       8,    1,  123,    2, 0x0a /* Public */,
       9,    1,  126,    2, 0x0a /* Public */,
      10,    1,  129,    2, 0x0a /* Public */,
      10,    1,  132,    2, 0x0a /* Public */,
      11,    1,  135,    2, 0x0a /* Public */,
      11,    1,  138,    2, 0x0a /* Public */,
      13,    1,  141,    2, 0x0a /* Public */,
      13,    1,  144,    2, 0x0a /* Public */,
      15,    1,  147,    2, 0x0a /* Public */,
      17,    1,  150,    2, 0x0a /* Public */,
      19,    1,  153,    2, 0x0a /* Public */,
      21,    1,  156,    2, 0x0a /* Public */,
      23,    1,  159,    2, 0x0a /* Public */,
      25,    1,  162,    2, 0x0a /* Public */,
      27,    1,  165,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::QColor,   16,
    QMetaType::Void, QMetaType::QColor,   18,
    QMetaType::Void, QMetaType::QColor,   20,
    QMetaType::Void, QMetaType::QColor,   22,
    QMetaType::Void, QMetaType::QColor,   24,
    QMetaType::Void, QMetaType::QColor,   26,
    QMetaType::Void, QMetaType::Int,   28,

 // properties: name, type, flags
       6, QMetaType::Double, 0x00095103,
       7, QMetaType::Double, 0x00095103,
       3, QMetaType::Double, 0x00095103,
      12, QMetaType::Double, 0x00095103,
      14, QMetaType::Int, 0x00095103,
      16, QMetaType::QColor, 0x00095103,
      18, QMetaType::QColor, 0x00095103,
      20, QMetaType::QColor, 0x00095103,
      22, QMetaType::QColor, 0x00095103,
      24, QMetaType::QColor, 0x00095103,
      26, QMetaType::QColor, 0x00095103,

       0        // eod
};

void BatteryNew::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BatteryNew *_t = static_cast<BatteryNew *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->updateValue(); break;
        case 2: _t->setRange((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 3: _t->setRange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->setMinValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->setMaxValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->setValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->setValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setAlarmValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->setAlarmValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setStep((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->setStep((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->setBorderColorStart((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 13: _t->setBorderColorEnd((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 14: _t->setAlarmColorStart((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 15: _t->setAlarmColorEnd((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 16: _t->setNormalColorStart((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 17: _t->setNormalColorEnd((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 18: _t->setDefault((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BatteryNew::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BatteryNew::valueChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        BatteryNew *_t = static_cast<BatteryNew *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< double*>(_v) = _t->getMinValue(); break;
        case 1: *reinterpret_cast< double*>(_v) = _t->getMaxValue(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->getValue(); break;
        case 3: *reinterpret_cast< double*>(_v) = _t->getAlarmValue(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->getStep(); break;
        case 5: *reinterpret_cast< QColor*>(_v) = _t->getBorderColorStart(); break;
        case 6: *reinterpret_cast< QColor*>(_v) = _t->getBorderColorEnd(); break;
        case 7: *reinterpret_cast< QColor*>(_v) = _t->getAlarmColorStart(); break;
        case 8: *reinterpret_cast< QColor*>(_v) = _t->getAlarmColorEnd(); break;
        case 9: *reinterpret_cast< QColor*>(_v) = _t->getNormalColorStart(); break;
        case 10: *reinterpret_cast< QColor*>(_v) = _t->getNormalColorEnd(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        BatteryNew *_t = static_cast<BatteryNew *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setMinValue(*reinterpret_cast< double*>(_v)); break;
        case 1: _t->setMaxValue(*reinterpret_cast< double*>(_v)); break;
        case 2: _t->setValue(*reinterpret_cast< double*>(_v)); break;
        case 3: _t->setAlarmValue(*reinterpret_cast< double*>(_v)); break;
        case 4: _t->setStep(*reinterpret_cast< int*>(_v)); break;
        case 5: _t->setBorderColorStart(*reinterpret_cast< QColor*>(_v)); break;
        case 6: _t->setBorderColorEnd(*reinterpret_cast< QColor*>(_v)); break;
        case 7: _t->setAlarmColorStart(*reinterpret_cast< QColor*>(_v)); break;
        case 8: _t->setAlarmColorEnd(*reinterpret_cast< QColor*>(_v)); break;
        case 9: _t->setNormalColorStart(*reinterpret_cast< QColor*>(_v)); break;
        case 10: _t->setNormalColorEnd(*reinterpret_cast< QColor*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject BatteryNew::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BatteryNew.data,
      qt_meta_data_BatteryNew,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BatteryNew::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BatteryNew::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BatteryNew.stringdata0))
        return static_cast<void*>(const_cast< BatteryNew*>(this));
    return QWidget::qt_metacast(_clname);
}

int BatteryNew::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 11;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void BatteryNew::valueChanged(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
