#include "army.h"
#include "game_state.h"

#include <list>

class Country;

Army::Army (Player * const owner, int number_of_armies) :
        owner_(owner), number_of_armies_(number_of_armies) {}

void Army::modify_army (int delta_nb_armies){
    number_of_armies_ += delta_nb_armies;
}

void Army::set_number_of_armies(int number_of_armies){
    number_of_armies_ = number_of_armies; 
}

void Army::set_owner(Player * const owner){ owner_ = owner; }

//useful when a territory is dominated by another player
void Army::conquered_by (Player * const new_player, int new_armies, GameState * const game_state){
    // Verify if previous owner player was defeated
    std::list<Country*> owned_countries = game_state->countries_owned_by(owner_);
    if (owned_countries.size() == 1) // His only remaining country has just been conquered
    {
        game_state->add_into_defeated(owner_, new_player);
    }
    // Update army object fields
    owner_ = new_player;
    number_of_armies_ = new_armies;
}

Player* Army::get_owner () const { return owner_; }

int Army::get_number_of_armies () const { return number_of_armies_; }

