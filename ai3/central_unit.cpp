#include "central_unit.h"
#include "pseudo-engine/graph.h"
#include "./../shared_structures/country.h"
#include "./../shared_structures/continent.h"
#include "./../shared_structures/army.h"
#include "./../shared_structures/initial_settings.h"
#include "./../shared_structures/global_settings.h"
#include "./../shared_structures/game_state.h"
#include "agent.h"
#include "bid.h"
#include <iostream>
#include <map>
#include <set>

using namespace std;

int Central_Unit::MAX_LENGTH_PATH = 3;

vector<Agent*> Central_Unit::m_agents=vector<Agent*>();

Central_Unit::Central_Unit()
{
    m_compt=0;
}

Central_Unit::Central_Unit(Graph* g, int player):m_player(player) //constructor
{
    m_nb_countries=g->GetN();
    State* s = g->Getstate()[0];
    int i;
    bool mars;
    //creation d'un agent par pays :
    for (i=0; i<m_nb_countries; i++)
    {
        s=g->Getstate()[i];
        mars=(s->Getjoueur()==player);
        Agent* ag=new Agent(*s,mars,player);
        m_agents.push_back(ag);
    }
    m_graph=g;
    m_compt=0;
    m_compt_attack=0;
    m_compt_path=0;
    m_compt_state=1;
}

Central_Unit::~Central_Unit()
{

}

Agent* Central_Unit::getAgent(int n)
{
    return (m_agents[n]);
}

//conversion state-country
Country* Central_Unit::State_to_Country(State* state){
    return Country::get_country(state->Getname());
}

Country* Central_Unit::Stateconst_to_Country(State* state){
    return Country::get_country(state->Getname());
}


State* Central_Unit::Country_to_State(Country* country){
    return (*m_graph)[country->get_id()];

}

State* Central_Unit::Countryconst_to_State(Country* country){
    return (*m_graph)[country->get_id()];

}

//conversion continent-continentAI
ContinentAI *Central_Unit::Continent_to_ContientAI(Continent* cont)
{
    //en l'absence de getid dans Continent...
    //je ferai ça demain...
    //enfin si c'est vraiment utile, à voir...
    //ça n'a pas l'air méga important en fait...
}

Continent* Central_Unit::ContinentAI_to_Continent(ContinentAI* cont_ai)
{
    return (Continent::get_continent(cont_ai->Getname())); // must just have the same name
}


void Central_Unit::receive_global_settings(Global_Settings* gs)
{
    //le but de cette fonction est d'initialiser le plateau
    //en gros ça crée une instance de la classe graph de pseudo-engine

    set<Continent*> cont=gs->get_continents();
    int NC=cont.size(); //nb de continents
    vector<ContinentAI*> tabcont=vector<ContinentAI*>();
    int j=0;
    int N=0; //nb de states
    set<Continent*>::iterator it;
    for(it=cont.begin();it!=cont.end();it++)
    {
        Continent* c=(*it);
        set<Country*> countries = c->get_countries();
        ContinentAI cAI = ContinentAI(c->toString(),c->get_troop_bonus(),countries.size());
        cAI.Setid(j);
        tabcont.push_back(&cAI);
        j++;
        //!!! il faut calculer le nombre de frontières!! ///
        set<Country*>::iterator itc;
        for(itc=countries.begin(); itc!=countries.end(); itc++)
        {
            Country* coun=(*itc);
            State* st = new State(coun->toString(),&cAI);
            N++;
        }
    }
    //on met les voisins et on crée le graphe
    vector<State*> tab=vector<State*>();
    int i=0;
    for(it=cont.begin();it!=cont.end();it++)
    {
        set<Country*> countries=(*it)->get_countries();
        set<Country*>::iterator itc;
        for (itc=countries.begin();itc!=countries.end();itc++)
        {
            Country* country = (*itc);
            State* pp = Country_to_State(country); //state courant
            pp->Setid(i);
            tab.push_back(pp);
            i++;
            set<Country*> vois=gs->get_neighbors(*itc);
            set<Country*>::iterator itv;
            for (itv=vois.begin();itv!=vois.end();itv++)
            {
                State* vv = Countryconst_to_State(*itv);
                pp->addVoisin(vv);
            }
        }
    }
    //on met à jour le nombre de frontières
    for (int i=0; i<tabcont.size(); i++)
    {
        tabcont[i]->Setfrontieres(tabcont[i]->nbFrontieres());
    }
    Graph g(N,tab,NC,tabcont);
    setGraph(&g);
    set_nb_countries(N);

}

void Central_Unit::receive_initial_settings(Initial_Settings* is)
{
    map<Player*, set<Country*> > ter = is->territories;
    map<Player*, set<Country*> >::iterator it;
    int joueur;
    for (it=ter.begin();it!=ter.end();it++)
    {
        set<Country*> setc=it->second;
        joueur=it->first->get_id();
        set<Country*>::iterator itc;
        for(itc=setc.begin(); itc!=setc.end(); itc++)
        {
            State* st=Country_to_State(*itc);
            st->Setjoueur(joueur);
        }
    }
    setNbTotPlayers(is->all_players.size());
}


void Central_Unit::receive_game_state(Game_State* gs)
{
    setPlayer((gs->get_current_player())->get_id());
    //setNbRenfort((gs.get_current_step())->id); bah je n'ai pas accès au dispatch step

    //mettre les bonhommes dans les pays, etc... et//
    for (int i=0; i<m_graph->GetN();i++)
    {
        State* s=(*m_graph)[i];
        Country* c=(State_to_Country(s));
        Army* a = gs->get_army(c);
        s->Setarmees(a->get_number_of_armies());
        s->Setjoueur(a->get_owner()->get_id());
    }
    //les cartes du joueur...
    /*set<Card*> cards;
    cards = gs->get_hand(gs->get_current_player());
    m_cards = vector<Card_Agent::Card_AI3>();
    for (set<Card*>::iterator k = cards.begin() ; k != cards.end(); k++){
       // m_cards.push_back(Card_Agent::convertFromEngine((*k));  ///////////////////!! à faire!!!!
    }*/
}


Dispatch_Move* Central_Unit::first_move(Initial_Settings* is){
    //function has to return the next Move (id of the country in which to place armies
    //takes Initial_settings as argument, i.e.( vector<Player*> players; map<Player*, set<Country*>> territories;(Initial territories' distribution)
    //map<Player*, Objective*> objectives (Objectives given to each player) //Dispatch_Step step;
    // All these elements are public

    //! *************************************************************************************************
    //! *************************************************************************************************
    //! en utilisant receive_initial_settings

    receive_initial_settings(is);
    vector<State*> my_states= m_graph->pays_joueur(m_player);
    int nb_states=my_states.size();
    Dispatch_Move* initial_move;
    //Debug error: if there are no countries that belong to me, return NULL
    if(nb_states==0){
        std::cout<<"Maxi Bug: j'ai plus de pays!!!!!";
        return initial_move;
    }
    for (int i=0; i<nb_states; i++)
    {
        my_states[i]->Setarmees(1); //on met une armée sur chaque pays
    }

    //Let's now define how many armies we can place at first
    int nb_players=m_nbTotPlayers;
    int nb_armies=0;
    switch (nb_players)
    {
    case 3:
        nb_armies= 35-nb_states;
        break;
    case 4:
        nb_armies=30-nb_states;
        break;
    case 5:
        nb_armies=25-nb_states;
        break;
    case 6:
        nb_armies=20-nb_states;
        break;
    default:
        cout << "Number of players has not been correctly implemented";
    }

    //After assigning one army in each country that we possess, it's time to allocate the remaining armies

    //1st step: determine the countries that are completely isolated and determine the occupation ratio of each continent
    vector<float> countries_border_ratio;
    map<int, int> compt_continent;
    //initialiser

    for(int i=0; i<nb_states;i++)
    {
        compt_continent[my_states[i]->Getcontinent()->Getid()]++;

        //Check if isolated
        vector<State*> voisins=my_states[i]->Getvoisins();  //function of pseudo engine which return all the neighbors if a given country
        int compt=0;
        //Loop over a country's neighbors to chech whether or not these countries belong to us
        for(int j=0; j<voisins.size();j++)
        {
            if (voisins[j]->Getjoueur()==m_player)
            {
                compt++;
            }
        }
        float ratio= ((float) compt/voisins.size());
        countries_border_ratio[i]=ratio;
    }
    //once that we have a map with all the ratio of the allied countries over the neighbouring countries, "discard" all the countries which are completely isolated
    //Define what we will return
    for (int k=0; k<countries_border_ratio.size();k++)
    {
        if(nb_armies>0){
            if (countries_border_ratio[k] > 1){
                //do nothing there are enough soldiers
                break;
            }
            if (countries_border_ratio[k]>0.65){
                my_states[k]->Setarmees(2);  //y'a pas besoin de beaucoup plus d'armées
                nb_armies=nb_armies-1;
                break;
            }
            if (countries_border_ratio[k]>=0.1){
                if(compt_continent[my_states[k]->Getcontinent()->Getid()]>3){
                    my_states[k]->Setarmees(4);
                    nb_armies=nb_armies-3;  //? je pense
                    break;
                }
                else{
                    my_states[k]->Setarmees(3);
                    nb_armies = nb_armies-2;  //rappel: on avait déjà décrementé de `1 par pays le nb d'armées à dispatcher
                    break;
                }
            }
        }
    }

    //on distribue aleatoirement le reste

    int nb= (int) nb_armies/nb_states;  //(entier)
    int a=nb_armies % nb_states;

    for (int i=0; i<nb_states;i++)
    {
        if (a>=0)
        {
            my_states[i]->addArmee(nb+1); //? enfin je pense que c'était faux...
            a=a-1;
        }
        else
        {
            my_states[i]->addArmee(nb);
        }
    }

    map <Country*, int> distribution;
    for(int i=0; i<nb_states;i++)
    {
        State* s=my_states[i];
        Country* c=State_to_Country(s);
        distribution[c]=s->Getarmees();
    }

    Dispatch_Move* initialisation = new Dispatch_Move();
    initialisation->distribution = distribution;
    return initialisation;



}



Move* Central_Unit::next_move(Game_State* gs){

    switch((gs->get_current_step())->id)
    {
    /*case 1: //idem à randomplayer car notre stratégie est indépendante de cette étape : on joue des cartes dès qu'on le peut
    {
        Change_Cards_Move* answer1=new Change_Cards_Move();
        answer1->id = 2;
        set<Card*>* ptr=&(answer1->change);
        ptr=NULL;
        return answer1;
    }
    case 2:
    {
        vector<Card_Agent::Card_AI3> cartes = this->get_cards();
        Card_Agent agen(this->getPlayer(), this->getGraph());
        for (Card_Agent::Card_AI3 car : cartes){
            agen.addCard(car);
        }
        Card_Agent::Combi AJouer = agen.bestCombi();
        vector<Card_Agent::Card_AI3> cartesAJouer = AJouer.getCards();
        set<Card*> JouerPourEngine ;
        for (vector<Card_Agent::Card_AI3>::iterator k = cartesAJouer.begin(); k != cartesAJouer.end();k++){
            JouerPourEngine.insert(Card::get_card(k->Card_AI3ToString()));
        }
        //Jouer les cartes :
        Change_Cards_Move* answer = new Change_Cards_Move();
        answer->id = 2;
        answer->change = JouerPourEngine;
        return answer;
    }*/
    case 3: //Dispatch_Move
    {    //A faire : Marie

        Dispatch_Move* answer3 = new Dispatch_Move();

        answer3->id = 3; //ne marche pas alors que ça marche dans randomplayer.cpp

        map<Country*,int> distribution; //champ de Dispatch-Move à retourner
        this->receive_game_state(gs);
        int comptNbArmies = this->m_nbRenfort;
        Player* joueur = gs->get_current_player();
        int id_joueur = joueur->get_id(); //on récupère l'id du current player
        vector<State*> countries = m_graph->pays_joueur(id_joueur); //vecteur des pays que l'on possède

        while(comptNbArmies>0)//algortihme glouton : tant que le nb d'armées à placer est positif,
            //je prends l'agent qui m'apporte le gain le + grand
        {
            int bid_value=0;
            Bid* bidMax;
            Path* pathMax;
            State* stateMax;
            bool mars;
            //je parcours les pays qui m'appartiennent
            for(vector<State*>::iterator itState=countries.begin();itState!=countries.end();itState++)
            {
                mars=(*itState)->Getjoueur()==m_player;
                Agent itAgent = Agent(*(*itState),mars,m_player); //State ==> Agent
                Bid* tempBid = itAgent.best_bid(comptNbArmies);
                if (tempBid->get_bid_value()>bid_value){
                    bidMax = tempBid;
                    pathMax = tempBid->get_path();
                    stateMax = *itState;
                }
            }

            //vérifier que le chemin trouvé ne contient pas un pays déjà contenu dans un autre chemin
            bool contains = false;
            vector<Agent*> vectorMax = pathMax->getPath();
            for(vector<Agent*>::iterator it=vectorMax.begin();it!=vectorMax.end();it++){
                for (vector<Path*>::iterator it2=m_listPaths.begin();it2!=m_listPaths.end();it2++){
                    if ((*it2)->contains(*(*it)))
                        contains = true;
                    break;
                }
            }
            if (!contains){
                Country* country = State_to_Country(stateMax); //State ==> Country
                distribution[country] = bidMax->get_bid_value(); //rajout à la map
                m_listPaths.push_back((bidMax->get_path())); //rajout du chemin à la liste des chemins
                comptNbArmies = comptNbArmies - bidMax->get_army_requested();
            }

        }
        answer3->distribution = distribution;
        return answer3; //ne marche pas alors que ça marche dans randomplayer.cpp

        break;
    }
    case 4:
    {
                receive_game_state(gs);
                Attack_Move* answer4;
                answer4->id = 4;
                //Récupère l'état du jeu: done
                //Check résultat de l'attaque précédente: pays conquis ou non
                Path* p = m_listPaths[m_compt_path];
                std::vector<Agent*> q = p->getPath();
                Agent a = *q[m_compt_state];
                State* c = a.getState();
                if(c->Getjoueur() != this->getPlayer()){
                    Agent b = *q[m_compt_state-1];
                    State* d = b.getState();
                    int m = c->Getarmees();
                    int n = d->Getarmees();
                    Proba p =Proba();
                    //si non attaque le même pays sans incrémenter si proba assez bonne
                    if(p.getProba(m,n)>0.7) {
                        answer4->origin = State_to_Country(c);
                        answer4->destination = State_to_Country(d);
                        answer4->number_of_armies = std::min(3,m-1);
                        return answer4;
                    }
                    m_compt_path ++;
                    // si plus de path proposé
                    if(m_compt_path>=(int)m_listPaths.size()){
                        // id du move égal à 0???
                        answer4->origin = NULL;
                        answer4->destination = NULL;
                        answer4->number_of_armies = 0;
                    }


                    //chemin d'après au state 1 directement si chemin actuel terminé
                    m_compt_state = 1;
                    return next_move(gs);
                }
                //si oui incrémente le compteur et attaque le pays d'après ou la première attaque du chemin d'après
                m_compt_state++;
                if(m_compt_state>=p->getLength()) {
                    m_compt_path ++;
                    m_compt_state = 1;
                    return next_move(gs);
                }
                //si chemin non fini incrémentation du nb correspondant à l'étape et rappel de la fonction sur le même gamestate
                return next_move(gs);
    }
    case 5:
        //Deplacement
    {

        //1ere etape: on regarde qui a la plus grosse fonction d'évaluation
        //2eme etape: on regarde parmi ses voisins qui est le moins interessant.
        //3eme etape. Transfert

        Displacement_Move* deplacement;
        this->receive_game_state(gs);
        Player* joueur = gs->get_current_player();
        int id_joueur = joueur->get_id(); //on récupère l'id du current player
        //Parcours des pays qui nous appartiennent
        State* min;
        State* max;

        vector<State*> countries = m_graph->pays_joueur(id_joueur);
        float value_max=0;
        for(vector<State*>::iterator itState=countries.begin();itState!=countries.end();itState++){
            State* temp=*itState;
            if (temp->countryEvaluation(m_player)>value_max){
                value_max=temp->countryEvaluation(m_player);
                max=temp;
            }
        }
        //on a trouvé le pays le plus intéressant
    //on cherche parmi ses voisins le moins intéressant
     //Ne pas oublier qu'il peut etre tout seul
        vector<State*> voisins=max->Getvoisins();
        float value_min=value_max;
        for(vector<State*>::iterator itVois=voisins.begin();itVois!=voisins.end();itVois++){
            State* temp=*itVois;
            if (temp->countryEvaluation(m_player)<value_min){
                value_min=temp->countryEvaluation(m_player);
                min=temp;
            }
        }

        deplacement->origin=State_to_Country(min);
        deplacement->destination=State_to_Country(max);
        deplacement->number_of_armies=min->Getarmees()/2;


        return deplacement;

    }
    case 6:
    {
    return NULL;
    //Thibaut dit :
    /*Dans la première partie, on aura signalé à l'Engine quelles cartes jouer dans son language
     Et l'agent joueur de cartes est recréé à chaque tour
    Donc ici, pas de passage par Card_AI3, on fait appel directement à Engine pour piocher une nouvelle carte
    En fait, vu l'implémentation de randomplayer, engine fait cette pioche de cartes en-dehors de la fonction*/
    }
    default: return NULL;
    }
}


