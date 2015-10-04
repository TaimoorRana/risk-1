#include "pseudo_engine/game.h"
#include "pseudo_net/fake_client.h"
#include "pseudo_net/server_utils.h"

int main(int argc, char *argv[])
{

    Server* server = new Server();
    int number_of_players = 3;

    server->connection(number_of_players);
    set<Player*> players = server_utils->get_players();

    Game *game = new Game("conf_file_name", players);

    // chat: recevoir  + envoyer les messages
    game->play();

    server->disconnect();

    return 0;
}
