/****************************************************************************
** Meta object code from reading C++ file 'settings_window.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/ros_gui/include/ros_gui/settings_window.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settings_window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SettingsWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   16,   15,   15, 0x0a,
      65,   15,   15,   15, 0x0a,
      96,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SettingsWindow[] = {
    "SettingsWindow\0\0state\0"
    "on_checkbox_default_port_stateChanged(int)\0"
    "on_button_close_port_clicked()\0"
    "on_button_open_port_clicked()\0"
};

void SettingsWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SettingsWindow *_t = static_cast<SettingsWindow *>(_o);
        switch (_id) {
        case 0: _t->on_checkbox_default_port_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_button_close_port_clicked(); break;
        case 2: _t->on_button_open_port_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SettingsWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SettingsWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SettingsWindow,
      qt_meta_data_SettingsWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SettingsWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SettingsWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SettingsWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SettingsWindow))
        return static_cast<void*>(const_cast< SettingsWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SettingsWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
