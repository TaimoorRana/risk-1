#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "./../interfaces/player.h"

class Human_Player : Player
{
private:
    map<Country*, set<Country>> graph;
    set <Continent*> continents;
    set <Objective*> objectives;
    vector <int> reward_values;
    vector<Player*> players;
    Objective my_objective;

public:
    Human_Player();
    void receive_global_settings(Global_Settings gs);
    Move first_move(Initial_Settings is);
    Move next_move(Game_State gs);
};

#endif // HUMAN_PLAYER_H
