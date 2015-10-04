#include "agent.h"
#include "bid.h"
#include "central_unit.h"
#include<set>
#include<vector>
#include<sstream>
#include<unistd.h>

using namespace std;

Agent::Agent()
{

}

Agent::Agent(State& s, bool mars, int joueur): m_worth(s.countryEvaluation(joueur)), m_isMars(mars), m_joueur(joueur)
{
    m_id = s.Getid();
    m_s = &s;
}

Agent::~Agent()
{

}

string Agent::toString()
{
    std::ostringstream buff;
    cout << m_id;
    //buff << m_worth;
    //return m_s->Getname() + ' ' + buff.str() + '\n';
    return m_s->Getname() + '\n';
}

bool Agent::isEqualTo(Agent const& a) const
{
    return (a.m_s == m_s);
    //c'est suffisant ou pas?
}

bool Agent::isAgent(const State& st)
{
    return (*m_s == st);
}

void Agent::clearGS()
{
    set<Path*>::iterator it;
    for (it=m_goalset.begin(); it!=m_goalset.end();it++)
    {
        m_goalset.erase(it);
    }
}

//j'en vois pas trop l'interet...
void Agent::setGoalset(const std::set<Path*> s)
{
    for (std::set<Path*>::iterator it = s.begin(); it != s.end(); it++)
    {
        this->m_goalset.insert(*it);
    }
}


set<Path*> Agent::send()
//récupère tous les chemins des voisins et les complète en ajoutant this
//renvoie ensuite l'ensemble de ses chemins
{
    //On itère sur les voisins
    for (vector<State*>::iterator st = (m_s->Getvoisins()).begin(); st != (m_s->Getvoisins()).end(); st++)
    {
        this->append(Central_Unit::getAgent((*st)->Getid())->getGoalset());
    }

    return this->m_goalset;
}


void Agent::append(std::set<Path*> ens)
//Complete l'ensemble des chemins de ens par this si ces chemins ne contiennent pas déjà this
{

    for (set<Path*>::iterator p = ens.begin(); p != ens.end(); p++)
    {
        cout << "llllllllllllo" << endl;
        if (!((*p)->contains(*this)))
        {
            Path pth((*p)->getLength(), (*p)->getValue(), (*p)->getBid(), (*p)->getNbArmees());
            pth.setPath((*p)->getPath());
            pth.add(this);//On augmente les chemins de this
            (this->m_goalset).insert(&pth);
            cout << "loulou";
            pth.affiche();
        }
    }

}

float Agent::goal_value()
{
    return getState()->countryEvaluation(m_joueur);
}

//les fonctions que j'ai rajoutées
void Agent::sendToNeighbours(Path& p)
{
    //p.affiche();
    vector<State*> voisins = (m_s->Getvoisins());
    Agent* v;
    vector<Agent*> np; //nouveau path
    //vector<Agent> ap=p.getPath(); //ancien path
    Path* ep; //path à envoyer ensuite
    for (unsigned int i = 0; i < voisins.size(); i++)
    {
        v = &(*Central_Unit::getAgent(voisins[i]->Getid()));
        //cout<<"voisin de "<<m_s->Getname()<<": "<<v->getState()->Getname()<<" "<<voisins.size()<<" id de voisins[i]: "<<voisins[i]->Getid()<<endl;
        if (!p.contains(*v))
        {
            //récursion, il faut maintenant supposer que l'agent nous appartient
            int anc_joueur = getState()->Getjoueur();
            setIsMars(true);
            getState()->Setjoueur(m_joueur);


            np = p.getPath();
            np.insert(np.begin(), v);
            ep = new Path(p.getLength() + 1, p.getValue() + v->goal_value(), p.getBid(), v->getState()->Getarmees());
            ep->setPath(np);
            if (ep->getLength() <= Central_Unit::MAX_LENGTH_PATH && !(v->getIsMars()))
            {

                //debug sur le bresil
                /*if (v->getState()->Getname() == "Brésil")
                {
                    cout << "action" << v->goal_value() << " " << ep->getLength() << " " << getState()->Getname() << " " << ep->getValue() << endl;
                }*/
                v->sendToNeighbours(*ep);
            }
            else if (v->getIsMars() && ep->getLength() <= Central_Unit::MAX_LENGTH_PATH + 1)
            {
                ep->setValue(ep->getValue() - v->goal_value());
                v->addToGoalSet(*ep);
                //cout<<"Ajout du au goalset de l'état "<<v->toString()<<endl;
            }
            //on remet les valeurs aux anciennes valeurs
            setIsMars(false);
            getState()->Setjoueur(anc_joueur);

        }
    }
}

void Agent::addToGoalSet(Path& p)
{
    m_goalset.insert(&p);
}

void Agent::printGoalSet()
{
    cout << "Affichage du goalset de l'agent de l'état " << getState()->Getname() << endl;
    int nb = 0;
    set<Path*>::iterator it;
    if (m_goalset.empty() || m_goalset.size() == 0)
    {
        cout << "    Goalset vide!" << endl << endl;
    }
    else
    {
        for (it = m_goalset.begin(); it != m_goalset.end(); it++)
        {
            nb++;
            cout << "     Affichage du path numéro " << nb << endl;
            (*it)->affiche();
        }
    }
    cout << "Fin de l'affichage du goalset de l'état " << getState()->Getname() << endl << endl;
}

bool Agent::attack(Path &p)
{
    vector<Agent*> chemin = p.getPath();
    State* s;
    Agent a;
    State* attaquant = m_s;
    if (!chemin[0]->isEqualTo(*this))
    {
        cout << "buuug" << endl;
    }
    for (int i = 0; i <= chemin.size() - 1; i++)
    {
        a = *(chemin[i]);
        s = a.getState();
        if (!attaquant->attack(s))
        {
            return false;
        }
        attaquant = s;
    }
    return true;
}

bool Agent::attack_agent(Agent& ag)
{
    State* attaquant=m_s;
    State* defenseur=ag.getState();
    if (attaquant->attack(defenseur))
    {
        ag.setIsMars(true);
        return true;
    }
    else
    {
        return false;
    }
}


//les fonctions de bid
Bid* Agent::offensive_bid(int nb_armies)
{

    // A voir: ajouter
    //the agent iterates over its own goal list and determines the best goal for nb_armies armies
    float compt = -10.0f;
    float bid = 0;
    set<Path*>::iterator it;
    Path* pointer_to_result = new Path();
    bool arg = false;
    for (it = (this->m_goalset).begin(); it != (this->m_goalset).end(); it++)
    {
        //debug sur l'argentine, pour comprendre pourquoi les best off bid ne sont que de taille 2
        /*vector<Agent*> vecta=(*it)->getPath();
        if (vecta[0]->getState()->Getname()=="Argentine")
        {
            arg=true;
            //cout<<vecta[0]->getState()->Getname()<<endl;
        }
        else
        {
            arg=false;
        }*/


        float p = (*it)->get_proba_of_success(nb_armies, arg);



        //cout<<p<<endl;
        //if the probability of sucess is too low (threshold?), discard this option i.e, set negative bid
        //float p=1.0f;
        if (p < 0.35) //le seuil risque d'être vraiment trop haut (surtout si on prend des chemins de grande longueur, il faudrait raffiner ntre analyse je pense
        {
            /*Bid* no_bid=new Bid();
            no_bid->set_path(&*it);
            no_bid->set_army_requested(nb_armies);
            no_bid->set_bid_value(-10);*/
            //DO NOTHING
            if (arg)
            {
                cout << "valeur du bid:" << bid << " et taille: " << (*it)->getLength() << " proba:" << p << endl;
            }

        }

        else     //c'est bon, le chemin est intéressant
        {
            float w = (*it)->getValue();
            if (nb_armies == 0)
            {
                bid = p * w;
            }
            else
            {
                bid = ((float)p * w / (1+0.2*(float)nb_armies));
            }

            //once the bid has been computed,  compare it to the compt value

            if (compt < bid)  //looks for the maximum: if greater than compt, replace compt by the bid
            {
                compt = bid;
                *pointer_to_result = **it;

            }
            if (arg)
            {
                cout << "valeur du bid:" << bid << " et taille: " << (*it)->getLength() << " proba:" << p << endl;
            }

        }
    }

    if (compt > -10.0f)
    {
        Bid* result = new Bid(pointer_to_result, compt, nb_armies);
        return result;
    }
    else
    {
        Bid* no_bid = new Bid(pointer_to_result, -10.0f, nb_armies);
        return no_bid;
    }

}

//j'ai commenté parce que ça n'vait pas l'air fini et que ça engendrait des erreurs  //effectivement

Bid* Agent::best_offensive_bid(int nb_armies_max)
{
    //This time, iterates for the total number of armies at our disposal, for a given agent
    //structure of the algorithm:
    //1st: Define a list/set of best offensive goals (for each nb of armies, gives the best course of action)
    //2nd: compute the best course of action according to this set

    Bid* result = new Bid();
    float best_value = 0.0;
    for (int i = 0; i <= nb_armies_max; i++)
    {
        Bid* enchere = this->offensive_bid(i);  //computes the best goal that this agent can reach if given i armies
        if (getState()->Getname()=="Argentine")
        {
                //cout<<i<<" "<<enchere->get_bid_value()<<endl;
        }

        if (enchere->get_bid_value() > best_value)
        {
            result = enchere;
            best_value = enchere->get_bid_value(); //increment the best_value param
        }

    }

    return result;


}

float Agent::get_ability_to_defend(int nbArmeesEnPlus)
{
    Proba::setDes();
    Proba::setProba();
    Proba::setSurvivors();
    int nbArmies = this->getState()->Getarmees() + nbArmeesEnPlus;
    //on renvoie le max des probas de mourir
    float d = 0;
    float probaaux = 0;
    vector<State*> voisins = getState()->Getvoisins();
    for (int i = 0; i < voisins.size(); i++)
    {
        if (voisins[i]->Getjoueur() != m_joueur)
        {
            //proba de mourir
            probaaux = Proba::getProba(voisins[i]->Getarmees()-1, nbArmies);
            if (probaaux > d)
            {
                d = probaaux;
            }
        }
    }
    return 1 - d;

}

Bid* Agent::defensive_bid(int nb_armies)
{

    // same as before, but only for defensive goals this time

    float bid = 0;
    float d = 1.0f; //how well it can defend itself from current ennemies. COMMENT QUANTIFIER CE TRUC?
    d = get_ability_to_defend(nb_armies);
    float coef = 4.0f; //ajustement avec offensive bid
    if (nb_armies == 0)
    {
        bid = this->getWorth() * d * coef;
    }
    else
    {
        bid = ((float) this->getWorth() * coef * d / (1 + 0.30 * (float)nb_armies));
    }

    Path* path = new Path();
    path->add(this);
    Bid* res = new Bid(path, bid, nb_armies);
    return res;


}

Bid* Agent::best_defensive_bid(int nb_armies)
{
    float compt = -10.0f;
    Bid* pointer_to_result = new Bid();
    for (int i = 0; i <= nb_armies; i++)
    {
        Bid* temp = defensive_bid(i);
        //cout<<i<<" "<<temp->get_bid_value()<<endl;
        if (temp->get_bid_value() > compt)
        {
            compt = temp->get_bid_value();
            pointer_to_result = temp;
        }
    }
    return pointer_to_result;
}

Bid* Agent::best_bid(int nb_armies)
{
    Bid* off = best_offensive_bid(nb_armies);
    Bid* def = best_defensive_bid(nb_armies);
    float ajust = 1.0f; //selon la stratégie voulue (offensive, defensive)
    if ((off->get_bid_value() >= ajust * def->get_bid_value())||(def->get_army_requested()==0&&off->get_bid_value()>1))
    {
        return off;
    }
    else
    {
        return def;
    }
}



