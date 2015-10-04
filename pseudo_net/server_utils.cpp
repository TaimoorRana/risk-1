#include "server_utils.h"
//#include "fake_client.h"



#include <iostream>


qint32 ArrayToInt(QByteArray source)
{
    qint32 temp;
    QDataStream data(&source, QIODevice::ReadWrite);
    data >> temp;
    return temp;
}


IServer::IServer(QLabel* etatServer)
{
// Gestion du serveur
    qDebug() << "Serveur créé";
    serveur = new QTcpServer();
    if (!serveur->listen(QHostAddress::Any, 50885)) // Démarrage du serveur sur toutes les IP disponibles et sur le port 50585
    {
        // Si le serveur n'a pas été démarré correctement
      etatServer->setText(("Le serveur n'a pas pu être démarré. Raison :<br />") + serveur->errorString());
    }
    else
    {
        // Si le serveur a été démarré correctement
      etatServer->setText(("Le serveur a été démarré sur le port <strong>") + QString::number(serveur->serverPort()) + ("</strong>.<br />Des clients peuvent maintenant se connecter."));
        connect(serveur, SIGNAL(newConnection()), this, SLOT(nouvelleConnexion()));
    }

    tailleMessage = 0;
}
IServer::IServer()
{
// Gestion du serveur
    qDebug() << "Serveur créé";
    serveur = new QTcpServer();
    if (!serveur->listen(QHostAddress::Any, 50885)) // Démarrage du serveur sur toutes les IP disponibles et sur le port 50585
    {
        // Si le serveur n'a pas été démarré correctement
      qDebug() << "Le serveur n'a pas pu être démarré. Raison :" << serveur->errorString();
    }
    else
    {
        // Si le serveur a été démarré correctement
      qDebug() << "Le serveur a été démarré sur le port " << QString::number(serveur->serverPort()) << ". Des clients peuvent maintenant se connecter.";
        connect(serveur, SIGNAL(newConnection()), this, SLOT(nouvelleConnexion()));
    }


    tailleMessage = 0;
}

IServer::~IServer() {}


void IServer::nouvelleConnexion()
{
    qDebug() << "Un nouveau client vient de se connecter";

    QTcpSocket *nouveauClient = serveur->nextPendingConnection();
    clients << nouveauClient;

    this->QObject::connect(nouveauClient, SIGNAL(readyRead()), this, SLOT(donneesRecues()));
    connect(nouveauClient, SIGNAL(disconnected()), this, SLOT(deconnexionClient()));
}

void IServer::donneesRecues()
{
    // 1 : on reçoit un paquet (ou un sous-paquet) d'un des clients

    qDebug() << "Reception de donnees";
    // On détermine quel client envoie le message (recherche du QTcpSocket du client)
    QTcpSocket *socket = static_cast<QTcpSocket*>(sender());

    //@TODO: non-protected against message cut
    QString message = socket->readAll();
    this->envoyerATous(message);


}

void IServer::deconnexionClient()
{
    envoyerATous(("<em>Un client vient de se déconnecter</em>"));

    // On détermine quel client se déconnecte
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0) // Si par hasard on n'a pas ouvé le client à l'origine du signal, on arrête la méthode
        return;

    clients.removeOne(socket);

    socket->deleteLater();
}

void IServer::envoyerATous(const QString &message)
{
    // Préparation du paquet
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    out << (quint16) 0; // On écrit 0 au début du paquet pour réIServer la place pour écrire la taille
    out << message; // On ajoute le message à la suite
    out.device()->seek(0); // On se replace au début du paquet
    out << (quint16) (paquet.size() - sizeof(quint16)); // On écrase le 0 qu'on avait réservé par la longueur du message

    //qDebug() <<"Envoi à tous :" << paquet.;
    // Envoi du paquet préparé à tous les clients connectés au serveur
    for (int i = 0; i < clients.size(); i++)
    {
        clients[i]->write(paquet);
    }

}


