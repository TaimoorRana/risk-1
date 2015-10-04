#include <QJsonObject>
#include <QMap>
#include "./../shared_structures/steps.h"
using namespace std;

QJsonObject Step::serialize(QMap<void*, int> &pointeurMap){
    QJsonObject json;
    json["id"]=this->id;
    return json;
}
void Step::deserialize(QMap<void*, int> &pointeurMap, QJsonObject json){
    this->id=json["id"].toInt();
}
