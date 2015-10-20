#include "country.h"

std::map <std::string, Country*> Country::name_to_country_;
std::map <int, Country*> Country::id_to_country_;

Country::Country(std::string name) : name_(name) {
    name_to_country_[name_] = this;
    id_ = name_to_country_.size();
    id_to_country_[id_] = this;
}

std::string Country::get_name() const { return name_; }

Country* Country::get_country (std::string country_name){
    return name_to_country_[country_name];
}

Country* Country::get_country (int id){
    return id_to_country_[id];
}

int Country::get_id() const { return id_; }
