/********************************************************************************
** Form generated from reading UI file 'log_window.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOG_WINDOW_H
#define UI_LOG_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LogWindow)
    {
        if (LogWindow->objectName().isEmpty())
            LogWindow->setObjectName(QString::fromUtf8("LogWindow"));
        LogWindow->resize(421, 481);
        centralwidget = new QWidget(LogWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setContextMenuPolicy(Qt::NoContextMenu);
        tableWidget->setAutoScrollMargin(17);
        tableWidget->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);

        gridLayout->addWidget(tableWidget, 0, 1, 1, 1);

        LogWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LogWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 421, 25));
        LogWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LogWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LogWindow->setStatusBar(statusbar);

        retranslateUi(LogWindow);

        QMetaObject::connectSlotsByName(LogWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LogWindow)
    {
        LogWindow->setWindowTitle(QApplication::translate("LogWindow", "Logs ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LogWindow: public Ui_LogWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_WINDOW_H
