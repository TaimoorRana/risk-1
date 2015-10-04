#include <map>
#include <set>
#include <vector>
#include <string>

#include "game_state.h"
#include "army.h"
#include "global_settings.h"


Game_State::Game_State(){

}

Game_State::Game_State(Initial_Settings* initial_settings)
{
    this->initial_settings = initial_settings;
    // . . .
}


Army* Game_State::get_army (Country* coutry)
{
    return current_armies[coutry];
}

Player* Game_State::owner (Country * country)
{
    Army* army = this->get_army(country);
    return army->get_owner();
}

list<Country*> Game_State::countries_owned_by (Player* player)
{
    list<Country*> owned_countries;
    map <Country*, Army*>::iterator it;
    for(it = current_armies.begin(); it != current_armies.end(); it++) {
        Country* country = it->first;
        Army* army = it->second;
        if (army->get_owner() == player)
        {
            owned_countries.insert(owned_countries.end(), country);
        }
    }
    return owned_countries;
}

Step* Game_State::get_current_step ()
{
    return this->current_step;
}

void Game_State::set_step (Step* new_step)
{
    this->current_step = new_step;
}

Player* Game_State::get_current_player ()
{
    return this->current_player;
}
void Game_State::set_player (Player* new_player)
{
    this->current_player = new_player;
}

set <Card*> Game_State::get_hand (Player* player)
{
    return this->hands[player];
}

//    Player* get_next_player ()
//    {
//        int id = current_player->get_id();
//        int size = (initial_settings->all_players).size();
//        for (int i=1; i<size; i++){
//            id = (id+i)%size;
//            Player* player = (initial_settings->all_players)[id];
//            if (still_playing.at(player)) return player;
//        }
//        return NULL; // current player is the only one playing the match
//    }


Global_Settings* Game_State::get_global_settings()
{
    return global_settings;
}

Initial_Settings* Game_State::get_initial_settings()
{
    return initial_settings;
}

map <Player*, Player*> Game_State::get_defeated_players()
{
    return this->was_defeated_by;
}

void Game_State::add_into_defeated (Player* defeated, Player* conqueror)
{
    this->was_defeated_by.insert(pair<Player*,Player*> (defeated, conqueror));
}

int Game_State::get_reward_index(){
    return reward_index;
}


void Game_State::update_reward_index(Global_Settings* gs){
    int l=gs->get_reward_values().size() - 1;
    if(reward_index < l)
    {
        reward_index++;
        return;
    }
    else
        return;
}

void Game_State::draw(Player* player){
    Card* tmp_card=deck.top();
    deck.pop();
    hands[player].insert(tmp_card);
}

map <Player*, set<Card*> > Game_State::get_hands(){
    return hands;
}


