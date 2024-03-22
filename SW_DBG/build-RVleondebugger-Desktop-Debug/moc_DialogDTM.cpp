/****************************************************************************
** Meta object code from reading C++ file 'DialogDTM.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../RVleondebugger/DialogDTM.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DialogDTM.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DialogDTM_t {
    QByteArrayData data[9];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogDTM_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogDTM_t qt_meta_stringdata_DialogDTM = {
    {
QT_MOC_LITERAL(0, 0, 9), // "DialogDTM"
QT_MOC_LITERAL(1, 10, 9), // "DTMcnnctd"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 1), // "b"
QT_MOC_LITERAL(4, 23, 17), // "ConfirmConnection"
QT_MOC_LITERAL(5, 41, 1), // "c"
QT_MOC_LITERAL(6, 43, 20), // "ConfirmDBGModeActive"
QT_MOC_LITERAL(7, 64, 22), // "on_BtnCnnctDTM_clicked"
QT_MOC_LITERAL(8, 87, 24) // "on_BtnDiscnntDTM_clicked"

    },
    "DialogDTM\0DTMcnnctd\0\0b\0ConfirmConnection\0"
    "c\0ConfirmDBGModeActive\0on_BtnCnnctDTM_clicked\0"
    "on_BtnDiscnntDTM_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogDTM[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   42,    2, 0x0a /* Public */,
       6,    1,   45,    2, 0x0a /* Public */,
       7,    0,   48,    2, 0x08 /* Private */,
       8,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DialogDTM::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DialogDTM *_t = static_cast<DialogDTM *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DTMcnnctd((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->ConfirmConnection((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->ConfirmDBGModeActive((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_BtnCnnctDTM_clicked(); break;
        case 4: _t->on_BtnDiscnntDTM_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DialogDTM::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DialogDTM::DTMcnnctd)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject DialogDTM::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogDTM.data,
      qt_meta_data_DialogDTM,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DialogDTM::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogDTM::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DialogDTM.stringdata0))
        return static_cast<void*>(const_cast< DialogDTM*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogDTM::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void DialogDTM::DTMcnnctd(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
