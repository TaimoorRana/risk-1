#include "continent.hpp"
#include <string>

//Refer to the Header file for implementing it

Continent::Continent()
{

}

// The set of countries is an unordered_set<Country> rather than int*
Continent::Continent(std::string nm, int *cnt, int bn, int idc){
    this->name=nm;
    this->countries=cnt;
    this->bonusarmies=bn;
    this->id=idc;
}

Continent::~Continent()
{
    name="deleted";
    delete countries;
    bonusarmies=-1;
    id=-1;
}

int Continent::getBonusarmies()
{
    return this->bonusarmies;
}

int Continent::getId()
{
    return this->id;
}


//This function should rather return an unorderred_set<Country>
int* Continent::getCountries()
{
    return countries;
}
