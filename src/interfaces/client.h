#ifndef CLIENT_H
#define CLIENT_H

#include <QtGui>
#include <QtNetwork>
#include <string>
#include <QString>
#include <QTcpServer>

#include "./../shared_structures/moves.h"
#include "./../interfaces/player.h"

using namespace std;

class Player; //forward declaration
class Initial_Settings; //forward declaration
class Game_State; //forward declaration

class Client_Manager : public Player
{
private:
    Client_Manager(QTcpSocket* s);
    void send_message(const QString &msg);
    void receive_message(const QString &msg);
    QTcpSocket* socket_client;
public:
    Client_Manager();
    ~Client_Manager();
    void disconnect();
    void receive_global_settings();
    Dispatch_Move first_move(Initial_Settings is);
    Move next_move(Game_State gs);
};

#endif // CLIENT_H
