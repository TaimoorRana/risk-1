#ifndef Connected_component_H
#define Connected_component_H

class Game_State;
class Country_Parameters;
class Probabilities;
class Country;

#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;


class Connected_component
{
public:
    Connected_component(map<Country*,set<Country*> >* world_map, Game_State* gs, Probabilities* proba);
    ~Connected_component();

    void add(Country* country);

    void computeCountriesParameters();

    bool operator>=(const Connected_component& otherComponent) const;

private:
    vector<Country*> connected_countries;
    vector<Country_Parameters*> connectedCountriesParameters;

    // float continentOccupation[6];

    int troops;
    int nbCountries;
    int borders;
    int necessaryTroopsDefense; // Back up troops necessary to defend with 50% proba

    map<Country*,set<Country*> > world_map;
    Game_State* gs;
    Probabilities* proba;

};

#endif // Connected_component_H
