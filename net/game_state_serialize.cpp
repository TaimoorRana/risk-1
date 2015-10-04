#include <QJsonObject>
#include <QMap>
#include "./shared_structures/game_state.h"



QJsonObject Game_State::serialize(QMap<void*, int> &pointeurMap){

    QJsonObject json;
    json["key"]=4;
    json["global_settings"] = pointeurMap(this->global_settings);
    json["initial_settings"] = pointeurMap(this->initial_settings);
    json["Player"]= pointeurMap(this->current_player);
    json["Step"]= pointeurMap(this->current_step);

    json["current_army"]=pointeurMap(this->current_armies);
    json["hands"]=pointeurMap(this->hands);
    json["jsonwas_defeated_by"]=pointeurMap(this->was_defeated_by);

    json["reward_index"]=this->reward_index;

    json["deck"]=pointeurMap(this->deck);
    return json;
}


//deserialize la classe game_state

void Game_State::deserialize(QMap<void*, int> &pointeurMap, QJsonObject json)
{


    if (json["key"] == 4) {

        //Deserialisation pour global_settings

         this->global_settings = pointeurMap.key(json["global_settings"].toInt());

        //Deserialisation pour initial_settings

         this->initial_settings = pointeurMap.key(json["initial_settings"].toInt());

        //Deserialisation pour current_player

         this->current_player = pointeurMap.key(json["Player"].toInt());

        //Deserialisation pour current_step

         this->current_step = pointeurMap.key(json["Step"].toInt());

        //Deserialisation de hands

        this->hands = pointeurMap.key(json["hands"].toInt());

        //deserialisation de current_army

        this->current_armies = pointeurMap.key(json["current_army"].toInt());

        //deserialisation de still_playing
        this->reward_index = pointeurMap.key(json["reward_index"].toInt());

        //deserialisation de deck
        this->deck = pointeurMap.key(json["deck"].toInt());
        }
    }
