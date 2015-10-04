#ifndef CONNECTEDCOMPONENT_H
#define CONNECTEDCOMPONENT_H

#include "interfaces/player.h"
#include "shared_structures/global_settings.h"
#include "shared_structures/country.h"
#include "ai2/probabilities.h"
#include "shared_structures/game_state.h"
#include <set>
#include "shared_structures/army.h"
#include "shared_structures/continent.h"

class connectedcomponent
{
public:
    connectedcomponent();
    ~connectedcomponent();

    Player* id_player;
    int Nb_components;
    float relevantInformation[42][11];
    /*  The matrix contains all the relevant information that we have for our border country
         *  Each country is represented by a column
         *  The 0th element in column "i" represents if the country "i" is ours: if no, relevantInformation[i][0]=0; if yes and this country face with at least one enemy country relevantInformation[i][0]=1; else relevantInformation[i][0]=2;
         *  The 1th element in column "i" represents the number of armies in country "i"
         *  The 2th element in column "i" represents the number of armies for the strongest enemy
         *  The 3th element in column "i" represents the Id for the strongest enemy
         *  The 4th element in column "i" represents the number of armies that we have to add for having a probability of surviving bigger than 0.5 against the strongest enemy
         *  The 5th element in column "i" represents the probability of surviving against the strongest enemy without additional armies
         *  The 6th element in column "i" represents the number of armies for the weakest enemy
         *  The 7th element in column "i" represents the Id for the weakest enemy
         *  The 8th element in column "i" represents the number of armies that we have to add for having a probability of victory bigger than 0.5 against the weakest enemy
         *  The 9th element in column "i" represents the probability of victory against the weakest enemy without additional armies
         *  The 10th element in column "i" represents the the total number of enemy countries at the border of the country "i"
         *  The 11th element in column "i" represents the Id of the connected component that the occupied country belong to, "0" means this country is not ours.
         */
    float continentOccupation[6];
    /*  The array contains the relative occupation of the continents
         * continentOccupation[i] = Nb of countries of the continent occupied / Nb of countries of the continent
         */
    //Function that find out all the countries in the connected component "component_id"
    int* component_members(int component_id);
    //Function that returns all the countries at the border
    set<Country*> get_border(Country* origin);
    //Function that find out the weakest enemy of a country
    int findWeakestEnemy(Country* country);

private:
    //Function that calculate the matrix continentOccupation line 0 to line 10
    void computeRelevantInformation();
    //Function that calculate the matrix continentOccupation line 11
    void component_id();
    //Function that calculate the vector continentOccupation
    void computeContinentOccupation();

};

#endif // CONNECTEDCOMPONENT_H
