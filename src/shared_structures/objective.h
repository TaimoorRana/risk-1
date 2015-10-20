#ifndef OBJECTIVE_H
#define OBJECTIVE_H

#include <string>

#include "army.h"
#include "game_state.h"
#include "global_settings.h"
#include "objective.h"
#include "./../interfaces/player.h"

class Objective : public Structure {

public:

    int get_id() const;
    std::string get_description() const;
    bool is_accomplished(GameState* game_state, Player* player) const;

protected:

    int id_;
    std::string description_;

};

#endif // OBJECTIVE_H
