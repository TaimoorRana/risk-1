#ifndef OBJECTIVES_H
#define OBJECTIVES_H


#include "./../shared_structures/objective.h"
#include "./../shared_structures/game_state.h"
#include "./../shared_structures/army.h"
#include "./../shared_structures/global_settings.h"
#include "./../interfaces/player.h"
#include <vector>



class Abstract_Objective : public Objective
{
public:

    virtual bool is_accomplished(Game_State* game_state, Player* player);
};



class Dominate_18_territories : public Abstract_Objective
{
public:

    Dominate_18_territories ();
    bool is_accomplished (Game_State* game_state, Player* player);
};

class Conquer_24_territories : public Abstract_Objective
{
public:

    Conquer_24_territories ();

    bool is_accomplished (Game_State* game_state, Player* player);
};


class Conquer_both_continents : public Abstract_Objective
{
public:

    string name1, name2;

    Conquer_both_continents (string continent1, string continent2);

    bool is_accomplished (Game_State* game_state, Player* player);
};


class Conquer_both_and_any_other : public Abstract_Objective
{
public:

    string name1, name2;

    Conquer_both_and_any_other (string continent1, string continent2);

    bool is_accomplished (Game_State* game_state, Player* player);
};


class Defeat_Opponent : public Abstract_Objective
{
public:

    Base_Player::Color to_be_defeated;

    Defeat_Opponent (Base_Player::Color to_be_defeated);

    bool is_accomplished (Game_State* game_state, Player* player);
};

set<Abstract_Objective*> get_all_objectives ();

#endif // OBJECTIVES_H
