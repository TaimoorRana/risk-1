PlayerInitialSettings::PlayerInitialSettings(InitialSettings initial_settings) :
					   InitialSettings(initial_settings) {  
}

std::vector<Player*> PlayerInitialSettings::get_players() const {
	return players_;
}

std::map<Player*, std::set<Country*> > PlayerInitialSettings::get_territories const {
	return territories_;
}