#ifndef HEADERS_H
#define HEADERS_H

#include "./shared_structures/army.h"
#include "./shared_structures/card.h"
#include "./shared_structures/continent.h"
#include "./shared_structures/country.h"
#include "./shared_structures/game_state.h"
#include "./shared_structures/global_settings.h"
#include "./shared_structures/initial_settings.h"
#include "./shared_structures/moves.h"
#include "./shared_structures/objective.h"
#include "./shared_structures/steps.h"
#include "./interfaces/player.h"
#include "./interfaces/client.h"
#include "./pseudo_engine/game.h"
//#include "./pseudo_net/client_utils.h"
//#include "./pseudo_net/fake_client.h"
//#include "./pseudo_net/server_utils.h"
#include "./utils/utils.h"


// Initializing static variables

int Continent::quantity_of_continents = 0;
int Card::quantity_of_cards = 0;
int Country::quantity_of_countries = 0;
map <string, Continent*> Continent::name_to_continent;
map <string, Country*> Country::name_to_Country;
map <int, Country*> Country::id_to_Country;

#endif // HEADERS_H
