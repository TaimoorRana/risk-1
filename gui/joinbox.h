#ifndef HEADER_FENCLIENT
#define HEADER_FENCLIENT

#include <QtGui>
#include <QtNetwork>
#include <QDialog>
#include "ui_joinbox.h"

#include "../pseudo_net/client_utils.h"

class JoinBox : public QDialog, private Ui::JoinBox
{
    Q_OBJECT

    public:
        JoinBox();

    private slots:
        void on_boutonConnexion_clicked();
        void on_boutonEnvoyer_clicked();
        void on_message_returnPressed();
        void donneesRecues();
        void connecte();
        void deconnecte() {};
        void erreurSocket(QAbstractSocket::SocketError erreur) {};
        void decoche(); //appel� lorsqu'un joueur d�coche l'action1
        void coche(); //appel� lorsqu'un joueur coche l'action1
        void pushAction(); //appel� lorsqu'un joueur appuie sur le bouton action2
        void sendGameAction(QString str);

    private:
        Client_Utils* client;
        quint16 tailleMessage;
};

#endif
