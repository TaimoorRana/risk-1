#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <time.h>
#include "ai3/pseudo-engine/continentai.h"
#include "ai3/pseudo-engine/state.h"
#include "ai3/pseudo-engine/graph.h"
#include "ai3/central_unit.h"

using namespace std;


void goalset(Central_Unit& UC, vector<State*>& mes_pays, vector<State*>& mes_ennemis)
{
    mes_pays = UC.getGraph()->pays_joueur(UC.getPlayer());
    mes_ennemis = UC.getGraph()->pays_ennemis(UC.getPlayer());
    Path p;
    Agent aa;//=Agent(*(mes_pays[0]),true);
    Agent* a = &aa;

    //remplissage des goalsets
    for (int i = 0; i < 42; i++)
    {
        a = Central_Unit::getAgent(i);
        a->clearGS();
        //cout<<a->getState()->Getname()<<"lol"<<a->getGoalset().size()<<endl;
    }

    for (int i = 0; i < mes_ennemis.size(); i++)
    {
        a = Central_Unit::getAgent(mes_ennemis[i]->Getid());
        p = Path(0, a->goal_value(), 0, mes_ennemis[i]->Getarmees());
        p.add(a);
        //p.affiche();
        a->sendToNeighbours(p);
    }
    /*for (int i = 0; i < mes_pays.size(); i++)
    {
        a = Central_Unit::getAgent(mes_pays[i]->Getid());
        //a->printGoalSet();
    }*/
}

int mainai3(int argc, char *argv[])
{

    QCommandLineParser parser;


    QApplication appli(argc, argv);
    MainWindow w;
    w.setWindowTitle("Ca roule pour AI3 xavier");
    //xavier
    //et Guillaume3
    //et Thibaut
    //et Valentin
    //claire
    //gabriel
    // JN
    w.show();

    //merci de ne pas supprimer ce code!!!! (hein wei zhou) :)
    /*******************************************************
        ****************TEST UC*********************************
        ********************************************************/
    /*centralUnit uc = centralUnit();
        int b = uc.essaifn(5);
        std::cout << "Failed to register window class" << std::endl;
    */

    /*******************************************************
        ****************FIN DE TEST UC**************************
        ********************************************************/


    /*******************************************************
    ****************GRAPHE DE TESTS*************************
    ********************************************************/
    srand(time(NULL));

    ContinentAI* Europe = new ContinentAI("Europe",5,7,6);
    ContinentAI* Asie = new ContinentAI("Asie",7,12,6);
    ContinentAI* Afrique = new ContinentAI("Afrique",3,6,4);
    ContinentAI* AN = new ContinentAI("Amérique du Nord",5,9,3);
    ContinentAI* AS = new ContinentAI("Amérique du Sud",2,4,2);
    ContinentAI* Oceanie = new ContinentAI("Océanie",2,4,1);



    State* Af1 = new State("Egypte", Afrique, 1, 2);
    State* Af2 = new State("Afrique du Nord", Afrique, 2, 3);
    State* Af3 = new State("Afrique Orientale", Afrique, 2, 3);
    State* Af4 = new State("Afrique du Sud", Afrique, 2, 4);
    State* Af5 = new State("Congo", Afrique, 1, 1);
    State* Af6 = new State("Madagascar", Afrique, 2, 1);

    State* E1 = new State("Europe Occidentale", Europe, 1, 2);
    State* E2 = new State("Europe du Sud", Europe, 2, 3);
    State* E3 = new State("Europe du Nord", Europe, 2, 2);
    State* E4 = new State("Grande-Bretagne", Europe, 2, 1);
    State* E5 = new State("Islande", Europe, 2, 2);
    State* E6 = new State("Ukraine", Europe, 2, 2);
    State* E7 = new State("Scandinavie", Europe, 2, 1);

    State* An1 = new  State("Alaska", AN, 2, 3);
    State* An2 = new State("TNO", AN, 1, 3);
    State* An3 = new State("Groenland", AN, 1, 5);
    State* An4 = new State("Alberta", AN, 1, 2);
    State* An5 = new State("Ontario", AN, 1, 1);
    State* An6 = new State("Québec", AN, 2, 5);
    State* An7 = new State("EE", AN, 2, 3);
    State* An8 = new State("EO", AN, 2, 4);
    State* An9 = new State("AC", AN, 2, 2);

    State* As1 = new State("Venezuela", AS, 2, 1);
    State* As2 = new State("Brésil", AS, 2, 2);
    State* As3 = new State("Pérou", AS, 2, 2);
    State* As4 = new State("Argentine", AS, 1, 5);

    State* O1 = new State("NG", Oceanie, 1, 4);
    State* O2 = new State("AusOcc", Oceanie, 1, 3);
    State* O3 = new State("Indonesie", Oceanie, 1, 2);
    State* O4 = new State("AusOr", Oceanie, 1, 3);

    State* A1 = new  State("Moyen-Orient", Asie, 2, 1);
    State* A2 = new State("Oural", Asie, 2, 2);
    State* A3 = new State("Afghanistan", Asie, 2, 1);
    State* A4 = new State("Sibérie", Asie, 2, 3);
    State* A5 = new State("Yakoutie", Asie, 2, 2);
    State* A6 = new State("Tchita", Asie, 1, 3);
    State* A7 = new State("Mongolie", Asie, 1, 2);
    State* A8 = new State("Kamtchatka", Asie, 2, 1);
    State* A9 = new State("Japon", Asie, 2, 2);
    State* A10 = new State("Chine", Asie, 2, 5);
    State* A11 = new State("Inde", Asie, 2, 4);
    State* A12 = new State("Siam", Asie, 2, 4);

    Af1->addVoisin(A1);
    Af1->addVoisin(Af2);
    Af1->addVoisin(Af3);
    Af1->addVoisin(E2);

    Af2->addVoisin(E1);
    Af2->addVoisin(E2);
    Af2->addVoisin(Af1);
    Af2->addVoisin(Af3);
    Af2->addVoisin(Af5);
    Af2->addVoisin(As2);

    Af3->addVoisin(Af1, Af2, Af3, Af4, Af5, A1);
    Af4->addVoisin(Af3, Af5, Af6);
    Af5->addVoisin(Af2,Af3,Af4,Af6);
    Af6->addVoisin(Af3,Af4);

    E1->addVoisin(E2,E3,E4,Af2);
    E2->addVoisin(E6,E3,E1,A1,Af1,Af2);
    E3->addVoisin(E1,E2,E4,E6,E7);
    E4->addVoisin(E1,E3,E5,E7);
    E5->addVoisin(E4,E7,An3);
    E6->addVoisin(E2,E3,E7,A1,A2,A3);
    E7->addVoisin(E3,E4,E5,E6);

    A1->addVoisin(Af1,E2,E6,A3,A11,Af3);
    A2->addVoisin(E6,A3,A4,A10);
    A3->addVoisin(E6,A1,A11,A10,A2);
    A4->addVoisin(A2,A5,A6,A7,A10);
    A5->addVoisin(A4,A6,A8);
    A6->addVoisin(A4,A5,A7,A8);
    A7->addVoisin(A4,A6,A8,A9,A10);
    A8->addVoisin(A5,A6,A7,A9,An1);
    A9->addVoisin(A7,A8);
    A10->addVoisin(A2,A3,A4,A7,A11,A12);
    A11->addVoisin(A1,A3,A10,A12);
    A12->addVoisin(A10,A11,O3);

    An1->addVoisin(A8,An2,An4);
    An2->addVoisin(An1,An3,An4,An5);
    An3->addVoisin(An2,An6,E5);
    An4->addVoisin(An1,An2,An5,An8);
    An5->addVoisin(An2,An4,An6,An7,An8);
    An6->addVoisin(An3,An5,An7);
    An7->addVoisin(An5,An6,An8,An9);
    An8->addVoisin(An4,An5,An7,An9);
    An9->addVoisin(An7,An8,As1);

    As1->addVoisin(An9,As3,As2);
    As2->addVoisin(As1,As3,As4,Af2);
    As3->addVoisin(As1,As2,As4);
    As4->addVoisin(As2,As3);

    O1->addVoisin(O2,O3,O4);
    O2->addVoisin(O1,O3,O4);
    O3->addVoisin(O1,O2,A12);
    O4->addVoisin(O1,O2);

    //je me cale sur l'ordre d'Engine en fait
    //et de toute façon ce code sera fait par receiveGlobalSettings
    /*State tab[42]={An1,An2,An3,An4,An5,An6,An7,An8,An9,
                            As1,As2,As3,As4,Af1,Af2,Af3,Af4,Af5,Af6,
                            E1,E2,E3,E4,E5,E6,E7,
                            A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,
                            O1,O2,O3,O4};*/
    State* tabaux[42]={An1,An4,An9,An7,An3,An2,An5,An6,An8,
                       As4,As2,As3,As1,
                       E4,E5,E3,E7,E2,E6,E1,
                       Af5,Af3,Af1,Af6,Af2,Af4,
                       A3,A10,A11,A6,A9,A8,A1,A7,A12,A4,A2,A5,
                       O4,O3,O1,O2};
    for (int k=0; k<42; k++)
    {
        tabaux[k]->Setid(k);
    }

    cout<<"rgmqejbeeefffffffffffffffffffffffffffffffff"<<endl;
    cout<<A3->Getid()<<endl;
    vector<State*> tab=vector<State*>();
    for (int i=0; i<42; i++)
    {
        tab.push_back(tabaux[i]);
    }

    vector<ContinentAI*> tabcont=vector<ContinentAI*>();
    tabcont.push_back(AN);
    tabcont.push_back(AS);
    tabcont.push_back(Europe);
    tabcont.push_back(Afrique);
    tabcont.push_back(Asie);
    tabcont.push_back(Oceanie);
    cout<<"zgzjkgnzgmmgnsmgsmkgnsmkgn"<<endl;
    cout<<tabcont[3]->Getfrontieres()<<endl;
    Graph g(42,tab,6,tabcont);







    vector<State*> europeens=(Europe->Getpays());
    cout<<"pays europeens"<<endl;
    for (int i=0; i<Europe->Gettaille();i++)
    {
        cout<<i<<endl;
        cout<<europeens[i]->Getname()<<endl;
        cout<< europeens[i]->Getid()<<endl;
    }

    //fin de la définition de la carte, début des tests à proprement parler

    g[0]->attack(g[1]);

    cout<<"armées sur alaska "<<g[0]->Getarmees()<<endl;
    cout<<"armées sur alberta "<<g[1]->Getarmees()<<endl;
    cout<<"proprio de alaska "<<g[0]->Getjoueur()<<endl;
    cout<<"proprio de alberta "<<g[1]->Getjoueur()<<endl;

    g[1]->move(g[0],2);
    cout<<"armées sur alaska "<<g[0]->Getarmees()<<endl;
    cout<<"armées sur alberta "<<g[1]->Getarmees()<<endl;

    ///TESTS SUR CENTRALUNIT
    Central_Unit UC=Central_Unit(&g, 1);
    UC.setNbTotPlayers(2);
    UC.setNbRenfort(3);
    vector<State*> mes_pays=UC.getGraph()->pays_joueur(UC.getPlayer());
    vector<State*> mes_ennemis=UC.getGraph()->pays_ennemis(UC.getPlayer());
    Path p;
    Agent aa;//=Agent(*(mes_pays[0]),true);
    Agent* a=&aa;
    for (int i=0; i<42;i++)
    {
        a=Central_Unit::getAgent(i);
        cout<<a->getState()->Getname()<<" "<<a->goal_value()<<endl;
    }

    //remplissage des goalsets

    for (int i=0; i<mes_ennemis.size();i++)
    {
        cout<<"**********************************************************"<<endl;
        cout<<mes_ennemis[i]->Getname()<<endl;
        a=Central_Unit::getAgent(mes_ennemis[i]->Getid());
        p=Path(0,a->goal_value(),0,mes_ennemis[i]->Getarmees());
        p.add(a);
        //p.affiche();
        a->sendToNeighbours(p);
    }
    for (int i=0; i<mes_pays.size();i++)
    {
        a=Central_Unit::getAgent(mes_pays[i]->Getid());
        if (a->getState()->Getname()=="Argentine")
        {
            a->printGoalSet();
        }
        //a->printGoalSet();
    }


    //génération des bids
    cout << "GENERATION DES OFFENSIVE BIDS" << endl;
    int nbRenforts = 5;
    for (int i = 0; i < mes_pays.size(); i++)
    {
        a = Central_Unit::getAgent(mes_pays[i]->Getid());
        Bid* bid = a->best_offensive_bid(nbRenforts);
        cout << "Best offensive bid de l'agent " << a->getState()->Getname() << endl;
        bid->affiche();
    }

    cout << "GENERATION DES DEFENSIVE BIDS" << endl;
    //int nbRenforts=5;
    for (int i = 0; i < mes_pays.size(); i++)
    {
        a = Central_Unit::getAgent(mes_pays[i]->Getid());
        Bid* bid = a->best_defensive_bid(nbRenforts);
        cout << "Best defensive bid de l'agent " << a->getState()->Getname() << endl;
        bid->affiche();
    }

    //Dispatch des troupes à placer
    vector<string> deja_faits = vector<string>(); //vector contenant les noms des pays qui ont déjà bénéficié d'un renfort
    bool vu;
    while (nbRenforts >= 1)
    {
        int bid_value = 0;
        Bid* bidMax;
        Path* pathMax;
        State* stateMax;
        int renforts_demandes = 0;
        bool mars;
        //je parcours les pays qui m'appartiennent
        for (int i = 0; i < mes_pays.size(); i++)
        {
            a = Central_Unit::getAgent(mes_pays[i]->Getid());
            vu = false;
            Bid* tempBid = a->best_bid(nbRenforts);
            //valeur de vu (vu=true si on a déjà mis des renforts pour cet agent)
            for (int k = 0; k < deja_faits.size(); k++)
            {
                if (deja_faits[k] == a->getState()->Getname())
                {
                    //cout<<a->getState()->Getname()<<endl;
                    vu = true;
                }
            }
            if (tempBid->get_bid_value() > bid_value && !vu)
            {
                bidMax = tempBid;
                pathMax = tempBid->get_path();
                stateMax = (a->getState());
                bid_value = tempBid->get_bid_value();
                renforts_demandes = bidMax->get_army_requested();
            }
        }
        //on donne les renforts à l'état idoine
        cout << "Ajout de " << renforts_demandes << " à l'état " << stateMax->Getname() << endl;
        stateMax->addArmee(renforts_demandes);
        nbRenforts -= renforts_demandes;
        deja_faits.push_back(stateMax->Getname());
    }
    cout << "Fin du dispatch des renforts" << endl;


    //Phase d'attaque
    bool attaque = true; //continuons d'attaquer!
    while (attaque)
    {
        goalset(UC, mes_pays, mes_ennemis);
        /*cout<<"amérique du sud"<<endl;
            cout<<As1->Getjoueur()<<" "<<As1->Getarmees()<<endl;
            cout<<As2->Getjoueur()<<" "<<As2->Getarmees()<<endl;
            cout<<As3->Getjoueur()<<" "<<As3->Getarmees()<<endl;
            cout<<As4->Getjoueur()<<" "<<As4->Getarmees()<<endl;*/
        Agent* attaquant;
        Agent* defenseur;
        float bid_value=0;
        Bid* best_bid;
        for (int i = 0; i < mes_pays.size(); i++)
        {
            a = Central_Unit::getAgent(mes_pays[i]->Getid());
            //if (a->getState()->Getname()=="Brésil"){cout<<"ok"<<endl;}
            Bid* bid = a->best_offensive_bid(0);
            //cout << "Best offensive0 bid de l'agent " << a->getState()->Getname() << endl;
            //bid->affiche();
            if (bid->get_bid_value()>bid_value)
            {
                best_bid=bid;
                bid_value=bid->get_bid_value();
                attaquant=a;
                defenseur=(bid->get_path()->getPath())[1];
            }
        }
        if (best_bid->get_path()->get_proba_of_success(0,false)>0.6)
        {
            cout<<"Attaque de "<<attaquant->getState()->Getname()<<" sur "<<defenseur->getState()->Getname()<<endl;
            attaquant->attack_agent(*defenseur);
            //cout<<"etat du jeu"<<endl;
            //cout<<attaquant->getState()->Getname()<<attaquant->getState()->Getarmees()<<endl;
            //cout<<defenseur->getState()->Getname()<<defenseur->getState()->Getarmees()<<" "<<defenseur->getState()->Getjoueur()<<" "<<defenseur->getIsMars()<<endl;
        }
        else
        {
            attaque=false;
            //cout<<"on aurait eu"<<attaquant->getState()->Getname()<<defenseur->getState()->Getname()<<best_bid->get_path()->get_proba_of_success(0,false)<<endl;
        }

    }

    /*********************************************************
             *****************FIN DES TESTS***************************
             *********************************************************/




    return appli.exec();
}

