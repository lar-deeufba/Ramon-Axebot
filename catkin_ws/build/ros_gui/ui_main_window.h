/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowDesign
{
public:
    QAction *action_Quit;
    QAction *action_Preferences;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QAction *actionLogs;
    QAction *actionField;
    QAction *actionMyrviz;
    QAction *actionSettings;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_20;
    QPushButton *button_connect;
    QPushButton *button_quit;
    QFrame *frame_mode;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_mode;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *mode_pid;
    QRadioButton *mode_pwm;
    QRadioButton *mode_automatic;
    QCheckBox *checkBox_mimic;
    QFrame *frame_reference;
    QGridLayout *gridLayout_19;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayout_8;
    QPushButton *button_stop;
    QPushButton *button_send;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_reference;
    QGridLayout *gridLayout_18;
    QGridLayout *gridLayout_12;
    QGridLayout *gridLayout_13;
    QLabel *m3;
    QDoubleSpinBox *m2_set;
    QDoubleSpinBox *m3_set;
    QLabel *m2;
    QDoubleSpinBox *m1_set;
    QCheckBox *m2_orientation;
    QCheckBox *m1_orientation;
    QLabel *m1;
    QCheckBox *m3_orientation;
    QHBoxLayout *horizontalLayout_2;
    QLabel *mode_description;
    QLabel *Description_3;
    QFrame *frame_pid;
    QGridLayout *gridLayout_4;
    QPushButton *button_send_pid_gain;
    QGroupBox *groupBox_pid;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_3;
    QLabel *m1_ki;
    QLabel *m1_kd;
    QLabel *m1_kp;
    QDoubleSpinBox *m1_set_ki;
    QDoubleSpinBox *m1_set_kd;
    QDoubleSpinBox *m1_set_kp;
    QLabel *motor1;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_7;
    QLabel *m2_kp;
    QLabel *m2_ki;
    QDoubleSpinBox *m2_set_ki;
    QLabel *m2_kd;
    QDoubleSpinBox *m2_set_kd;
    QDoubleSpinBox *m2_set_kp;
    QLabel *motor2;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_11;
    QLabel *m3_kp;
    QLabel *m3_ki;
    QDoubleSpinBox *m3_set_ki;
    QLabel *m3_kd;
    QDoubleSpinBox *m3_set_kd;
    QDoubleSpinBox *m3_set_kp;
    QLabel *motor3;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menuTools;
    QMenu *menuSerial;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QString::fromUtf8("MainWindowDesign"));
        MainWindowDesign->resize(423, 660);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(MainWindowDesign->sizePolicy().hasHeightForWidth());
        MainWindowDesign->setSizePolicy(sizePolicy);
        MainWindowDesign->setMinimumSize(QSize(362, 606));
        MainWindowDesign->setMaximumSize(QSize(423, 699));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowDesign->setWindowIcon(icon);
        MainWindowDesign->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        action_Quit = new QAction(MainWindowDesign);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        action_Quit->setShortcutContext(Qt::ApplicationShortcut);
        action_Preferences = new QAction(MainWindowDesign);
        action_Preferences->setObjectName(QString::fromUtf8("action_Preferences"));
        actionAbout = new QAction(MainWindowDesign);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_Qt = new QAction(MainWindowDesign);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        actionLogs = new QAction(MainWindowDesign);
        actionLogs->setObjectName(QString::fromUtf8("actionLogs"));
        actionLogs->setEnabled(true);
        actionField = new QAction(MainWindowDesign);
        actionField->setObjectName(QString::fromUtf8("actionField"));
        actionMyrviz = new QAction(MainWindowDesign);
        actionMyrviz->setObjectName(QString::fromUtf8("actionMyrviz"));
        actionSettings = new QAction(MainWindowDesign);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        centralwidget = new QWidget(MainWindowDesign);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_20 = new QGridLayout(frame);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        button_connect = new QPushButton(frame);
        button_connect->setObjectName(QString::fromUtf8("button_connect"));
        button_connect->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(button_connect->sizePolicy().hasHeightForWidth());
        button_connect->setSizePolicy(sizePolicy1);

        gridLayout_20->addWidget(button_connect, 5, 0, 1, 1);

        button_quit = new QPushButton(frame);
        button_quit->setObjectName(QString::fromUtf8("button_quit"));
        sizePolicy1.setHeightForWidth(button_quit->sizePolicy().hasHeightForWidth());
        button_quit->setSizePolicy(sizePolicy1);

        gridLayout_20->addWidget(button_quit, 5, 1, 1, 1);

        frame_mode = new QFrame(frame);
        frame_mode->setObjectName(QString::fromUtf8("frame_mode"));
        frame_mode->setFrameShape(QFrame::StyledPanel);
        frame_mode->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_mode);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_mode = new QGroupBox(frame_mode);
        groupBox_mode->setObjectName(QString::fromUtf8("groupBox_mode"));
        groupBox_mode->setMinimumSize(QSize(301, 51));
        groupBox_mode->setMaximumSize(QSize(301, 51));
        horizontalLayout_5 = new QHBoxLayout(groupBox_mode);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        mode_pid = new QRadioButton(groupBox_mode);
        mode_pid->setObjectName(QString::fromUtf8("mode_pid"));
        mode_pid->setEnabled(false);

        horizontalLayout_5->addWidget(mode_pid);

        mode_pwm = new QRadioButton(groupBox_mode);
        mode_pwm->setObjectName(QString::fromUtf8("mode_pwm"));
        mode_pwm->setEnabled(false);
        mode_pwm->setChecked(true);

        horizontalLayout_5->addWidget(mode_pwm);

        mode_automatic = new QRadioButton(groupBox_mode);
        mode_automatic->setObjectName(QString::fromUtf8("mode_automatic"));
        mode_automatic->setEnabled(false);
        mode_automatic->setChecked(false);

        horizontalLayout_5->addWidget(mode_automatic);


        verticalLayout->addWidget(groupBox_mode);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        checkBox_mimic = new QCheckBox(frame_mode);
        checkBox_mimic->setObjectName(QString::fromUtf8("checkBox_mimic"));

        gridLayout_2->addWidget(checkBox_mimic, 1, 0, 1, 1);


        gridLayout_20->addWidget(frame_mode, 0, 0, 1, 2);

        frame_reference = new QFrame(frame);
        frame_reference->setObjectName(QString::fromUtf8("frame_reference"));
        frame_reference->setFrameShape(QFrame::StyledPanel);
        frame_reference->setFrameShadow(QFrame::Raised);
        gridLayout_19 = new QGridLayout(frame_reference);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        horizontalSpacer_4 = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_19->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        button_stop = new QPushButton(frame_reference);
        button_stop->setObjectName(QString::fromUtf8("button_stop"));
        button_stop->setEnabled(false);

        gridLayout_8->addWidget(button_stop, 1, 1, 1, 1);

        button_send = new QPushButton(frame_reference);
        button_send->setObjectName(QString::fromUtf8("button_send"));
        button_send->setEnabled(false);

        gridLayout_8->addWidget(button_send, 1, 0, 1, 1);


        gridLayout_19->addLayout(gridLayout_8, 1, 1, 2, 1);

        horizontalSpacer_3 = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_19->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        groupBox_reference = new QGroupBox(frame_reference);
        groupBox_reference->setObjectName(QString::fromUtf8("groupBox_reference"));
        gridLayout_18 = new QGridLayout(groupBox_reference);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_13 = new QGridLayout();
        gridLayout_13->setSpacing(6);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout_13->setContentsMargins(0, -1, -1, -1);
        m3 = new QLabel(groupBox_reference);
        m3->setObjectName(QString::fromUtf8("m3"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(m3->sizePolicy().hasHeightForWidth());
        m3->setSizePolicy(sizePolicy2);
        m3->setMinimumSize(QSize(70, 27));
        m3->setMaximumSize(QSize(100, 27));
        m3->setFrameShape(QFrame::StyledPanel);
        m3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_13->addWidget(m3, 3, 0, 1, 1);

        m2_set = new QDoubleSpinBox(groupBox_reference);
        m2_set->setObjectName(QString::fromUtf8("m2_set"));
        m2_set->setDecimals(2);
        m2_set->setMaximum(6);
        m2_set->setSingleStep(0.01);

        gridLayout_13->addWidget(m2_set, 2, 1, 1, 1);

        m3_set = new QDoubleSpinBox(groupBox_reference);
        m3_set->setObjectName(QString::fromUtf8("m3_set"));
        m3_set->setMaximum(6);
        m3_set->setSingleStep(0.01);

        gridLayout_13->addWidget(m3_set, 3, 1, 1, 1);

        m2 = new QLabel(groupBox_reference);
        m2->setObjectName(QString::fromUtf8("m2"));
        sizePolicy2.setHeightForWidth(m2->sizePolicy().hasHeightForWidth());
        m2->setSizePolicy(sizePolicy2);
        m2->setMinimumSize(QSize(70, 27));
        m2->setMaximumSize(QSize(100, 27));
        m2->setFrameShape(QFrame::StyledPanel);
        m2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_13->addWidget(m2, 2, 0, 1, 1);

        m1_set = new QDoubleSpinBox(groupBox_reference);
        m1_set->setObjectName(QString::fromUtf8("m1_set"));
        m1_set->setDecimals(2);
        m1_set->setMaximum(6);
        m1_set->setSingleStep(0.01);

        gridLayout_13->addWidget(m1_set, 1, 1, 1, 1);

        m2_orientation = new QCheckBox(groupBox_reference);
        m2_orientation->setObjectName(QString::fromUtf8("m2_orientation"));

        gridLayout_13->addWidget(m2_orientation, 2, 2, 1, 1);

        m1_orientation = new QCheckBox(groupBox_reference);
        m1_orientation->setObjectName(QString::fromUtf8("m1_orientation"));

        gridLayout_13->addWidget(m1_orientation, 1, 2, 1, 1);

        m1 = new QLabel(groupBox_reference);
        m1->setObjectName(QString::fromUtf8("m1"));
        sizePolicy2.setHeightForWidth(m1->sizePolicy().hasHeightForWidth());
        m1->setSizePolicy(sizePolicy2);
        m1->setMinimumSize(QSize(70, 27));
        m1->setMaximumSize(QSize(100, 27));
        m1->setFrameShape(QFrame::StyledPanel);
        m1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_13->addWidget(m1, 1, 0, 1, 1);

        m3_orientation = new QCheckBox(groupBox_reference);
        m3_orientation->setObjectName(QString::fromUtf8("m3_orientation"));

        gridLayout_13->addWidget(m3_orientation, 3, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        mode_description = new QLabel(groupBox_reference);
        mode_description->setObjectName(QString::fromUtf8("mode_description"));
        mode_description->setMinimumSize(QSize(0, 27));
        mode_description->setMaximumSize(QSize(16777215, 27));
        mode_description->setLayoutDirection(Qt::LeftToRight);
        mode_description->setFrameShape(QFrame::Box);
        mode_description->setFrameShadow(QFrame::Plain);
        mode_description->setLineWidth(1);
        mode_description->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(mode_description);


        gridLayout_13->addLayout(horizontalLayout_2, 0, 0, 1, 2);

        Description_3 = new QLabel(groupBox_reference);
        Description_3->setObjectName(QString::fromUtf8("Description_3"));
        Description_3->setMinimumSize(QSize(0, 27));
        Description_3->setMaximumSize(QSize(16777215, 27));
        Description_3->setLayoutDirection(Qt::LeftToRight);
        Description_3->setFrameShape(QFrame::Box);
        Description_3->setFrameShadow(QFrame::Plain);
        Description_3->setLineWidth(1);
        Description_3->setAlignment(Qt::AlignCenter);

        gridLayout_13->addWidget(Description_3, 0, 2, 1, 1);


        gridLayout_12->addLayout(gridLayout_13, 4, 0, 1, 1);


        gridLayout_18->addLayout(gridLayout_12, 0, 0, 1, 1);


        gridLayout_19->addWidget(groupBox_reference, 0, 1, 1, 1);


        gridLayout_20->addWidget(frame_reference, 1, 0, 2, 2);

        frame_pid = new QFrame(frame);
        frame_pid->setObjectName(QString::fromUtf8("frame_pid"));
        frame_pid->setEnabled(true);
        frame_pid->setFrameShape(QFrame::StyledPanel);
        frame_pid->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_pid);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        button_send_pid_gain = new QPushButton(frame_pid);
        button_send_pid_gain->setObjectName(QString::fromUtf8("button_send_pid_gain"));
        button_send_pid_gain->setEnabled(false);
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(button_send_pid_gain->sizePolicy().hasHeightForWidth());
        button_send_pid_gain->setSizePolicy(sizePolicy3);
        button_send_pid_gain->setMinimumSize(QSize(150, 0));
        button_send_pid_gain->setMaximumSize(QSize(150, 16777215));

        gridLayout_4->addWidget(button_send_pid_gain, 1, 0, 1, 1, Qt::AlignRight);

        groupBox_pid = new QGroupBox(frame_pid);
        groupBox_pid->setObjectName(QString::fromUtf8("groupBox_pid"));
        horizontalLayout = new QHBoxLayout(groupBox_pid);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout_3->setContentsMargins(0, -1, -1, -1);
        m1_ki = new QLabel(groupBox_pid);
        m1_ki->setObjectName(QString::fromUtf8("m1_ki"));
        m1_ki->setMinimumSize(QSize(30, 27));
        m1_ki->setMaximumSize(QSize(30, 27));
        m1_ki->setFrameShape(QFrame::StyledPanel);

        gridLayout_3->addWidget(m1_ki, 2, 0, 1, 1);

        m1_kd = new QLabel(groupBox_pid);
        m1_kd->setObjectName(QString::fromUtf8("m1_kd"));
        m1_kd->setMinimumSize(QSize(30, 27));
        m1_kd->setMaximumSize(QSize(30, 27));
        m1_kd->setFrameShape(QFrame::StyledPanel);
        m1_kd->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(m1_kd, 1, 0, 1, 1);

        m1_kp = new QLabel(groupBox_pid);
        m1_kp->setObjectName(QString::fromUtf8("m1_kp"));
        sizePolicy2.setHeightForWidth(m1_kp->sizePolicy().hasHeightForWidth());
        m1_kp->setSizePolicy(sizePolicy2);
        m1_kp->setMinimumSize(QSize(30, 27));
        m1_kp->setMaximumSize(QSize(30, 27));
        m1_kp->setFrameShape(QFrame::StyledPanel);
        m1_kp->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(m1_kp, 0, 0, 1, 1);

        m1_set_ki = new QDoubleSpinBox(groupBox_pid);
        m1_set_ki->setObjectName(QString::fromUtf8("m1_set_ki"));
        m1_set_ki->setMaximum(2.55);
        m1_set_ki->setSingleStep(0.01);

        gridLayout_3->addWidget(m1_set_ki, 2, 1, 1, 1);

        m1_set_kd = new QDoubleSpinBox(groupBox_pid);
        m1_set_kd->setObjectName(QString::fromUtf8("m1_set_kd"));
        m1_set_kd->setMaximum(2.55);
        m1_set_kd->setSingleStep(0.01);

        gridLayout_3->addWidget(m1_set_kd, 1, 1, 1, 1);

        m1_set_kp = new QDoubleSpinBox(groupBox_pid);
        m1_set_kp->setObjectName(QString::fromUtf8("m1_set_kp"));
        m1_set_kp->setMaximum(2.55);
        m1_set_kp->setSingleStep(0.01);

        gridLayout_3->addWidget(m1_set_kp, 0, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 1, 0, 1, 1);

        motor1 = new QLabel(groupBox_pid);
        motor1->setObjectName(QString::fromUtf8("motor1"));
        motor1->setMinimumSize(QSize(0, 27));
        motor1->setMaximumSize(QSize(16777215, 27));
        motor1->setLayoutDirection(Qt::LeftToRight);
        motor1->setFrameShape(QFrame::Box);
        motor1->setFrameShadow(QFrame::Plain);
        motor1->setLineWidth(1);
        motor1->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(motor1, 0, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_5);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout_7->setContentsMargins(0, -1, -1, -1);
        m2_kp = new QLabel(groupBox_pid);
        m2_kp->setObjectName(QString::fromUtf8("m2_kp"));
        sizePolicy2.setHeightForWidth(m2_kp->sizePolicy().hasHeightForWidth());
        m2_kp->setSizePolicy(sizePolicy2);
        m2_kp->setMinimumSize(QSize(30, 27));
        m2_kp->setMaximumSize(QSize(30, 27));
        m2_kp->setFrameShape(QFrame::StyledPanel);
        m2_kp->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_7->addWidget(m2_kp, 0, 0, 1, 1);

        m2_ki = new QLabel(groupBox_pid);
        m2_ki->setObjectName(QString::fromUtf8("m2_ki"));
        sizePolicy2.setHeightForWidth(m2_ki->sizePolicy().hasHeightForWidth());
        m2_ki->setSizePolicy(sizePolicy2);
        m2_ki->setMinimumSize(QSize(30, 27));
        m2_ki->setMaximumSize(QSize(30, 27));
        m2_ki->setFrameShape(QFrame::StyledPanel);
        m2_ki->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_7->addWidget(m2_ki, 2, 0, 1, 1);

        m2_set_ki = new QDoubleSpinBox(groupBox_pid);
        m2_set_ki->setObjectName(QString::fromUtf8("m2_set_ki"));
        m2_set_ki->setMaximum(2.55);
        m2_set_ki->setSingleStep(0.01);

        gridLayout_7->addWidget(m2_set_ki, 2, 1, 1, 1);

        m2_kd = new QLabel(groupBox_pid);
        m2_kd->setObjectName(QString::fromUtf8("m2_kd"));
        sizePolicy2.setHeightForWidth(m2_kd->sizePolicy().hasHeightForWidth());
        m2_kd->setSizePolicy(sizePolicy2);
        m2_kd->setMinimumSize(QSize(30, 27));
        m2_kd->setMaximumSize(QSize(30, 27));
        m2_kd->setFrameShape(QFrame::StyledPanel);
        m2_kd->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_7->addWidget(m2_kd, 1, 0, 1, 1);

        m2_set_kd = new QDoubleSpinBox(groupBox_pid);
        m2_set_kd->setObjectName(QString::fromUtf8("m2_set_kd"));
        m2_set_kd->setMaximum(2.55);
        m2_set_kd->setSingleStep(0.01);

        gridLayout_7->addWidget(m2_set_kd, 1, 1, 1, 1);

        m2_set_kp = new QDoubleSpinBox(groupBox_pid);
        m2_set_kp->setObjectName(QString::fromUtf8("m2_set_kp"));
        m2_set_kp->setMaximum(2.55);
        m2_set_kp->setSingleStep(0.01);

        gridLayout_7->addWidget(m2_set_kp, 0, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_7, 1, 0, 1, 1);

        motor2 = new QLabel(groupBox_pid);
        motor2->setObjectName(QString::fromUtf8("motor2"));
        motor2->setMinimumSize(QSize(0, 27));
        motor2->setMaximumSize(QSize(16777215, 27));
        motor2->setLayoutDirection(Qt::LeftToRight);
        motor2->setFrameShape(QFrame::Box);
        motor2->setFrameShadow(QFrame::Plain);
        motor2->setLineWidth(1);
        motor2->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(motor2, 0, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_6);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_11 = new QGridLayout();
        gridLayout_11->setSpacing(6);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout_11->setContentsMargins(0, -1, -1, -1);
        m3_kp = new QLabel(groupBox_pid);
        m3_kp->setObjectName(QString::fromUtf8("m3_kp"));
        sizePolicy2.setHeightForWidth(m3_kp->sizePolicy().hasHeightForWidth());
        m3_kp->setSizePolicy(sizePolicy2);
        m3_kp->setMinimumSize(QSize(30, 27));
        m3_kp->setMaximumSize(QSize(30, 27));
        m3_kp->setFrameShape(QFrame::StyledPanel);
        m3_kp->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_11->addWidget(m3_kp, 0, 0, 1, 1);

        m3_ki = new QLabel(groupBox_pid);
        m3_ki->setObjectName(QString::fromUtf8("m3_ki"));
        sizePolicy2.setHeightForWidth(m3_ki->sizePolicy().hasHeightForWidth());
        m3_ki->setSizePolicy(sizePolicy2);
        m3_ki->setMinimumSize(QSize(30, 27));
        m3_ki->setMaximumSize(QSize(30, 27));
        m3_ki->setFrameShape(QFrame::StyledPanel);
        m3_ki->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_11->addWidget(m3_ki, 2, 0, 1, 1);

        m3_set_ki = new QDoubleSpinBox(groupBox_pid);
        m3_set_ki->setObjectName(QString::fromUtf8("m3_set_ki"));
        m3_set_ki->setMaximum(2.55);
        m3_set_ki->setSingleStep(0.01);

        gridLayout_11->addWidget(m3_set_ki, 2, 1, 1, 1);

        m3_kd = new QLabel(groupBox_pid);
        m3_kd->setObjectName(QString::fromUtf8("m3_kd"));
        sizePolicy2.setHeightForWidth(m3_kd->sizePolicy().hasHeightForWidth());
        m3_kd->setSizePolicy(sizePolicy2);
        m3_kd->setMinimumSize(QSize(30, 27));
        m3_kd->setMaximumSize(QSize(30, 27));
        m3_kd->setFrameShape(QFrame::StyledPanel);
        m3_kd->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_11->addWidget(m3_kd, 1, 0, 1, 1);

        m3_set_kd = new QDoubleSpinBox(groupBox_pid);
        m3_set_kd->setObjectName(QString::fromUtf8("m3_set_kd"));
        m3_set_kd->setMaximum(2.55);
        m3_set_kd->setSingleStep(0.01);

        gridLayout_11->addWidget(m3_set_kd, 1, 1, 1, 1);

        m3_set_kp = new QDoubleSpinBox(groupBox_pid);
        m3_set_kp->setObjectName(QString::fromUtf8("m3_set_kp"));
        m3_set_kp->setMaximum(2.55);
        m3_set_kp->setSingleStep(0.01);

        gridLayout_11->addWidget(m3_set_kp, 0, 1, 1, 1);


        gridLayout_10->addLayout(gridLayout_11, 1, 0, 1, 1);

        motor3 = new QLabel(groupBox_pid);
        motor3->setObjectName(QString::fromUtf8("motor3"));
        motor3->setMinimumSize(QSize(0, 27));
        motor3->setMaximumSize(QSize(16777215, 27));
        motor3->setLayoutDirection(Qt::LeftToRight);
        motor3->setFrameShape(QFrame::Box);
        motor3->setFrameShadow(QFrame::Plain);
        motor3->setLineWidth(1);
        motor3->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(motor3, 0, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_10);


        gridLayout_4->addWidget(groupBox_pid, 0, 0, 1, 1);


        gridLayout_20->addWidget(frame_pid, 3, 0, 2, 2);


        gridLayout->addWidget(frame, 0, 0, 1, 1);

        MainWindowDesign->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowDesign);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 423, 25));
        menubar->setDefaultUp(false);
        menubar->setNativeMenuBar(false);
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuSerial = new QMenu(menubar);
        menuSerial->setObjectName(QString::fromUtf8("menuSerial"));
        MainWindowDesign->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowDesign);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindowDesign->setStatusBar(statusbar);

        menubar->addAction(menu_File->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuSerial->menuAction());
        menu_File->addAction(actionAbout);
        menu_File->addSeparator();
        menu_File->addAction(action_Quit);
        menuTools->addAction(actionLogs);
        menuTools->addAction(actionField);
        menuSerial->addAction(actionSettings);

        retranslateUi(MainWindowDesign);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindowDesign, SLOT(close()));
        QObject::connect(button_quit, SIGNAL(clicked()), MainWindowDesign, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindowDesign);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowDesign)
    {
        MainWindowDesign->setWindowTitle(QApplication::translate("MainWindowDesign", "ROS Enviroment", 0, QApplication::UnicodeUTF8));
        action_Quit->setText(QApplication::translate("MainWindowDesign", "&Quit", 0, QApplication::UnicodeUTF8));
        action_Quit->setShortcut(QApplication::translate("MainWindowDesign", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        action_Preferences->setText(QApplication::translate("MainWindowDesign", "&Preferences", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindowDesign", "&About", 0, QApplication::UnicodeUTF8));
        actionAbout_Qt->setText(QApplication::translate("MainWindowDesign", "About &Qt", 0, QApplication::UnicodeUTF8));
        actionLogs->setText(QApplication::translate("MainWindowDesign", "&Logs", 0, QApplication::UnicodeUTF8));
        actionField->setText(QApplication::translate("MainWindowDesign", "&Field", 0, QApplication::UnicodeUTF8));
        actionMyrviz->setText(QApplication::translate("MainWindowDesign", "myrviz", 0, QApplication::UnicodeUTF8));
        actionSettings->setText(QApplication::translate("MainWindowDesign", "Settings", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        button_connect->setToolTip(QApplication::translate("MainWindowDesign", "Set the target to the current joint trajectory state.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        button_connect->setStatusTip(QApplication::translate("MainWindowDesign", "Clear all waypoints and set the target to the current joint trajectory state.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        button_connect->setText(QApplication::translate("MainWindowDesign", "Start", 0, QApplication::UnicodeUTF8));
        button_quit->setText(QApplication::translate("MainWindowDesign", "Quit", 0, QApplication::UnicodeUTF8));
        groupBox_mode->setTitle(QApplication::translate("MainWindowDesign", "Mode", 0, QApplication::UnicodeUTF8));
        mode_pid->setText(QApplication::translate("MainWindowDesign", "PID", 0, QApplication::UnicodeUTF8));
        mode_pwm->setText(QApplication::translate("MainWindowDesign", "PWM", 0, QApplication::UnicodeUTF8));
        mode_automatic->setText(QApplication::translate("MainWindowDesign", "AUTO", 0, QApplication::UnicodeUTF8));
        checkBox_mimic->setText(QApplication::translate("MainWindowDesign", "Mimic", 0, QApplication::UnicodeUTF8));
        button_stop->setText(QApplication::translate("MainWindowDesign", "Stop", 0, QApplication::UnicodeUTF8));
        button_send->setText(QApplication::translate("MainWindowDesign", "Send", 0, QApplication::UnicodeUTF8));
        groupBox_reference->setTitle(QApplication::translate("MainWindowDesign", "Reference", 0, QApplication::UnicodeUTF8));
        m3->setText(QApplication::translate("MainWindowDesign", "Motor 3", 0, QApplication::UnicodeUTF8));
        m2->setText(QApplication::translate("MainWindowDesign", "Motor 2", 0, QApplication::UnicodeUTF8));
        m2_orientation->setText(QApplication::translate("MainWindowDesign", "ClockWise", 0, QApplication::UnicodeUTF8));
        m1_orientation->setText(QApplication::translate("MainWindowDesign", "ClockWise", 0, QApplication::UnicodeUTF8));
        m1->setText(QApplication::translate("MainWindowDesign", "Motor 1", 0, QApplication::UnicodeUTF8));
        m3_orientation->setText(QApplication::translate("MainWindowDesign", "ClockWise", 0, QApplication::UnicodeUTF8));
        mode_description->setText(QApplication::translate("MainWindowDesign", "Voltage", 0, QApplication::UnicodeUTF8));
        Description_3->setText(QApplication::translate("MainWindowDesign", "Orientation", 0, QApplication::UnicodeUTF8));
        button_send_pid_gain->setText(QApplication::translate("MainWindowDesign", "Send ", 0, QApplication::UnicodeUTF8));
        groupBox_pid->setTitle(QApplication::translate("MainWindowDesign", "PID Parameters", 0, QApplication::UnicodeUTF8));
        m1_ki->setText(QApplication::translate("MainWindowDesign", "Ki", 0, QApplication::UnicodeUTF8));
        m1_kd->setText(QApplication::translate("MainWindowDesign", "Kd", 0, QApplication::UnicodeUTF8));
        m1_kp->setText(QApplication::translate("MainWindowDesign", "Kp", 0, QApplication::UnicodeUTF8));
        motor1->setText(QApplication::translate("MainWindowDesign", "Motor 1", 0, QApplication::UnicodeUTF8));
        m2_kp->setText(QApplication::translate("MainWindowDesign", "Kp", 0, QApplication::UnicodeUTF8));
        m2_ki->setText(QApplication::translate("MainWindowDesign", "Ki", 0, QApplication::UnicodeUTF8));
        m2_kd->setText(QApplication::translate("MainWindowDesign", "Kd", 0, QApplication::UnicodeUTF8));
        motor2->setText(QApplication::translate("MainWindowDesign", "Motor 2", 0, QApplication::UnicodeUTF8));
        m3_kp->setText(QApplication::translate("MainWindowDesign", "Kp", 0, QApplication::UnicodeUTF8));
        m3_ki->setText(QApplication::translate("MainWindowDesign", "Ki", 0, QApplication::UnicodeUTF8));
        m3_kd->setText(QApplication::translate("MainWindowDesign", "Kd", 0, QApplication::UnicodeUTF8));
        motor3->setText(QApplication::translate("MainWindowDesign", "Motor 3", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("MainWindowDesign", "&File", 0, QApplication::UnicodeUTF8));
        menuTools->setTitle(QApplication::translate("MainWindowDesign", "&Tools", 0, QApplication::UnicodeUTF8));
        menuSerial->setTitle(QApplication::translate("MainWindowDesign", "Serial", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
