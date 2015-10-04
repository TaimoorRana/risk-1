#include "probabilities.h"

Probabilities::Probabilities()
{
    n = 201;
    proba = new double[n*n];

    for(int k = 0;k<n;k++){
        proba[k]=0.; //defender wins
        proba[k*n]=1.; //attacker wins
    }

    for(int i=1;i<n;i++){
    for(int j=1;j<n;j++){
        if(i>=3&&j>=2){proba[i*n+j /* 605 to 803, 806 to 1004, ...... 40202 to  40400 */ ] = (2890./7776.*proba[i*n+j-2]
                                                   +2275./7776.*proba[(i-2)*n+j]
                                                   +2611./7776.*proba[(i-1)*n+j-1]);}
        if(i>=3&&j==1){proba[i*n+j /* 604, 805, 1006, .... , 40201 */ ] = (855./1296.
                                                   +441./1296.*proba[(i-1)*n+j]);}
        if(i==2&&j>=2){proba[i*n+j /* 404 to 602 */] = (295./1296.*proba[i*n+j-2]
                                                   +581./1296.*proba[(i-2)*n+j]
                                                   +420./1296.*proba[(i-1)*n+j-1]);}
        if(i==2&&j==1){proba[i*n+j /* 403 */ ] = (125./216.
                                                   +91./216.*proba[(i-1)*n+j]);}
        if(i==1&&j>=2){proba[i*n+j /* 203 to 401*/ ] = (55./216.*proba[i*n+j-1]);}
        if(i==1&&j==1){proba[i*n+j /* 202 */] = (15./36.);}
    }
    }

}

Probabilities::~Probabilities()
{
    delete[] proba;
    //dtor
}

//Return the probability to win a war (i vs j)
float Probabilities::proba_to_win(int i, int j){
    return proba[i*n+j];
}

//Return the probability to survive a war (j attack i (us))
float Probabilities::proba_to_survive(int i, int j){
    return 1. - proba[j*n+i];
}


//Return the amount of army that you need to add to i to have at least 50% chance to win against j (when you attack j)
int Probabilities::reinforcement_attack(int i, int j){
    int r=0; //armies that you need to add
    while(proba_to_win(i+r,j)<0.5){
        r++;
    }
    return r;
}

//Return the amount of army that you need to add to i to have at least 50% chance to win against j (when you defend !)
int Probabilities::reinforcement_defense(int i, int j){
    int r=0; //armies that you need to add
    while(proba_to_win(j,i+r)>0.5){
        r++;
    }
    return r;
}
