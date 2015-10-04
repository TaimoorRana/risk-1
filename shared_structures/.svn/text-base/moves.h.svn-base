#ifndef MOVES_H
#define MOVES_H

#include <set>
#include <map>
//#include <QJsonObject>
//#include <QMap>
using namespace std;

class Card; //forward declaration
class Country; //forward declaration

class Move {
public:
    int id;
    //methodes de serialisation/deserialisation
//    QJsonObject serialize(QMap<void*, int> &pointeurMap);
//    void deserialize(QMap<void*, int> &pointeurMap,QJsonObject json);
};

class Change_Cards_Move : public Move{
public:
    set <Card*> change;
//    QJsonObject serialize(QMap<void*, int> &pointeurMap);
//    void deserialize(QMap<void*, int> &pointeurMap,QJsonObject json);
};

class Dispatch_Move : public Move {
public:
    map <Country*, int> distribution;
//    QJsonObject serialize(QMap<void*, int> &pointeurMap);
//    void deserialize(QMap<void*, int> &pointeurMap,QJsonObject json);
};

class Attack_Move : public Move {
public:
    Country* origin;
    Country* destination;
    int number_of_armies;
//    QJsonObject serialize(QMap<void*, int> &pointeurMap);
//    void deserialize(QMap<void*, int> &pointeurMap,QJsonObject json);
};

class Displacement_Move : public Move {
public:
    Country* origin;
    Country* destination;
    int number_of_armies;
//    QJsonObject serialize(QMap<void*, int> &pointeurMap);
//    void deserialize(QMap<void*, int> &pointeurMap,QJsonObject json);
};

#endif // MOVES_H
