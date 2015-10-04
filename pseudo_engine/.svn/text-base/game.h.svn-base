#ifndef GAME_H
#define GAME_H

#include <string>
#include <set>
#include <vector>
#include "objectives.h"

using namespace std;

class Player; //forward declaration
class Game_State; //forward declaration
class Global_Settings; //forward declaration
class Initial_Settings; //forward declaration

class Game
{
private:

    Global_Settings *global_settings;
    vector<Player*> ordered_players;
    map<Player*, Abstract_Objective*> objectives;
    int current_player_index;
    map<Country*, Army*> current_armies;
    map<Player*, set<Card*> > hands;
    stack<Card*> deck;
    int reward_index;

    void set_player_order(set<Player*> players);
    void deal_objectives(set<Abstract_Objective*> objs);
    void deal_countries(set<Country*> countries);
    void initialize_hands();
    void build_deck(set<Card*> cards);
    void broad_global_settings();
    void first_move_part();

public:
    void play();
    Game(char* conf_file_path, set<Player*> players);
    ~Game();
};

#endif // GAME_H
