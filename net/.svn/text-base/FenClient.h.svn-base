#ifndef HEADER_FENCLIENT
#define HEADER_FENCLIENT

#include <QtGui>
#include <QtNetwork>
#include "ui_FenClient.h"


class FenClient : public QWidget, private Ui::FenClient
{
    Q_OBJECT

    public:
        FenClient();

    private slots:
        void on_boutonConnexion_clicked();
        void on_boutonEnvoyer_clicked();
        void on_message_returnPressed();
        void donneesRecues();
        void connecte();
        void deconnecte();
        void erreurSocket(QAbstractSocket::SocketError erreur);
        void decoche(); //appelé lorsqu'un joueur décoche l'action1
        void coche(); //appelé lorsqu'un joueur coche l'action1
        void pushAction(); //appelé lorsqu'un joueur appuie sur le bouton action2
        void sendGameAction(QString str);

    private:
        QTcpSocket *socket; // Représente le serveur
        quint16 tailleMessage;
};

#endif
