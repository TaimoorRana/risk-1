#ifndef CARD_H
#define CARD_H

#include <map>
#include <string>

class Country;

class Card : public Structure {

public:

    enum Symbol {
        Infantry = 0,
        Artillery,
        Cavalry,
        Joker,
        Undefined
    };

    Card(Country * const country, Symbol const symbol);

    static Symbol get_symbol(std::string const symbol_name);
    static Card* get_card (Country * const country);
    static Card* get_card (std::string const country_name);

    Symbol get_symbol() const;
    Country* get_country_card() const;

private:
    static std::map<Country*, Card*> country_to_card_;

    Country *country_;
    Symbol symbol_;
    int id_;

};


#endif // CARD_H
