#ifndef CARD_AGENT_H
#define CARD_AGENT_H

#include <vector>
#include "../ai3/pseudo-engine/graph.h"
#include "../shared_structures/card.h"

#include "../shared_structures/country.h"

//it is a bad idea to write using namespace in header files

//Each player instantiates a card agent which represents the cards he owns and finds the best combos he can use
class Card_Agent
{
    public:
        //Represents a card : it is just an integer which is between 0 and 43 (42 and 43 = joker)
        class Card_AI3{
        public :
            Card_AI3(int a);
            unsigned char getCard();
            unsigned char getSymb();
            static Card_AI3 convertFromEngine(Card* c);
            std::string Card_AI3ToString();
        private :
            static unsigned char c;
        };

        //Represents the result when the Card_Agent wants to use cards
        class Combi{
        public :
            Combi(int a, std::vector<Card_AI3> c);
            ~Combi();
            int getRes();
            std::vector<Card_AI3> getCards();
        private :
            int base; //Represents the number of soldiers you can add playing this combo
            std::vector<Card_AI3> cartes; //The cards you have to play when you play this combo
        };

        int getColor(); //get the number of the player
        int getCavalry();// get the position of the golden cavalry
        std::vector<Card_AI3> getCards ();//get the cards the player owns
        void addCard(Card_AI3 a);//add Card a to the player's cards
        void removeCard(Card_AI3 c);
        void playCards(std::vector<Card_AI3> v);
        int nbCards();// return the player's number of cards
        bool hasToPlay();// return true if and only if the player has got at least 5 cards
        Combi bestCombi();

        Card_Agent(int nb);//constructeur : nb represents the number of the player
        Card_Agent(int nb, Graph g); //constructeur : nb represents the number of the player, g the graph of the game
        Graph getGraph(){return g;}
        ~Card_Agent();//destructeur

    private:
          Graph g;
          int color; //The number of the player
          std::vector<Card_AI3> cards; //The cards the player owns
          static int goldCavalry; //The position of the golden cavalry (this number is the number of added troops corresponding to the next combo someone plays)

          static void CavalryMove();//moves the golden cavalry to his next position
          Combi combines();

          //returns true if and only if your cards allow you to play times combos of type k
          //v contains the number of each type of card you have ; for the moment there are no jokers ; v[0] = nb of soliers, v[1] = nb of cavalry, v[2] = nb of barrels
          //if k <=2 one is looking for combos composed of 3 cards of type k
          //if k==3 one is looking for combos composed of one card of each type
          bool traitement_aux(std::vector<int>* v, unsigned char k, int times);

          std::vector<std::vector<int> > traitement_aux_cycle(std::vector<int>* v, unsigned char j1, unsigned char j2, unsigned char j3, unsigned char j4);
          std::vector<std::vector<int> > traitement(std::vector<int>* v);
          int RenfortCombi(int k);
};

int Card_Agent::goldCavalry = 4;//initializes the golden cavalry

#endif // Card_Agent_H
