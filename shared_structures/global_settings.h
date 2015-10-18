#ifndef GLOBAL_SETTINGS_H
#define GLOBAL_SETTINGS_H

#include <map>
#include <set>
#include <vector>

class Continent;
class Card;
class Country;
class Objective;

class GlobalSettings : public Structure {

public:
    GlobalSettings();
    GlobalSettings(char* data_file_name, std::set<Objective*> objectives);
    GlobalSettings(char* data_file_name);

    std::set<Country*> get_neighbours (Country * country) const;

    std::set<Continent*> get_continents () const;

    std::map <Country*, std::set<Country*> > get_graph () const;

    std::set <Country*> get_countries() const;

    std::set <Card*> get_cards () const;

    std::set <Objective*> get_objectives () const;

    std::vector <int> get_reward_values() const;

private:

    std::set <Continent*> continents_;
    std::map <Country*, std::set<Country*> > graph_;
    std::set <Card*> cards_;
    std::set <Objective*> objectives_;
    std::vector <int> reward_values_;
};

#endif // GLOBAL_SETTINGS_H
