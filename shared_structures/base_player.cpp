#include "base_player.h"

Base_Player::Base_Player()
{

}

Base_Player::~Base_Player()
{

}

int Base_Player::get_id()
{
    return this->id;
}

void Base_Player::set_id(int id)
{
    this->id = id;
}

Base_Player::Color Base_Player::get_color()
{
    return this->color;
}

const char * Base_Player::color_names[] = {
    "Yellow",
    "Red",
    "Green",
    "White",
    "Black",
    "Blue"
};
