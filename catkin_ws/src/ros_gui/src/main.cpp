/**
 * @file /src/main.cpp
 *
 * @brief Qt based gui.
 *
 * @date November 2010
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QApplication>
#include "../include/ros_gui/main_window.hpp"
//#include <sdpa_call.h>

/*****************************************************************************
** Main
*****************************************************************************/

int main(int argc, char **argv) {

//     SDPA teste;

 //    teste.printSDPAVersion();


    /*********************
    ** Qt
    **********************/
    QApplication app(argc, argv);
    ros_gui::MainWindow w(argc,argv);
    w.show();
    app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()));
    int result = app.exec();

	return result;
}
