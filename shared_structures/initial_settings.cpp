#include "initial_settings.h"

InitialSettings::InitialSettings(std::vector<Player*> all_players, std::map<Player*, std::set<Country*> > territories, 
								std::map<Player*,Objective*> players_objectives, Dispatch_Step step) :
								all_players_(all_players),
								territories_(territories),
								players_objectives_(players_objectives),
								step_(step) {
}
