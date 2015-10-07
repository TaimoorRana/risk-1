#ifndef CONTINENT_H
#define CONTINENT_H

#include <map>
#include <set>
#include <string>

class Country; //forward declaration
class Player; //forward declaration
class GameState; //forward declaration

class Continent{
    
public:

    Continent(std::string name, int troop_bonus);

    static Continent* get_continent (std::string name) const;

    void add_country (Country* country);
    std::string get_name() const;
    bool is_owned_by (Player* player, GameState* game_state) const;
    int get_troop_bonus () const;
    std::set<Country*> get_countries () const;


private:
    static std::map <std::string, Continent*> name_to_continent_;
    std::string name_;
    int troop_bonus_;
    std::set<Country*> countries_;
    int id_;
};

#endif // CONTINENT_H
