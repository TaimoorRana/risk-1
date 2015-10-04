#ifndef Central_Unit_H
#define Central_Unit_H

#include<iostream>
#include <vector>

#include "./../interfaces/player.h"
#include "pseudo-engine/graph.h"
#include "path.h"
#include "agent.h"
#include "bid.h"
//#include "card_agent.h"

// Forward declarations
//class Agent;
//class Graph;
class Global_Settings;
class Initial_Settings;
class Continent;
class Country;
class Army;
class Game_State;
class Steps;
class Move;
class Dispatch_Move;
class State;
class ContinentAI;
//class Path;
class Card;


//it is a bad idea to write using namespace in header files

class Central_Unit : public Player
{
    public:
        Central_Unit();
        Central_Unit(Graph* g, int player);
        ~Central_Unit();

        //getters,setters
        static Agent* getAgent(int n);
        int get_nb_countries(){return m_nb_countries;}
        int getProbaMin(){return m_probaMin;}
        int getRenfort(){return m_nbRenfort;}
        unsigned int get_compt(){return m_compt;}
        unsigned int get_compt_attack(){return m_compt_attack;}
        Graph* getGraph(){return m_graph;}
        int getPlayer() {return m_player;}
        int getNbTotPlayers() {return m_nbTotPlayers;}
//        std::vector<Card_Agent::Card_AI3> get_cards(){return m_cards;}
//        Card* get_card(std::string s); //!!!!!! à coder !!!!!!!!!!!!!!!!!!!!!!!!!
        void set_nb_countries(int val){m_nb_countries=val;}
        void setNbRenfort(int val){m_nbRenfort=val;}
        void setProbaMin(float val){m_probaMin=val;}
        void setCompt(unsigned int val){m_compt=val;}
        void set_compt_attack(unsigned int val){m_compt_attack=val;}
        void setGraph(Graph* g){m_graph=g;}
        void setPlayer(int val){m_player=val;}
        void setNbTotPlayers(int val){m_nbTotPlayers=val;}
//        void setCartes(std::vector<Card_Agent::Card_AI3> cartes){m_cards=cartes;}

        virtual void receive_global_settings(Global_Settings *gs);
        void receive_initial_settings(Initial_Settings *is);
        void receive_game_state(Game_State* gs);

        virtual Dispatch_Move* first_move(Initial_Settings* is);
        virtual Move* next_move(Game_State* gs);

        //les fonctions de conversion avec shared_structures
        Country* State_to_Country(State* state);
        State* Country_to_State(Country* country);
        State* Countryconst_to_State(Country* country);
        Country* Stateconst_to_Country(State* state);

        ContinentAI* Continent_to_ContientAI(Continent *cont);
        Continent* ContinentAI_to_Continent(ContinentAI *cont_ai);

        static int MAX_LENGTH_PATH;



    protected:
        int m_nb_countries;
        int m_nbRenfort;
        float m_probaMin;

        int m_compt;
        int m_compt_path;
        int m_compt_state;
        int m_compt_attack;

        Graph* m_graph;
        int m_player; //notre numéro de joueur!
        int m_nbTotPlayers;
        static std::vector<Agent*> m_agents;
//        std::vector<Card_Agent::Card_AI3> m_cards;
        std::vector<Path*> m_listPaths;

};

#endif // Central_Unit_H
