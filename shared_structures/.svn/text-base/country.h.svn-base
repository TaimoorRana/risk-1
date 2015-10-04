#ifndef COUNTRY_H
#define COUNTRY_H

using namespace std;

#include <string>
#include <map>

//#include <QJsonObject>
//#include <QMap>

class Country
{

public:

    Country(string name);

    string get_name();

    static Country* get_country (string country_name);

    static Country* get_country (int id);

    int get_id() const;

    string toString ();

    static int quantity_of_countries; // Initialized as zero with command int Country::quantity_of_countries = 0;
//    QJsonObject serialize(QMap<void*, int> &pointeurMap);
//    void deserialize(QMap<void*, int> &pointeurMap,QJsonObject json);
private:

    string name;
    int id;
    static map <string, Country*> name_to_Country;
    static map <int, Country*> id_to_Country;

};

#endif // COUNTRY_H
