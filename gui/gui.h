#ifndef GUI_H
#define GUI_H
#include "./../shared_structures/moves.h"
#include "./../shared_structures/card.h"
#include "./../shared_structures/country.h"
#include <QObject>

//This class is the core hosting the logic of the GUI

//It contains methods corresponding to steps, taking as input a set of parameters
//taken from human_player, returning moves or decisions

class Gui
{
public:
    Gui();
    ~Gui();
    bool want_change_cards();
    Change_Cards_Move change(bool must_change);
    Dispatch_Move dispatch_backups(int backups_nb);
    Attack_Move attack();
    Displacement_Move displacement();
};

#endif // GUI_H
