#ifndef OBJECTIVE_H
#define OBJECTIVE_H
#include <iostream>
#include "country.h"
#include"player.hpp"
#include"map.hpp"
using namespace std;
class Objective
{
protected:
    int IDcard;
    Player* PlayerID;
public:

    Objective();
    Objective(Player* PlayerID, int IDcard);
    ~Objective();

//isAchieved(Player* Player) returns true if the player in argument has achieved his objective and false if not.
// is a virtual function
    virtual bool isAchieved(Player* Player);


// areValid(gameState) returns the list of valid objectives
//	vector<int> areValid(gameState);

// distributeObjectives(areValid(gameState)) set the players objectives


// numberOfCountriesConquered
    int  numberOfCountriesConquered(Player* Player);

// -boolean numberOfArmies returns true if the player has at least 2 armies on numberOfCountries countries
    bool numberOfArmies(Player* Player, int numberOfCountries,Map map);

//boolean isContinentConquered(int player, int continent) returns true if the continent is entirely conquered by the player
    bool isContinentConquered(Player* Player, int continent);

//boolean isArmyDestroyed(int opponent) return true if the opponent has 0 army left
    bool isArmyDestroyed(Player* opponent);

//int Killer(int opponent) returns the id of the player who destroyed the opponent

    virtual void print();

};


// the 1st objective card
//You must conquer and occupy 18 territories each with at least two armies

class O1 : public Objective {

    int IDcard;
    Player* PlayerID;
    public:
    O1();
    O1(Player* Player,int IDcard);
    ~O1();

    virtual bool isAchieved(Player* Player,Map map);

};



// the 2nd,6st,7st,8st objective cards
//You must conquer all of X and Y continents .

class O2_6_7_8 : public Objective {

    int IDcard;
    int continent_1;
    int continent_2;
    Player* PlayerID;
    public:
    O2_6_7_8();
    O2_6_7_8(Player* Player,int IDcard);
    ~O2_6_7_8();

    virtual bool isAchieved(Player* Player);
    virtual void print();
};

// the 3rd,4st objective cards
//You must conquer all of X and Y continents over a third continent
class O3_4 : public Objective {

    int IDcard;
    int continent_1;
    int continent_2;
    Player* PlayerID;
    public:
    O3_4();
    O3_4(Player* Player,int IDcard);
    ~O3_4();

    virtual bool isAchieved(Player* Player);
    virtual void print();
};



// the 5st Objective card
//You must conquer 24  territories
class O5 : public Objective {

    int IDcard;
    int continent_1;
    int continent_2;
    Player* PlayerID;
    public:
    O5();
    O5(Player* Player,int IDcard);
    ~O5();

    virtual bool isAchieved(Player* Player);
    virtual void print();
};



// Objective cards from 9 to 14
//"You must destroy the color X armies. If you are yourself the owner of the X army or the X army is removed by another player, your goal becomes automatically to conquer 24 territories. "
class O9_14 : public Objective
{
int IDcard;
Player* PlayerID;
Player* Opponent;
public:
    O9_14();
    O9_14(Player* player, Player* opponent,int IDcard );
    ~O9_14();

    virtual bool isAchieved();
    virtual void print();

};

#endif // OBJECTIVE_H
