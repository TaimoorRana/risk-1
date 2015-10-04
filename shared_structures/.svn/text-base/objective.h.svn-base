#ifndef OBJECTIVE_H
#define OBJECTIVE_H

#include <string>
#include "./../shared_structures/objective.h"
#include "./../shared_structures/game_state.h"
#include "./../shared_structures/army.h"
#include "./../shared_structures/global_settings.h"
#include "./../interfaces/player.h"
#include <vector>


//#include <QJsonObject>
//#include <QMap>

using namespace std;

class Objective {

public :

    int get_id();
    string get_description();
    bool is_accomplished(Game_State* game_state, Player* player);
//    QJsonObject serialize(QMap<void*, int> &pointeurMap);
//    void deserialize(QMap<void*, int> &pointeurMap,QJsonObject json);

protected:

    int id;
    string description;

};

#endif // OBJECTIVE_H
