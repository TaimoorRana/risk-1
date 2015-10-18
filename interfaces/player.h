#ifndef PLAYER_H
#define PLAYER_H

#include "./../shared_structures/base_player.h"
#include "./../shared_structures/moves.h"

class GlobalSettings;
class InitialSettings;
class GameState;


class Player : public BasePlayer {
	
public:
    Player();
    virtual ~Player();
    virtual void receive_global_settings(GlobalSettings *global_settings);
    virtual DispatchMove* first_move(InitialSettings *initial_settings);
    virtual Move* next_move(GameState *game_state);
    static Player* get_player (InitialSettings* initial_settings, BasePlayer::Color color);
};

#endif // PLAYER_H
