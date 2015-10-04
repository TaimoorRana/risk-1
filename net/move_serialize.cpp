#include <QJsonObject>
#include <QMap>
#include "./../shared_structures/moves.h"
using namespace std;

QJsonObject Move::serialize(QMap<void*, int> &pointeurMap){
    QJsonObject json;
    json["id"]=this->id;
    return json;
}
void Move::deserialize(QMap<void*, int> &pointeurMap, QJsonObject json){
    this->id=json["id"].toInt();

}
