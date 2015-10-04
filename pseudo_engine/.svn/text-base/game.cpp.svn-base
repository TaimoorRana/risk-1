#include "game.h"
#include "./../shared_structures/global_settings.h"
#include "objectives.h"
#include "./../utils/utils.h"


Game::Game(char* conf_file_path, set<Player*> players)
{
    this->global_settings = new Global_Settings(conf_file_path, get_all_objectives());

    set_player_order(players);
    deal_objectives(get_all_objectives());
    deal_countries(global_settings->get_countries());
    initialize_hands();
    reward_index = 0;
    build_deck(global_settings->get_cards());
}

void Game::play()
{
    broad_global_settings();
}

void Game::set_player_order(set<Player*> players)
{
    ordered_players = set_to_vector(players);
    shuffle(ordered_players);
    current_player_index = 0;
}

void Game::deal_objectives(set<Abstract_Objective*> objs)
{
    vector<Abstract_Objective*> ordered_objectives = set_to_vector(objs);
    shuffle(ordered_objectives);
    for(int i = 0; i<ordered_players.size(); i++)
        objectives[ordered_players[i]] = ordered_objectives[i];
}

void Game::deal_countries(set<Country*> countries)
{
    vector<Country*> ordered_countries = set_to_vector(countries);
    shuffle(ordered_countries);
    for(int i = 0; i<ordered_countries.size(); i++)
        current_armies[ordered_countries[i]] = new Army(ordered_players[i%ordered_players.size()], 1);
}

void Game::initialize_hands()
{
    for(int i = 0; i<ordered_players.size(); i++)
    {
        set<Card*> hand;
        hands[ordered_players[i]] = hand;
    }
}

void Game::build_deck(set<Card*> cards)
{
    vector<Card*> ordered_cards = set_to_vector(cards);
    shuffle(ordered_cards);
    for(int i = 0; i<ordered_cards.size(); i++)
        deck.push(ordered_cards[i]);
}

void Game::broad_global_settings()
{
    for(int i = 0; i<ordered_players.size(); i++)
        ordered_players[i]->receive_global_settings();
}

void Game::first_move_part()
{
    map<Player*, set<Country*> > territories;
    for(int i = 0; i<ordered_players.size(); i++)
    {
        set<Country*> owned_countries;
        territories[ordered_players[i]] = owned_countries;
    }
    for(map <Country*, Army*>::iterator it = current_armies.begin(); it != current_armies.end(); ++it)
        territories[it->second->get_owner()] = it->first;

    for(int i = 0; i<ordered_players.size(); i++)
    {
        Dispatch_Step step;
        step.id = 3;
        step.number_of_troops = max(territories[ordered_players[i]].size(), 3);
        Initial_Settings initial_settings(ordered_players, territories, objectives[ordered_players[i]], step);
        Move move = ordered_players[i]->first_move(initial_settings);
        //continue
    }
}

Game::~Game()
{

}

