#ifndef INITIAL_SETTINGS_H
#define INITIAL_SETTINGS_H


#include <vector>
#include <set>
#include <map>
//#include "../engine/objectives.h"
//#include <QJsonObject>
//#include <QMap>
#include "steps.h"

class Player; //forward declaration
class Country; //forward declaration
class Objective; //forward declaration

using namespace std;

class Initial_Settings {

public:
    Initial_Settings();
    Initial_Settings(vector<Player*> all_players, map<Player*, set<Country*> > territories, map<Player*,Objective*> players_objectives, Dispatch_Step step);
    vector<Player*> all_players; // Players who will join the match
    map<Player*, set<Country*> > territories; // Initial territories' distribution
    map<Player*,Objective*> players_objectives;
    Dispatch_Step step;
//    QJsonObject serialize(QMap<void*, int> &pointeurMap);
//    QJsonObject deserialize(QMap<void*, int> &pointeurMap, QJsonObject json);
};

#endif // INITIAL_SETTINGS_H
