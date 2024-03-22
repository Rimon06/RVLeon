/****************************************************************************
** Meta object code from reading C++ file 'dtmcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../RVleondebugger/dtmcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dtmcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DTMController_t {
    QByteArrayData data[16];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DTMController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DTMController_t qt_meta_stringdata_DTMController = {
    {
QT_MOC_LITERAL(0, 0, 13), // "DTMController"
QT_MOC_LITERAL(1, 14, 11), // "DMConnected"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 1), // "y"
QT_MOC_LITERAL(4, 29, 12), // "dataReceived"
QT_MOC_LITERAL(5, 42, 1), // "b"
QT_MOC_LITERAL(6, 44, 1), // "c"
QT_MOC_LITERAL(7, 46, 1), // "s"
QT_MOC_LITERAL(8, 48, 9), // "DMRunning"
QT_MOC_LITERAL(9, 58, 11), // "dataIsDATA0"
QT_MOC_LITERAL(10, 70, 15), // "DMActiveChanged"
QT_MOC_LITERAL(11, 86, 13), // "haltedChanged"
QT_MOC_LITERAL(12, 100, 15), // "ndmresetChanged"
QT_MOC_LITERAL(13, 116, 9), // "dataReady"
QT_MOC_LITERAL(14, 126, 11), // "ChangeState"
QT_MOC_LITERAL(15, 138, 7) // "context"

    },
    "DTMController\0DMConnected\0\0y\0dataReceived\0"
    "b\0c\0s\0DMRunning\0dataIsDATA0\0DMActiveChanged\0"
    "haltedChanged\0ndmresetChanged\0dataReady\0"
    "ChangeState\0context"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DTMController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    3,   62,    2, 0x06 /* Public */,
       8,    1,   69,    2, 0x06 /* Public */,
       9,    2,   72,    2, 0x06 /* Public */,
      10,    1,   77,    2, 0x06 /* Public */,
      11,    1,   80,    2, 0x06 /* Public */,
      12,    1,   83,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   86,    2, 0x08 /* Private */,
      14,    3,   87,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::UChar, QMetaType::Short,    5,    6,    7,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Short,    5,    7,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::UChar, QMetaType::UShort,    5,    6,   15,

       0        // eod
};

void DTMController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DTMController *_t = static_cast<DTMController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DMConnected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->dataReceived((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< qint16(*)>(_a[3]))); break;
        case 2: _t->DMRunning((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->dataIsDATA0((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< qint16(*)>(_a[2]))); break;
        case 4: _t->DMActiveChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->haltedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->ndmresetChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->dataReady(); break;
        case 8: _t->ChangeState((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DTMController::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DTMController::DMConnected)) {
                *result = 0;
            }
        }
        {
            typedef void (DTMController::*_t)(QByteArray , quint8 , qint16 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DTMController::dataReceived)) {
                *result = 1;
            }
        }
        {
            typedef void (DTMController::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DTMController::DMRunning)) {
                *result = 2;
            }
        }
        {
            typedef void (DTMController::*_t)(QByteArray , qint16 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DTMController::dataIsDATA0)) {
                *result = 3;
            }
        }
        {
            typedef void (DTMController::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DTMController::DMActiveChanged)) {
                *result = 4;
            }
        }
        {
            typedef void (DTMController::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DTMController::haltedChanged)) {
                *result = 5;
            }
        }
        {
            typedef void (DTMController::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DTMController::ndmresetChanged)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject DTMController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DTMController.data,
      qt_meta_data_DTMController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DTMController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DTMController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DTMController.stringdata0))
        return static_cast<void*>(const_cast< DTMController*>(this));
    return QObject::qt_metacast(_clname);
}

int DTMController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void DTMController::DMConnected(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DTMController::dataReceived(QByteArray _t1, quint8 _t2, qint16 _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DTMController::DMRunning(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DTMController::dataIsDATA0(QByteArray _t1, qint16 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DTMController::DMActiveChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DTMController::haltedChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void DTMController::ndmresetChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
