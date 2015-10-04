#include <QJsonObject>
#include <QMap>
#include "./../shared_structures/continent.h"
using namespace std;
QJsonObject serialize(QMap<void*, int> &pointeurMap){
    QJsonObject json;
    json["name"]=this->name;
    json["troop_bonus"]=this->troop_bonus;
    json["number_of_continents"]=this->number_of_continents;
    json["id"]=this->id;
    json["countries"]=pointeurMap[this->countries];
    return json;
}
void deserialize(QMap<void*, int> &pointeurMap,QJsonObject json){
    this->name=json["name"].toString();
    this->troop_bonus=json["troop_bonus"].toInt();
    this->number_of_continents=json["number_of_continents"].toInt();
    this->id=json["id"].toInt();
    this->countries=pointeurMap.key(json["countries"].toInt());






}
