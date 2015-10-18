#ifndef ARMY_H
#define ARMY_H

class GameState;
class Player;

class Army : public Structure {

public:

    Army (Player * const owner, int number_of_armies);

    void modify_army (int delta_nb_armies);
    void set_number_of_armies (int number_of_armies);
    void set_owner (Player * const owner);
    // Useful when a territory is dominated by another player.
    void conquered_by (Player * const new_player, int new_armies, GameState * const game_state);

    Player* get_owner () const;
    int get_number_of_armies () const;

private:
    Player *owner_;
    int number_of_armies_; 
};

#endif // ARMY_H
