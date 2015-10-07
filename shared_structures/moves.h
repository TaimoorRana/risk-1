#ifndef MOVES_H
#define MOVES_H

#include <map>
#include <set>

using namespace std;

class Card;
class Country;

class Move {
public:
    int id_;
    //methodes de serialisation/deserialisation
};

class Change_Cards_Move : public Move{
public:
    std::set<Card*> change_;
};

class Dispatch_Move : public Move {
public:
    std::map<Country*, int> distribution_;
};

class Attack_Move : public Move {
public:
    Country* origin_;
    Country* destination_;
    int number_of_armies_;
};

class Displacement_Move : public Move {
public:
    Country* origin_;
    Country* destination_;
    int number_of_armies_;
};

#endif // MOVES_H
