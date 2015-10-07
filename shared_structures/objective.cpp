#include "objective.h"

int Objective::get_id() { return id_; }

std::string Objective::get_description() { return description_; }

bool Objective::is_accomplished(GameState *game_state, Player *player){
    return true;
}
