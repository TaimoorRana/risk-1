#include "pseudo_net/client_utils.h"
#include "interfaces/player.h"


int main(int argc, char *argv[])
{
    Client_Utils *client_utils = new Client_Utils();
    Player *player;

    client_utils->connect();


    return 0;
}
