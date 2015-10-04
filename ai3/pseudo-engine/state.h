#ifndef STATE_H
#define STATE_H

#include<iostream>
#include<string>
#include<vector>

#include "continentai.h"


class State
{
public:

    //ctor, dtor
    State();
    State(std::string name, ContinentAI* c, int j=1, int a=0);
    State(State const& s);
    virtual ~State();

    //getters, setters
    std::string Getname() const { return m_name; }
    void Setname(std::string val) { m_name = val; }
    ContinentAI* Getcontinent() { return m_continent; }
    int Getjoueur() {return m_joueur;}
    int Getarmees() {return m_armees;}
    void Setjoueur(int j) {m_joueur=j;}
    void Setarmees(int a) {m_armees=a;}
    void Setcontinent(ContinentAI* val) { m_continent = val; }
    std::vector<State*> Getvoisins() { return m_voisins; }
    void Setvoisins(std::vector<State*> val) { m_voisins = val; }
    unsigned int Getid(){return m_id;}
    void Setid(unsigned int val){m_id=val;}

    friend bool operator==(State const& s, State const& t);
    void addVoisin(State* v);
    void addVoisin(State* v1, State* v2);
    void addVoisin(State* v1, State* v2, State* v3);
    void addVoisin(State* v1, State* v2, State* v3, State* v4);
    void addVoisin(State* v1, State* v2, State* v3, State* v4, State* v5);
    void addVoisin(State* v1, State* v2, State* v3, State* v4, State* v5, State* v6);


    void addArmee(int supp); //ajout d'armees (en positif ou en negatif)
    float eval(int joueur);
    //attaquer l'état a
    bool attack(State* a);
    static int random(); //renvoie un entier aléatoire entre 1 et 6
    //simulation du jeu des dés.
    //da -> dés de l'attaquant, dd->dés de la défense
    //d-> nb de défenseurs, a-> nb d'attaquants
    static bool jeu_des(int da, int dd, int& a, int& d); //return true si le combat n'est pas fini
    //dépacement de nb bonshommes de l'état vers a
    void move(State* a, int nb);
    bool isEqual(State st);

    float countryEvaluation(int moi); //moi->indice du joueur actuel



protected:
    std::string m_name;
    ContinentAI* m_continent;
    std::vector<State*> m_voisins;
    int m_joueur;
    int m_armees;
    unsigned int m_id;

    //Constantes utiles pour le calcul de la valeur d'un pays modifiables pour changer la stratégie/ l'agressivité...

    static float C_sv; //CV STATIC BONUS Bonus multiplier, used to adjust the static value of a country
    static float C_fn; //CV FRIENDLY NEIGHBOR The value of having a friendly neighbor
    static float C_en; //CV ENEMY NEIGHBOR The value of having a enemy neighbor
    static float C_fnu; //CV FRIENDLY NEIGHBOR UNIT The value of each neighboring friendly unit
    static float C_enu; //CV ENEMY NEIGHBOR UNIT The value of each neighboring enemy unit
    static float C_cb; //CV CONTINENT BORDER BONUS Bonus for bordering another continent
    static float C_oc; //CV OWN CONTINENT BONUS Bonus for owning the whole continent
    static float C_eoc; //CV ENEMY OWN CONTINENT Enemy owns the whole continent
};



#endif // STATE_H
