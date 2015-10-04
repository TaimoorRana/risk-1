#ifndef RANDOMREINFORCEMENT_H
#define RANDOMREINFORCEMENT_H


#include "./shared_structures/game_state.h"
#include "./shared_structures/moves.h"
#include "./shared_structures/global_settings.h"
#include "./shared_structures/initial_settings.h"
#include <queue>
#include "./engine/player.hpp"
#include "evaluate.h"
#include "attack.h"

class RandomReinforcement
{
public:
    Player* MyPlayer; //Our player
    RandomReinforcement();
    RandomReinforcement(int RDN , int EN , Game_State* IGS,Evaluate eva ,Global_Settings glob ,Initial_Settings ini);
    ~RandomReinforcement();
    int RandomDrawNumber; //number of random draw
    int ExlorationNumber; //number of try (selection of the best configurations among the randomly chosen ones)
    Game_State* InitialGameState; //store the initial GameState
    Dispatch_Move* CurrentStrategy;
    std::priority_queue< Dispatch_Move*>* CurrentBestStrategies; //the GameState which maximizes decideBestAttack
    Evaluate evaluation;
    Global_Settings global;
    Initial_Settings initial;

//***********MAIN FUNCTION***********
    Dispatch_Move* decideReinforcement(); //It is supposed to give you a valid reinforcement strategy

//***********AUXILIARY FUNCTIONS*****
    void fillQueue();
    Game_State* fromStrategyToGameState(Dispatch_Move* s); //Do the conversion between Dispatch_Move and Game_state
    Dispatch_Move* drawConfiguration(); //draws a random cofiguration of the reinforcements and returns the corresponding GameState
    float reinforcementConfigurationEvaluation(Game_State* NewGameState); //Evaluates a configuration
};

#endif RANDOMREINFORCEMENT_H
