#ifndef COUNTRYPARAMETERS_H
#define COUNTRYPARAMETERS_H

#include"shared_structures/country.h"
#include"shared_structures/game_state.h"
#include"probabilities.h"
#include"interfaces/player.h"


class CountryParameters : public Country
{
public:
    CountryParameters(Country* country, map<Country*, set<Country*> > & world_map, Game_State* gs, Probabilities* proba);
    ~CountryParameters();

    void computeParameters();

    bool operator>=(const CountryParameters& otherCountry) const;

    int troops;
    bool borders;
    float probaDefeat;
    float probaVictory;
    int backupTroopsDefense; // with 50% of success
    int backupTroopsAttack; // with 50% of success
    int enemyPresence;

    Country* weakestCountry;

protected:

    map<Country*,set<Country*> > world_map;
    Game_State* gs;
    Probabilities* proba;

};

#endif // COUNTRYPARAMETERS_H
