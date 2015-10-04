#ifndef ARMY_H
#define ARMY_H

#include <set>
#include <string>
#include <map>
#include <list>

using namespace std;

class Game_State; //forward declaration
class Player; //forward declaration
class Country;

class Army
{

public:

    Army (Player * owner, int number_of_armies);

    void modify_army (int delta_nbarmies);
    void set_number_of_armies(int na);
    void set_owner(Player* ow);
    //useful when a territory is dominated by another player
    void conquered_by (Player* new_player, int new_armies, Game_State* game_state);

    Player* get_owner ();
//    QJsonObject serialize(QMap<void*, int> &pointeurMap);
//    void deserialize(QMap<void*, int> &pointeurMap,QJsonObject json);

    int get_number_of_armies ();

private:
    int number_of_armies;
    Player* owner;
};

#endif // ARMY_H
