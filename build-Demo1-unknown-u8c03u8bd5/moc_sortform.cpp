/****************************************************************************
** Meta object code from reading C++ file 'sortform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Demo1/sortform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sortform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SortForm_t {
    QByteArrayData data[15];
    char stringdata0[368];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SortForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SortForm_t qt_meta_stringdata_SortForm = {
    {
QT_MOC_LITERAL(0, 0, 8), // "SortForm"
QT_MOC_LITERAL(1, 9, 9), // "OnRefresh"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 13), // "OnRefreshSend"
QT_MOC_LITERAL(4, 34, 8), // "initForm"
QT_MOC_LITERAL(5, 43, 9), // "initEquip"
QT_MOC_LITERAL(6, 53, 33), // "on_pushButton_SortModInit_cli..."
QT_MOC_LITERAL(7, 87, 35), // "on_pushButton_SortMod_Light_c..."
QT_MOC_LITERAL(8, 123, 41), // "on_pushButton_SortMod_Light_C..."
QT_MOC_LITERAL(9, 165, 35), // "on_pushButton_Sort_AdjustIn_c..."
QT_MOC_LITERAL(10, 201, 36), // "on_pushButton_Sort_AdjustOut_..."
QT_MOC_LITERAL(11, 238, 34), // "on_pushButton_Sort_LongOut_cl..."
QT_MOC_LITERAL(12, 273, 19), // "SortModChangedEvent"
QT_MOC_LITERAL(13, 293, 38), // "on_pushButton_Sort_OCRReaderI..."
QT_MOC_LITERAL(14, 332, 35) // "on_pushButton_Sort_VerifyIn_c..."

    },
    "SortForm\0OnRefresh\0\0OnRefreshSend\0"
    "initForm\0initEquip\0on_pushButton_SortModInit_clicked\0"
    "on_pushButton_SortMod_Light_clicked\0"
    "on_pushButton_SortMod_Light_Close_clicked\0"
    "on_pushButton_Sort_AdjustIn_clicked\0"
    "on_pushButton_Sort_AdjustOut_clicked\0"
    "on_pushButton_Sort_LongOut_clicked\0"
    "SortModChangedEvent\0"
    "on_pushButton_Sort_OCRReaderIn_clicked\0"
    "on_pushButton_Sort_VerifyIn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SortForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   79,    2, 0x0a /* Public */,
       3,    3,   86,    2, 0x0a /* Public */,
       4,    0,   93,    2, 0x08 /* Private */,
       5,    0,   94,    2, 0x08 /* Private */,
       6,    0,   95,    2, 0x08 /* Private */,
       7,    0,   96,    2, 0x08 /* Private */,
       8,    0,   97,    2, 0x08 /* Private */,
       9,    0,   98,    2, 0x08 /* Private */,
      10,    0,   99,    2, 0x08 /* Private */,
      11,    0,  100,    2, 0x08 /* Private */,
      12,    0,  101,    2, 0x08 /* Private */,
      13,    0,  102,    2, 0x08 /* Private */,
      14,    0,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SortForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SortForm *_t = static_cast<SortForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnRefresh((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->OnRefreshSend((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->initForm(); break;
        case 3: _t->initEquip(); break;
        case 4: _t->on_pushButton_SortModInit_clicked(); break;
        case 5: _t->on_pushButton_SortMod_Light_clicked(); break;
        case 6: _t->on_pushButton_SortMod_Light_Close_clicked(); break;
        case 7: _t->on_pushButton_Sort_AdjustIn_clicked(); break;
        case 8: _t->on_pushButton_Sort_AdjustOut_clicked(); break;
        case 9: _t->on_pushButton_Sort_LongOut_clicked(); break;
        case 10: _t->SortModChangedEvent(); break;
        case 11: _t->on_pushButton_Sort_OCRReaderIn_clicked(); break;
        case 12: _t->on_pushButton_Sort_VerifyIn_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject SortForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SortForm.data,
      qt_meta_data_SortForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SortForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SortForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SortForm.stringdata0))
        return static_cast<void*>(const_cast< SortForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int SortForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
