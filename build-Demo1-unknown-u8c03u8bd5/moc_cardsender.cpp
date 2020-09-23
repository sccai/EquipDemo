/****************************************************************************
** Meta object code from reading C++ file 'cardsender.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Demo1/CardSender/cardsender.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cardsender.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CardSender_t {
    QByteArrayData data[10];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CardSender_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CardSender_t qt_meta_stringdata_CardSender = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CardSender"
QT_MOC_LITERAL(1, 11, 12), // "OnReceiveMsg"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 9), // "OnSendMsg"
QT_MOC_LITERAL(4, 35, 16), // "Socket_Read_Data"
QT_MOC_LITERAL(5, 52, 12), // "updateStatus"
QT_MOC_LITERAL(6, 65, 10), // "CardStatus"
QT_MOC_LITERAL(7, 76, 6), // "NoCard"
QT_MOC_LITERAL(8, 83, 8), // "LessCard"
QT_MOC_LITERAL(9, 92, 6) // "Normal"

    },
    "CardSender\0OnReceiveMsg\0\0OnSendMsg\0"
    "Socket_Read_Data\0updateStatus\0CardStatus\0"
    "NoCard\0LessCard\0Normal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CardSender[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       1,   50, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   34,    2, 0x06 /* Public */,
       3,    3,   41,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   48,    2, 0x08 /* Private */,
       5,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // enums: name, flags, count, data
       6, 0x0,    3,   54,

 // enum data: key, value
       7, uint(CardSender::NoCard),
       8, uint(CardSender::LessCard),
       9, uint(CardSender::Normal),

       0        // eod
};

void CardSender::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CardSender *_t = static_cast<CardSender *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnReceiveMsg((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->OnSendMsg((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->Socket_Read_Data(); break;
        case 3: _t->updateStatus(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CardSender::*_t)(QString , QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CardSender::OnReceiveMsg)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CardSender::*_t)(QString , QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CardSender::OnSendMsg)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject CardSender::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CardSender.data,
      qt_meta_data_CardSender,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CardSender::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CardSender::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CardSender.stringdata0))
        return static_cast<void*>(const_cast< CardSender*>(this));
    if (!strcmp(_clname, "devicebase"))
        return static_cast< devicebase*>(const_cast< CardSender*>(this));
    return QObject::qt_metacast(_clname);
}

int CardSender::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CardSender::OnReceiveMsg(QString _t1, QString _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CardSender::OnSendMsg(QString _t1, QString _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
