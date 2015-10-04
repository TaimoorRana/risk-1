#include "objectives.h"
#include <vector>
#include "./../shared_structures/continent.h"
#include "./../shared_structures/base_player.h"
#include "./../interfaces/player.h"


Dominate_18_territories::Dominate_18_territories()
{
    this->description = "Conquer 18 territories with "
                        "at least two armies in each of them";
    this->id = 1;
}

bool Dominate_18_territories::is_accomplished(Game_State* game_state, Player* player)
{
    int conquered = 0;
    list<Country*> owned = game_state->countries_owned_by (player);
    for (list<Country*>::iterator it = owned.begin(); it != owned.end(); ++it)
    {
        if (game_state->get_army((*it))->get_number_of_armies() >= 2)
            conquered++;
    }
    return conquered >= 18;
}


Conquer_24_territories::Conquer_24_territories()
{
    this->description = "Conquer 24 territories";
    this->id = 2;
}

bool Conquer_24_territories::is_accomplished(Game_State* game_state, Player* player)
{
    list<Country*> owned = game_state->countries_owned_by (player);
    return owned.size() >= 24;
}


Conquer_both_continents::Conquer_both_continents(string continent1, string continent2)
{
    this->description = string("Conquer both ")+continent1+" and "+continent2;
    this->id = 3;
    this->name1 = continent1;
    this->name2 = continent2;
}

bool Conquer_both_continents::is_accomplished(Game_State* game_state, Player* player)
{
    Continent* c1 = Continent::get_continent(name1);
    Continent* c2 = Continent::get_continent(name2);
    return c1->is_owned_by(player, game_state) && c2->is_owned_by(player, game_state);
}

Conquer_both_and_any_other::Conquer_both_and_any_other(string continent1, string continent2)
{
    this->description = string("Conquer both ")+continent1+" and "+continent2
                         + " and any other third continent";
    this->id = 4;
    this->name1 = continent1;
    this->name2 = continent2;
}


bool Conquer_both_and_any_other::is_accomplished(Game_State* game_state, Player* player)
{
    Continent* c1 = Continent::get_continent(name1);
    Continent* c2 = Continent::get_continent(name2);

    if (!(c1->is_owned_by(player, game_state) && c2->is_owned_by(player, game_state)))
        return false; // player doesn't own at least one of required continents

    set<Continent*> all = game_state->get_global_settings()->get_continents();
    for (set<Continent*>::iterator it = all.begin(); it != all.end(); ++it){
        if ((*it)!=c1 && (*it)!=c2 && (*it)->is_owned_by(player, game_state)){
            return true; // third continent conquered
    }   }
    return false;
}


Defeat_Opponent::Defeat_Opponent(Base_Player::Color to_be_defeated)
{
    string opp_name = string(Base_Player::color_names[to_be_defeated]);
    this->description = string("Defeat all ")+opp_name+" armies. "
                        "If the " + opp_name + " player is yourself or it did not join the match or it was defeated by another player,"
                        " the objective becomes to conquer 24 territories";
    this->id = 5;
    this->to_be_defeated = to_be_defeated;
}

bool Defeat_Opponent::is_accomplished(Game_State* game_state, Player* player)
{
    Player* opponent = Player::get_player(game_state->get_initial_settings(), to_be_defeated);
    if (opponent == NULL || opponent == player)
    {// opponent player didn't join the match or is the player owning this objective
        return (new Conquer_24_territories())->is_accomplished(game_state, player);
    }
    map<Player*, Player*> def = game_state->get_defeated_players();
    if (def.find(opponent) != def.end())
    {// yellow player was defeated
        if (def[opponent] == player) return true; // by player owning this objective
        else return (new Conquer_24_territories())->is_accomplished(game_state, player); // by another player
    }
    return false; // opponent player was not defeated
}


set<Abstract_Objective*> get_all_objectives()
{
    set<Abstract_Objective*> all_objectives;
    all_objectives.insert(new Dominate_18_territories());
    all_objectives.insert(new Conquer_24_territories());
    all_objectives.insert(new Conquer_both_continents(string("North_America"),string("Africa")));
    all_objectives.insert(new Conquer_both_continents(string("North_America"),string("Oceania")));
    all_objectives.insert(new Conquer_both_continents(string("Asia"),string("Africa")));
    all_objectives.insert(new Conquer_both_continents(string("Asia"),string("South_America")));
    all_objectives.insert(new Conquer_both_and_any_other(string("Europe"),string("South_America")));
    all_objectives.insert(new Conquer_both_and_any_other(string("Europe"),string("Oceania")));

    for (int i = 0; i < 6; i++)
    {
        Base_Player::Color opponent = static_cast<Base_Player::Color>(i);
        all_objectives.insert(new Defeat_Opponent(opponent));
    }
    return all_objectives;
}

