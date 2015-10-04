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
    //connect(checkBox, SIGNAL(stateChanged(int)),this, SLOT(decoche()));//lance decoche() si on d�choche la case
    //connect(pushButton, SIGNAL(clicked()),this, SLOT(pushAction()));//lance pushAction() si on lance l'action 2
    tailleMessage = 0;
}
void FenClient::pushAction()
{
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    // On pr�pare le paquet � envoyer
    QString messageAEnvoyer = tr("0<strong>") + pseudo->text() +tr("</strong> a lanc� l'action2' ");

    out << (quint16) 0;
    out << messageAEnvoyer;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));
    socket->write(paquet); // On envoie le paquet
//test
    message->clear(); // On vide la zone d'�criture du message
    message->setFocus(); // et on remet le curseur � l'int�rieur
}

//Un joueur d�coche l'action1
void FenClient::decoche()
{
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    // On pr�pare le paquet � envoyer
    QString messageAEnvoyer = tr("<strong>") + pseudo->text() +tr("</strong> a d�coch� l'action1' ");

    out << (quint16) 0;
    out << messageAEnvoyer;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));

    socket->write(paquet); // On envoie le paquet

    message->clear(); // On vide la zone d'�criture du message
    message->setFocus(); // Et on remet le curseur � l'int�rieur
}

//Un joueur coche l'action1
void FenClient::coche()
{
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    // On pr�pare le paquet � envoyer
    QString messageAEnvoyer = tr("0<strong>") + pseudo->text() +tr("</strong> a coch� l'action1' ");

    out << (quint16) 0;
    out << messageAEnvoyer;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));

    socket->write(paquet); // On envoie le paquet

    message->clear(); // On vide la zone d'�criture du message
    message->setFocus(); // Et on remet le curseur � l'int�rieur
}

// Tentative de connexion au serveur
void FenClient::on_boutonConnexion_clicked()
{
    // On annonce sur la fen�tre qu'on est en train de se connecter
    listeMessages->append(tr("<em>Tentative de connexion en cours...</em>"));
    boutonConnexion->setEnabled(false);

    socket->abort(); // On d�sactive les connexions pr�c�dentes s'il y en a
    socket->connectToHost(serveurIP->text(), serveurPort->value()); // On se connecte au serveur demand�


}

// Envoi d'un message au serveur
void FenClient::on_boutonEnvoyer_clicked()
{
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    // On pr�pare le paquet � envoyer
    // On ajoute un 0 pour signaler un message a destination du chat
    QString messageAEnvoyer = '0' + tr("<strong>") + pseudo->text() +tr("</strong> : ") +message->text();
    std::cout << "Message a envoyer: " << messageAEnvoyer.toStdString() << std::endl;

    out << (quint16) 0;
    out << messageAEnvoyer;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));

    socket->write(paquet); // On envoie le paquet

    message->clear(); // On vide la zone d'�criture du message
    message->setFocus(); // Et on remet le curseur � l'int�rieur
}

// Appuyer sur la touche Entr�e a le m�me effet que cliquer sur le bouton "Envoyer"
void FenClient::on_message_returnPressed()
{
    on_boutonEnvoyer_clicked();
}

//Fonction qui prend un string correspondant � une action de jeu, lui ajoute 1, et l'envoie au serveur

void FenClient::sendGameAction(QString str){

    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    // On pr�pare le paquet � envoyer
    QString messageAEnvoyer = '1'+ tr("<strong>") + pseudo->text() +tr("</strong> : ");
    messageAEnvoyer.append(str);


    out << (quint16) 0;
    out << messageAEnvoyer;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));

    socket->write(paquet); // On envoie le paquet
    message->clear(); // On vide la zone d'�criture du message
    message->setFocus(); // Et on remet le curseur � l'int�rieur
}

// On a re�u un paquet (ou un sous-paquet)
void FenClient::donneesRecues()
{
    /* M�me principe que lorsque le serveur re�oit un paquet :
    On essaie de r�cup�rer la taille du message
    Une fois qu'on l'a, on attend d'avoir re�u le message entier (en se basant sur la taille annonc�e tailleMessage)
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


    // Si on arrive jusqu'� cette ligne, on peut r�cup�rer le message entier
    QString messageRecu;
    in >> messageRecu;


    std::cout << "Message recu: "  << messageRecu.toStdString() << std::endl;

    //Si le premier carat�re est 0 on le supprime et on affiche le message dans le chat
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

    // On remet la taille du message � 0 pour pouvoir recevoir de futurs messages
    tailleMessage = 0;


}

// Ce slot est appel� lorsque la connexion au serveur a r�ussi
void FenClient::connecte()
{
    listeMessages->append(tr("<em>Connexion r�ussie !</em>"));
    boutonConnexion->setEnabled(true);
}

// Ce slot est appel� lorsqu'on est d�connect� du serveur
void FenClient::deconnecte()
{
    listeMessages->append(tr("<em>D�connect� du serveur</em>"));
}

// Ce slot est appel� lorsqu'il y a une erreur
void FenClient::erreurSocket(QAbstractSocket::SocketError erreur)
{
    switch(erreur) // On affiche un message diff�rent selon l'erreur qu'on nous indique
    {
        case QAbstractSocket::HostNotFoundError:
            listeMessages->append(tr("<em>ERREUR : le serveur n'a pas pu �tre trouv�. V�rifiez l'IP et le port.</em>"));
            break;
        case QAbstractSocket::ConnectionRefusedError:
            listeMessages->append(tr("<em>ERREUR : le serveur a refus� la connexion. V�rifiez si le programme \"serveur\" a bien �t� lanc�. V�rifiez aussi l'IP et le port.</em>"));
            break;
        case QAbstractSocket::RemoteHostClosedError:
            listeMessages->append(tr("<em>ERREUR : le serveur a coup� la connexion.</em>"));
            break;
        default:
            listeMessages->append(tr("<em>ERREUR : ") + socket->errorString() + tr("</em>"));
    }

    boutonConnexion->setEnabled(true);
}
