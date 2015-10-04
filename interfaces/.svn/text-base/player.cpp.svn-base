#include "player.h"
#include <vector>
#include <iostream>
#include "./../shared_structures/initial_settings.h"

Player::Player()
{

}

Player::~Player()
{

}

Player* Player::get_player (Initial_Settings* initial_settings, Base_Player::Color color)
{
    vector<Player*> players = initial_settings->all_players;
    for (vector<Player*>::iterator it = players.begin(); it!=players.end(); ++it)
    {
        if ((*it)->get_color() == color) return (*it);
    }
    return NULL; // There isn't a player with the given color
}

