#ifndef CLIENT_H
#define CLIENT_H
#include "player.h"
#endif // CLIENT_H

/**This file is the interface for the client : Engine <-> InterfaceClient <-> Network
 *
 * It is done to transmit the data between the engine and the network.
 *
 * **/


class InterfaceEngineNetwork : public Player {
public:
    InterfaceEngineNetwork(/*Ici Connexion*/);

private:
    void sendMessage(string s);
    string receiveMessage();
};
