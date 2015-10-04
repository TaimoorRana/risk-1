#include <QJsonObject>
#include <QMap>
#include "./../shared_structures/country.h"
using namespace std;


QJsonObject country::serialize(QMap<void*, int> &pointeurMap){
    QJsonObject json;
    json["name"]=this->name;
    json["id"]=this->id;
    json["quantity_of_countries"]=this->quantity_of_army;
    return json;
}
QJsonObject country::deserialize(QMap<void*, int> &pointeurMap, QJsonObject json){
    this->name=json["name"].toString();
    this->id=json["id"].toInt();
    this->quantity_of_countries=json["quantity_of_countries"].toString();
}
