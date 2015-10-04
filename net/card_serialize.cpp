#include "./../shared_structures/card.h"
#include <QJsonObject>
#include <QMap>
using namespace std;

QJsonObject card::Serialize(QMap<void*, int> &pointeurMap){
    QJsonObject json;
    json["id"]=this->id;
    json["country"]= pointeurMap[this->country];
    json["symbol"]=pointeurMap[this->symbol];
    return json;
}
void card::deserialize(QMap<void*, int> &pointeurMap,QJsonObject json){
    this->id=json["id"].toInt();
    this->country=pointeurMap.key(json["country"].toInt());
    this->symbol=pointeur.key(json["symbol"].toString());

}
