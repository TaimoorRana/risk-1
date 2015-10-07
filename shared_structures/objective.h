#ifndef OBJECTIVE_H
#define OBJECTIVE_H

#include <string>

#include "./../shared_structures/objective.h"
#include "./../shared_structures/game_state.h"
#include "./../shared_structures/army.h"
#include "./../shared_structures/global_settings.h"
#include "./../interfaces/player.h"

class Objective {

public:

    int get_id() const;
    std::string get_description() const;
    bool is_accomplished(GameState* GameState, Player* player) const;

protected:

    int id_;
    std::string description_;

};

#endif // OBJECTIVE_H
