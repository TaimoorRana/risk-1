#include "country.h"

Country::Country(string name) : name_(name) {
    name_to_Country_[name_] = this;
    id_ = name_to_Country_.size();
    id_to_Country[id_] = this;
}

std::string Country::get_name(){ return name_; }

Country* Country::get_country (std::string country_name){
    return name_to_Country_[country_name];
}

Country* Country::get_country (int id){
    return id_to_Country_[id];
}

int Country::get_id(){ return id_; }
