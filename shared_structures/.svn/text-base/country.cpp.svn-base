#include "country.h"

int Country::quantity_of_countries = 0;
map <string, Country*> Country::name_to_Country=map <string, Country*>();
map <int, Country*> Country::id_to_Country=map <int, Country*>();

Country::Country(string name)
{
    this->name = name;
    this->id = ++Country::quantity_of_countries;
    name_to_Country.insert(pair<string, Country*> (name, this));
    id_to_Country.insert(pair<int, Country*> (id, this));
}

string Country::get_name()
{
    return this->name;
}

Country* Country::get_country (string country_name)
{
    return name_to_Country[country_name];
}

Country* Country::get_country (int id)
{
    return id_to_Country[id];
}

int Country::get_id() const
{
    return this->id;
}

string Country::toString ()
{
    return this->name;
}
