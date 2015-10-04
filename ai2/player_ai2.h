#ifndef AI2PLAYER_H
#define AI2PLAYER_H

#include "./../interfaces/player.h"

// Forward declaration
class Probabilities;
class Initial_Settings;
class Global_Settings;
class Game_State;
class Move;
class Country;

#include <map>
#include <set>

using namespace std;

class Ai2player : public Player
{
public:
    Ai2player();
    ~Ai2player();
    void receive_global_settings(Global_Settings* gs);
    Dispatch_Move first_move(Initial_Settings* is);
    Move next_move(Game_State* gs);
private:
    map<Country*,set<Country*> > world_map;
    Probabilities* proba;
};

#endif // AI2PLAYER_H
