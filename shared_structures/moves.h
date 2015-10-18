#ifndef MOVES_H
#define MOVES_H

#include <map>
#include <set>

class Card;
class Country;

class Move : public Structure {
public:
    int id_;
    //methodes de serialisation/deserialisation
};

class ChangeCardsMove : public Move{
public:
    std::set<Card*> change_;
};

class DispatchMove : public Move {
public:
    std::map<Country*, int> distribution_;
};

class AttackMove : public Move {
public:
    Country* origin_;
    Country* destination_;
    int number_of_armies_;
};

class DisplacementMove : public Move {
public:
    Country* origin_;
    Country* destination_;
    int number_of_armies_;
};

#endif // MOVES_H
