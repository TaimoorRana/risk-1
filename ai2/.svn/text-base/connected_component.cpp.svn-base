#include "connected_component.h"

#include "shared_structures/game_state.h"
#include "country_parameters.h"
#include "probabilities.h"

Connected_component::Connected_component(map<Country *, set<Country*> >* world_map, Game_State* gs, Probabilities* proba):world_map(world_map),
    gs(gs), proba(proba), borders(0), nbCountries(0), troops(0), necessaryTroopsDefense(0)
{
}

Connected_component::~Connected_component()
{
    if(!connectedCountriesParameters.empty())
    {
        for(vector<Country_Parameters*>::iterator it = connectedCountriesParameters.begin(); it != connectedCountriesParameters.end(); ++it)
        {
            delete (*it);
        }
    }
}

void Connected_component::add(Country *country){
    connected_countries.push_back(country);
}

void Connected_component::computeCountriesParameters(){
    Country_Parameters* tempCountry(0);
    for(const auto& elem : connected_countries){
        tempCountry = new Country_Parameters(elem, world_map, gs, proba);
        tempCountry->computeParameters();

        borders+=tempCountry->borders;
        troops+=tempCountry->troops;
        necessaryTroopsDefense+=tempCountry->backupTroopsDefense;
        nbCountries+=1;

        connectedCountriesParameters.push_back(tempCountry);
    }

    sort(connectedCountriesParameters.begin(), connectedCountriesParameters.end());

}

bool Connected_component::operator >=(const Connected_component& otherComponent) const{
    float coeff1 = troops+nbCountries-borders+(1.0/necessaryTroopsDefense);
    float coeff2 = otherComponent.troops+otherComponent.nbCountries-otherComponent.borders+(1.0/otherComponent.necessaryTroopsDefense);
    return (coeff1 >= coeff2);
}


