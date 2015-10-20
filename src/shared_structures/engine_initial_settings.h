#ifndef PLAYER_INITIAL_SETTINGS_H
#define PLAYER_INITIAL_SETTINGS_H


class EngineInitialSettings : private InitialSettings {

public:
    EngineInitialSettings(InitialSettings &initial_settings);
    std::vector<Player*> get_players() const;
    std::map<Player*, std::set<Country*> > get_territories const;
    std::map<Player*, Objective*> get_players_objectives const;
};

#endif // PLAYER_INITIAL_SETTINGS_H
