#ifndef STEPS_H
#define STEPS_H

//#include <QJsonObject>
//#include <QMap>

class Step {
public:
    int id;
//    QJsonObject serialize(QMap<void*, int> &pointeurMap);
//    void deserialize(QMap<void*, int> &pointeurMap,QJsonObject json);
};

class Dispatch_Step : public Step {
public:
    int number_of_troops;
//    QJsonObject serialize(QMap<void*, int> &pointeurMap);
//    void deserialize(QMap<void*, int> &pointeurMap,QJsonObject json);
};

#endif // STEPS_H
