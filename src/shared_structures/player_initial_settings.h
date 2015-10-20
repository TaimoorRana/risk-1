#ifndef PLAYER_INITIAL_SETTINGS_H
#define PLAYER_INITIAL_SETTINGS_H


class PlayerInitialSettings : private InitialSettings {

public:
    PlayerInitialSettings(InitialSettings &initial_settings);
    std::vector<Player*> get_players() const;
    std::map<Player*, std::set<Country*> > get_territories const;
};

#endif // PLAYER_INITIAL_SETTINGS_H
