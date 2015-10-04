#ifndef CONTINENTAI_H
#define CONTINENTAI_H

#include<iostream>
#include<string>
#include<vector>

class State;

class ContinentAI
{
    public:
        ContinentAI();
        ContinentAI(std::string name, int r,int t, int f=1); //renforts, taille, frontières
        virtual ~ContinentAI();
        std::string Getname() { return m_name; }
        void Setname(std::string val) { m_name = val; }
        int Getrenforts() { return m_renforts; }
        void Setrenforts(int val) { m_renforts = val; }
        int Gettaille() { return m_taille; }
        void Settaille(int val) { m_taille = val; }
        int Getfrontieres() { return m_frontieres; }
        void Setfrontieres(int val) { m_frontieres = val; }
        int Getid() {return m_id;}
        void Setid(int val) {m_id=val;}
        std::vector<State*> Getpays(){return m_pays;} //vector contenant les pays du continent
        void Setpays(std::vector<State*> val){m_pays=val;}

        void addState(State* s);
        int nbFrontieres(); //renvoie le nombre de frontières que possède un continent //à tester!!


    protected:
    private:
        std::string m_name;
        int m_id;
        int m_renforts;
        int m_taille;
        int m_frontieres;
        std::vector<State*> m_pays;
};

#endif // CONTINENTAI_H
