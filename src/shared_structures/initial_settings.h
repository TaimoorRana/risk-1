#ifndef INITIAL_SETTINGS_H
#define INITIAL_SETTINGS_H

#include <map>
#include <set>
#include <vector>


class Player;
class Country;
class Objective;

class InitialSettings : public Structure {

public:
    InitialSettings();
    InitialSettings(std::vector<Player*> &players, std::map<Player*, std::set<Country*> > &territories,
                    std::map<Player*,Objective*> &players_objectives);

protected:
	InitialSettings(InitialSettings &initial_settings);
    std::vector<Player*> players_; // Players who will join the match.
    std::map<Player*, std::set<Country*> > territories_; // Initial territories' distribution.
    std::map<Player*, Objective*> players_objectives_;
};

#endif // INITIAL_SETTINGS_H
