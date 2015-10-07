#ifndef COUNTRY_H
#define COUNTRY_H

#include <map>
#include <string>

class Country{

public:

    Country(std::string name);

    static Country* get_country (std::string country_name);
    static Country* get_country (int id);

    std::string get_name() const;
    int get_id() const;

private:
    static std::map <std::string, Country*> name_to_Country_;
    static std::map <int, Country*> id_to_Country_;
    std::string name_;
    int id_;
    
};

#endif // COUNTRY_H
