#include "initial_settings.h"

InitialSettings(InitialSettings &initial_settings) :
								players_(initial_settings.players),
								territories_(initial_settings.territories),
								players_objectives_(initial_settings.players_objectives) {
}

InitialSettings::InitialSettings(std::vector<Player*> &all_players, std::map<Player*, std::set<Country*> > &territories,
                                std::map<Player*,Objective*> &players_objectives, DispatchStep *step) :
								players_(players),
								territories_(territories),
								players_objectives_(players_objectives) {
}
