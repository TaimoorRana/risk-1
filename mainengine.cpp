#include "mainwindow.h"
#include <QApplication>

int mainengine(int argc, char *argv[])
{

    QCommandLineParser parser;


    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Ca roule!!!");
    w.show();

    return a.exec();
}

