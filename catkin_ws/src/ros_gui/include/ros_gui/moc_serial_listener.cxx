/****************************************************************************
** Meta object code from reading C++ file 'serial_listener.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "serial_listener.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serial_listener.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ros_gui__SerialListener[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   24,   24,   24, 0x05,
      42,   24,   24,   24, 0x05,
      56,   24,   24,   24, 0x05,
      69,   24,   24,   24, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ros_gui__SerialListener[] = {
    "ros_gui::SerialListener\0\0loggingUpdated()\0"
    "rosShutdown()\0updateData()\0updateList()\0"
};

void ros_gui::SerialListener::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SerialListener *_t = static_cast<SerialListener *>(_o);
        switch (_id) {
        case 0: _t->loggingUpdated(); break;
        case 1: _t->rosShutdown(); break;
        case 2: _t->updateData(); break;
        case 3: _t->updateList(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ros_gui::SerialListener::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ros_gui::SerialListener::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ros_gui__SerialListener,
      qt_meta_data_ros_gui__SerialListener, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ros_gui::SerialListener::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ros_gui::SerialListener::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ros_gui::SerialListener::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ros_gui__SerialListener))
        return static_cast<void*>(const_cast< SerialListener*>(this));
    return QThread::qt_metacast(_clname);
}

int ros_gui::SerialListener::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ros_gui::SerialListener::loggingUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ros_gui::SerialListener::rosShutdown()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ros_gui::SerialListener::updateData()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void ros_gui::SerialListener::updateList()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
