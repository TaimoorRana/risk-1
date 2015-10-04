#include "fortifying.h"
#include <algorithm>
#include <stdlib.h> // for dynamic memory allocation

#include "./../shared_structures/global_settings.h"
#include "./../shared_structures/country.h"
#include "./../shared_structures/game_state.h"
#include "./../shared_structures/initial_settings.h"
#include "./../shared_structures/army.h"
#include "./../shared_structures/country.h"
#include "./../shared_structures/moves.h"
#include "connected_component.h"

Fortifying::Fortifying(Connected_component *c, Game_State* game_state, Initial_Settings *initial_settings, Global_Settings *global_settings, Player* player)
{

    troops=0;

    this->c=c;
    this->game_state=game_state;
    this->player=player;
    this->initial_settings=initial_settings;
    this->global_settings=global_settings;

    // Allocate dynamically memory for distance matrix

    nb_countries = global_settings->get_countries().size();

    distance = (int**)malloc(nb_countries*sizeof(int*));
    for (int i=0; i<nb_countries; i++)
        distance[i] = (int*)malloc(nb_countries*sizeof(int));


    floyd_warshall();
}


Fortifying::~Fortifying()
{
}

//return 1 if i and j are neighbors 0 otherwise
int Fortifying::are_neighbors(int i, int j)
{
    set<Country*> neighbors = global_settings->get_neighbors(Country::get_country(i));
    set<Country*>::iterator it = neighbors.find(Country::get_country(j));
    return it != neighbors.end();
}


//compute the minimal distance between two countries
void Fortifying::floyd_warshall()
{
    // Do not use 42 here, rather use nb_countries

    for(int i=0; i<nb_countries; i++){
    for(int j=0; j<nb_countries; j++){
        if(are_neighbors(i,j)){
            distance[i][j]=1;
            distance[j][i]=1;
        }
        else{
            distance[i][j]=nb_countries;
            distance[j][i]=nb_countries;
        }
    }
    distance[i][i]=0;
    }

    for(int k=0; k<nb_countries; k++){
        for(int i=0; i<nb_countries; i++){
            for(int j=0; j<nb_countries; j++){
                distance[i][j]=std::min(distance[i][j],distance[i][k]+distance[k][j]);
            }
        }
    }
}

bool Fortifying::is_on_the_border(Country* country){
    set<Country*> neighbors = global_settings->get_neighbors(country);

    for (set<Country*>::iterator it=neighbors.begin(); it!=neighbors.end(); ++it){   //To judge if all the neighbor countries are mine
        if(game_state->owner(*it) != player) {
            return true;
        }
    }
    return false;
}

void Fortifying::action(){
    //find one of our country with the highest number of troops and not on the border
    //this country is our origin
    troops=0;
    set<Country*> my_countries =  initial_settings->territories.find(player)->second;
    for(set<Country*>::iterator it = my_countries.begin(); it != my_countries.end(); ++it)
    {

        Country *current_country = (*it);

        if(!is_on_the_border(current_country)){    //The country must NOT be on the border
            int current_troops = game_state->get_army(current_country)->get_number_of_armies();
            if(current_troops - 1 > troops){ //We can not move a 1 troop country
                troops=current_troops-1;
                origin=current_country;
            }
        }
    }



    //compute the distance of the neighbors to the border
    //the minimal distance give us the destination
    set<Country*> neighbors = global_settings->get_neighbors(origin);
    set<Country*> border = c->get_border(origin);

    int destination_id = 0;
    int d_neighbors_to_border = 1+nb_countries;


    for(set<Country*>::iterator it1=neighbors.begin(); it1!=neighbors.end(); it1++){
    for(set<Country*>::iterator it2=border.begin(); it2!=border.end(); it2++){
        int i = (*it1)->get_id(); //neighbors
        int j = (*it2)->get_id(); //border
        int d = distance[i][j]; //distance between a neighbor and a country on the border
        if(d_neighbors_to_border > d){
            destination_id = i;
            d_neighbors_to_border = d; //this neighbor is closer to the border than the others
        }
    }
    }
    destination = Country::get_country(destination_id);

    cout<<"We should move "<<troops<<" troops from "<<origin->get_id()<<" to "<<destination->get_id()<<std::endl;
}



//return the Displacement_Move corresponding to the object we created
Displacement_Move Fortifying::move(){
    action();
    Displacement_Move move;
    move.number_of_armies = troops;
    move.origin = origin;
    move.destination = destination;
    return move;
}

