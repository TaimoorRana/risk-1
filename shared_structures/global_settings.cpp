#include "global_settings.h"

#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <string>

#include "card.h"
#include "continent.h"
#include "country.h"
//#include "../engine/objectives.h"
#include "../utils/textutils.h"

GlobalSettings::GlobalSettings(){

}


GlobalSettings::GlobalSettings(char* data_file_name, std::set<Objective*> objectives) : objectives_(objectives){
    ifstream data_file;
    data_file.open(data_file_name, ios::in);


//    qDebug()<<"File open";

    if (data_file.is_open()){
        TextUtils * utils = new TextUtils();
        std::string line;
        getline(data_file, line); // Reading header

        // Read Continents and corresponding troop bonus
        while (getline(data_file, line) && line[0] != '/'){
            utils->remove_empty_spaces(line); // Defined on TextUtils
            std::vector<std::string> splited_line = utils->split(line, '#'); // Defined on TextUtils

            std::string continent_name = splited_line[0];
            int troop_bonus = atoi(splited_line[1].c_str());

            continents_.insert(new Continent(continent_name, troop_bonus));
        }

        // Read Countries and corresponding Continents and Symbol

        while (getline(data_file, line) && line[0] != '/'){
            utils->remove_empty_spaces(line); // Defined on TextUtils
            std::vector<std::string> splited_line = utils->split(line, '#'); // Defined on TextUtils

            std::string country_name = splited_line[0];
            std::string continent_name = splited_line[1];
//            Card::Symbol symbol = Card::get_symbol(splited_line[2]);

            Country * country = new Country (country_name);
            Continent::get_continent(continent_name)->add_country(country);
//            cards_.insert(new Card(country, symbol));
        }

        // Read Countries and corresponding neighors list
        while (getline(data_file, line) && line[0] != '/'){

            utils->remove_empty_spaces(line); // Defined on TextUtils

            std::vector<std::string> splited_line = utils->split(line, '#'); // Defined on TextUtils

            std::string country_name = splited_line[0];
            Country* country = Country::get_country(country_name);
            std::set<Country*> neighbours = graph_[country];

            std::vector<std::string>::iterator it;
            for (it = splited_line.begin()+1; it != splited_line.end(); ++it) {
                std::string neighbour_name = *it;
                Country* neighbour = Country::get_country(neighbour_name);
                neighbours.insert(neighbour);
            }
        }
        data_file.close();

    } else {
        cout << "Error: Unable to open file " << data_file_name;
    }

    // Initializing std::vector<int> reward_values_;
    // ... to be done
}


std::set<Country*> GlobalSettings::get_neighbours (Country * country) const{
    return graph_.find(country)->second;
}


std::set<Continent*> GlobalSettings::get_continents () const { return continents_; }

std::set<Card*> GlobalSettings::get_cards () const { return cards_; }


std::set<Country*> GlobalSettings::get_countries() const {
    std::set<Country*> all_countries;
    std::set<Continent*> continents = GlobalSettings::get_continents ();
    for (std::set<Continent*>::iterator it = continents.begin(); it != continents.end(); ++it)
    {   // For each continent
        std::set<Country*> cont_countries = (*it)->get_countries();
        for (std::set<Country*>::iterator it2 = cont_countries.begin(); it2 != cont_countries.end(); ++it2)
        {   // Insert all its contries
            all_countries.insert((*it2));
        }
    }
    return all_countries;
}


std::set<Objective *> GlobalSettings::get_objectives() const { return objectives_; }

std::vector<int> GlobalSettings::get_reward_values() const { return reward_values_; }

std::map<Country*, std::set<Country*> > GlobalSettings::get_graph () const { return graph_; }
