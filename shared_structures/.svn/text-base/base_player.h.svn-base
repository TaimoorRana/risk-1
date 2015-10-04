#ifndef BASE_PLAYER_H
#define BASE_PLAYER_H

class Base_Player
{
public:
    Base_Player();
    virtual ~Base_Player();
    int get_id ();
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

    Color get_color();

    static const char * color_names[];

private:
    int id;
    Color color;
};

#endif // BASE_PLAYER_H
