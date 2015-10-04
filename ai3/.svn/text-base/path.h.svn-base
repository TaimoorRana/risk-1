#ifndef PATH_H
#define PATH_H
#include<vector>
#include<string>
#include <iostream>
#include "proba.h"

class Agent;

class Path
{
    public:
        Path(unsigned int length=0, float value=0, float bid = 0,int nbArmees=0);
        bool contains (Agent& a) const;//false si l'Agent n'est pas dans la liste, true sinon
        void add (Agent* a);//rajoute l'Agent a au chemin
        void affiche() const;
        float get_proba_of_success(int nbArmeesEnPlus, bool debug) const;
        Agent* getHead(); //renvoie le premier agent du path

        //getteurs et accesseurs
        int getLength() const{return m_length;}
        float getValue() const{return m_value;}
        float getBid() const{return m_bid;}
        float getNbArmees() const{return m_nbArmees;}
        std::vector<Agent*> getPath() const{return m_path;}

        void setValue(const float val){m_value=val;}
        void setBid(const float val){m_bid=val;}
        void setPath(std::vector<Agent*> v){m_path=v;}
        void setNbArmees(int n){m_nbArmees=n;}
        void setLength(unsigned int l){m_length=l;}

        bool friend operator<(Path const& p1, Path const& p2);

    protected:
        unsigned int m_length;
        std::vector<Agent*> m_path;
        float m_value;
        float m_bid; //nul sauf si enchère
        int m_nbArmees;

};


#endif // PATH_H
