#include "base_player.h"

BasePlayer::BasePlayer()
{

}

BasePlayer::~BasePlayer()
{

}

int BasePlayer::get_id() const { return id_; }

void BasePlayer::set_id(int id) { id_ = id; }

BasePlayer::Color BasePlayer::get_color() const { return color_; }

const char * BasePlayer::color_names[] = {
    "Yellow",
    "Red",
    "Green",
    "White",
    "Black",
    "Blue"
};
