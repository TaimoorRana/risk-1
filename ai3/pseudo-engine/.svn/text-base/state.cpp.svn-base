#include "state.h"
#include<stdlib.h>
#include<time.h>
#include <algorithm>

using namespace std;
float State::C_sv = 70;
float State::C_fn = 1.2;
float State::C_en = -0.3;
float State::C_fnu = 0.05;
float State::C_enu = -0.03;
float State::C_cb = 0.5;
float State::C_oc = 20;
float State::C_eoc = 4;


//Calcule la valeur d'un pays
float State::countryEvaluation(int moi)
{
    //valeur "statique" d'un pays
    float V_sv = (1.0 * m_continent->Getrenforts()) / ((1.0 * m_continent->Gettaille()) * (1.0 * m_continent->Getfrontieres()));
    //cout<<"stat"<<V_sv<<endl;
    //valeurs "dynamiques" initialisées
    int V_fn = 0;
    int V_fnu = 0;
    int V_en = 0;
    int V_enu = 0;
    int V_cb = 0;
    int V_cp = 0;
    int V_oc = 0;
    int V_eoc = 0;
    vector<ContinentAI> continentsVoisins;

    bool ven = false;
    if (m_name == "Venezuela")
    {
        //cout << "ah" << endl;
        ven = true;
    }

    //calcul du nombre de voisins ennemis et amis, leurs unités, et le nombre de continents différents avec qui il partage une frontière
    for (int i = 0; i < (int)(m_voisins).size(); i++)
    {
        if ((m_voisins)[i]->m_continent->Getname() != this->m_continent->Getname())
        {
            bool b = false;
            for (int j = 0; j < (int)(continentsVoisins).size(); j++)
            {
                if ((continentsVoisins[j]).Getname() == (m_voisins)[i]->Getname())
                {
                    b = true;
                    break;
                }
            }
            if (!b)
            {
                V_cb ++;
                continentsVoisins.push_back(*((m_voisins)[i]->m_continent));
            }
        }
        if ((m_voisins)[i]->m_joueur == moi)
        {
            V_fn ++;
            V_fnu += (m_voisins)[i]->m_armees;
        }
        else
        {
            V_en ++;
            V_enu += (m_voisins)[i]->m_armees;
        }
    }

    //calcul du nb de pays dans le même continent
    int autres_Joueurs = 0;
    int current_Joueur = -1;
    for (int i = 0; i < (int)(m_continent->Getpays()).size(); i++)
    {
        State* s = (m_continent->Getpays())[i];
        if (moi== s->m_joueur)
        {
            V_cp ++;
        }
        else
        {
            if (current_Joueur != s->m_joueur)
            {
                autres_Joueurs ++;
                current_Joueur = s->m_joueur;
            }
        }
    }

    // est ce que le continent est entièrement détenu par le joueur actuel ou par un autre
    /*if (V_cp == this->m_continent->Gettaille())
    {
        V_oc = 0; //j'ai changé ça, avant c'était un 1
        V_eoc = 0;
    }

    else
    {
        V_oc = 0;
        if (autres_Joueurs > 1)
        {
            V_eoc = 0;
        }

        else
        {
            V_eoc = 1;
        }
    }*/

    if (V_cp == 0 && autres_Joueurs==1)
    {
        V_eoc = 1;
    }

    //pour V_oc
    if (V_cp == this->m_continent->Gettaille()-1 && moi!=m_joueur)
    {
        V_oc = 1;
    }
    else
    {
        V_oc = 0;
    }

    //if (ven){cout<<V_oc<<" "<<V_cp<<" "<<m_joueur<<" "<<moi<<endl;}
    //combinaison de tous les paramètres multipliés par les constantes statiques
    //cout<<m_name<<" "<<V_sv<<" "<<V_fn<<" "<<V_fnu<<" "<<V_en<<" "<<V_enu<<" "<<V_cb<<" "<<V_cp<<" "<<V_oc<<" "<<V_eoc<<endl;;
    float V_c = C_sv * V_sv + C_fn * V_fn + C_fnu * V_fnu + C_en * V_en + C_enu * V_enu + C_cb * V_cb + m_continent->Getrenforts() * (V_cp + C_oc * V_oc + C_eoc * V_eoc);
    return V_c;
}


State::State()
{
    //ctor
}

State::State(string name, ContinentAI* c, int j, int a): m_name(name), m_continent(c), m_joueur(j), m_armees(a)
{
    m_voisins = vector<State*>();
    cout << name << endl;
    c->addState(this);
    // m_voisins->push_back(*this);
}

State::State(State const& s): m_name(s.m_name), m_continent(s.m_continent), m_joueur(s.m_joueur), m_armees(s.m_armees)
{
    m_voisins = vector<State*>((s.m_voisins));
}

State::~State()
{
    //delete[] m_voisins;
}

void State::addVoisin(State* v)
{
    m_voisins.push_back(v);
}

void State::addVoisin(State* v1, State* v2)
{
    m_voisins.push_back(v1);
    m_voisins.push_back(v2);
}

void State::addVoisin(State* v1, State* v2, State* v3)
{
    m_voisins.push_back(v1);
    m_voisins.push_back(v2);
    m_voisins.push_back(v3);
}

void State::addVoisin(State* v1, State* v2, State* v3, State* v4)
{
    m_voisins.push_back(v1);
    m_voisins.push_back(v2);
    m_voisins.push_back(v3);
    m_voisins.push_back(v4);
}

void State::addVoisin(State* v1, State* v2, State* v3, State* v4, State* v5)
{
    m_voisins.push_back(v1);
    m_voisins.push_back(v2);
    m_voisins.push_back(v3);
    m_voisins.push_back(v4);
    m_voisins.push_back(v5);
}

void State::addVoisin(State* v1, State* v2, State* v3, State* v4, State* v5, State* v6)
{
    m_voisins.push_back(v1);
    m_voisins.push_back(v2);
    m_voisins.push_back(v3);
    m_voisins.push_back(v4);
    m_voisins.push_back(v5);
    m_voisins.push_back(v6);
}

void State::addArmee(int supp)
{
    m_armees = m_armees + supp;
    if (m_armees < 0)
    {
        m_armees = 0;
    }
}

float State::eval(int joueur)
{
    float rep;
    if (m_joueur == joueur)
    {
        rep = (float)m_armees;
    }
    else
    {
        rep = -(float)m_armees / 5;
    }
    return rep;
}

int State::random()
{
    //srand(time(NULL));
    int rep = 1 + rand() % 6;
    //cout << rep << endl;
    return rep;
}

bool State::jeu_des(int da, int dd, int &a, int &d)
{
    if (da > a || dd > d)
    {
        cout << "Mauvais nombre de dés" << endl;
        return true;
    }
    else
    {
        if (dd == 1)
        {
            int d1 = random();
            int d2 = 0;
            int daux;
            for (int k = 1; k <= da; k++)
            {
                daux = random();
                if (daux >= d2)
                {
                    d2 = daux;
                }
            }
            if (d2 > d1)
            {
                d = d - 1;
            }
            else
            {
                a = a - 1;
            }
        }
        if (dd == 2)
        {
            int d1 = random();
            int d2 = random();
            int d3 = 0;
            int d4 = -1;
            int daux;
            if (d1 < d2)
            {
                daux = d2;
                d2 = d1;
                d1 = daux;
            }
            for (int k = 1; k <= da; k++)
            {
                daux = random();
                if (daux > d3)
                {
                    d4 = d3;
                    d3 = daux;
                }
                else if (daux > d4)
                {
                    d4 = daux;
                }
            }
            if (d3 > d1)
            {
                d = d - 1;
            }
            else
            {
                a = a - 1;
            }
            if (d4 > d2 && da != 1)
            {
                d = d - 1;
            }
            if (d4 <= d2 && da != 1)
            {
                a = a - 1;
            }
        }
    }
    return (d != 0 && a != 0);
}

bool State::attack(State *a)
{
    if (a->m_joueur == m_joueur)
    {
        cout << "Vous ne pouvez pas attaquer votre pays" << endl;
        return false;
    }
    else
    {
        int att = m_armees - 1;
        int def = a->m_armees;
        int dd = 1;
        int da = 1;
        while (att > 0 && def > 0)
        {
            dd = 1;
            da = 1;
            if (att == 2)
            {
                da = 2;
            }
            if (att >= 3)
            {
                da = 3;
            }
            if (def >= 2)
            {
                dd = 2;
            }
            jeu_des(da, dd, att, def);
        }
        if (def == 0)
        {
            cout << "Conquête!!! Il reste " <<att<<" attaquants sur le sol du pays conquis."<< endl<<endl;
            a->m_joueur = m_joueur;
            a->Setarmees(att);
            Setarmees(1);
            return true;
        }
        if (att == 0)
        {
            cout << "Défaite!!! Il reste " <<def<<" défenseurs sur le pays."<< endl<<endl;
            Setarmees(1);
            a->Setarmees(def);
            return false;
        }
        cout << "Bug" << endl;
        return false;
    }
}

void State::move(State* a, int nb)
{
    if ((Getarmees() - nb <= 0 || nb < 0))
    {
        cout << "Déplacement impossible" << endl;
    }
    else if (a->Getjoueur() != Getjoueur())
    {
        cout << "pas le même proprio" << endl;
    }
    else
    {
        a->addArmee(nb);
        addArmee(-nb);
        cout << "Déplacement réalisé" << endl;
    }
}

bool State::isEqual(State st)
{
    return m_name == st.Getname();
}

bool operator==(State const& s, State const& t)
{
    return s.Getname() == t.Getname();
}


