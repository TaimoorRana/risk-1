EngineInitialSettings::EngineInitialSettings(InitialSettings initial_settings) :
					   InitialSettings(initial_settings) {  
}

std::vector<Player*> EngineInitialSettings::get_players() const {
	return players_;
}

std::map<Player*, std::set<Country*> > EngineInitialSettings::get_territories const {
	return territories_;
}

std::map<Player*, std::set<Country*> > EngineInitialSettings::get_players_objectives const {
	return players_objectives_;
}
