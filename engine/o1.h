#pragma once

#include "Objective.h" 
// Objective 1:
//Vous devez conqu�rir 18 territoires et occuper chacun d'eux avec deux arm�es au moins

class O1 : public Objective {

public:
	Player* PlayerID;
	O1();
    O1(Player* Player);
    ~O1();

	virtual bool isAchieved(Player* PlayerID);	

};