/*
 * player.hpp
 *
 *  Created on: Jan 27, 2015
 *      Author: hugo.marival
 */

#include <iostream>
#include "./shared_structures/continent.h"
#include "./shared_structures/country.h"
#include "map.hpp"
using namespace std;

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

class Player{
	int id;
	string name;
	bool cards[];
	bool countries[];
	bool continents[];
	int curState;
	bool alive;
	Objective mission;
	int leftArmies;

public:
	Player();
	~Player(){
		delete id;
		delete name;
		delete cards;
		delete countries;
		delete continents;
		delete curState;
		delete alive;
		delete mission;
		delete leftArmies;
	};
	Player(int id, string name, bool cards[], bool countries[], bool continents[], int curState, bool alive, Objective mission, int leftArmies){
		this->id = id;
		this->name = name;
		this->cards = cards;
		this->countries = countries;
		this->continents = continents;
		this->curState = curState;
		this->alive = alive;
		this->mission = mission;
		this->leftArmies = leftArmies;
	};

	bool isAlive(){
		return this->alive;
	};
	bool getCards(){
		return this-> cards;
	};
	bool getCountries(){
		return this->countries;
	};
	bool getContinents(){
		return this->continents;
	};
	Objective getMission(){
		return this->mission;
	};
	int getLeftArmies(){
		return this->leftArmies;
	};
	int getNbCountries(){
		bool c = this->getCountries();
		int length = sizeof(c);
		int acc=0;
		for (int i=0; i<length; i = i+1){
			if (c[i]) {
				acc = acc+1;
			}
		}
		return acc;
	};

	void setCards(bool cards[]);/*initial set of cards*/
	void setCountries(bool countries[]);/*initial set of countries*/

	void play();/*This function will run through the player's turn depending on the current state (curState)*/

	void changeCards(List ajouter, List retirer);
	bool performAttack(int nbDefTroops, int nbAtkTroops);
	void afterConquest(int troopsMoved);/*Moves troopsMoved troops to the conquered country*/
	bool isDead(int playerId);
	void deadBackups(); /*sets curState to 5 (choose backups).*/
	void drawCard();
	void moveOneTroop(int departureCouuntryId, int arrivalCountryId);

};



#endif /* PLAYER_HPP_ */
