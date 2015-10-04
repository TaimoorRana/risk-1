#ifndef GLOBAL_SETTINGS_H
#define GLOBAL_SETTINGS_H

#include <map>
#include <set>
#include <vector>
#include <string>

//#include <QJsonObject>
//#include <QMap>

class Continent; //forward declaration
class Card; //forward declaration
class Country; //forward declaration
class Objective; //forward declaration
class Objective; //forward declaration

using namespace std;


class Global_Settings
{

public:
    Global_Settings();
    Global_Settings(char* data_file_name, set<Objective*> objectives);
    Global_Settings(char* data_file_name);
    set<Country*> get_neighbors (Country * country);

    set<Continent*> get_continents ();

    map <Country*, set<Country*> > get_graph ();

    set <Country*> get_countries();

    set <Card*> get_cards ();

//    QJsonObject serialize(QMap<void*, int> &pointeurMap);
//    QJsonObject deserialize(QMap<void*, int> &pointeurMap);

    set <Objective*> get_objectives ();

    vector <int> get_reward_values();

private:

    set <Continent*> continents;
    map <Country*, set<Country*> > graph;
    set <Card*> cards;
    set <Objective*> objectives;
    vector <int> reward_values;
};

#endif // GLOBAL_SETTINGS_H
