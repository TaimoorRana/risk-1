#include"abstract_objectives.h"
#include <string>
#include <iostream>
#include <string>
#include "objective.h"
#include "./../shared_structures/game_state.h"
#include "./../shared_structures/global_settings.h"
using namespace std;

Abtract_Objectives ::Abtract_Objectives(){

this->PlayerID=0;

}
Abtract_Objectives :: ~Abtract_Objectives(){

}
Abtract_Objectives ::Abtract_Objectives(Player* PlayerID){
this->PlayerID = PlayerID;
}


virtual bool Abtract_Objectives :: isAchieved(){

return false;  }

// the 1st objective card
//You must conquer and occupy 18 territories each with at least two armies

O1::~O1(){}
O1::O1(){
this->PlayerID=0;
}

virtual bool O1::isAchieved(Game_State* gamestate){
list<Country*> list_countries = countries_owned_by(this->PlayerID);
list<Country*>::iterator it;
int nbCountries = 0;
for(it = list_countries.begin(); it =! list_countries.end(); it++)
{
    if (gamestate->getArmy(it)->number_of_armies >= 2)
        nbCountries++;
}
return (nbCountries >= 18);
}




// the 2nd,6st,7st,8st objective cards
//You must conquer all of X and Y continents .



O2_6_7_8::O2_6_7_8(){
    this->name_continent_1=0;
    this->name_continent_2=0;
    }


O2_6_7_8::O2_6_7_8(string name_continent_1,string name_continent_2){
    this->name_continent_1= name_continent_1;
    this->name_continent_2=name_continent_2;

}

O2_6_7_8::~O2_6_7_8(){}

virtual bool O2_6_7_8::isAchieved(Game_State* gamestate){

Continent* continent_1 = Continent::get_continent(name_continent_1);
Continent* continent_2 = Continent::get_continent(name_continent_2);
return (continent_1->is_owned_by(this->PlayerID, gamestate)&&continent_2->is_owned_by(this->PlayerID, gamestate));
}



O3_4::O3_4(){

    this->name_continent_2=0;
    this->name_continent_1=0;
}


O3_4::O3_4(string name_continent_1, name_continent_2){

    this->name_continent_2=name_continent_1;
    this->name_continent_1=name_continent_2;
}


O3_4::~O3_4(){

}

O3_4::O3_4(Player* PlayerID){
this->PlayerID=PlayerID;

}


// the 3rd,4st objective cards
//You must conquer all of X and Y continents over a third continent


virtual bool  O3_4::isAchieved(Game_State* gamestate){
    Continent* continent_1 = Continent::Continent->get_continents(name_continent_1);
    Continent* continent_2 = Continent::Continent->get_continents(name_continent_2);
    if(continent_1->is_owned_by(this->PlayerID, gamestate)&&continent_2->is_owned_by(this->PlayerID, gamestate)){
        int number_continent=0;
        for(it = gamestate->get_global_settings()->get_continents().begin(); it =! gamestate->get_global_settings()->get_continents().end(); it++){
            if(it->is_owned_by(this->PlayerID, gamestate)) number_continent++;}
        return(number_continent>=3);

    };
    else return false;


    }




// the 5st Objective card
//You must conquer 24  territories

O5::O5(){
    this->PlayerID=0;
    }
O5::~O5(){}

virtual bool O5:: isAchieved(Game_State* gamestate){
    list<Country*> list_countries = countries_owned_by(this->PlayerID);
    list<Country*>::iterator it;
    int nbCountries = 0;
    for(it = list_countries.begin(); it =! list_countries.end(); it++)
    {
        nbCountries++;
    }
    return (nbCountries >= 24);
    }




// Objective cards from 9 to 14
//"You must destroy the color X armies. If you are yourself the owner of the X army or the X army is removed by another player, your goal becomes automatically to conquer 24 territories. "

O9_14::O9_14(){}
O9_14::~O9_14(){}
O9_14::O9_14(Player* Opponent){
    this->Opponent=Opponent;
}
virtual bool O9_14::isAchieved(Game_State* gamestate){

    map<Player*,Player*> correspondance_morts =gamestate->get_defeated_players();  //COMPLETER AVEC LA SYNTAXE EXACTE
    if (Opponent == PlayerID)
    {
        list<Country*> list_countries = countries_owned_by(this->PlayerID);
        list<Country*>::iterator it;
        int nbCountries = 0;
        for(it = list_countries.begin(); it =! list_countries.end(); it++)
        {
            nbCountries++;
        }
        return (nbCountries >= 24);
     }

    else{

        if (correspondance_morts.find(Opponent)==correspondance_morts.end()) return false;
        else{
            if (correspondance_morts.tmap(Opponent) == PlayerID) return true;

            else{
             list<Country*> list_countries = countries_owned_by(this->PlayerID);
             list<Country*>::iterator it;
             int nbCountries = 0;
             for(it = list_countries.begin(); it =! list_countries.end(); it++)
        {
            nbCountries++;
        }
        return (nbCountries >= 24);
    }

        }
    }
}
