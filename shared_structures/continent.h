#ifndef CONTINENT_H
#define CONTINENT_H

#include <set>
#include <string>
#include <map>


using namespace std;

class Country; //forward declaration
class Player; //forward declaration
class Game_State; //forward declaration

class Continent
{
public:

    Continent(string name, int troop_bonus);

    void add_country (Country* country);

    string toString();

    static Continent* get_continent (string continent_name);

    bool is_owned_by (Player* player, Game_State* game_state);

    static int quantity_of_continents; // Initialized as zero with command int Continent::quantity_of_continents = 0;

    int get_troop_bonus ();
    set<Country*> get_countries ();
//    QJsonObject serialize(QMap<void*, int> &pointeurMap);
//    void deserialize(QMap<void*, int> &pointeurMap,QJsonObject json);


private:
    string name;
    int troop_bonus;
    set<Country*> countries;
    int id;
    static map <string, Continent*> name_to_continent;
};

#endif // CONTINENT_H
