/****************************************************************************
** Meta object code from reading C++ file 'main_window.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/ros_gui/include/ros_gui/main_window.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ros_gui__MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x0a,
      48,   20,   20,   20, 0x0a,
      78,   20,   20,   20, 0x0a,
     104,   20,   20,   20, 0x0a,
     137,  131,   20,   20, 0x0a,
     169,   20,   20,   20, 0x0a,
     203,   20,   20,   20, 0x0a,
     228,   20,   20,   20, 0x0a,
     255,  253,   20,   20, 0x0a,
     286,  253,   20,   20, 0x0a,
     317,  253,   20,   20, 0x0a,
     348,  253,   20,   20, 0x0a,
     382,  253,   20,   20, 0x0a,
     416,  253,   20,   20, 0x0a,
     450,  253,   20,   20, 0x0a,
     484,  253,   20,   20, 0x0a,
     518,  253,   20,   20, 0x0a,
     552,  253,   20,   20, 0x0a,
     586,  253,   20,   20, 0x0a,
     620,  253,   20,   20, 0x0a,
     656,  654,   20,   20, 0x0a,
     688,  654,   20,   20, 0x0a,
     720,  654,   20,   20, 0x0a,
     752,  654,   20,   20, 0x0a,
     778,  654,   20,   20, 0x0a,
     804,  654,   20,   20, 0x0a,
     836,   20,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ros_gui__MainWindow[] = {
    "ros_gui::MainWindow\0\0on_actionAbout_triggered()\0"
    "on_actionSettings_triggered()\0"
    "on_actionLogs_triggered()\0"
    "on_actionField_triggered()\0check\0"
    "on_button_connect_clicked(bool)\0"
    "on_button_send_pid_gain_clicked()\0"
    "on_button_send_clicked()\0"
    "on_button_stop_clicked()\0i\0"
    "on_m1_set_valueChanged(double)\0"
    "on_m2_set_valueChanged(double)\0"
    "on_m3_set_valueChanged(double)\0"
    "on_m1_set_kp_valueChanged(double)\0"
    "on_m1_set_ki_valueChanged(double)\0"
    "on_m1_set_kd_valueChanged(double)\0"
    "on_m2_set_kp_valueChanged(double)\0"
    "on_m2_set_ki_valueChanged(double)\0"
    "on_m2_set_kd_valueChanged(double)\0"
    "on_m3_set_kp_valueChanged(double)\0"
    "on_m3_set_ki_valueChanged(double)\0"
    "on_m3_set_kd_valueChanged(double)\0b\0"
    "on_m1_orientation_toggled(bool)\0"
    "on_m2_orientation_toggled(bool)\0"
    "on_m3_orientation_toggled(bool)\0"
    "on_mode_pwm_toggled(bool)\0"
    "on_mode_pid_toggled(bool)\0"
    "on_mode_automatic_toggled(bool)\0"
    "updateList()\0"
};

void ros_gui::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_actionAbout_triggered(); break;
        case 1: _t->on_actionSettings_triggered(); break;
        case 2: _t->on_actionLogs_triggered(); break;
        case 3: _t->on_actionField_triggered(); break;
        case 4: _t->on_button_connect_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_button_send_pid_gain_clicked(); break;
        case 6: _t->on_button_send_clicked(); break;
        case 7: _t->on_button_stop_clicked(); break;
        case 8: _t->on_m1_set_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->on_m2_set_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->on_m3_set_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->on_m1_set_kp_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->on_m1_set_ki_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->on_m1_set_kd_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->on_m2_set_kp_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->on_m2_set_ki_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->on_m2_set_kd_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->on_m3_set_kp_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->on_m3_set_ki_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 19: _t->on_m3_set_kd_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 20: _t->on_m1_orientation_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->on_m2_orientation_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->on_m3_orientation_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->on_mode_pwm_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->on_mode_pid_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->on_mode_automatic_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->updateList(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ros_gui::MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ros_gui::MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ros_gui__MainWindow,
      qt_meta_data_ros_gui__MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ros_gui::MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ros_gui::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ros_gui::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ros_gui__MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ros_gui::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
