#include "FenClient.h"
#include <iostream>
#include <QListWidgetItem>

FenClient::FenClient()
{
    setupUi(this);

    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(donneesRecues()));
    connect(socket, SIGNAL(connected()), this, SLOT(connecte()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(deconnecte()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(erreurSocket(QAbstractSocket::SocketError)));
    //connect(checkBox, SIGNAL(stateChanged(int)),this, SLOT(coche()));//lance coche() si on choche la case
    //connect(checkBox, SIGNAL(stateChanged(int)),this, SLOT(decoche()));//lance decoche() si on déchoche la case
    //connect(pushButton, SIGNAL(clicked()),this, SLOT(pushAction()));//lance pushAction() si on lance l'action 2
    tailleMessage = 0;
}
void FenClient::pushAction()
{
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    // On prépare le paquet à envoyer
    QString messageAEnvoyer = tr("0<strong>") + pseudo->text() +tr("</strong> a lancé l'action2' ");

    out << (quint16) 0;
    out << messageAEnvoyer;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));
    socket->write(paquet); // On envoie le paquet
//test
    message->clear(); // On vide la zone d'écriture du message
    message->setFocus(); // et on remet le curseur à l'intérieur
}

//Un joueur décoche l'action1
void FenClient::decoche()
{
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    // On prépare le paquet à envoyer
    QString messageAEnvoyer = tr("<strong>") + pseudo->text() +tr("</strong> a décoché l'action1' ");

    out << (quint16) 0;
    out << messageAEnvoyer;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));

    socket->write(paquet); // On envoie le paquet

    message->clear(); // On vide la zone d'écriture du message
    message->setFocus(); // Et on remet le curseur à l'intérieur
}

//Un joueur coche l'action1
void FenClient::coche()
{
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    // On prépare le paquet à envoyer
    QString messageAEnvoyer = tr("0<strong>") + pseudo->text() +tr("</strong> a coché l'action1' ");

    out << (quint16) 0;
    out << messageAEnvoyer;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));

    socket->write(paquet); // On envoie le paquet

    message->clear(); // On vide la zone d'écriture du message
    message->setFocus(); // Et on remet le curseur à l'intérieur
}

// Tentative de connexion au serveur
void FenClient::on_boutonConnexion_clicked()
{
    // On annonce sur la fenêtre qu'on est en train de se connecter
    listeMessages->append(tr("<em>Tentative de connexion en cours...</em>"));
    boutonConnexion->setEnabled(false);

    socket->abort(); // On désactive les connexions précédentes s'il y en a
    socket->connectToHost(serveurIP->text(), serveurPort->value()); // On se connecte au serveur demandé


}

// Envoi d'un message au serveur
void FenClient::on_boutonEnvoyer_clicked()
{
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    // On prépare le paquet à envoyer
    // On ajoute un 0 pour signaler un message a destination du chat
    QString messageAEnvoyer = '0' + tr("<strong>") + pseudo->text() +tr("</strong> : ") +message->text();
    std::cout << "Message a envoyer: " << messageAEnvoyer.toStdString() << std::endl;

    out << (quint16) 0;
    out << messageAEnvoyer;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));

    socket->write(paquet); // On envoie le paquet

    message->clear(); // On vide la zone d'écriture du message
    message->setFocus(); // Et on remet le curseur à l'intérieur
}

// Appuyer sur la touche Entrée a le même effet que cliquer sur le bouton "Envoyer"
void FenClient::on_message_returnPressed()
{
    on_boutonEnvoyer_clicked();
}

//Fonction qui prend un string correspondant à une action de jeu, lui ajoute 1, et l'envoie au serveur

void FenClient::sendGameAction(QString str){

    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    // On prépare le paquet à envoyer
    QString messageAEnvoyer = '1'+ tr("<strong>") + pseudo->text() +tr("</strong> : ");
    messageAEnvoyer.append(str);


    out << (quint16) 0;
    out << messageAEnvoyer;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));

    socket->write(paquet); // On envoie le paquet
    message->clear(); // On vide la zone d'écriture du message
    message->setFocus(); // Et on remet le curseur à l'intérieur
}

// On a reçu un paquet (ou un sous-paquet)
void FenClient::donneesRecues()
{
    /* Même principe que lorsque le serveur reçoit un paquet :
    On essaie de récupérer la taille du message
    Une fois qu'on l'a, on attend d'avoir reçu le message entier (en se basant sur la taille annoncée tailleMessage)
    */
    QDataStream in(socket);

    if (tailleMessage == 0)
    {
        if (socket->bytesAvailable() < (int)sizeof(quint16))
             return;

        in >> tailleMessage;
    }

    if (socket->bytesAvailable() < tailleMessage)
        return;


    // Si on arrive jusqu'à cette ligne, on peut récupérer le message entier
    QString messageRecu;
    in >> messageRecu;


    std::cout << "Message recu: "  << messageRecu.toStdString() << std::endl;

    //Si le premier caratère est 0 on le supprime et on affiche le message dans le chat
    if(messageRecu[0]=='0'){


        // On affiche le message sur la zone de Chat
        listeMessages->append(messageRecu.remove(0,1));

    }

    //On recoit un message de type action de jeu
    if (messageRecu[0]=='1'){
        //inclure la fonction de traduction de Jean et Thibaut
    }

    //On recoit le message de bienvenue sur le chat
    if(messageRecu[0]=='2'){
        // On affiche le message sur la zone de Chat
        listeMessages->append(messageRecu.remove(0,1));

    }

    qDebug() << "OK";

    // On remet la taille du message à 0 pour pouvoir recevoir de futurs messages
    tailleMessage = 0;


}

// Ce slot est appelé lorsque la connexion au serveur a réussi
void FenClient::connecte()
{
    listeMessages->append(tr("<em>Connexion réussie !</em>"));
    boutonConnexion->setEnabled(true);
}

// Ce slot est appelé lorsqu'on est déconnecté du serveur
void FenClient::deconnecte()
{
    listeMessages->append(tr("<em>Déconnecté du serveur</em>"));
}

// Ce slot est appelé lorsqu'il y a une erreur
void FenClient::erreurSocket(QAbstractSocket::SocketError erreur)
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

    boutonConnexion->setEnabled(true);
}
