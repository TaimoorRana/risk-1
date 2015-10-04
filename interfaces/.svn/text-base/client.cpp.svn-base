#include "headers.h"


Client_Manager::Client_Manager(QTcpSocket* s)
{
   socket_client=s;
}

void Client_Manager::send_message(const QString &msg)
{
    QByteArray packet;
    QDataStream out(&packet, QIODevice::WriteOnly);

    out << (quint16) 0; // On écrit 0 au début du paquet pour réserver la place pour écrire la taille
    out << msg; // On ajoute le message à la suite
    out.device()->seek(0); // On se replace au début du paquet
    out << (quint16) (packet.size() - sizeof(quint16)); // On écrase le 0 qu'on avait réservé par la longueur du message



    qDebug() << "Envoi\n";
    this->socket_client->write(packet);

}

void Client_Manager::receive_message(const QString &msg)
{
    qDebug() << "Message recu : " << msg << "\n";
}
