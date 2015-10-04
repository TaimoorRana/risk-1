#include "connectedcomponent.h"
#include "interfaces/player.h"
#include "shared_structures/global_settings.h"
#include "shared_structures/country.h"
#include "ai2/probabilities.h"
#include "shared_structures/game_state.h"
#include <set>
#include "shared_structures/army.h"
#include "shared_structures/continent.h"

connectedcomponent(Player* current_player)
{
    id_player=current_player;
    computeRelevantInformation();
    component_id();
    computeContinentOccupation();
}
~connectedcomponent(){

}


/*possible improvement:
 this function aims to find out the weakest enemy of a country. Under the assumption that each country has a very high probability to attack its weakest enemy, this function can be used to redefine the concept of 'strongest-enemy', that is, the enemy which has not only the most troops but also a very high probability to attack us.
 */
 int findWeakestEnemy(Counry* current_country){
    set<Country*> neighbors=Global_Settings.get_neighbors(current_country);
    set<Country*>::iterator it_neighbors;
    int term=0;
    for(it_neighbors = neighbors.begin(); it_neighbors!=neighbors.end(); ++it_neighbors){
        Country* current_neighbor = *it_neighbors;
        if ((*current_neighbor).get_id==(*current_country).get_id)
                it_neighbors++;
        else{
            term++;// it aimes to initialize weakestenemy
            if(term==1){
                weakestenemy=Game_State.get_army(current_neighbor)->get_number_of_armies();
                weakestenemy_id=(*current_neighbor).get_id();
            }
        else{
            int term_weak=Game_State.get_army(current_neighbor)->get_number_of_armies();
            if(weakestenemy>term_weak){
                weakestenemy=term_weak;
                weakestenemy_id=(*current_neighbor).get_id();
            }
        }
    }
    return weakestenemy_id;
    }
 }

 void computeRelevantInformation(){
    set<Country*> all_countries = Global_Settings.get_countries();
    set<Country*>::iterator it;
    //Find out all the countries occupied by me at border
    for(it = all_countries.begin(); it!=all_countries.end(); ++it){
        //Get the "Country" object
        Country* current_country = *it;
        int country_id=(*current_country).get_id();
        //To judge if this country is mine
        if(id_player==Game_State.owner(current_country)){
            relevantInformation[country_id][1]=Game_State.get_army(current_country)->get_number_of_armies();
            set<Country*> neighbors=Global_Settings.get_neighbors(current_country);
            set<Country*>::iterator it_neighbors;
            int sign=2;
            int strongestenemy=0;
            int strongestenemy_id=COUNTRY_NB;
            int weakestenemy=0;
            int weakestenemy_id=COUNTRY_NB;
            int first=0;
            for(it_neighbors = neighbors.begin(); it_neighbors!=neighbors.end(); ++it_neighbors){
                //Get its neighbor countries
                Country* current_neighbor = *it_neighbors;
                if(Game_State.owner(current_neighbor)!=id_player){
                    first++;
                    if(first==1){
                        //Nb of troops in this country occupied by me
                        weakestenemy=Game_State.get_army(current_neighbor)->get_number_of_armies();
                        weakestenemy_id=(*current_neighbor).get_id();
                    }
                    else{
                        int term_weak=Game_State.get_army(current_neighbor)->get_number_of_armies();
                        if(weakestenemy>term_weak){
                            weakestenemy=term_weak;
                            weakestenemy_id=(*current_neighbor).get_id();
                        }
                    }
                    sign=1;
                    int term_strong = Game_State.get_army(current_neighbor)->get_number_of_armies();
                    if((term_strong>strongestenemy) && (findweakesteney(current_neighbor) =! (*current_country).get_id())){
                        strongestenemy=term_strong;
                        strongestenemy_id=(*current_neighbor).get_id();
                    }
                }
            }
            //Indicate the type of country
            relevantInformation[country_id][0]=sign;
            //Nb of troops for the strongest enemy
            relevantInformation[country_id][2]=strongestenemy;
            //Id for the strongest enemy
            relevantInformation[country_id][3]=strongestenemy_id;
            //Nb of troops to add for having a defend probability bigger than 0.5
            relevantInformation[country_id][4]=Probabilities.reinforcement_defense(relevantInformation[i][1],relevantInformation[i][2]);
            //Probability to defend the strongest enemy without additional troops
            relevantInformation[country_id][5]=Probabilities.proba_to_survive(relevantInformation[i][1],relevantInformation[i][2]);
            //Nb of troops for the weakest enemy;
            relevantInformation[country_id][6]=weakestenemy;
            //Id for the weakest enemy
            relevantInformation[country_id][7]=weakestenemy_id;
            //Nb of troops to add for having a victory probability bigger than 0.5
            relevantInformation[country_id][8]=Probabilities->reinforcement_attack(relevantInformation[i][1],relevantInformation[i][6]);
            // Probability to win the weakest enemy without additional troops
            relevantInformation[country_id][9]=proba->proba_to_win(relevantInformation[i][1],relevantInformation[i][6]);
            //Nb of neighbor enemies for our border country
            relevantInformation[country_id][10]=first;
        }
        else{

            relevantInformation[country_id][0]=0;
            relevantInformation[country_id][1]=0;
            relevantInformation[country_id][2]=0;
            relevantInformation[country_id][3]=0;
            relevantInformation[country_id][4]=0;
            relevantInformation[country_id][5]=0;
            relevantInformation[country_id][6]=0;
            relevantInformation[country_id][7]=0;
            relevantInformation[country_id][8]=0;
            relevantInformation[country_id][9]=0;
            relevantInformation[country_id][10]=0;
        }
    }
}

// Class for calculating the id for each connected component: ie: countries "i", "j", "k" are in the same connected component, then the id of this component is 1, etc
// If a country is not ours, the the component id is 0
void component_id(){
    int COUNTRY_NB=42;
    // to identify the component id
    int comp_id=0;
    //the flag to find out our first country
    int country_id=COUNTRY_NB;
    //initialize the component id for each country
    for(int i=0; i<COUNTRY_NB; i++) relevantInformation[i][11]=0;
    for(int i=0; i<COUNTRY_NB; i++){
        Country* current_country=Country.get_country(i);
        //if a country is ours first country found out
        if(relevantInformation[i][0]!=0) {
            country_id++;                       //We change the flag
            comp_id++;                          //The component id for this country is 1
            relevantInformation[i][11]=comp_id; //Set the component id equal to 1
            //Find out all the neighbor countries for this country
            set<Country*> neighbors=Global_Settings.get_neighbors(current_country);
            set<Country*>::iterator it_neighbors;
            //For all the neighbor countries, if it is occupied by us, we set the same component id
            for(it_neighbors = neighbors.begin(); it_neighbors!=neighbors.end(); ++it_neighbors){
                Country* current_neighbor = *it_neighbors;
                int current_id = current_neighbor->get_id();
                if(id_player==Game_State.owner(current_neighbor)){
                    relevantInformation[neighbors[current_id]][11]=comp_id;
                }
            }

        }
        //If this is not the first country that found out
        else{
            //And it hasn't a component id yet
            if(relevantInformation[i][11]==0){
                comp_id++;                            // Then we add 1 to the component id counter
                relevantInformation[i][11]=comp_id; // We set the component id for this country
                //Find out all the neighbor countries for this country
                set<Country*> neighbors=Global_Settings.get_neighbors(current_country);
                set<Country*>::iterator it_neighbors;
                //For all the neighbor countries, if it is occupied by us, we set the same component id
                for(it_neighbors = neighbors.begin(); it_neighbors!=neighbors.end(); ++it_neighbors){
                    Country* current_neighbor = *it_neighbors;
                    int current_id = current_neighbor->get_id();
                    if(id_player==Game_State.owner(current_neighbor)){
                        relevantInformation[neighbors[current_id]][11]=comp_id;
                    }
                }
            }
        }
    }
    // Total number of connected components
    Nb_components=comp_id;
}


 void computeContinentOccupation(){
    // Nb of continents
    int CONTINENT_NB=6;
    // Nb of countries in each continent
    int CONTINENT_COUNTRIES[CONTINENT_NB];
    // In North America, there are 9 countries indexed from 0 to 8
    CONTINENT_COUNTRIES[0]=9;
    // In South America, there are 4 countries indexed from 9 to 12
    CONTINENT_COUNTRIES[1]=4;
    // In Europe, there are 7 countries indexed from 13 to 19
    CONTINENT_COUNTRIES[2]=7;
    // In Africa, there are 6 countries indexed from 20 to 25
    CONTINENT_COUNTRIES[3]=6;
    // In Asia, there are 12 countries indexed from 26 to 37
    CONTINENT_COUNTRIES[4]=12;
    // In Australia, there are 4 countries indexed from 38 to 41
    CONTINENT_COUNTRIES[5]=4;
    for(int i=0; i<CONTINENT_NB; i++){
        // A counter to remember the number of countries occupied by us in the same continent
        int compt=0;
        // To check if the country indexed "CONTINENT_NB" in the continent "i" is occupied by us
            for(int j=0; j<CONTINENT_COUNTRIES[i]; j++){
                Country* current_country = Country.get_country(j);
                if(Game_State.owner(current_country)==id_player) compt++; // If yes, we do compt++
            }
            continentOccupation[i]=compt/CONTINENT_COUNTRIES[i];  // To calculate the fraction of countries occupied by us in continent "i"
    }

}

//Function that find out all the countries in the connected component "component_id"
int* component_members(int component_id){
    int COUNTRY_NB=42;
    int compt=0;
    // Find the total number of countries in this connected component
    for(int i=0; i<COUNTRY_NB; i++){
        if(relevantInformation[i][11]==component_id)    compt++;
    }
    //create an array to stock all the country ids in this connected component
    int* members = new int[compt];
    compt=0;
    for(int i=0; i<COUNTRY_NB; i++){
        if(relevantInformation[i][11]==component_id)    {
            members[compt]=i;
            compt++;
        }
    }
    return members;
}

//Function that returns all the countries at the border
set<Country*> get_border(Country* origin){
    // Nomber of countries
    int COUNTRY_NB=42;
    // Get the id of the country origin
    int origin_id = origin->get_id();
    // Get the connected component id of the country "origin"
    int id_component = RelevantInformation[origin_id][11];
    // Creat a new set to stock all our countries at the border of this connected component
    set<Country*> border;
    // Boucle to find out the aim-countries
    for(int i=0; i<COUNTRY_NB; i++){
        // If the current country is a country such that it is in this connected component and it faces with at least one ennemy country
        if((RelevantInformation[i][11]==id_component)&&(RelevantInformation[i][0]==1)){
            border.insert(Country.get_country(i));
        }
    }
    // return the result
    return border;
}

