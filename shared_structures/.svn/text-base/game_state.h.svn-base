#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <map>
#include <set>
#include <stack>
#include <list>

#include "steps.h"

using namespace std;

class Player; //forward declaration
class Country; //forward declaration
class Continent; //forward declaration
class Card; //forward declaration
class Army; //forward declaration
class Global_Settings; //forward declaration
class Initial_Settings; //forward declaration

class Game_State
{

public:

    Game_State();

    Game_State(Initial_Settings* initial_settings);

    Army* get_army (Country* coutry);

    Player* owner (Country * country);

    list<Country*> countries_owned_by (Player* player);

    Step* get_current_step ();
    void set_step (Step* new_step);

    Player* get_current_player ();
    void set_player (Player* new_player);

    set <Card*> get_hand (Player* player);

//    Player* get_next_player ();

    Global_Settings* get_global_settings();

    Initial_Settings* get_initial_settings();

    map <Player*, Player*> get_defeated_players();

    void add_into_defeated (Player* defeated, Player* conqueror);

    int get_reward_index();

    void update_reward_index(Global_Settings *gs);

    void draw(Player* player);

    map <Player*, set<Card*> > get_hands();

private:

    Global_Settings* global_settings;
    Initial_Settings* initial_settings;

    Player* current_player;
    Step* current_step;

    map <Country*, Army*> current_armies;
    map <Player*, set<Card*> > hands;
    map <Player*, Player*> was_defeated_by;
    stack <Card*> deck;

    int reward_index;
};

#endif // GAME_STATE_H
