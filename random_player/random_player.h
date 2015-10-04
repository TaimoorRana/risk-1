#ifndef RANDOM_PLAYER_H
#define RANDOM_PLAYER_H

#include <map>
#include <set>
#include "./../interfaces/player.h"

using namespace std;

class Random_Player : public Player {
public:
    Random_Player();
    void receive_global_settings(Global_Settings gs);
    Move first_move(Initial_Settings is);
    Move next_move(Game_State gs);
private:
    map<Country*,set<Country*>> world_map;
};

#endif // RANDOM_PLAYER_H
