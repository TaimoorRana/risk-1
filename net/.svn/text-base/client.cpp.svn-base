#include "client.h"
#include "../shared_structures/global_settings.h"
#include <iostream>
#include <QListWidgetItem>
#include <QtNetwork>
#include <QMap>
#include <QtTest/QTest>
#include <string>

Client::Client()
{
    setupUi(this);
    messageLength = 0;
    pointeurMap= new QMap<void*, int>;
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(readyRead()), this, SLOT(receive_message()));
    connect(socket, SIGNAL(connected()), this, SLOT(connecte()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnecte()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(erreurSocket(QAbstractSocket::SocketError)));
    setWindowTitle(tr("Risk585 Client"));

}

/*
void client::setUpObjects(QMap<void*, int> &pointeurMap, QJsonObject json){
    int nbPays = json["nbPays"].toInt();
    int nbContinents = json["nbContinents"].toInt();
    int nbObjectives = json["nbObjectives"].toInt();
    int nbCards = json["nbCards"].toInt();
    int indexObjet = 0;
    int n= json["n"].toInt();

    //on cree les pays
    QJsonArray listePays = json["pays"].toArray();
    for(int i=0; i<nbPays; i++){
        Country* pays= new Country;
        pays.deserialize(listePays[i].toObject());
        pointeurMap.insert(pays,indexObjet);
        indexObjet++;
    }

    //on cree les continents
    QJsonArray listeContinents = json["continents"].toArray();
    for(int i=0; i<nbContinents; i++){
        Continent* continent= new Continent;
        continent.deserialize(listeContinents[i].toObject());
        pointeurMap.insert(continent,indexObjet);
        indexObjet++;
    }

    //on cree les cards
    QJsonArray listeCards = json["cards"].toArray();
    for(int i=0; i<nbCards; i++){
        Card* card= new Card;
        card.deserialize(listeCards[i].toObject());
        pointeurMap.insert(card,indexObjet);
        indexObjet++;
    }

    //on cree les objectifs
    QJsonArray listeObjectives = json["obj"].toArray();
    for(int i=0; i<nbObjectives; i++){
        Objective* obj= new Objective;
        obj.deserialize(listeObjectives[i].toObject());
        pointeurMap.insert(obj,indexObjet);
        indexObjet++;
    }
}
*/
void Client :: receive_message(){
    //this->setCursor(Qt::IBeamCursor);
    qDebug() << "Receiving";
    QDataStream in(socket);

    if (messageLength == 0)
    {
        if (socket->bytesAvailable() < (int)sizeof(quint64))
             return;
        in >> messageLength;
        qDebug() <<messageLength;
    }
    //qDebug() <<"I'm here";
    qDebug() << socket->bytesAvailable();
    if (socket->bytesAvailable() < messageLength){
        qDebug() << "ERREUUUUUUUUURRRRRRRRRRRRRRRRR";
        return;
    }
    //qDebug() <<"Now, I'm here";



    char* s=new char[messageLength];
    qDebug() <<"yo";
    in.readRawData(s,messageLength);
    qDebug() <<"s : "<<s;
    QByteArray receivedMessage_qbyte(s,messageLength);
    qDebug()<< "\nreceivedMessage_qbyite is : " << receivedMessage_qbyte;
    delete[] s;
    QJsonDocument docCopie=QJsonDocument::fromBinaryData(receivedMessage_qbyte);
    QJsonObject jsonCopie=docCopie.object();
    qDebug()<< "\nJSON IS : " << jsonCopie;

    int key=jsonCopie["key"].toInt();
    qDebug() << "\nkey is "<<key;

    if(key==0){
    //PlayerId
        //this.set_id(receivedMessage.remove(0,1));
        int myid=jsonCopie["id"].toInt();
        QString textid="my id is : %1";
        textid=textid.arg(myid);
        listeMessages->append(textid);
    }

    if (key==1){
        //Deserializing
    }

    if(key==2){
        // GlobalSettings
    }
    if(key==3){
    //InitialSettings
    }
    if(key==4){
    //GameState
    }

    if(key==7){
        qDebug() << "\n Receiving a chat message";
        QJsonValue h=jsonCopie["text"];
        qDebug() << "\nh created";
        QString st=jsonCopie["text"].toString();
        qDebug() << "\nst created";
        listeMessages->append(st);

    //Text received from server, show it somewhere, depends on the window...
    }
    messageLength=0;
    qDebug() << "\n messageLength reset";
}

void Client::on_boutonConnexion_clicked()
{
    // On annonce sur la fenêtre qu'on est en train de se connecter
    listeMessages->append(tr("<em>Tentative de connexion en cours...</em>"));
    boutonConnexion->setEnabled(false);

    socket->abort(); // On désactive les connexions précédentes s'il y en a
    socket->connectToHost(serveurIP->text(), serveurPort->value()); // On se connecte au serveur demandé


}

void Client::connecte()
{
    qDebug() << "OK";

    listeMessages->append(tr("<em>Connexion réussie !</em>"));
    qDebug() << "OK";

    boutonConnexion->setEnabled(true);
    qDebug() << "OK";

}

void Client :: disconnecte()
    {
        listeMessages->append(tr("<em>Déconnecté du serveur</em>"));
    }

void Client :: erreurSocket(QAbstractSocket::SocketError erreur)
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
void Client::on_boutonEnvoyer_clicked()
{
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    // On pr�pare le paquet � envoyer
    // On ajoute un 0 pour signaler un message a destination du chat
    QString messageAEnvoyer = tr("<strong>") + pseudo->text() +tr("</strong> : ") +message->text();
    std::cout << "Message a envoyer: " << messageAEnvoyer.toStdString() << std::endl;

    QJsonObject tosend;

    tosend["key"]=7;
    tosend["text"]=messageAEnvoyer;


    send_message(tosend);

    message->clear(); // On vide la zone d'�criture du message
    message->setFocus(); // Et on remet le curseur � l'int�rieur
}

void Client :: send_message(QJsonObject j){


    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);
    out << (quint64) 0;
    QJsonDocument doc(j);
    QByteArray bin = doc.toBinaryData();
    paquet.append(bin);
    out.device()->seek(0);
    out << (quint64) (paquet.size() - sizeof(quint64));

    socket->write(paquet); // On envoie le paquet

}
