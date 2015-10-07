#include "game_state.h"

#include <string>
#include <vector>

#include "army.h"
#include "global_settings.h"

GameState::GameState(){}

GameState::GameState(InitialSettings* initial_settings) : initial_settings_(initial_settings) {
    // . . .
}


Army* GameState::get_army (Country* coutry){
    return current_armies_[coutry];
}

Player* GameState::owner (Country * country){
    Army* army = get_army(country);
    return army->get_owner();
}

std::list<Country*> GameState::countries_owned_by (Player* player){
    list<Country*> owned_countries;
    for(auto const &e : current_armies_) {
        Country* country = e.first;
        Army* army = e.second;
        if (army->get_owner() == player) {
            owned_countries.insert(owned_countries.end(), country);
        }
    }
    return owned_countries;
}

Step* GameState::get_current_step (){ return current_step_; }

void GameState::set_current_step_ (Step* current_step)
    current_step_ = current_step;
}

Player* GameState::get_current_player () { return current_player_; }

void GameState::set_current_player (Player* current_player) {
    current_player_ = current_player;
}

set <Card*> GameState::get_hand (Player* player){ return hands_[player]; }

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


GlobalSettings* GameState::get_global_settings(){ return global_settings_; }

InitialSettings* GameState::get_initial_settings(){ return initial_settings_; }

std::map <Player*, Player*> GameState::get_defeated_players() { return was_defeated_by_; }


void GameState::add_into_defeated (Player* defeated, Player* conqueror){
    was_defeated_by_[defeated] = conqueror;
}

int GameState::get_reward_index(){ return reward_index_; }

void GameState::update_reward_index(GlobalSettings* global_settings){
    int l = global_settings->get_reward_values().size() - 1;
    if(reward_index_ < l){
        ++reward_index_;
    }
}

void GameState::draw(Player* player){
    Card* tmp_card = deck_.top();
    deck_.pop();
    hands_[player].insert(tmp_card);
}

std::map <Player*, std::set<Card*> > GameState::get_hands(){ return hands_; }


