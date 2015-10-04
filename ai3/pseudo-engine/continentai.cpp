#include "continentai.h"
#include "state.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

ContinentAI::ContinentAI()
{

}

ContinentAI::ContinentAI(string name, int r, int t, int f):m_name(name), m_renforts(r), m_taille(t),m_frontieres(f)
{
    //ctor
    m_pays=vector<State*>();
}

ContinentAI::~ContinentAI()
{
    //dtor
}

void ContinentAI::addState(State* s)
{
    m_pays.push_back(s);
}

int ContinentAI::nbFrontieres()
{
    vector<State*> pays=Getpays();
    int rep=0;
    for (int i=0; i<pays.size();i++)
    {
        vector<State*> voisins=pays[i]->Getvoisins();
        for (int j=0; j<voisins.size();j++)
        {
            if (voisins[j]->Getcontinent()->Getid()!=Getid())
            {
                rep++;
            }
        }
    }
    return rep;
}
