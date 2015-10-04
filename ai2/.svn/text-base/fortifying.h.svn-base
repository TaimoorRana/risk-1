#ifndef FORTIFYING_H
#define FORTIFYING_H

class Moves;
class Game_State;
class Global_Settings;
class Initial_Settings;
class connectedcomponent;
class Player;
class Displacement_Move;
class Country;

class Fortifying
{
public:
    Fortifying(Connected_component *c, Game_State* game_state, Initial_Settings* initial_settings, Global_Settings* global_settings, Player* player);
    ~Fortifying();

    int are_neighbors(int i, int j); //return 1 if i and j are neighbors 0 otherwise
    void floyd_warshall(); //compute the matrix of minimal distance between 2 countries
    bool is_on_the_border(Country* country); //return if i is on the border or not
    void action(); //compute the value for the move : origin/destination/troops
    Displacement_Move move(); //return the move corresponding to the fortifying class


private:
    connectedcomponent *c;
    Game_State* game_state;
    Initial_Settings* initial_settings;
    Global_Settings* global_settings;
    Player* player;
    int nb_countries;

    //distance gives the minimal distance between two countries we use it to find the best move during the fortifying phase
    //int distance[42][42];
    // Ideally do not use 42 here as it might change with any modification on the map configurations
    // Rather obtain it from the Global_Settings class
    int ** distance;

    //origin and destination represent the movement of our troops in the fortifying phase
    Country* origin;
    Country* destination;
    int troops; //Number of troops we will move
};

#endif // FORTIFYING_H
