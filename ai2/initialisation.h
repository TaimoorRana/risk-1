#ifndef INITIALISATION_H
#define INITIALISATION_H

#include "../shared_structures/game_state.h"
#include "../shared_structures/moves.h"
//#include "../shared_structures/initial_settings.h"

class initialisation
{
public:
    initialisation();
    ~initialisation();
    void deploy(int troopNb);

private:
    int a[42][42];
    int b[42][42];
    float firstround[42][42];
};

#endif // INITIALISATION_H
