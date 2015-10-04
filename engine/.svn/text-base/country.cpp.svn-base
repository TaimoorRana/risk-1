#include "country.hpp"
#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>

std::string pays[42] = {"Alaska","Alberta","Central America","Eastern United States", "Greenland", "Northwest Territory", "Ontario", "Quebec", "Western United States",
                        "Argentina", "Brazil", "Peru", "Vanezuela",
                        "Great Britain", "Iceland", "Northern Europe", "Scandinavia", "Southern Europe", "Ukraine", "Western Europe",
                        "Congo", "Easte Africa", "Egypt", "Madagascar", "North Africa", "South Africa",
                        "Afghanistan", "China", "India", "Irkutsk", "Japan", "Kamchatka", "Middle East", "Mongolia", "Siam", "Siberia", "Ural", "Yakutsk",
                        "Eastern Australia", "Indonesia", "New Guinea", "Western Australia"
                        };
int cnt[42]={0,0,0,0,0,0,0,0,0,         //North America
             1,1,1,1,                   //South America
             2,2,2,2,2,2,2,             //Europe
             3,3,3,3,3,3,               //Africa
             4,4,4,4,4,4,4,4,4,4,4,4,   //Asia
             5,5,5,5,                   //Australia
            };

Country::Country()
{
    name = "country";
    id = 0;
    nbarmies = 0;
    player = -1;
    continent = 0;
}

Country::~Country()
{
    name = "no country";
    id = 0;
    nbarmies = 0;
    player = -1;
    continent = 0;
}

Country::Country(int i){
    name = pays[i];//Il faudra rechercher le nom dans un tableau pré rempli
    id = i;
    nbarmies = 0;
    player = -1;
    continent = cnt[i];
}

Country::Country(std::string nom,int i){
    name = nom;
    id = i;
    nbarmies = 0;
    player = -1;
    continent = cnt[i];
}

Country::Country(std::string nom,int i,int cont){
    name = nom;
    id = i;
    nbarmies = 0;
    player = -1;
    continent = cont;
}

Country::Country(std::string nom,int i,int armies, int joueur, int cont){
    name = nom;
    id = i;
    nbarmies = armies;
    player = joueur;
    continent = cont;
}
std::string Country::getName(){
    return this->name;
}

int Country::getArmies(){
    return this->nbarmies;
}

int Country::getPlayer(){
    return this->player;
}

int Country::getContinent(){
    return this->continent;
}

int Country::getId(){
    return this->id;
}

void Country::setName(std::string nom){
    this->name=nom;
}

void Country::setArmies(int i)
{
    this->nbarmies=i;
}

void Country::setPlayer(int i){
    this->player=i;
}

void Country::setContinent(int i){
    this->continent=i;
}

void Country::setId(int i){
    this->id=i;
}

void Country::addArmies(int i){
    if(this->nbarmies + i > 0)
    {
       this->nbarmies=this->nbarmies + i;
    }
    else
    {
        throw std::logic_error("Error: there must be at least one army in each country!");
    }
}

void Country::print(){
    std::cout << name << continent << std::endl;
}

