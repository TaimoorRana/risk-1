#ifndef CARD_H
#define CARD_H

#include <map>
#include <string>

class Country;

class Card {

public:

    enum Symbol {
        Infantry,
        Artillery,
        Cavalry,
        Joker,
        Undefined
    };

    Card(Country* country, Symbol symbol);

    static Symbol get_symbol(std::string symbol_name) const;
    static Card* get_card (Country* country) const;
    static Card* get_card (std::string country_name) const;

    Symbol get_symbol() const;
    Card* get_card() const;
    Country* get_country_card() const;

private:
    static std::map<Country*, Card*> country_to_card_;

    Country* country_;
    Symbol symbol_;
    int id_;

};


#endif // CARD_H
