#include "continent.h"
#include "game_state.h"
#include "army.h"

int Continent::quantity_of_continents = 0;
map <string, Continent*> Continent::name_to_continent=map<string, Continent*>();

Continent::Continent(string name, int troop_bonus)
{
    this->name = name;
    this->troop_bonus = troop_bonus;
    this->id = ++Continent::quantity_of_continents;
    Continent::name_to_continent.insert(pair<string, Continent*> (name, this));
}

void Continent::add_country (Country* country)
{
    countries.insert(country);
}

Continent* Continent::get_continent (string continent_name)
{
    return name_to_continent[continent_name];
}

bool Continent::is_owned_by (Player* player, Game_State* game_state)
{
    set<Country*>::iterator it;
    for (it = countries.begin(); it != countries.end(); ++it){
        if (game_state->owner((*it)) != player)
        {
            return false;
        }
    }
    return true;
}


int Continent::get_troop_bonus ()
{
    return this->troop_bonus;
}

set<Country*> Continent::get_countries ()
{
    return this->countries;
}

string Continent::toString()
{
    return this->name;
}

