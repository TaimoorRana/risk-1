#include "army.h"
#include "game_state.h"



Army::Army (Player * owner, int number_of_armies)
{
    this->owner = owner;
    this->number_of_armies = number_of_armies;
}

void Army::modify_army (int delta_nbarmies)
{
    this->number_of_armies += delta_nbarmies;
}

void Army::set_number_of_armies(int na){
    this->number_of_armies=na;
}

void Army::set_owner(Player *ow){
    this->owner=ow;
}

//useful when a territory is dominated by another player
void Army::conquered_by (Player* new_player, int new_armies, Game_State* game_state)
{
    // Verify if previous owner player was defeated
    list<Country*> owned_countries = game_state->countries_owned_by(owner);
    if (owned_countries.size() == 1) // His only remaining country has just been conquered
    {
        game_state->add_into_defeated(this->owner, new_player);
    }
    // Update army object fields
    this->owner = new_player;
    this->number_of_armies = new_armies;
}

Player* Army::get_owner ()
{
    return this->owner;
}

int Army::get_number_of_armies ()
{
    return this->number_of_armies;
}

