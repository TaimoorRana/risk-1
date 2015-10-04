#include "country_parameters.h"

CountryParameters::CountryParameters(Country* country, map<Country*,set<Country*>>& world_map, Game_State* gs, Probabilities* proba):
    Country(*country), world_map(world_map), gs(gs), proba(proba), weakestCountry(0), troops(0), borders(false),
    probaDefeat(0), probaVictory(0), backupTroopsAttack(0), backupTroopsDefense(0), enemyPresence(0)
{
}

void CountryParameters::computeParameters(){
    Army* army = gs->get_army(this);
    troops = army->get_number_of_armies();
    set<Country*> neighbors = world_map[this];

    map<Player*, int> tab;

    Player* currentPlayer = gs->get_current_player();
    map<Player*, int>::iterator iter;

    set<Country*>::iterator it;
    for(it=neighbors.begin();it!=neighbors.end();it++){
        Player* joueur = gs->owner(it);
        if(joueur!=currentPlayer){
            iter = tab.find(joueur);
            if(iter!=tab.end()){
                tab[joueur]+=(gs->get_army(joueur))->get_number_of_armies();
            }
            else{
                tab[joueur]=(gs->get_army(joueur))->get_number_of_armies();
            }
        }
    }

    if(neighbors.empty()){
        return;
    }

    borders=true;

    int minimum(1000), maximum(0), somme(0);

    for(const auto& elem: tab){
        if(elem->second>maximum){
            maximum = elem->second;
        }
        if(elem->second<minimum){
            minimum = elem->second;
            weakestCountry = elem->first;
        }
        somme+=elem->second;
    }
    enemyPresence = somme;

    probaDefeat = proba->proba_to_survive(troops, maximum);
    probaVictory = proba->proba_to_win(troops, minimum);

    backupTroopsDefense = proba->reinforcement_defense(troops, maximum);
    backupTroopsAttack = proba->reinforcement_attack(troops, minimum);

}

bool CountryParameters::operator>=(const CountryParameters& otherCountry) const {

    if(this->borders > otherCountry.borders) return true;
    if(this->borders < otherCountry.borders) return false;

    int backupTroops = (*(gs->get_current_step())).number_of_troops;

    float ratio1Defense = (float)backupTroopsDefense/backupTroops;
    float ratio2Defense = (float)otherCountry.backupTroopsDefense/backupTroops;
    float ratio1Attack = (float)backupTroopsAttack/backupTroops;
    float ratio2Attack = (float)otherCountry.backupTroopsAttack/backupTroops;

    float coeff1 = troops*((1/ratio1Defense)+(1/ratio1Attack)+probaVictory+(1/probaDefeat));
    float coeff2 = otherCountry.troops*((1/ratio2Attack)+(1/ratio2Defense)+otherCountry.probaVictory+(1/otherCountry.probaDefeat));

    return (coeff1 >= coeff2);

}

