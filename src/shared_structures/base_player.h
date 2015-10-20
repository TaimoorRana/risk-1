#ifndef BASE_PLAYER_H
#define BASE_PLAYER_H

#include "structure.h"

class BasePlayer : public Structure {

public:
    BasePlayer();
    virtual ~BasePlayer();

    int get_id () const;
    void set_id (int id);

    enum Color
    {
        Yellow = 0,
        Red,
        Green,
        White,
        Black,
        Blue
    };

    Color get_color() const;

    static const char * color_names_[];

private:
    int id_;
    Color color_;
};

#endif // BASE_PLAYER_H
