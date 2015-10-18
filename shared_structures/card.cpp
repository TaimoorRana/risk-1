#include "card.h"

#include "country.h"

Card::Card(Country* country, Card::Symbol symbol) : country_(country), symbol_(symbol){
    country_to_card_[country_] = this;
    id_ = country_to_card_.size();
}

Country* Card::get_country_card() const { return country_; }

Card::Symbol Card::get_symbol() const { return symbol_; }

Card::Symbol Card::get_symbol(std::string const symbol_name) {
    switch (symbol_name){
        case "Infantry"  : return Card::Infantry;
        case "Cavalry"   : return Card::Cavalry;
        case "Artillery" : return Card::Artillery;
        case "Joker"     : return Card::Joker;
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

