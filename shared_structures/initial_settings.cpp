#include "initial_settings.h"

Initial_Settings::Initial_Settings(vector<Player*> all_players, map<Player*, set<Country*> > territories, map<Player*,Objective*> players_objectives, Dispatch_Step step)
{
    this->all_players = all_players;
    this->territories = territories;
    this->players_objectives = players_objectives;
    this->step = step;
}
