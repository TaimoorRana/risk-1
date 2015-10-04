#include <QJsonObject>
#include <QMap>
#include "./shared_structures/global_settings.h"


//Serialize la classe global_settings
QJsonObject Global_Settings::serialize(QMap<void*, int> &pointeurMap){

    QJsonObject json;
    json["key"] = 2;
    json["continent"] = pointeurMap(this->continents);
    json["map"] = pointeurMap(this->graph);
    json["card"] =pointeurMap(this->cards);
    json["objective"] = pointeurMap(this->objectives);
    json["vector_value"] = pointeurMap(this->reward_values);





}


//deserialize la classe global_settings
void Global_Settings::deserialize(QMap<void*, int> &pointeurMap, QJsonObject json){
    {
        if (json["key"] == 2) {

            //Deserialisation pour continents

             this->continents = pointeurMap.key(json["continent"].toInt());

            //Deserialisation pour graph

             this->graph = pointeurMap.key(json["map"].toInt());

            //Deserialisation pour cards

             this->cards = pointeurMap.key(json["card"].toInt());

            //Deserialisation pour objectives

             this->objectives = pointeurMap.key(json["objective"].toInt());

            //Deserialisation pour vector_value

             this->reward_values = pointeurMap.key(json["vector_value"].toInt());


            }
    }
}
