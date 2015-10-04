#include "card.h"
#include "country.h"

int Card::quantity_of_cards=0;

Card::Card(Country* country, Symbol symbol)
{
    this->country = country;
    this->symbol = symbol;
    this->id = ++Card::quantity_of_cards;
    Card::country_to_card.insert(pair<Country*, Card*> (country, this));
}

Card* Card::get_card()
{
    return this;
}

Country* Card::get_country_card()
{
    return this->country;
}

Card::Symbol Card::get_symbol()
{
    return this->symbol;
}

Card::Symbol Card::get_symbol(string symbol_name)
{
    if (symbol_name.compare(string("Infantry")) == 0) return Infantry;
    else if (symbol_name.compare(string("Cavalry")) == 0) return Cavalry;
    else if (symbol_name.compare(string("Artillery")) == 0) return Artillery;
    else if (symbol_name.compare(string("Joker")) == 0) return Joker;
    else return Undefined;
}

Card* Card::get_card (Country* country)
{
    return Card::country_to_card[country];
}

Card* Card::get_card (string country_name)
{
    Country* country = Country::get_country(country_name);
    return Card::get_card(country);
}

map <Country*, Card*> Card::country_to_card;
