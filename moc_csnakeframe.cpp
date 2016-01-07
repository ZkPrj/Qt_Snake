/****************************************************************************
** Meta object code from reading C++ file 'csnakeframe.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "csnakeframe.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'csnakeframe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CSnakeFrame_t {
    QByteArrayData data[5];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CSnakeFrame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CSnakeFrame_t qt_meta_stringdata_CSnakeFrame = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CSnakeFrame"
QT_MOC_LITERAL(1, 12, 14), // "m_Eat_Food_Sig"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "m_Game_Over_Sig"
QT_MOC_LITERAL(4, 44, 17) // "m_Replay_Game_Sig"

    },
    "CSnakeFrame\0m_Eat_Food_Sig\0\0m_Game_Over_Sig\0"
    "m_Replay_Game_Sig"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CSnakeFrame[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,
       4,    0,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CSnakeFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CSnakeFrame *_t = static_cast<CSnakeFrame *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->m_Eat_Food_Sig(); break;
        case 1: _t->m_Game_Over_Sig(); break;
        case 2: _t->m_Replay_Game_Sig(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CSnakeFrame::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSnakeFrame::m_Eat_Food_Sig)) {
                *result = 0;
            }
        }
        {
            typedef void (CSnakeFrame::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSnakeFrame::m_Game_Over_Sig)) {
                *result = 1;
            }
        }
        {
            typedef void (CSnakeFrame::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSnakeFrame::m_Replay_Game_Sig)) {
                *result = 2;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CSnakeFrame::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_CSnakeFrame.data,
      qt_meta_data_CSnakeFrame,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CSnakeFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSnakeFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CSnakeFrame.stringdata0))
        return static_cast<void*>(const_cast< CSnakeFrame*>(this));
    return QFrame::qt_metacast(_clname);
}

int CSnakeFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void CSnakeFrame::m_Eat_Food_Sig()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CSnakeFrame::m_Game_Over_Sig()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void CSnakeFrame::m_Replay_Game_Sig()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
