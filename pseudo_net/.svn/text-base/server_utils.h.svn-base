#ifndef IServer_H
#define IServer_H

#include <QtGui>
#include <QtNetwork>
#include "../interfaces/client.h"
#include <QLabel>

class Fake_Client; // forward declaration
class Client; // forward declaration
class Player; // forward declaration

using namespace std;

class IServer : public QObject
{
Q_OBJECT


public:
    IServer(QLabel* etatServeur);
    ~IServer();
    IServer();
    void envoyerATous(const QString &message);

    private slots:
        void nouvelleConnexion();
        void donneesRecues();
        void deconnexionClient();

    private:
        //QLabel *etatServeur;
        //QPushButton *boutonQuitter;

        QTcpServer *serveur;
        QHash<QTcpSocket*, QByteArray*> buffers; //We need a buffer to store data until block has completely received
        QHash<QTcpSocket*, qint32*> sizes; //We need to store the size to verify if a block has received completely

        QList<QTcpSocket *> clients;
        quint16 tailleMessage;
};
#endif // IServer_H
