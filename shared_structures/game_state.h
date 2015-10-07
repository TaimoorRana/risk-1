#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <list>
#include <map>
#include <set>
#include <stack>

#include "steps.h"


class Player;
class Country;
class Card;
class Army;
class GlobalSettings;
class InitialSettings;

class GameState{

public:

    GameState();

    GameState(InitialSettings* initial_settings);

    void set_step (Step* new_step);

    void set_current_player (Player* current_player);

    void add_into_defeated (Player* defeated, Player* conqueror);

    void update_reward_index(GlobalSettings *global_settings);

    void draw(Player* player);

    Army* get_army (Country* coutry) const;

    Player* owner (Country * country) const;

    std::list<Country*> countries_owned_by (Player* player) const;

    Step* get_current_step () const;
    
    Player* get_current_player () const;

    std::set<Card*> get_hand (Player* player) const;

    GlobalSettings* get_global_settings() const;

    InitialSettings* get_initial_settings() const;

    std::map<Player*, Player*> get_defeated_players() const;

    int get_reward_index() const;

    std::map<Player*, std::set<Card*> > get_hands() const;

private:

    GlobalSettings* global_settings_;
    InitialSettings* initial_settings_;

    Player* current_player_;
    Step* current_step_;

    std::map <Country*, Army*> current_armies_;
    std::map <Player*, std::set<Card*> > hands_;
    std::map <Player*, Player*> was_defeated_by_;
    std::stack <Card*> deck_;

    int reward_index_;
};

#endif // GAME_STATE_H
