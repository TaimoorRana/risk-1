#ifndef AGENT_H
#define AGENT_H
#include "pseudo-engine/state.h"
#include <set>
#include<string>
#include"path.h"
//#include"Central_Unit.h"

//it is a bad idea to write using namespace in std files

class Bid;

class Agent
{
    public:
        //ctor, dtor
        Agent();
        ~Agent();
        Agent(State& s, bool mars, int joueur);

        //methods
        std::string toString(); //renvoie une chaine décrivant brièvement l'agent               ok
        float ability_to_defend(State& c);
        float goal_value();
        float get_ability_to_defend(int nbArmeesEnPlus);
        Bid* best_offensive_bid(int nb_armies);//Claire & Marie
        Bid* best_defensive_bid(int nb_armies);//Claire & Marie
        Bid* best_bid(int nb_armies); //combine best_offensive et best_defensive bids
        Bid* offensive_bid(int nb_armies);//Claire & Marie
        Bid* defensive_bid(int nb_armies);
        bool isAgent(const State& st);//retourne 1 si le state st correspond à cet Agent        ok
        bool isEqualTo(Agent const& a) const; //compare deux agents                             ok
        std::set<Path*> send();//récupère tous les chemins des voisins et les complète en ajoutant this, renvoie ensuite l'ensemble de ses chemins //Mickael
        void append(std::set<Path*> ens);//ajoute à l'ensemble actuel les chemins reçus par send des autres Agents //Mickael

        //je rajoute des fonctions qui me semblent utiles (mais ptet pas en fait)
        void sendToNeighbours(Path& p); //permet à un agent d'envoyer un chemin à tous ses voisins
        //cette fonction est récursive, les voisins renvoyant eux-mêmes le path à leurs voisins, jusqu'à ce que l'on
        //tombe sur un agent de mars ou si la longueur devient trop grande
        void addToGoalSet(Path& p); //ajoute le path p au goalset de l'agent a
        bool attack(Path& p); //demande à l'agent (de Mars!) d'attaquer suivant le chemin p, c'est a priori utile que pendant les phases de test
        //car c'est engine qui s'en occupera finalement
        bool attack_agent(Agent& ag);
        void printGoalSet();
        void clearGS();


        //accesseurs et getters
        unsigned int getId() const{return m_id;}
        bool getIsMars() const{return m_isMars;}
        std::set<Path*> getGoalset() const{return m_goalset;}
        State* getState() const {return m_s;}
        float getWorth() const{return m_worth;}
        int getJoueur() const{return m_joueur;}
        //Central_Unit getUC() const {return m_uc;}
        void setId(unsigned int i){m_id=i;}
        void setGoalset(std::set<Path*> s);
        void setIsMars(bool im){m_isMars=im;}
        void setState(State* s){m_s=s;}
        void setWorth(float w){m_worth=w;}
        void setJoueur(int val){m_joueur=val;}
        //void setUC(Central_Unit c){m_uc=c;}



    protected:
        std::set<Path*> m_goalset; // notre set qui contient tous nos buts
        float m_worth; //represente la valeur de l'agent
        unsigned int m_id;//Différencier les agents
        bool m_isMars;//1 si l'Agent nous appartient, 0 sinon
        State* m_s;
        int m_joueur; //numéro du joueur de UC qui a créé l'agent
        //Central_Unit m_uc;

};

#endif // AGENT_H
