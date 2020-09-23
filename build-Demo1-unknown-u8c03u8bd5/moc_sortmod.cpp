/****************************************************************************
** Meta object code from reading C++ file 'sortmod.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Demo1/SortMod/sortmod.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sortmod.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SortMod_t {
    QByteArrayData data[10];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SortMod_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SortMod_t qt_meta_stringdata_SortMod = {
    {
QT_MOC_LITERAL(0, 0, 7), // "SortMod"
QT_MOC_LITERAL(1, 8, 12), // "OnReceiveMsg"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 9), // "OnSendMsg"
QT_MOC_LITERAL(4, 32, 7), // "SendMsg"
QT_MOC_LITERAL(5, 40, 9), // "HexString"
QT_MOC_LITERAL(6, 50, 12), // "SendLightMsg"
QT_MOC_LITERAL(7, 63, 3), // "msn"
QT_MOC_LITERAL(8, 67, 16), // "Socket_Read_Data"
QT_MOC_LITERAL(9, 84, 19) // "socket_Disconnected"

    },
    "SortMod\0OnReceiveMsg\0\0OnSendMsg\0SendMsg\0"
    "HexString\0SendLightMsg\0msn\0Socket_Read_Data\0"
    "socket_Disconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SortMod[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   44,    2, 0x06 /* Public */,
       3,    3,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   58,    2, 0x08 /* Private */,
       6,    2,   61,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    5,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SortMod::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SortMod *_t = static_cast<SortMod *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnReceiveMsg((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->OnSendMsg((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->SendMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->SendLightMsg((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->Socket_Read_Data(); break;
        case 5: _t->socket_Disconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SortMod::*_t)(QString , QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SortMod::OnReceiveMsg)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SortMod::*_t)(QString , QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SortMod::OnSendMsg)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject SortMod::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SortMod.data,
      qt_meta_data_SortMod,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SortMod::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SortMod::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SortMod.stringdata0))
        return static_cast<void*>(const_cast< SortMod*>(this));
    return QObject::qt_metacast(_clname);
}

int SortMod::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void SortMod::OnReceiveMsg(QString _t1, QString _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SortMod::OnSendMsg(QString _t1, QString _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
