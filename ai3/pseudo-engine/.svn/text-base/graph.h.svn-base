#ifndef GRAPH_H
#define GRAPH_H

#include "state.h"
#include <vector>

//it is a bad idea to use namespace in header files!!

class Graph
{
    public:
        Graph();
        Graph(int N, std::vector<State*> tab, int NC, std::vector<ContinentAI*> tabcont);
        virtual ~Graph();
        std::vector<State*> Getstate() { return m_state; }
        void Setstate(std::vector<State*> val) { m_state = val; }
        std::vector<ContinentAI*> Getcontinent() {return m_continent;}
        void Setcontinent(std::vector<ContinentAI*> val){m_continent=val;}
        int GetN() { return m_N; }
        void SetN(int val) { m_N = val; }
        int GetNC() { return m_NC; }
        void SetNC(int val) { m_NC = val; }
        void addState(State& s); //non implémenté...
        void addContinent(ContinentAI& c); //non implémenté...
        float eval(int joueur);
        State* operator[](int i);
        //ContinentAI*& operator[](int i);
        std::vector<State*> pays_joueur(int i);
        std::vector<State*> pays_ennemis(int i);
    protected:
    private:
        std::vector<State*> m_state;
        std::vector<ContinentAI*> m_continent;
        int m_N;
        int m_NC; //nb de continents
};

#endif // GRAPH_H
