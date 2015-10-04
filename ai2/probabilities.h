#ifndef PROBABILITIES_H
#define PROBABILITIES_H

#pragma once

class Probabilities
{
    public:
        Probabilities();
        ~Probabilities();
        /*
         * i and j represent number of armies
         * i is used for our number of armies
         * while j is used for enemies army
         */
        float proba_to_win(int i, int j);
        float proba_to_survive(int i, int j);
        int reinforcement_attack(int i, int j);
        int reinforcement_defense(int i, int j);
    private:
        double *proba;
        int n; // length
};


#endif // PROBABILITIES_H
