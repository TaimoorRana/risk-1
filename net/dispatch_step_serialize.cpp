#include <QJsonObject>
#include <QMap>
#include "./../shared_structures/steps.h"
using namespace std;


QJsonObject Dispatch_Step::serialize(QMap<void*, int> &pointeurMap){
    QJsonObject json;
    json["number_of_troops"]=this->number_of_troops;

    return json;
}
QJsonObject Dispatch_Step::deserialize(QMap<void*, int> &pointeurMap, QJsonObject json){
    this->number_troops=json["number_of_troops"].toInt();

}
