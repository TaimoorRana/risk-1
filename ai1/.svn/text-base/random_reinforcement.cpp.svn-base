#include "random_reinforcement.h"
#include <map>
#include <stdlib.h>
#include <list>
RandomReinforcement::RandomReinforcement()
{

}

RandomReinforcement::RandomReinforcement(int RDN , int EN , Game_State* IGS ,Evaluate eva ,Global_Settings glob ,Initial_Settings ini)
{
    RandomDrawNumber = RDN;
    ExlorationNumber = EN;
    InitialGameState = IGS;
    MyPlayer = InitialGameState->get_current_player();
    evaluation = eva;
    global = glob;
    initial = ini;

}

RandomReinforcement::~RandomReinforcement()
{

}

//

Dispatch_Move* RandomReinforcement::decideReinforcement()
{

    CurrentBestStrategies = new std::priority_queue<Dispatch_Move*>(); //the GameState which maximizes decideBestAttack
    //fill the queue with random strats
    fillQueue();
    //initilization of BestStrategy
    Dispatch_Move* BestStrategy = CurrentBestStrategies->top();
    //initilization of CurrentGameState
    Game_State* CurrentGameState = Game_State(InitialGameState->get_initial_settings);
    //initilization of BestScore
    double BestScore = reinforcementConfigurationEvaluation(CurrentGameState);
    //Selecting the best strategy in the queue
    for(Dispatch_Move* CurrentStrategy : *CurrentBestStrategies)
    {
        CurrentGameState = Game_State(InitialGameState->get_initial_settings);
        AttackStrategy attack= Attack::decideNextAttack(global,initial,fromStrategyToGameState(CurrentStrategy));
        list<Country*> l = CurrentGameState->countries_owned_by(MyPlayer);
        l.push_back(attack.attacked);
        CurrentGameState->current_armies.find(attack.attacker) = 1;
        CurrentGameState->current_armies.find(attack.attacked) = (int)(InitialGameState->get_army(attack.attacker)-1)*0.5;
        double score = reinforcementConfigurationEvaluation(CurrentGameState);
        if(score > BestScore)
        {
            BestScore = score;
            BestStrategy = CurrentStrategy;
        }
    }
    return BestStrategy;
}

void RandomReinforcement::fillQueue()
{
    for(int i = 0 ; i < ExlorationNumber ; i++)
    {
        CurrentStrategy = drawConfiguration();
        CurrentBestStrategies.push(CurrentStrategy);
    }
    for(int i = 0 ; i < RandomDrawNumber - ExlorationNumber ; i++)
    {
        CurrentStrategy = drawConfiguration();
        insertConfiguration(CurrentStrategy);
    }
}
Game_State* RandomReinforcement::fromStrategyToGameState(Dispatch_Move* s)
{
    Game_State* NewGameState = new Game_State();
    for(Country* c = s->distribution.begin() ; c != s->distribution.end() ; c++ )
    {
        NewGameState->current_armies.at(c) += s->distribution.find(c);
    }
    return NewGameState;
}



Dispatch_Move* RandomReinforcement::drawConfiguration()
{
    list<Country*> owned_countries = InitialGameState->countries_owned_by(MyPlayer);
    Dispatch_Move* NewStrat = new Dispatch_Move();
    int size = owned_countries.size();
    int id = 0;
    int* renfort = new int[size];
    for(int i = 0 ; i < InitialGameState->reward_index ; i++)
        renfort[rand() % size]++;
    for(list<Country*>::iterator c = owned_countries.begin() ; c != owned_countries.end() ; c++ )
    {
        NewStrat->distribution.at[c] += renfort[id];
        id++;
    }


    return NewStrat;
}
    //draws a random cofiguration of the reinforcements and returns the corresponding GameState
float RandomReinforcement::reinforcementConfigurationEvaluation(Game_State* NewGameState)
{
    return evaluation.evaluate_game_state(global,initial , NewGameState , 1., 1., 1.,1.,1.);
}
    //Evaluates a configuration


