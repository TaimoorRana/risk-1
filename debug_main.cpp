#include "headers.h"


#include <vector>
#include <iostream>

using namespace std;


int main () {

    //char * path = "C:\\Users\\CESAR\\Documents\\Polytechnique\\3A\\INF585\\Project\\data\\standard_risk_configurations.dat";
    char *path = ":/data/standard_risk_configurations.dat";


    Global_Settings *gs = new Global_Settings (path);
    // Verifying if configurations are inputed correctly

    // Printing continents and corresponding countries
//    set<Continent*> continents = gs->get_continents();
//    set<Continent*>::iterator it;
//    for (it = continents.begin(); it != continents.end(); ++it){
//        cout << endl << "Continent : " << (*it)->toString() << ", troop bonus = " << (*it)->get_troop_bonus()
//             << endl << "Countries : ";
//        set<Country*>::iterator it2;
//        set<Country*> countries = (*it)->get_countries();
//        char * delim = "";
//        for (it2 = countries.begin(); it2 != countries.end(); ++it2){
//            cout << delim << (*it2)->toString();
//            delim = " | ";
//        }
//        cout << endl;

//    }

//    Debuging TextUtils
//    TextUtils *tu = new TextUtils();
//    string line ("Eastern_United_United # North_America # Artillery");
//    tu->remove_empty_spaces(line);
//    cout << line << endl;
//    vector<string> splited = tu->split(line, '#');
//    vector<string>::iterator it;
//    for (it = splited.begin(); it != splited.end(); ++it)
//    {
//        cout << (*it) << endl;
//    }

    cout << endl << "Exiting main function" << endl;

    return 0;
}
