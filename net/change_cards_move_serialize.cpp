#include <QJsonObject>
#include <QMap>
#include "./../shared_structures/moves.h"
using namespace std;
QJsonObject serialize(QMap<void*, int> &pointeurMap){
    QJsonObject json;
    json["change"]=pointeurMap[this->change];
    return json;
}

void deserialize(QMap<void*, int> &pointeurMap,QJsonObject json){
        this->change=pointeurMap.key(json["change"].toInt());
}
