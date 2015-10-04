#ifndef GAME
#define GAME

#include "../shared_structures/country.h"
#include "../shared_structures/army.h"
#include "../interfaces/player.h"
#include "../shared_structures/steps.h"
#include "../shared_structures/global_settings.h"
#include "../shared_structures/initial_settings.h"
#include "../shared_structures/game_state.h"
#include "../shared_structures/continent.h"
#include "../shared_structures/moves.h"
#include "objectives.h"
#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <set>
#include <map>

class Game
{
public:
    Game();
    ~Game();

    Game(Initial_Settings IS);

    //beginning, initial settings
    void first_move();//create initial settings
    //void loop::aux();
    int giveArmies();
    void giveTerritories(Initial_Settings* In_Set);
    //void place1Army(Player player);

    //Move functions
    void displacement(Country* origin, Country* destination, int number_of_armies);
    int* Attack(int troupnumber_origin,int troupnumber_destination);
    bool dispatch_backups(map <Country*,int> to_dispatch,int total_backup_armies);

    //Exchange cards funtions
    int change_cards(Change_Cards_Move cards_change_move);
    void update_cards(Change_Cards_Move cards_change_move);

    //Other functions
    void main_loop (list<Player*> players, Game_State game_state);
    int change_loop ();
    int bonus_backups (Player* player);
    void won_cards (Player* loser);
    Player* get_and_set_next_player( Initial_Settings* is);
    bool won_battle(Army* defender, int destroyed_armies);
    void addTroops(map <Country*,Army*> to_dispatch);



private:
    Initial_Settings * In_Set;
    Global_Settings m_global_settings;
    Game_State m_game_state;

    map <Player*,Objective*> * objectives;
    map <Player*,set<Country> > * territories;
    map <Country*,Army*> * armies;

    int m_nbplayers;
};


#endif // GAME

