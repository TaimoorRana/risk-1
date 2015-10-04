#pragma once

#include "Objective.h" 
// Objective 1:
//Vous devez conquérir 18 territoires et occuper chacun d'eux avec deux armées au moins

class O1 : public Objective {

public:
	Player* PlayerID;
	O1();
    O1(Player* Player);
    ~O1();

	virtual bool isAchieved(Player* PlayerID);	

};