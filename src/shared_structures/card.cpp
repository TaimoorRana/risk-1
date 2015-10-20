#include "card.h"

#include "country.h"

std::map<Country*, Card*> Card::country_to_card_;

Card::Card(Country* country, Card::Symbol symbol) : country_(country), symbol_(symbol){
    country_to_card_[country_] = this;
    id_ = country_to_card_.size();
}

Country* Card::get_country_card() const { return country_; }

Card::Symbol Card::get_symbol() const { return symbol_; }

Card::Symbol Card::get_symbol(std::string const symbol_name) {
    if (symbol_name.compare("Infantry") == 0){
        return Card::Infantry;
    } else if (symbol_name.compare("Cavalry") == 0){
        return Card::Cavalry;
    } else if (symbol_name.compare("Artillery") == 0){
        return Card::Artillery;
    } else if (symbol_name.compare("Joker") == 0){
        return Card::Joker;
    }
    return Card::Undefined;
}

Card* Card::get_card (Country * const country){
    return Card::country_to_card_[country];
}

Card* Card::get_card (std::string const country_name){
    Country* country = Country::get_country(country_name);
    return Card::get_card(country);
}
