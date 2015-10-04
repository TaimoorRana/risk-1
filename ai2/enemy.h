#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <list>

class Country; // Forward declararion

using namespace std;

class Enemy
{
public:
    Enemy();
    ~Enemy();
    int ArmiesInTerritory; //number of armies in territory
    int ArmiesToWin; //number of armies to win at 50% probability
    int PlayerId;
    int calArmyInTerritory(); //calculate the number of armies in the territory
    int calArmyToWin(); //calculate the number of armies to win at 50%
    list<Country*> neighbourToThisEnemy; //list of our countries which are neighbouring to this enemy

};

#endif // ENEMY_H
