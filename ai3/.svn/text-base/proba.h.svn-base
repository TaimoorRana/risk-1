#ifndef PROBA_H
#define PROBA_H


class Proba
{
    public:

         //j'ai bougé ça du .h parce que le principe c'est quon puisse voir tous les champs dans le .h...
        static int test[];
        static double des[4][3][5];
        static const int nbAttMax=20;
        static const int nbDefMax=20;
        static double tab[nbAttMax][nbDefMax];  //Tableau de proba de victoire pour i attaquants contre j défenseurs
        static double nbsurvivors[nbAttMax][nbDefMax];
        static bool visite[nbAttMax][nbDefMax];
        static bool visite2[nbAttMax][nbDefMax];


        Proba();
        virtual ~Proba();
        static void setDes();
        static void setProba();
        static double setProbabis(int i,int j);
        static void setSurvivors();
        static double setSurvivorsbis(int att,int def);
        static int neededAtt(int def,double seuil);
        static int remainingAtt(int att,int def);
        static double getProba(int att,int def);
        //float get_proba_of_success(Path path);
        static int nbDefMax_value() {return nbDefMax;}




};

#endif // PROBA_H
