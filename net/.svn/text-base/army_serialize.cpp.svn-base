#include <QJsonObject>
#include <QMap>
#include "./../shared_structures/army.h"
using namespace std;

QJsonObject Army::serialize(QMap<void*, int> &pointeurMap){
    QJsonObject json;
    json["number_of_army"]=this->number_of_army;
    json["owner"]=pointeurMap[this->owner];
    return json;
}
void Army::deserialize(QMap<void*, int> &pointeurMap,QJsonObject json){
    this->number_of_armies=json["number_of_armies"].toInt();
    this->owner=pointeurMap.key(json["owner"].toInt());
}

