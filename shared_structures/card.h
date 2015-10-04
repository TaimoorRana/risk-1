#ifndef CARD_H
#define CARD_H

#include <string>
#include <stdexcept>
#include <map>
//#include <QJsonObject>
//#include <QMap>
using namespace std;

class Country; //forward declaration

class Card {

public:

    enum Symbol {
        Infantry,
        Artillery,
        Cavalry,
        Joker,
        Undefined
    };

    Symbol get_symbol();

    Card(Country* country, Symbol symbol);

    Card* get_card();

    Country* get_country_card();

    static Symbol get_symbol(string symbol_name);

    static Card* get_card (Country* country);
    static Card* get_card (string country_name);

    static map<Country*, Card*> country_to_card;
    static int quantity_of_cards; // Initialized as zero with command int Card::quantity_of_cards = 0;
//    QJsonObject serialize(QMap<void*, int> &pointeurMap);
//    void deserialize(QMap<void*, int> &pointeurMap,QJsonObject json);
private:

    Country* country;
    Symbol symbol;
    int id;


};


#endif // CARD_H
