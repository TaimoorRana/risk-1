#include "proba.h"
#include "math.h"
#include "iostream"

using namespace std;

int Proba::test[10];
double Proba::des [4][3][5];
//const int Proba::nbAttMax=20;
//const int Proba::nbDefMax=20;
double Proba::tab[nbAttMax][nbDefMax];  //Tableau de proba de victoire pour i attaquants contre j défenseurs
double Proba::nbsurvivors [nbAttMax][nbDefMax];
bool Proba::visite [nbAttMax][nbDefMax];
bool Proba::visite2 [nbAttMax][nbDefMax];

Proba::Proba()
{
}

Proba::~Proba()
{
}

void Proba::setDes()    // Le tableau de probabilité des resultats de dés
{
    for (int i=0;i<4;i++)
    {
          for (int j=0;j<3;j++)
          {
              for (int k=0;k<5;k++)
              {
                  des[i][j][k]=0;
              }
          }

    }
    //Tableau de probabilités. Pour i dés attaquants et j défenseurs
    //le résultat k est obtenu ac proba tab[i][j][k]
    //Résultats : 0 : 2 attaquants morts.. 2 : 1 de chaque, 4 : 2 def morts

    des[1][1][1]=0.58;
    des[1][1][3]=0.42;
    des[2][1][1]=0.42;
    des[2][1][3]=0.58;
    des[3][1][1]=0.34;
    des[3][1][3]=0.66;
    des[1][2][1]=0.75;
    des[1][2][3]=0.25;
    des[2][2][0]=0.45;
    des[2][2][2]=0.32;
    des[2][2][4]=0.23;
    des[3][2][0]=0.29;
    des[3][2][2]=0.34;
    des[3][2][4]=0.37;
}



void Proba::setProba()                 // Construit le tableau de probabilité de victoire
{
    for (int att=0;att<nbAttMax;att++)   // Initialise le tableau de booleens de visite à false
    {
        for (int def=0;def<nbDefMax;def++)
        {
            visite2[att][def]=false;
        }
    }

    for (int i=0;i<nbAttMax;i++)          // Valeurs évidentes : S'il y a 0 attaquant (resp. defenseur),
    {                                     // on gagne avec proba 0 (resp. 1)
        tab[i][0]=1;
        for (int j=1;j<nbDefMax;j++)
        {
            tab[i][j]=0;
        }
    }

    tab[1][0]=1;                          // Valeurs d'initialisation pour lancer la récurrence
    tab[2][0]=1;
    tab[1][1]=des[1][1][3];
    tab[2][1]=des[2][1][3]+(1-des[2][1][3])*des[1][1][3];
    tab[1][2]=des[1][2][3]*des[1][1][3];
    tab[2][2]=des[2][2][4]+des[2][2][2]*des[1][1][3];
    tab[3][1]=des[3][1][3]+des[3][1][1]*tab[2][1];
    tab[3][2]=des[3][2][4]+des[3][2][2]*tab[2][1]+des[3][2][0]*tab[1][2]; // Ex : A 3 contre 2, la proba est celle d'eliminer les deux défenseurs du premier coup,
                                                                          // plus celle de faire 1-1 * la proba de gagner en configuration 2-1
                                                                          // plus celle de perdre 2 attaquants * la proba de gagner en config 1-2

    for (int i=1;i<nbAttMax;i++)           // Appelle a la fonction récursive setProbabis
    {
        for (int j=1;j<nbDefMax;j++)
        {
            tab[i][j]=setProbabis(i,j);
            visite2[i][j]=true;
        }
    }

    for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            //cout<<round(tab[i][j]*100)<<"  ";
        }
        //cout<<" "<<endl;
    }

}
double Proba::setProbabis(int i,int j)   // Auxiliaire de setProba
{
    if (visite2[i][j])                     // Pour plus d'efficacité, on reprend les valeurs deja obtenues precedemment
    {
        return(tab[i][j]);
    }

    else if ((i<=3 && j<=2) || (i==0) || (j==0))  //
    {
        return(tab[i][j]);
    }

    else if (i==2 && j>=2) // Configuration 2 contre 2
    {
        return (des[2][2][0]*setProbabis(i-2,j)+des[2][2][2]*setProbabis(i-1,j-1)+des[2][2][4]*setProbabis(i,j-2));
    }
    else if (i==1 && j>=2)  // Configuration 1 contre 2
    {
        return (des[1][2][1]*setProbabis(i-1,j)+des[1][2][3]*setProbabis(i,j-1));
    }
    else if (i>=3 && j==1)  // Configuration 3 contre 1
    {
        return (des[3][1][1]*setProbabis(i-1,j)+des[3][1][3]*setProbabis(i,j-1));
    }
    else  // Configuration à 3 contre 2
    {
        return (des[3][2][0]*setProbabis(i-2,j)+des[3][2][2]*setProbabis(i-1,j-1)+des[3][2][4]*setProbabis(i,j-2));
    }
}


void Proba::setSurvivors()  // Construit le tableau avec le nombre d'attaquants restants
{
    for (int att=0;att<nbAttMax;att++)
    {
        for (int def=0;def<nbDefMax;def++)
        {
            visite[att][def]=false;
        }
    }
    for (int i=0;i<nbAttMax;i++)
    {
        nbsurvivors[i][0]=i;
        nbsurvivors[0][i]=0;
    }
    for (int att=1;att<nbAttMax;att++)
    {
        for (int def=1;def<nbDefMax;def++)
        {
            nbsurvivors[att][def]=setSurvivorsbis(att,def);
            visite[att][def]=true;
        }
    }


    for (int att=0;att<10;att++)
    {
        for (int def=0;def<10;def++)
        {
            //cout<<round(nbsurvivors[att][def])<<"  ";
        }
        //cout<<" "<<endl;
    }
}

double Proba::setSurvivorsbis(int att, int def)   // Fonction auxiliaire de setSurvivor
{
    if (visite[att][def])
    {
        return (nbsurvivors[att][def]);
    }
    else if (att==0 || def==0)
    {
        return (nbsurvivors[att][def]);
    }
    else if (att==1 && def==1)  // Tirage 1 contre 1
    {
        return(des[1][1][1]*setSurvivorsbis(att-1,def)+des[1][1][3]*setSurvivorsbis(att,def-1));
    }
    else if (att==2 && def==1)  // Tirage 2 contre 1
    {
        return(des[2][1][1]*setSurvivorsbis(att-1,def)+des[2][1][3]*setSurvivorsbis(att,def-1));
    }
    else if (att==2 && def>=2) // Tirage 2 contre 2
    {
        return (des[2][2][0]*setSurvivorsbis(att-2,def)+des[2][2][2]*setSurvivorsbis(att-1,def-1)+des[2][2][4]*setSurvivorsbis(att,def-2));
    }
    else if (att==1 && def>=2)  // Tirage 1 contre 2
    {
        return (des[1][2][1]*setSurvivorsbis(att-1,def)+des[1][2][3]*setSurvivorsbis(att,def-1));
    }
    else if (att>=3 && def==1)  // Tirage 3 contre 1
    {
        return (des[3][1][1]*setSurvivorsbis(att-1,def)+des[3][1][3]*setSurvivorsbis(att,def-1));
    }
    else  // Tirage à 3 contre 2
    {
        return (des[3][2][0]*setSurvivorsbis(att-2,def)+des[3][2][2]*setSurvivorsbis(att-1,def-1)+des[3][2][4]*setSurvivorsbis(att,def-2));
    }

}


int Proba::neededAtt(int def,double seuil)  // Seuil désigne la proba minimale de victoire qu'on souhaite
{
    int att=0;
    while (tab[att][def]<seuil)
    {
        att++;
    }
    return (att);
}



int Proba::remainingAtt(int att,int def)  // Renvoie le nombre moyen d'attaquants restant apres l'attaque de att contre def
{
    return(round)(nbsurvivors[att][def]);
}

double Proba::getProba (int att, int def) // Renvoie la proba de victoire a att contre def
{
    return (tab[att][def]);
}

