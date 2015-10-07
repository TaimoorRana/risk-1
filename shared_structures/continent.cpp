#include "continent.h"

#include "army.h"
#include "game_state.h"

Continent::Continent(std::string name, int troop_bonus) : name_(name), troop_bonus_(troop_bonus){
    name_to_continent_ [name_] = this;
    id_ = name_to_continent_.size();
}

void Continent::add_country (Country* country){
    countries_.insert(country);
}

Continent* Continent::get_continent (std::string name){
    return name_to_continent_[name];
}

bool Continent::is_owned_by (Player* player, GameState* GameState) const{
    for (Country *country : countries_){
        if (GameState->owner(country) != player) {
            return false;
        }
    }
    return true;
}

int Continent::get_troop_bonus () const { return troop_bonus_; }

std::set<Country*> Continent::get_countries () const { return countries_; }

std::string Continent::get_name() const { return name_; }

