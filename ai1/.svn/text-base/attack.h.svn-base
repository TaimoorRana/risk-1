#ifndef ATTACK_H
#define ATTACK_H

#include "player_ai1.h"

#include "./../shared_structures/game_state.h"
#include "./../shared_structures/global_settings.h"
#include "./../shared_structures/initial_settings.h"
#include "./../shared_structures/army.h"
#include "./../shared_structures/continent.h"
#include "./../shared_structures/card.h"
#include "./../shared_structures/country.h"

//forward declarations
class Game_State;
class Global_Settings;
class Initial_Settings;
class Army;
class Country;
class Continent;
class Card;


class AttackStrategy {
public:
    Country* attacker;
    Country* attacked;
};

class Attack {
public:
    static AttackStrategy decideNextAttack(Global_Settings* global, Initial_Settings* initial_settings, Game_State* state);


};


#endif // ATTACK_H

