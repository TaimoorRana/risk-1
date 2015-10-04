#ifndef EVALUATION_H
#define EVALUATION_H

class Country;
class Game_State;
class Connected_component;
class Probabilities;

#include<vector>
#include<stack>
#include<set>
#include<map>

using namespace std;

class Evaluation
{
public:
    Evaluation(map<Country*,set<Country*> >* world_map, Game_State* gs);
    ~Evaluation();
    void computeConnectedComponents();
    void sortConnectedComponents();

private:
    vector<Connected_component*> connected_components;
    Probabilities * probabilities;
    map<Country*,set<Country*> >* world_map;
    Game_State* gs;
};

#endif // EVALUATION_H
