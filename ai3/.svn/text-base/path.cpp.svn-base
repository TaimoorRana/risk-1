#include "path.h"
#include "agent.h"
#include<unistd.h>

using namespace std;

Path::Path(unsigned int length, float value, float bid, int nbArmees) :
    m_length(length),
    m_value(value),
    m_bid(bid),
    m_nbArmees(nbArmees)
{
    m_path = vector<Agent*>();
}

//je ne comprends pas l'utilité de cette fonction...
/*void Path::setPath(vector<Agent*> v){
    for(vector<Agent*>::iterator it=v.begin();it!=v.end();it++){
        m_path.insert(m_path.end()-1,*it);
    }
}*/

Agent* Path::getHead()
{
    return m_path[0];
}

bool Path::contains(Agent &a) const
{
    for (unsigned int i = 0; i < m_path.size(); i++)
    {
        if (m_path[i]->isEqualTo(a))
            return true;
    }
    return false;
}

void Path::add(Agent* a)
{
    m_path.push_back (a);
    m_length = m_length + 1;
    m_value = m_value + a->getWorth();  //?//
}

//fonction toString optionnelle : fonction d'affichage d'un agent à coder
void Path::affiche() const
{
    cout << "The agents of this path (of value " << m_value << ", with " << m_nbArmees << " armies) are: \n";
    for (int i = 0; i < m_path.size(); i++)
    {
        Agent a = *(m_path[i]);
        cout << ' ' << m_path[i]->toString();
    }
    cout << '\n';
}

bool operator<(Path const& p1, Path const& p2)
{
    return p1.getValue() < p2.getValue();
}

float Path::get_proba_of_success(int nbArmeesEnPlus, bool debug) const
{

    Proba::setDes();
    Proba::setProba();
    Proba::setSurvivors();

    //iterates over the agents in the path and determines the probility of success
    int nb_armies_left = this->m_nbArmees+nbArmeesEnPlus-1;
    float p = 1.0f;
    //y avait des erreurs et j'avoue trouver la syntaxe classique boucle for plus simple
    for (int i = 1; i < m_path.size(); i++) //on commence à 1 parce que le premier pays nous appartient
    {
        int nb_armies_enemy = (m_path[i]->getState())->Getarmees();
        p = p * Proba::getProba(nb_armies_left, nb_armies_enemy); //calculates the probability of victory (the global one)
        if (debug)
        {
            //cout<<Proba::getProba(nb_armies_left,nb_armies_enemy)<<" "<<nb_armies_left<<" "<<nb_armies_enemy<<" "<<Proba::remainingAtt(nb_armies_left, nb_armies_enemy)<<endl;
        }

        //cout<<p<<endl;
        nb_armies_left = Proba::remainingAtt(nb_armies_left, nb_armies_enemy); //calculates the remaining number of attackants after the attack
    }
    return p;
}



