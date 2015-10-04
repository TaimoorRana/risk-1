#include "mainwindow.h"
#include <QApplication>

int mainai1(int argc, char *argv[])
{

    QCommandLineParser parser; //Random Comment


    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Ca roule la sime!!!");
    w.show();

    return a.exec();
}
