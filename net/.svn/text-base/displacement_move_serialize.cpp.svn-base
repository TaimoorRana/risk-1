#include <QJsonObject>
#include <QMap>
#include "./../shared_structures/moves.h"
using namespace std;


QJsonObject Displacement_Move::serialize(QMap<void*, int> &pointeurMap){
    QJsonObject json;
    json["origin"]=pointeurMap[this->origin];
    json["destination"]=pointeurMap[this->destination];
    json["number_of_armies"]=this->number_of_armies;
    return json;
}

void Displacement_Move::deserialize(QMap<void*, int> &pointeurMap,QJsonObject json){
    this->number_of_armies=json["number_of_armies"].toInt();
    this->origin=pointeurMap.key(json["origin"].toInt());
    this->destination=pointeurMap.key(json["destination"].toInt());

}

