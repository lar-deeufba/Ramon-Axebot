/********************************************************************************
** Form generated from reading UI file 'settings_window.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_WINDOW_H
#define UI_SETTINGS_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_device_connection;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_serial_port;
    QLineEdit *line_edit_serial_port;
    QCheckBox *checkbox_default_port;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_open_port;
    QPushButton *button_close_port;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox;
    QComboBox *comboBox_4;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName(QString::fromUtf8("SettingsWindow"));
        SettingsWindow->resize(285, 457);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../Downloads/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        SettingsWindow->setWindowIcon(icon);
        centralwidget = new QWidget(SettingsWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_device_connection = new QGroupBox(centralwidget);
        groupBox_device_connection->setObjectName(QString::fromUtf8("groupBox_device_connection"));
        formLayout = new QFormLayout(groupBox_device_connection);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_serial_port = new QLabel(groupBox_device_connection);
        label_serial_port->setObjectName(QString::fromUtf8("label_serial_port"));
        label_serial_port->setFrameShape(QFrame::StyledPanel);

        verticalLayout_4->addWidget(label_serial_port);

        line_edit_serial_port = new QLineEdit(groupBox_device_connection);
        line_edit_serial_port->setObjectName(QString::fromUtf8("line_edit_serial_port"));
        line_edit_serial_port->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_4->addWidget(line_edit_serial_port);

        checkbox_default_port = new QCheckBox(groupBox_device_connection);
        checkbox_default_port->setObjectName(QString::fromUtf8("checkbox_default_port"));
        checkbox_default_port->setLayoutDirection(Qt::RightToLeft);

        verticalLayout_4->addWidget(checkbox_default_port);

        horizontalWidget = new QWidget(groupBox_device_connection);
        horizontalWidget->setObjectName(QString::fromUtf8("horizontalWidget"));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        button_open_port = new QPushButton(horizontalWidget);
        button_open_port->setObjectName(QString::fromUtf8("button_open_port"));

        horizontalLayout->addWidget(button_open_port);

        button_close_port = new QPushButton(horizontalWidget);
        button_close_port->setObjectName(QString::fromUtf8("button_close_port"));
        button_close_port->setEnabled(false);

        horizontalLayout->addWidget(button_close_port);


        verticalLayout_4->addWidget(horizontalWidget);


        formLayout->setLayout(0, QFormLayout::SpanningRole, verticalLayout_4);

        groupBox = new QGroupBox(groupBox_device_connection);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setEnabled(false);

        gridLayout_2->addWidget(comboBox_2, 1, 1, 1, 1);

        comboBox_3 = new QComboBox(groupBox);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setEnabled(false);

        gridLayout_2->addWidget(comboBox_3, 2, 1, 1, 1);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setEnabled(false);
        comboBox->setEditable(false);

        gridLayout_2->addWidget(comboBox, 0, 1, 1, 1);

        comboBox_4 = new QComboBox(groupBox);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setEnabled(false);

        gridLayout_2->addWidget(comboBox_4, 3, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        comboBox->raise();
        comboBox->raise();
        comboBox_2->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        comboBox_3->raise();
        comboBox_4->raise();
        label_4->raise();

        formLayout->setWidget(1, QFormLayout::SpanningRole, groupBox);


        gridLayout->addWidget(groupBox_device_connection, 0, 0, 1, 1);

        SettingsWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SettingsWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 285, 25));
        SettingsWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SettingsWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SettingsWindow->setStatusBar(statusbar);

        retranslateUi(SettingsWindow);

        comboBox_3->setCurrentIndex(1);
        comboBox->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SettingsWindow)
    {
        SettingsWindow->setWindowTitle(QApplication::translate("SettingsWindow", "Settings", 0, QApplication::UnicodeUTF8));
        groupBox_device_connection->setTitle(QApplication::translate("SettingsWindow", "Device Connection", 0, QApplication::UnicodeUTF8));
        label_serial_port->setText(QApplication::translate("SettingsWindow", "Serial Port", 0, QApplication::UnicodeUTF8));
        line_edit_serial_port->setText(QString());
        checkbox_default_port->setText(QApplication::translate("SettingsWindow", "Use default port", 0, QApplication::UnicodeUTF8));
        button_open_port->setText(QApplication::translate("SettingsWindow", "Open", 0, QApplication::UnicodeUTF8));
        button_close_port->setText(QApplication::translate("SettingsWindow", "Close", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("SettingsWindow", "Settings", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SettingsWindow", "BaudRate", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SettingsWindow", "Parity", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SettingsWindow", "Data Bits", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("SettingsWindow", "NONE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsWindow", "ODD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsWindow", "EVEN", 0, QApplication::UnicodeUTF8)
        );
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("SettingsWindow", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsWindow", "8", 0, QApplication::UnicodeUTF8)
        );
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("SettingsWindow", "1200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsWindow", "2400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsWindow", "4800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsWindow", "9600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsWindow", "19200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsWindow", "38400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsWindow", "57600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsWindow", "115200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsWindow", "230400", 0, QApplication::UnicodeUTF8)
        );
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("SettingsWindow", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsWindow", "2", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("SettingsWindow", "Stop Bits", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_WINDOW_H
