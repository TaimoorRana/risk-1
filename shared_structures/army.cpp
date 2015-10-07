#include "army.h"
#include "game_state.h"

#include <list>

class Country;

Army::Army (Player * owner, int number_of_armies) : 
        owner_(owner), number_of_armies_(number_of_armies) {}

void Army::modify_army (int delta_nb_armies){
    number_of_armies_ += delta_nb_armies;
}

void Army::set_number_of_armies(int number_of_armies){
    number_of_armies_ = number_of_armies; 
}

void Army::set_owner(Player *owner){ owner_ = owner; }

//useful when a territory is dominated by another player
void Army::conquered_by (Player* new_player, int new_armies, GameState* GameState){
    // Verify if previous owner player was defeated
    std::list<Country*> owned_countries = GameState->countries_owned_by(owner_);
    if (owned_countries.size() == 1) // His only remaining country has just been conquered
    {
        GameState->add_into_defeated(owner_, new_player);
    }
    // Update army object fields
    owner_ = new_player;
    number_of_armies_ = new_armies;
}

Player* Army::get_owner () { return owner_; }

int Army::get_number_of_armies (){ return this->number_of_armies; }

