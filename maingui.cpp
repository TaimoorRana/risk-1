#include "mainwindow.h"
#include "loadingwindow.h"
#include <QApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    qDebug()<<"gui in action";


    QApplication a(argc, argv);

    //LoadingWindow *lw = new LoadingWindow("loading...", &a);
    //lw->show();
    //displays a waiting screen

    MainWindow w;
    w.setWindowTitle("Risk");
    w.showMaximized();

    return a.exec();
}

