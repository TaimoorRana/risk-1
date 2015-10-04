#ifndef DISPATCH_MOVE_AI_H
#define DISPATCH_MOVE_AI_H
#pragma once
#include "randomreinforcement.h"

class compareDispatchMove
{
public:
    bool operator()(Dispatch_Move* a , Dispatch_Move* b)
    {
        float score_a = RandomReinforcement::reinforcementConfigurationEvaluation(a);
        float score_b = RandomReinforcement::reinforcementConfigurationEvaluation(b);
        if(score_a >= score_b)
            return true;
        return false;

    }
};



#endif // DISPATCH_MOVE_AI_H
