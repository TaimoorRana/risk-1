#ifndef GAME_H
#define GAME_H

#include "./../shared_structures/global_settings.h"
#include "./../shared_structures/initial_settings.h"
#include "./../shared_structures/game_state.h"

class Game
{
public:
    Game(std::set<Player*> players);
    ~Game();
    void play();

private:
    GlobalSettings* global_settings_;
    InitialSettings* initial_settings_;
    GameState* game_state_;
    
    InitialSettings* initialize_game(std::set<Player*> players);
    std::map<Player*, Army*> first_move();
    int number_of_backups(int number_of_territories);
};

#endif // GAME_H
