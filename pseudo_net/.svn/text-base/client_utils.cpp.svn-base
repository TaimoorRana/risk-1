#include "client_utils.h"
#include <iostream>
#include <QListWidgetItem>

Client_Utils::Client_Utils(QTextEdit *liste) {
    listeMessages = liste;
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(donneesRecues()));
    connect(socket, SIGNAL(connected()), this, SLOT(connecte()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(deconnecte()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(erreurSocket(QAbstractSocket::SocketError)));

    tailleMessage = 0;
}

Client_Utils::Client_Utils() {
    //listeMessages = liste;
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(donneesRecues()));
    connect(socket, SIGNAL(connected()), this, SLOT(connecte()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(deconnecte()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(erreurSocket(QAbstractSocket::SocketError)));

    tailleMessage = 0;
}

Client_Utils::~Client_Utils() {}

// Tentative de connexion au serveur
void Client_Utils::connect_to(QString ip, int port)
{
    // On annonce sur la fenêtre qu'on est en train de se connecter
    listeMessages->append(tr("<em>Tentative de connexion en cours...</em>"));
    //boutonConnexion->setEnabled(false);

    socket->abort(); // On désactive les connexions précédentes s'il y en a
    socket->connectToHost(ip, port); // On se connecte au serveur demandé
}

// Envoi d'un message au serveur
void Client_Utils::send(const QString &messageAEnvoyer)
{
   /* QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    out << (quint16) 0;
    out << messageAEnvoyer;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));

    qDebug() << paquet << " " << messageAEnvoyer;
    socket->write(paquet); // On envoie le paquet*/

    QByteArray msg = messageAEnvoyer.toUtf8();
    socket->write(msg);

    //message->clear(); // On vide la zone d'écriture du message
    //message->setFocus(); // Et on remet le curseur à l'intérieur
}


// On a reçu un paquet (ou un sous-paquet)
void Client_Utils::donneesRecues()
{
    QDataStream in(socket);
    if (tailleMessage == 0)
    {
        if (socket->bytesAvailable() < (int)sizeof(quint16))
             return;

        in >> tailleMessage;
    }

    if (socket->bytesAvailable() < tailleMessage)
        return;


    QString messageRecu;
    in >> messageRecu;
    listeMessages->append(messageRecu);
    tailleMessage = 0;
}

// Ce slot est appelé lorsque la connexion au serveur a réussi
void Client_Utils::connecte()
{
    listeMessages->append(tr("<em>Connexion réussie !</em>"));
}

// Ce slot est appelé lorsqu'on est déconnecté du serveur
void Client_Utils::deconnecte()
{
    listeMessages->append(tr("<em>Déconnecté du serveur</em>"));
}

// Ce slot est appelé lorsqu'il y a une erreur
void Client_Utils::erreurSocket(QAbstractSocket::SocketError erreur)
{
    switch(erreur) // On affiche un message différent selon l'erreur qu'on nous indique
    {
        case QAbstractSocket::HostNotFoundError:
            listeMessages->append(tr("<em>ERREUR : le serveur n'a pas pu être trouvé. Vérifiez l'IP et le port.</em>"));
            break;
        case QAbstractSocket::ConnectionRefusedError:
            listeMessages->append(tr("<em>ERREUR : le serveur a refusé la connexion. Vérifiez si le programme \"serveur\" a bien été lancé. Vérifiez aussi l'IP et le port.</em>"));
            break;
        case QAbstractSocket::RemoteHostClosedError:
            listeMessages->append(tr("<em>ERREUR : le serveur a coupé la connexion.</em>"));
            break;
        default:
            listeMessages->append(tr("<em>ERREUR : ") + socket->errorString() + tr("</em>"));
    }

    //boutonConnexion->setEnabled(true);
}
