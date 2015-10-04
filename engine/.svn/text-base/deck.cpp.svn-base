#include "deck.h"

//There are totally 44 cards, each card has two function, one is country, the other is type of army
std::string nameList[88] = {
    "Alaska", "soldier",
    "Alberta", "soldier",
    "Central America", "cavalry",
    "Eastern United States", "artillery",
    "Greenland", "cavalry",
    "Northwest Territory", "artillery",
    "Ontario", "cavalry",
    "Quebec", "artillery",
    "Western United States", "soldier",
    "Argentina", "soldier",
    "Brazil", "artillery",
    "Peru", "cavalry",
    "Venezuela", "artillery",
    "Great Britain", "cavalry",
    "Iceland", "soldier",
    "Northern Europe", "cavalry",
    "Scandinavia", "artillery",
    "Southern Europe", "cavalry",
    "Ukraine", "artillery",
    "Western Europe", "soldier",
    "Congo", "cavalry",
    "East Africa", "artillery",
    "Egypt", "soldier",
    "Madagascar", "soldier",
    "North Africa", "soldier",
    "South Africa", "artillery",
    "Afghanistan", "soldier",
    "China", "cavalry",
    "India", "soldier",
    "Irkutsk", "soldier",
    "Japan", "soldier",
    "Kamchatka", "cavalry",
    "Middle East", "artillery",
    "Mongolia", "artillery",
    "Siam", "artillery",
    "Siberia", "artillery",
    "Ural", "cavalry",
    "Yakutsk", "cavalry",
    "Eastern Australia", "soldier",
    "Indonesia", "cavalry",
    "New Guinea", "cavalry",
    "Western Australia", "artillery",
    "joker", "joker",
    "joker","joker"
};


Card::Card(){
    cardID=0;
}

Card::~Card(){}

int Card::getID(){
    return cardID;
}

std::string Card::getTerritory(){
    return nameList[2*cardID];
}

std::string Card::getArmy(){
    return nameList[2*cardID+1];
}

void Card::setCard(int i){
    cardID=i;
}

bool Card::canExchange(int playerCards[], int numCards){
    if(numCards<3) return false;

    int armyCount[3];
    for(int i=0;i<4;i++){
        armyCount[i]=0;
    }
    std::string str0("soldier");
    std::string str1("cavalry");
    std::string str2("artillery");
    for(int i=0; i<numCards; i++){
        if(playerCards[i]==42||playerCards[i]==43) return true;
        std::string str = nameList[2*playerCards[i]+1];
        if(str.compare(str0)==0) armyCount[0]++;
        if(str.compare(str1)==0) armyCount[1]++;
        if(str.compare(str2)==0) armyCount[2]++;
    }
    for(int i=0;i<3;i++){
        if(armyCount[i]>=3) return true;
    }
    if(armyCount[0]>0&&armyCount[1]>0&&armyCount[2]>0) return true;
    return false;
}

bool Card::canExchangeSelected(int selectedCards[]){

    int armyCount[4];
    for(int i=0;i<4;i++){
        armyCount[i]=0;
    }
    std::string str0("soldier");
    std::string str1("cavalry");
    std::string str2("artillery");
    std::string str3("joker");
    for(int i=0; i<3; i++){
        std::string str = nameList[2*selectedCards[i]+1];
        if(str.compare(str0)==0) armyCount[0]++;
        if(str.compare(str1)==0) armyCount[1]++;
        if(str.compare(str2)==0) armyCount[2]++;
        if(str.compare(str3)==0) armyCount[3]++;
    }
    // 3 same cards
    for(int i=0;i<3;i++){
        if(armyCount[i]==3) return true;
    }
    // 3 different cards
    if(armyCount[0]>0&&armyCount[1]>0&&armyCount[2]>0) return true;
    // 1 joker + 2 other cards
    if(armyCount[3]==1) return true;
    return false;
}

//For each round, we can exchange for different quatity cards
int Card::exchangeCards(int round){
    if(round==1) return 4;
    else if(round==2) return 6;
    else if(round==3) return 8;
    else return 10 + 5*(round-4);
}



Deck::Deck(){
    deckTop=0;
    for(int i=deckTop; i < 44; i++)
        aDeckOfCards[i].setCard(i);
}

Deck::~Deck(){}

Card Deck::pickCard(){
    if(deckTop<44){
        Card c = aDeckOfCards[deckTop];
        deckTop++;
        return c;
    }else{
        shuffleDeck();
        deckTop=1;
        return aDeckOfCards[0];
    }
}

void Deck::shuffleDeck(){
    srand (time(NULL));
    for (int i = 0; i < 100; i++){
        int index1 = rand()%44;
        int index2 = rand()%44;
        swapCards(index1, index2);
    }
}

void Deck::swapCards(int first, int second){
    Card temp = aDeckOfCards[first];
    aDeckOfCards[first] = aDeckOfCards[second];
    aDeckOfCards[second] = temp;
}
