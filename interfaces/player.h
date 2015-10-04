#ifndef PLAYER_H
#define PLAYER_H

#include "./../shared_structures/moves.h"
#include "./../shared_structures/base_player.h"

class Global_Settings; //forward declaration
class Initial_Settings; //forward declaration
class Game_State; //forward declaration


class Player : public Base_Player
{
public:
    Player();
    virtual ~Player();
    virtual void receive_global_settings(Global_Settings* gs)=0;
    virtual Dispatch_Move* first_move(Initial_Settings* is)=0;
    virtual Move* next_move(Game_State* gs)=0;

    static Player* get_player (Initial_Settings* initial_settings, Base_Player::Color color);
};

#endif // PLAYER_H
