#include "card_agent.h"

#include <iostream>

Card_Agent::Card_AI3::Card_AI3(int a){ //creates a card
    if ((c>=43) || (c<0)){
        //Error : gets printed
        std::cout << "Mauvais numéro de carte" << std::endl;
        c = 0;
    }
    c = (unsigned char) a;
}

unsigned char Card_Agent::Card_AI3::getCard(){ // returns the card
    return c;
}

Card_Agent::Card_AI3 Card_Agent::Card_AI3::convertFromEngine(Card* c){
    std::string str (c->get_country_card()->get_name());
    if (str.compare("Alaska") == 0)
        return Card_AI3(0);
    if (str.compare("Alberta") == 0)
        return Card_AI3(1);
    if (str.compare("Central America") == 0)
        return Card_AI3(2);
    if (str.compare("Eastern United States") == 0)
        return Card_AI3(3);
    if (str.compare("Greenland") == 0)
        return Card_AI3(4);
    if (str.compare("Northwest Territory") == 0)
        return Card_AI3(5);
    if (str.compare("Ontario") == 0)
        return Card_AI3(6);
    if (str.compare("Quebec") == 0)
        return Card_AI3(7);
    if (str.compare("Western United States") == 0)
        return Card_AI3(8);
    if (str.compare("Argentina") == 0)
        return Card_AI3(9);
    if (str.compare("Brazil") == 0)
        return Card_AI3(10);
    if (str.compare("Peru") == 0)
        return Card_AI3(11);
    if (str.compare("Venezuela") == 0)
        return Card_AI3(12);
    if (str.compare("Great Britain") == 0)
        return Card_AI3(13);
    if (str.compare("Iceland") == 0)
        return Card_AI3(14);
    if (str.compare("Northern Europe") == 0)
        return Card_AI3(15);
    if (str.compare("Scandinavia") == 0)
        return Card_AI3(16);
    if (str.compare("Southern Europe") == 0)
        return Card_AI3(17);
    if (str.compare("Ukraine") == 0)
        return Card_AI3(18);
    if (str.compare("Western Europe") == 0)
        return Card_AI3(19);
    if (str.compare("Congo") == 0)
        return Card_AI3(20);
    if (str.compare("Eastern Africa") == 0)
        return Card_AI3(21);
    if (str.compare("Egypt") == 0)
        return Card_AI3(22);
    if (str.compare("Madagascar") == 0)
        return Card_AI3(23);
    if (str.compare("North Africa") == 0)
        return Card_AI3(24);
    if (str.compare("South Africa") == 0)
        return Card_AI3(25);
    if (str.compare("Afghanistan") == 0)
        return Card_AI3(26);
    if (str.compare("China") == 0)
        return Card_AI3(27);
    if (str.compare("India") == 0)
        return Card_AI3(28);
    if (str.compare("Irkutsk") == 0)
        return Card_AI3(29);
    if (str.compare("Japan") == 0)
        return Card_AI3(30);
    if (str.compare("Kamchatka") == 0)
        return Card_AI3(31);
    if (str.compare("Middle East") == 0)
        return Card_AI3(32);
    if (str.compare("Mongolia") == 0)
        return Card_AI3(33);
    if (str.compare("Siam") == 0)
        return Card_AI3(34);
    if (str.compare("Siberia") == 0)
        return Card_AI3(35);
    if (str.compare("Ural") == 0)
        return Card_AI3(36);
    if (str.compare("Yakutsk") == 0)
        return Card_AI3(37);
    if (str.compare("Eastern Australia") == 0)
        return Card_AI3(38);
    if (str.compare("Indonesia") == 0)
        return Card_AI3(39);
    if (str.compare("New Guinea") == 0)
        return Card_AI3(40);
    if (str.compare("Western Australia") == 0)
        return Card_AI3(41);
    if (str.compare("Joker1") == 0)
        return Card_AI3(42);
    return Card_AI3(43);
}

string Card_Agent::Card_AI3::Card_AI3ToString(){
    switch(this->getCard()){
    case 0:return "Alaska";
    case 1:return "Alberta";
    case 2:return "Central America";
    case 3:return "Eastern United States";
    case 4:return "Greenland";
    case 5:return "Northwest Territory";
    case 6:return "Ontario";
    case 7:return "Quebec";
    case 8:return "Western United States";
    case 9:return "Argentina";
    case 10:return "Brazil";
    case 11:return "Peru";
    case 12:return "Venezuela";
    case 13:return "Great Britain";
    case 14:return "Iceland";
    case 15:return "Northern Europe";
    case 16:return "Scandinavia";
    case 17:return "Southern Europe";
    case 18:return "Ukraine";
    case 19:return "Western Europe";
    case 20:return "Congo";
    case 21:return "Eastern Africa";
    case 22:return "Egypt";
    case 23:return "Madagascar";
    case 24:return  "North Africa";
    case 25:return "South Africa";
    case 26:return "Afghanistan";
    case 27:return "China";
    case 28:return "India";
    case 29:return "Irkutsk";
    case 30:return "Japan";
    case 31:return "Kamchatka";
    case 32:return "Middle East";
    case 33:return "Mongolia";
    case 34:return "Siam";
    case 35:return "Siberia";
    case 36:return "Ural";
    case 37:return "Yakutsk";
    case 38:return "Eastern Australia";
    case 39:return "Indonesia";
    case 40:return "New Guinea";
    case 41:return "Western Australia";
    case 42:return "Joker1";
    case 43:return "Joker2";
    }
}
unsigned char Card_Agent::Card_AI3::getSymb(){
    switch(c){
        case 0 : return 0 ;
        case 1 : return 0 ;
        case 2 : return 1 ;
        case 3 : return 0 ;
        case 4 : return 1 ;
        case 5 : return 2 ;
        case 6 : return 1 ;
        case 7 : return 2 ;
        case 8 : return 0 ;
        case 9 : return 0 ;
        case 10 : return 2 ;
        case 11 : return 1 ;
        case 12 : return 2 ;
        case 13 : return 1 ;
        case 14 : return 0 ;
        case 15 : return 1 ;
        case 16 : return 2 ;
        case 17 : return 1 ;
        case 18 : return 2 ;
        case 19 : return 0 ;
        case 20 : return 1 ;
        case 21 : return 2 ;
        case 22 : return 0 ;
        case 23 : return 0 ;
        case 24 : return 0 ;
        case 25 : return 2 ;
        case 26 : return 0 ;
        case 27 : return 1 ;
        case 28 : return 0 ;
        case 29 : return 0 ;
        case 30 : return 0 ;
        case 31 : return 1 ;
        case 32 : return 2 ;
        case 33 : return 2 ;
        case 34 : return 2 ;
        case 35 : return 2 ;
        case 36 : return 1 ;
        case 37 : return 1 ;
        case 38 : return 0 ;
        case 39 : return 1 ;
        case 40 : return 1 ;
        case 41 : return 2 ;
    }
    return 3;
}

//creates a card agent of color g
Card_Agent::Card_Agent(int g)
{
    cards = std::vector<Card_AI3> ();
    color = g;
}

//creates a card agent with color nb and graph g
Card_Agent::Card_Agent(int nb, Graph g){
    cards = std::vector<Card_AI3> ();
    color = nb;
    this->g = g;
}




//destructor
Card_Agent::~Card_Agent(){};

//adds card a to the list of cards of this card agent
void Card_Agent::addCard(Card_AI3 a){
    cards.push_back(a);
}

//return the cards of this card agent
std::vector<Card_Agent::Card_AI3> Card_Agent::getCards(){
    return cards;
}

//returns the number of cards of this card agent
int Card_Agent::nbCards(){
    return cards.size();
}

//returns true if and only if the player has strictly more than 4 cards
bool Card_Agent::hasToPlay(){
    return (Card_Agent::nbCards() >= 5);
}

//returns the number of troops you can get if you play the next combo of cards
int Card_Agent::getCavalry(){
    return Card_Agent::goldCavalry;
}

//moves the golden cavalry to his next position
void Card_Agent::CavalryMove(){
    //order of moves : 4 6 8 10 15 20 25 30 35 40 45 50 55 60
    if (Card_Agent::goldCavalry < 10)
         Card_Agent::goldCavalry += 2;
    else {
         if (Card_Agent::goldCavalry < 60)
             Card_Agent::goldCavalry += 5;
         else
                Card_Agent::goldCavalry = 4; // returns to 4 after reinforcing with 60 troops ; this rule can be discussed
    }

}

//creates a combi which gives you a troops playing the cards in c
Card_Agent::Combi::Combi(int a, std::vector<Card_Agent::Card_AI3> c){
    base = a;
    cartes = c;
}

//destructor of a combi
Card_Agent::Combi::~Combi(){}

//returns the number of troops you earn through this combi
int Card_Agent::Combi::getRes(){return base;}

//return the cards you have to play in order to play this combi
std::vector<Card_Agent::Card_AI3> Card_Agent::Combi::getCards (){
    return cartes;
}

void Card_Agent::removeCard(Card_Agent::Card_AI3 c){
    for (std::vector<Card_Agent::Card_AI3>::iterator k = cards.begin(); k != cards.end() ; k++){
        /*bool trouve = false;//becomes true when c has been found
        if (trouve){
            (*(k-1)) = Card_Agent::Card_AI3((*k).getCard());//erase preceding value
        }
        if ((*k).getCard() == c.getCard()){
            trouve = true;
        }
        if (trouve)
            cards.pop_back();
    }
            cards.erase(k);
            break;
        }*/
        if ((*k).getCard() == c.getCard()){
            cards.erase(k);
            return;
        }
    }

}
void Card_Agent::playCards(std::vector<Card_Agent::Card_AI3> v){
    for (int i=0; i < (int) v.size(); i++){
        this->removeCard(v[i]);
    }
}

//returns true if and only if your cards allow you to play times combos of type k
//v contains the number of each type of card you have ; v[0] = nb of soliers, v[1] = nb of cavalry, v[2] = nb of barrels
//v[3] = nb of jokers
//if k <=2 one is looking for combos composed of 3 cards of type k
//if k==3 one is looking for combos composed of one card of each type
bool Card_Agent::traitement_aux(std::vector<int>* v, unsigned char k, int times){
    if ((k >= 0) &&(k <= 2)){
        if ((*v)[k] + (*v)[3] >= 3*times){
            int temp = (*v)[k] - 3*times;
            if (temp < 0){
                (*v)[3] += temp;
            }
            (*v)[k] = std::max(0, (*v)[k] - 3*times);
            return true;
        }
        return false;
    }
    if (k==3){
        if ((*v)[3] + std::min((*v)[0], std::min((*v)[1], (*v)[2])) >= times){
            (*v)[0] -=times;
            (*v)[1] -=times;
            (*v)[2] -=times;
            for (int j = 0; j <= 2 ; j++){
                if ((*v)[j] < 0){
                    (*v)[3] += (*v)[j];
                    (*v)[j] = 0;
                }
            }
            return true;
        }
        return false;
    }
    std::cout << "Erreur dans le traitement des combinaisons" << std::endl;
    return false;
}

//Returns in a list every multi-type combination of combos (1 combo = 3 cards which give troops) using the parameters
//v contains the number of each type of card you have ; v[0] = nb of soliers, v[1] = nb of cavalry, v[2] = nb of barrels
//j1,j2,j3,j4 represent the maximum number of combo of type 0,1,2,3 you want to try to use in order to make a cross-type multiple combo
//In fact this happens very scarcely, it can happen only if you have just eliminated a player which owned a lot of cards in your preceding turn
std::vector<std::vector<int> > Card_Agent::traitement_aux_cycle(std::vector<int>* v, unsigned char j1, unsigned char j2, unsigned char j3, unsigned char j4){
    std::vector<std::vector<int> > res = std::vector<std::vector<int> > ();
    for (unsigned char i1=0; i1 <= j1; i1++){
        for (unsigned char i2=0; i2 <= j2 ; i2++){
            for (unsigned char i3=0; i3 <= j3 ; i3++){
                for (unsigned char i4 = 0; i4 <= j4 ; i4++){
                    std::vector<int>* z = new std::vector<int> ();
                    //v has to get copied because traitement_aux modifies its argument
                    (*z)[0] = (*v)[0];
                    (*z)[1] = (*v)[1];
                    (*z)[2] = (*v)[2];
                    (*z)[3] = (*v)[3];
                    if ((Card_Agent::traitement_aux(z, (unsigned char) 0, (int) i1)) && (Card_Agent::traitement_aux(z, (unsigned char) 1, (int) i2)) &&(Card_Agent::traitement_aux(z,(unsigned char) 2,(int) i3 )) && (Card_Agent::traitement_aux(z,(unsigned char) 3,(int) i4))){
                                //this multi-type combination is realizable so we have to add it to our resulting list
                                std::vector<int> t = std::vector<int>();
                                t[0] = i1;
                                t[1] = i2;
                                t[2] = i3;
                                t[3] = i4;
                                res.push_back(t);
                            }
                }
            }
        }
    }
    return res;
}

//Returns the best multi-combination for the player
//w contains the player's numbers of cards, w[0,1,2,3] the number of cards with respectively soldier, cavalry, barrel, joker
std::vector<std::vector<int> > Card_Agent::traitement(std::vector<int>* w){
    unsigned char w3 = std::min((*w)[0], std::min((*w)[1], (*w)[2]))+ (*w)[3];
    return Card_Agent::traitement_aux_cycle(w, ((*w)[0]+ (*w)[3])/3 , ((*w)[1]+ (*w)[3])/3 , ((*w)[2]+ (*w)[3])/3, w3);
}

int Card_Agent::RenfortCombi(int k){
    int res = 0;
    int mem = goldCavalry;
    for (int i = 0; i < k; i++){
        res += Card_Agent::goldCavalry;
        Card_Agent::CavalryMove();
    }
    Card_Agent::goldCavalry = mem;
    return res;
}

//Creates the v necessary for Card_Agent::traitement, computes traitement and then finds the best multi-combination for the player
//Returns this best multi-combination
Card_Agent::Combi Card_Agent::bestCombi(){
    std::vector<Card_AI3> cartes = Card_Agent::getCards();
    std::vector<int> * w = new std::vector<int> ();
    std::vector<std::vector<int> > v = std::vector<std::vector<int> > ();
    //In w are stored the numbers of card of each type (soldier, cavalry, barrel, joker)
    //In v are stored the countries on the cards of the player, in v[4,5,6] if this country belongs to the player, in v[0,1,2,3] otherwise
    //v[3] contains the jokers
    for (std::vector<Card_AI3>::iterator k = cartes.begin() ; k != cartes.end() ; k++){

        (*w)[(*k).getSymb()]++;
        if ((this->getGraph()).Getstate()[(*k).getCard()]->State::Getjoueur() == this->Card_Agent::getColor()){
            v[((*k).getSymb()) + 4].push_back((*k).getCard());
        }
        else
            v[((*k).getSymb())].push_back((*k).getCard());
    }
    std::vector<std::vector<int> > liste = Card_Agent::traitement(w); // contains the list of playable combinations
    //Computes the resulting troops for each playable multi-combination and keeps in mind the best one
    if (liste.size() == 0){
        return Card_Agent::Combi(0, std::vector<Card_Agent::Card_AI3> ());
    }
    int base = 0;
    std::vector<int> temp = std::vector<int> ();
    std::vector<int> cardsToPlay = std::vector<int> ();//contains the number of cards of each type which have to get played
    for (std::vector<std::vector<int> >::iterator k = liste.begin(); k != liste.end(); k++){
        temp = *k;
        int base_temp = 2*(std::min((int) v[4].size(), temp[0]) + std::min((int)v[5].size(), temp[1]) + std::min((int) v[6].size(), temp[2])) + Card_Agent::RenfortCombi((temp[0]+temp[1]+temp[2]+temp[3])/3);
        if (base_temp > base){ //we have to register this multi-combination as a local best one
            base = base_temp;
            cardsToPlay[0] = temp[0];
            cardsToPlay[1] = temp[1];
            cardsToPlay[2] = temp[2];
            cardsToPlay[3] = temp[3];
        }
    }
    //Choose the cards to play (in terms of their corresponding countries)
    std::vector<Card_Agent::Card_AI3> cartesJouer = std::vector<Card_Agent::Card_AI3> ();
    for (int i=0; i < 4 ; i++){//For cards with soldier, cavalry, barrel, joker
        for (int j = 0; j < std::min(cardsToPlay[i], (int) v[i+4].size()); j++){//Cards which add 2 supplementary troops
            cartesJouer.push_back(Card_Agent::Card_AI3(v[i+4][j]));
        }
        for (int j=0; j < cardsToPlay[i] - (int) v[i+4].size(); j++){//Other cards
            cartesJouer.push_back(Card_Agent::Card_AI3(v[i][j]));
        }
    }

    return Card_Agent::Combi(base, cartesJouer);
}
