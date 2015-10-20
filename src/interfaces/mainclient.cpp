
#include <QApplication>
#include "client.h"
#include "../pseudo_net/client_utils.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Client_Utils fenetre;
//fenetre.show();

    return app.exec();
}
