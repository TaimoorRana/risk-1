#include "objective.h"

int Objective::get_id() const { return id_; }

std::string Objective::get_description() const { return description_; }

bool Objective::is_accomplished(GameState *game_state, Player *player) const {
    (void)game_state;
    (void)player;
    return true;
}
