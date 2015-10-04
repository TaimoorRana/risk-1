#ifndef CLIENT_H
#define CLIENT_H

#include <QtNetwork>
#include <QMap>
#include "../interfaces/player.h"
#include "ui_Client.h"
//class Player; //forward declaration

class Client : public QWidget, private Ui::Client//, public Player
{
    Q_OBJECT

    public:
        Client();
        void setUpObjects();

    private slots:
        void on_boutonEnvoyer_clicked();
        void on_boutonConnexion_clicked();
        void receive_message();
        void connecte();
        void disconnecte();
        void erreurSocket(QAbstractSocket::SocketError erreur);
        void send_message(QJsonObject j);

    private:
        QTcpSocket *socket; // Représente le serveur
        quint64 messageLength;
        QMap<void*, int>* pointeurMap;

};

#endif // CLIENT_H

