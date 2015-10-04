/*
 * Game.hpp
 *
 *  Created on: Feb 3, 2015
 *      Author: hugo.marival
 */

#include <iostream>
#include<Continent.hpp>
#include<Country.hpp>
#include<Map.hpp>
#include<exception>
#include <stdexcept>
using namespace std;

#ifndef GAME_HPP_
#define GAME_HPP_

class Game {
public:
	Game();
	virtual ~Game();
	Player getPlayer();
	Map getMap();
	/*countriesId[i] tells addTroops to add countriesId[i] troops to country i.
	* This function does not check if the player actually has the countries on which he adds troops
	* neither does it check if the number of added troops is equal to the number of available troops
	* N.B.: This function has to increment Player.currState at the end of its execution. (NOT DONE)*/
	void addTroops(int countriesId[]){
		int length = sizeof(countriesId);
			for (int i=0; i<length; i=i+1)
			{
				if ((countriesId[i]>0)&&(this->getPlayer().getCountries[i])){
					this->getMap().getCountry(i).Country::addArmies(i);
				}
				else
				{
					throw std::logic_error("You do not own some of these countries !");
				}
			}
	};

private:
	Player player[];
	Map map;
};

#endif /* GAME_HPP_ */
