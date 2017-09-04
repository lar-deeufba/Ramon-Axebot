/********************************************************************************
** Form generated from reading UI file 'field_window.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIELD_WINDOW_H
#define UI_FIELD_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FieldWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLineEdit *line_height;
    QLabel *label_2;
    QLineEdit *line_width;
    QLabel *label;
    QLineEdit *lineEdit;
    QGraphicsView *graphicsView;
    QLineEdit *lineEdit_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FieldWindow)
    {
        if (FieldWindow->objectName().isEmpty())
            FieldWindow->setObjectName(QString::fromUtf8("FieldWindow"));
        FieldWindow->resize(546, 500);
        centralwidget = new QWidget(FieldWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        line_height = new QLineEdit(frame);
        line_height->setObjectName(QString::fromUtf8("line_height"));

        gridLayout_2->addWidget(line_height, 0, 2, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        line_width = new QLineEdit(frame);
        line_width->setObjectName(QString::fromUtf8("line_width"));

        gridLayout_2->addWidget(line_width, 1, 2, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 0, 3, 1, 1);

        graphicsView = new QGraphicsView(frame);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMinimumSize(QSize(200, 105));
        graphicsView->setMaximumSize(QSize(1000, 525));
        graphicsView->setSizeIncrement(QSize(2, 1));

        gridLayout_2->addWidget(graphicsView, 2, 0, 1, 4);

        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_2->addWidget(lineEdit_2, 1, 3, 1, 1);


        gridLayout->addWidget(frame, 0, 0, 1, 1);

        FieldWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FieldWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 546, 25));
        FieldWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(FieldWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FieldWindow->setStatusBar(statusbar);

        retranslateUi(FieldWindow);

        QMetaObject::connectSlotsByName(FieldWindow);
    } // setupUi

    void retranslateUi(QMainWindow *FieldWindow)
    {
        FieldWindow->setWindowTitle(QApplication::translate("FieldWindow", "Field", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FieldWindow", "width", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FieldWindow", "Height", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FieldWindow: public Ui_FieldWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIELD_WINDOW_H
