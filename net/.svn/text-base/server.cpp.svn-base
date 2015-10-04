
#include "server.h"
#include <iostream>

Server::Server()
{
    port=50885; // To replace if required.
    // Création et disposition des widgets de la fenêtre !!!!!!!!
    Serverstate = new QLabel;
    boutonQuitter = new QPushButton(tr("Quit"));
    connect(boutonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(Serverstate);
    layout->addWidget(boutonQuitter);
    setLayout(layout);

    setWindowTitle(tr("Risk585 Server"));

    // Gestion du serveur
    server = new QTcpServer(this);
    if (!server->listen(QHostAddress::Any, port)) // Démarrage du serveur sur toutes les IP disponibles et sur le port 50585
    {
        // Si le serveur n'a pas été démarré correctement
        Serverstate->setText(tr("Server couldn't start. Reason :<br />") + server->errorString());
    }
    else
    {
        // Si le serveur a été démarré correctement
        Serverstate->setText(tr("Server started successfully on port <strong>") + QString::number(server->serverPort()) + tr("</strong>.<br />Players can now connect."));
        connect(server, SIGNAL(newConnection()), this, SLOT(newConnexion())); //PAY ATTENTION TO CONNEXION AND CONNECTION !!!!!
    }

    messageLength = 0;
    id_count=0;

}

void Server::newConnexion()
{
    qDebug() << "OK";
    QJsonObject tosend;

    tosend["key"]=7;
    tosend["text"]=tr("<em>Someone just connected</em>");

    send_message(tosend);

    qDebug() << "OK";

    QTcpSocket *nouveauClient = server->nextPendingConnection();
    clients << nouveauClient;
    id_count++;
    int playerid = id_count;
    map.insert(playerid, nouveauClient);
    ids.append(playerid);
    //qDebug()<<ids[0];
    connect(nouveauClient, SIGNAL(readyRead()), this, SLOT(receive_message()));
    connect(nouveauClient, SIGNAL(disconnected()), this, SLOT(disconnectClient()));

    //send_message(tosend);



    //QString pid;
    //pid.setNum(playerid);

    QList<int> l;
    l << playerid;
    qDebug() << "list l : " << l ;
    QJsonObject j;

    j["key"]=0;
    j["id"]=playerid;
    send_message(l,j);
    qDebug() << "End of new connexion";
}

void Server::receive_message()
{

    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0)
        return;
    QDataStream in(socket);


    if (messageLength == 0) // Try to get the message length if we do not know it yet
    {
        if (socket->bytesAvailable() < (int)sizeof(quint64)) // Still not yet
             return;
        in >> messageLength; // If received, we stock it
    }


    if (socket->bytesAvailable() < messageLength) // If still not yet
        return;


    char* s=new char[messageLength];
    qDebug() <<"yo";
    in.readRawData(s,messageLength);
    qDebug() <<"s : "<<s;
    QByteArray receivedMessage_qbyte(s,messageLength);
    qDebug()<< receivedMessage_qbyte;
    delete[] s;
    QJsonDocument docCopie=QJsonDocument::fromBinaryData(receivedMessage_qbyte);
    QJsonObject jsonCopie=docCopie.object();
    qDebug()<< "JSON IS : " << jsonCopie;


    int key=jsonCopie["key"].toInt();
    qDebug() << "key is "<<key;



    //std::cout << "Received from client: " << message.toStdString() << std::endl;


    if(key==5){
    //First Move
    }
    if(key==6){
    //Next Move
    }
    if(key==7){
        send_message(jsonCopie);
    }



    messageLength = 0;
}

void Server::disconnectClient()
{
    QJsonObject j;
    j["key"]=7;
    j["text"]=tr("<em>Someone's gone</em>");
    send_message(j);

    // Tell who
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0)
        return;

    clients.removeOne(socket);
    ids.removeOne(map.key(socket));
    map.remove(map.key(socket));

    socket->deleteLater();
}

void Server::send_message(const QJsonObject j)
{
    qDebug() << j;
    // Preparation of packet
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);



    out << (quint64) 0; // On écrit 0 au début du paquet pour réserver la place pour écrire la taille
    //out << j; // On ajoute le message à la suite
    QJsonDocument doc(j);
    qDebug() << doc;

    QByteArray bin=doc.toBinaryData();
    qDebug() << "bin : " <<bin.length()<<"\n";
    qDebug() << 1<< paquet.length() <<"\n";
    paquet.append(bin);
    qDebug() << 2<< paquet.length()<<"\n";
    out.device()->seek(0); // On se replace au début du paquet
    out << (quint64) (paquet.size() - sizeof(quint64)); // On écrase le 0 qu'on avait réservé par la longueur du message
    qDebug() << 3 << paquet.length()<<"\n";;

    if(clients.size()>0)
        for (int i = 0; i < clients.size(); i++)
        {
            //std::cout << "Envoi a joueur " << clients[i] << " : " << message.toStdString() << std::endl;
            int numberOfWrittenBytes=clients[i]->write(paquet);
           // std::cout << "Nombre d'octets ecrits: " << numberOfWrittenBytes << std::endl;

        }
}

void Server::send_message(const QList<int> playerids,const QJsonObject j)
{
    qDebug() << j;
    // Preparation of packet
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);


    out << (quint64) 0; // On écrit 0 au début du paquet pour réserver la place pour écrire la taille
    //out << j; // On ajoute le message à la suite
    QJsonDocument doc(j);
    qDebug() << doc;

    QByteArray bin=doc.toBinaryData();
    qDebug() << bin;
    paquet.append(bin);
    out.device()->seek(0); // On se replace au début du paquet
    out << (quint64) (paquet.size() - sizeof(quint64)); // On écrase le 0 qu'on avait réservé par la longueur du message


    //qDebug() << playerids;
    qDebug() << "\nSending to ids";
    if(playerids.size()>0)
        for (int i = 0; i < playerids.size(); i++)
        {
            //std::cout << "Envoi a joueur " << playerids[i] << " (QTcpSocket*: " << map.value(playerids[i]) << ")" << std::endl;
            (map.value(playerids[i]))->write(paquet);

        }
    qDebug() << "\nSent";


}
/*
/*QJsonObject Server::setUpObjects(QMap<void*, int> &pointeurMap ){

    QJsonObject json;
    int indexObjet=0; //on compte le nombre d'objets que l'on recense

    //-----On recupere les pays
    QJsonArray paysTab;
    set <Country*> listePays=Global_Settings::get_countries();
    json["nbPays"]=listePays.size();
    for (std::set<Country*>::iterator it=listePays.begin() ; it!=listePays.end() ; ++it){
        paysTab.append(**it.serialize());
        pointeurMap.insert(*it,indexObjet);
        indexObjet++;
    }
    json["pays"]=paysTab;

    //-----On recupere les continents
    QJsonArray continentsTab;
    set <Continents*> listeContinents=Global_Settings::get_continents();
    json["nbContinents"]=listeContinents.size();
    for (std::set<Continents*>::iterator it=listeContinents.begin() ; it!=listeContinents.end() ; ++it){
        continentsTab.append(**it.serialize());
        pointeurMap.insert(*it,indexObjet);
        indexObjet++;
    }
    json["continents"]=continentsTab;

    //-----On recupere les cards
    QJsonArray cardsTab;
    set <Card*> listeCard=Global_Settings::get_cards();
    json["nbCards"]=listeCard.size();
    for (std::set<Card*>::iterator it=listeCard.begin() ; it!=listeCard.end() ; ++it){
        cardsTab.append(**it.serialize());
        pointeurMap.insert(*it,indexObjet);
        indexObjet++;
    }
    json["cards"]=cardsTab;

    //-----On recupere les objectifs
    QJsonArray objectivesTab;
    set <Objective*> listeObjectives=Global_Settings::get_objectives();
    json["nbObjectives"]=listeObjectives.size();
    for (std::set<Objective*>::iterator it=listeObjectives.begin() ; it!=listeObjectives.end() ; ++it){
        objectivesTab.append(**it.serialize());
        pointeurMap.insert(*it,indexObjet);
        indexObjet++;
    }
    json["obj"]=objectivesTab;


    return json;


}
*/
