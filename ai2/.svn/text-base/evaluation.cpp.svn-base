#include "evaluation.h"

#include "shared_structures/country.h"
#include "shared_structures/game_state.h"
#include "shared_structures/global_settings.h"
#include "connected_component.h"
#include "probabilities.h"

#include <stdlib.h> // for dinamic allocation

Evaluation::Evaluation(map<Country*, set<Country*> >* world_map, Game_State *gs)
{
    this->world_map = world_map;
    this->gs = gs;
    probabilities = new Probabilities();
}

Evaluation::~Evaluation()
{
    if(!connected_components.empty())
    {
        for(vector<Connected_component*>::iterator it = connected_components.begin(); it != connected_components.end(); ++it)
        {
            delete (*it);
        }
    }
}

void Evaluation::computeConnectedComponents()
{
    // Do not use 42 here as it might change from outside this file
    // Rather obtain the number of countries from Global Settings
    int nb_countries = gs->get_global_settings()->get_countries().size();
    //bool markedCountries[42]; Must be allocated dinamically
    bool* markedCountries = (bool*) malloc (nb_countries * sizeof(bool));

    for(int i=0; i<nb_countries; i++)
    {
        markedCountries[i]=0;
    }

    stack<Country*> pile;
    list<Country*> countries = gs->countries_owned_by(gs->get_current_player());
    for (list<Country*>::iterator it = countries.begin(); it!=countries.end(); ++it)
    {
        markedCountries[(*it)->get_id()]=1;
        pile.push(*it);
    }



    while(!pile.empty()){
        Country* elem = pile.top();
        pile.pop(); // void
        if (markedCountries[elem->get_id()]==0){continue;}
        else{
            stack<Country*> parcours;
            Connected_component* connected_comp = new Connected_component(world_map, gs, probabilities);
            parcours.push(elem);
            while(!parcours.empty()){
                Country* father = parcours.top();
                parcours.pop(); // void
                if(markedCountries[father->get_id()]==0){continue;}
                else{
                    markedCountries[father->get_id()]=0;
                    connected_comp->add(father);

                    set<Country*> sons = (world_map->find(father))->second;

                    for(set<Country*>::iterator son = sons.begin(); son!=sons.end(); ++son)
                    {
                        if(gs->owner(*son) == gs->get_current_player()){
                            parcours.push(*son);
                        }
                    }
                }
            }
            connected_components.push_back(connected_comp);
        }
    }
}

void Evaluation::sortConnectedComponents(){
    for(vector<Connected_component*>::iterator it = connected_components.begin(); it!=connected_components.end();it++){
        it->computeCountriesParameters();
    }
    sort(connected_components.begin(),connected_components.end());
}




