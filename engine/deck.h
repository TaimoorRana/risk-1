#ifndef DECK
#define DECK

#include <random>
#include <time.h>
#include <string>


/*
* class Card:
* use getID(), getTerritory() and getArmy() functions to get the content of a card
*/

/*
* class Deck:
* use pickCard() to pick a card from the top of the deck, the return value is a Card
*/


class Card{
public:
    Card();
    ~Card();
    int getID();
    std::string getTerritory();
    std::string getArmy();
    void setCard(int i);
    static bool canExchange(int playerCards[], int numCards);
    static bool canExchangeSelected(int selectedCards[]);
    static int exchangeCards(int round);

protected:
    int cardID;
};


class Deck : public Card{
public:
    Deck();
    ~Deck();
    Card pickCard();
    void shuffleDeck();
    void swapCards(int first, int second);

private:
    Card aDeckOfCards[44]; // create a deck of cards
    int deckTop;

};

#endif // DECK

