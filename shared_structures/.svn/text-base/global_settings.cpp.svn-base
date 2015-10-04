#include <iostream>
#include <fstream>
#include <stdlib.h>

#include <map>
#include <set>
#include <vector>
#include <string>

//#include <QFile>
//#include <QDebug>

#include "global_settings.h"
#include "continent.h"
#include "card.h"
#include "country.h"
//#include "../engine/objectives.h"
#include "../utils/textutils.h"

Global_Settings::Global_Settings(){

}


Global_Settings::Global_Settings(char* data_file_name, set<Objective*> objectives)
{
    ifstream data_file;
    data_file.open(data_file_name, ios::in);


//    qDebug()<<"File open";

    if (data_file.is_open())
    {
        TextUtils * utils = new TextUtils();
        string line;
        getline(data_file, line); // Reading header

        // Read Continents and corresponding troop bonus
        while (getline(data_file, line) && line[0] != '/')
        {
            utils->remove_empty_spaces(line); // Defined on TextUtils
            vector<string> splited_line = utils->split(line, '#'); // Defined on TextUtils

            string continent_name = splited_line[0];
            int troop_bonus = atoi(splited_line[1].c_str());

            continents.insert(new Continent(continent_name, troop_bonus));
        }

        // Read Countries and corresponding Continents and Symbol

        while (getline(data_file, line) && line[0] != '/')
        {
            utils->remove_empty_spaces(line); // Defined on TextUtils
            vector<string> splited_line = utils->split(line, '#'); // Defined on TextUtils

            string country_name = splited_line[0];
            string continent_name = splited_line[1];
//            Card::Symbol symbol = Card::get_symbol(splited_line[2]);

            Country * country = new Country (country_name);
            Continent::get_continent(continent_name)->add_country(country);
//            cards.insert(new Card(country, symbol));
        }

        // Read Countries and corresponding neighors list
        while (getline(data_file, line) && line[0] != '/')
        {

            utils->remove_empty_spaces(line); // Defined on TextUtils

            vector<string> splited_line = utils->split(line, '#'); // Defined on TextUtils

            string country_name = splited_line[0];
            Country* country = Country::get_country(country_name);
            set<Country*> neighbors = graph[country];

            vector<string>::iterator it;
            for (it = splited_line.begin()+1; it != splited_line.end(); ++it) {
                string neighbor_name = *it;
                Country* neighbor = Country::get_country(neighbor_name);
                neighbors.insert(neighbor);
            }
        }

        data_file.close();
    }

    else cout << "Error: Unable to open file " << data_file_name;

    // Initializing objectives
    this->objectives = objectives;

    // Initializing vector <int> reward_values;
    // ... to be done
}

Global_Settings::Global_Settings(char* data_file_name)
{
    /*QFile data_file(data_file_name);
    qDebug() << "Beginning of the reading";
    qDebug() << "Reading continents...";
    if (data_file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        TextUtils * utils = new TextUtils();
        string line;
        data_file.readLine(); // Reading header
        bool continuer = true;
        // Read Continents and corresponding troop bonus
        while (!data_file.atEnd() && continuer)
        {
            if (line[0] == '/')
                continuer = false;
            else
            {
                line = data_file.readLine().toStdString();
                utils->remove_empty_spaces(line); // Defined on TextUtils
                vector<string> splited_line = utils->split(line, '#'); // Defined on TextUtils
                string continent_name = splited_line[0];
                int troop_bonus = atoi(splited_line[1].c_str());

                continents.insert(new Continent(continent_name, troop_bonus));
            }
        }
        qDebug() << "Reading countries...";
        // Read Countries and corresponding Continents and Symbol
        continuer = true;
        while (!data_file.atEnd() && continuer)
        {
            if (line[0] == '/')
                continuer = false;
            else
            {
                utils->remove_empty_spaces(line); // Defined on TextUtils
                vector<string> splited_line = utils->split(line, '#'); // Defined on TextUtils

                string country_name = splited_line[0];
                string continent_name = splited_line[1];
                Card::Symbol symbol = Card::get_symbol(splited_line[2]);

                Country * country = new Country (country_name);
                Continent::get_continent(continent_name)->add_country(country);
                cards.insert(new Card(country, symbol));
            }
        }

        // Read Countries and corresponding neighors list

        continuer = true;
        qDebug() << "Reading neighbors...";
        while (!data_file.atEnd() && continuer)
        {
            if (line[0] == '/')
                continuer = false;
            else
            {
                utils->remove_empty_spaces(line); // Defined on TextUtils

                vector<string> splited_line = utils->split(line, '#'); // Defined on TextUtils

                string country_name = splited_line[0];
                Country* country = Country::get_country(country_name);
                set<Country*> neighbors = graph[country];

                vector<string>::iterator it;
                for (it = splited_line.begin()+1; it != splited_line.end(); ++it) {
                    string neighbor_name = *it;
                    Country* neighbor = Country::get_country(neighbor_name);
                    neighbors.insert(neighbor);
                }
            }
        }

        data_file.close();
    }

    else cout << "Error: Unable to open file " << data_file_name;

    // Initializing objectives
    this->objectives = objectives;

    // Initializing vector <int> reward_values;
    // ... to be done
    */
}

set<Country*> Global_Settings::get_neighbors (Country * country)
{
    return graph[country];
}

set<Continent*> Global_Settings::get_continents ()
{
    return this->continents;
}

set <Card*> Global_Settings::get_cards ()
{
    return this->cards;
}

set <Country*> Global_Settings::get_countries()
{
    set<Country*> all_countries;
    set<Continent*> continents = Global_Settings::get_continents ();
    for (set<Continent*>::iterator it = continents.begin(); it != continents.end(); ++it)
    {   // For each continent
        set<Country*> cont_countries = (*it)->get_countries();
        for (set<Country*>::iterator it2 = cont_countries.begin(); it2 != cont_countries.end(); ++it2)
        {   // Insert all its contries
            all_countries.insert((*it2));
        }
    }
    return all_countries;
}


set<Objective *> Global_Settings::get_objectives()
{
    return this->objectives;
}

vector <int> Global_Settings::get_reward_values()
{
    return this->reward_values;
}

map <Country*, set<Country*> > Global_Settings::get_graph ()
{
    return this->graph;
}
