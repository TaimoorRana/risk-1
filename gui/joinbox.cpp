#include "joinbox.h"
#include <iostream>

JoinBox::JoinBox()
{
    setupUi(this);
    client = new Client_Utils(listeMessages);
    connect(boutonConnexion, SIGNAL(clicked()), this, SLOT(connecte()));
    //socket = new QTcpSocket(this);
    /*connect(socket, SIGNAL(readyRead()), this, SLOT(donneesRecues()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(deconnecte()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(erreurSocket(QAbstractSocket::SocketError)));
    //connect(checkBox, SIGNAL(stateChanged(int)),this, SLOT(coche()));//lance coche() si on choche la case
    //connect(checkBox, SIGNAL(stateChanged(int)),this, SLOT(decoche()));//lance decoche() si on d�choche la case
    //connect(pushButton, SIGNAL(clicked()),this, SLOT(pushAction()));//lance pushAction() si on lance l'action 2
    tailleMessage = 0;*/
}

void JoinBox::connecte() {
    client->connect_to(serveurIP->text(), serveurPort->value());
}

void JoinBox::pushAction()
{
    /*
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    // On pr�pare le paquet � envoyer
    QString messageAEnvoyer = tr("<strong>") + pseudo->text() +tr("</strong> a lanc� l'action2' ");

    out << (quint16) 0;
    out << messageAEnvoyer;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));
    socket->write(paquet); // On envoie le paquet

    message->clear(); // On vide la zone d'�criture du message
    message->setFocus(); // Et on remet le curseur � l'int�rieur
    */
}

//Un joueur d�coche l'action1
void JoinBox::decoche()
{
   /* QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    // On pr�pare le paquet � envoyer
    QString messageAEnvoyer = tr("<strong>") + pseudo->text() +tr("</strong> a d�coch� l'action1' ");

    out << (quint16) 0;
    out << messageAEnvoyer;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));

    socket->write(paquet); // On envoie le paquet

    message->clear(); // On vide la zone d'�criture du message
    message->setFocus(); // Et on remet le curseur � l'int�rieur*/
}

//Un joueur coche l'action1
void JoinBox::coche()
{
    /*QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    // On pr�pare le paquet � envoyer
    QString messageAEnvoyer = tr("<strong>") + pseudo->text() +tr("</strong> a coch� l'action1' ");

    out << (quint16) 0;
    out << messageAEnvoyer;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));

    socket->write(paquet); // On envoie le paquet

    message->clear(); // On vide la zone d'�criture du message
    message->setFocus(); // Et on remet le curseur � l'int�rieur*/
}

// Tentative de connexion au serveur
void JoinBox::on_boutonConnexion_clicked()
{
   /* // On annonce sur la fen�tre qu'on est en train de se connecter
    listeMessages->append(tr("<em>Tentative de connexion en cours...</em>"));
    boutonConnexion->setEnabled(false);

    socket->abort(); // On d�sactive les connexions pr�c�dentes s'il y en a
    socket->connectToHost(serveurIP->text(), serveurPort->value()); // On se connecte au serveur demand�*/
}

// Envoi d'un message au serveur
void JoinBox::on_boutonEnvoyer_clicked()
{

    QString messageAEnvoyer =
            tr("<strong>") + pseudo->text() +tr("</strong> : ") +message->text();
    client->send(messageAEnvoyer);
}

// Appuyer sur la touche Entr�e a le m�me effet que cliquer sur le bouton "Envoyer"
void JoinBox::on_message_returnPressed()
{
    on_boutonEnvoyer_clicked();
}

//Fonction qui prend un string correspondant � une action de jeu, lui ajoute 1, et l'envoie au serveur

void JoinBox::sendGameAction(QString str){
/*
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
    */
}

// On a re�u un paquet (ou un sous-paquet)
void JoinBox::donneesRecues()
{

}
