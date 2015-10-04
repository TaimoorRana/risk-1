#include "O1.h"
#include <iostream>
// Objective 1:
//Vous devez conquérir 18 territoires et occuper chacun d'eux avec deux armées au moins

O1::O1(){
	this->PlayerID=0;
}
O1::O1(Player* PlayerID){
	this->PlayerID=PlayerID;
	
}
O1::~O1(){
}

bool O1::isAchieved(Player* PlayerID){
	if( numberOfCountriesConquered(PlayerID)>=18)
		return true;
	else
		return false; }