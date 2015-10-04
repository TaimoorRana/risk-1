#include <QJsonObject>
#include <QMap>
#include "./../shared_structures/objective.h"


QJsonObject objective::serialize(QMap<void*, int> &pointeurMap){
    QJsonObject json;
    json["id"]=this->id;
    json["description"]=description;
    return json;
}
void objective::deserialize(QMap<void*, int> &pointeurMap, QJsonObject json){
    this->description=json["description"].toString();
    this->id=json["id"].toInt();

}
