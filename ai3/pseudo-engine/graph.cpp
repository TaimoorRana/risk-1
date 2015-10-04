#include "graph.h"
#include<iostream>

using namespace std;

Graph::Graph()
{
    //ctor
}

Graph::Graph(int N, vector<State*> tab, int NC, vector<ContinentAI*> tabcont):m_N(N),m_NC(NC)//, m_state(tab)
{
    m_state=vector<State*>();
    for (int i=0; i<N; i++)
    {
        m_state.push_back(tab[i]);
    }
    m_continent=vector<ContinentAI*>();
    for (int i=0; i<NC; i++)
    {
        m_continent.push_back(tabcont[i]);
    }
}

Graph::~Graph()
{
    //dtor
   // delete[] m_state;
}

float Graph::eval(int joueur)
{
    float rep=0;
    for (int i=0; i<m_N; i++)
    {
        rep=rep+m_state[i]->eval(joueur);
    }
    return rep;

}

State* Graph::operator [](int i)
{
    if (i<0 || i>=m_N)
    {
        cout<<"erreur indice"<<endl;
        return m_state[0];
    }
    else
    {
        return m_state[i];
    }
}


//très vraisemblablement inutile
/*
ContinentAI*& Graph::operator [](int i)
{
    if (i<0 || i>=m_NC)
    {
        cout<<"erreur indice"<<endl;
        return m_continent[0];
    }
    else
    {
        return m_continent[i];
    }
}
*/

vector<State *> Graph::pays_joueur(int i)
{
    vector<State*> rep;
    for (int k=0; k<m_N; k++)
    {
        if (m_state[k]->Getjoueur()==i)
        {
            rep.push_back(m_state[k]);
        }
    }
    return rep;
}

vector<State *> Graph::pays_ennemis(int i)
{
    vector<State*> rep;
    for (int k=0; k<m_N; k++)
    {
        if (m_state[k]->Getjoueur()!=i)
        {
            rep.push_back(m_state[k]);
        }
    }
    return rep;
}
