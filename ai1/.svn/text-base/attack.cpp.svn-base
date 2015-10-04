#include "attack.h"
#include "evaluate.h"
#include <limits>

#include "./../shared_structures/game_state.h"
#include "./../shared_structures/global_settings.h"
#include "./../shared_structures/initial_settings.h"
#include "./../shared_structures/army.h"
#include "./../shared_structures/continent.h"
#include "./../shared_structures/card.h"
#include "./../shared_structures/country.h"

AttackStrategy Attack::decideNextAttack(Global_Settings* global, Initial_Settings* initial_settings, Game_State* state) {
    Game_State* tempState;
    AttackStrategy result;
    Evaluate evaluator;
    double bestScore = - numeric_limits<double>::max();
    double currentScore;
    list<Country*> myCountries = state->countries_owned_by(0);
    std::set<Country*> setCountries(myCountries.begin(), myCountries.end());
    set<Country*> neighbors;
    for (list<Country*>::iterator attacker=myCountries.begin(); attacker!=myCountries.end();++attacker){
        neighbors = global->get_neighbors(*attacker);
        for (set<Country*>::iterator attacked=neighbors.begin(); attacked!=neighbors.end();++attacked){
            if (setCountries.find(*attacked) != setCountries.end()) {
                //tempState = new GameState(tempState.attack(*attacker, *attacked)); // To be adapted when engine is done
                currentScore = evaluator.evaluate_game_state(global, initial_settings, tempState, 1, 1, 1, 1, 1);
                if (currentScore > bestScore) {
                    result.attacker = *attacker;
                    result.attacked = *attacked;
                    bestScore = currentScore;
                }
            }
        }
    }
    return result;
}
