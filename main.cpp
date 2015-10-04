#include "mainwindow.h"
#include <QApplication>
#include <getopt.h>
#include "pseudo_net/server_utils.h"

int mainai1(int argc, char *argv[]);
int mainai2(int argc, char *argv[]);
int mainai3(int argc, char *argv[]);
int mainnetwork(int argc, char *argv[]);
int mainengine(int argc, char *argv[]);
int maingui(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qDebug() << "Test commit !";

    IServer server;

    return app.exec();
}
