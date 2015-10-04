#include <QJsonObject>
#include <QMap>
#include "./shared_structures/initial_settings.h"



QJsonObject Initial_Settings::serialize(QMap<void*, int> &pointeurMap){

    QJsonObject json;
    json["key"] = 3;
    json["players"] = pointeurMap(this->all_players);
    json["territories"] = pointeurMap(this->territories);
    json["objectives"] = pointeurMap(this->objective);
    json["step"] = pointeurMap(this->step);

    return json;
}

//deserialisation
void Initial_Settings::deserialize(QMap<void*, int> &pointeurMap, QJsonObject json){


    if (json["key"] == 3) {

        //Deserialisation pour players

         this->all_players = pointeurMap.key(json["players"].toInt());

        //Deserialisation pour territories

         this->territories = pointeurMap.key(json["territories"].toInt());

        //Deserialisation pour objectives

         this->objective = pointeurMap.key(json["objective"].toInt());

        //Deserialisation pour step

         this->step = pointeurMap.key(json["Step"].toInt());


        }



}
