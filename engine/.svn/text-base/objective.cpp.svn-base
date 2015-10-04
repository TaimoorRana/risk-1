#include "objective.h"
#include <iostream>
using namespace std;

Objective::Objective(){
    this->PlayerID=0;
    this->IDcard =0;
}
Objective::Objective(Player* PlayerID, int IDcard){
    this->PlayerID=PlayerID;
    this->IDcard=IDcard;

}
Objective::~Objective(){
}

 bool Objective ::isAchieved(Player* Player){
return false;



}


int Objective:: numberOfCountriesConquered(Player* player){

    int compter(0);

    for (int index=0; index<42; index++){

        if ( player->getCountries() [index] ==true)
            compter++;
    }

    return compter;
}


bool Objective::numberOfArmies(Player* player, int IDcountries, Map map){

    if ( player-> getCountries()[IDcountries]==false)
    return false;
    else
    return ( map[IDcountries].getArmies() >=2);

}
bool Objective::isContinentConquered(Player* player, int IDcontinent){

    bool T(true);
    switch(IDcontinent){
    case 0:
        //North America
        for( int i=0; i<9;i++){
            if (player->getCountries()[i]==false)
                T=false;
        }
        break;
    case 1:
        // South America
        for( int i=9; i<13;i++){
            if (player->getCountries()[i]==false)
                T=false;
        }
        break;

    case 2:
        // Europe
        for( int i=13; i<20;i++){
            if (player->getCountries()[i]==false)
                T=false;
        }
        break;
    case 3:
        //Africa
        for( int i=20; i<26;i++){
            if (player->getCountries()[i]==false)
                T=false;
        }
        break;
    case 4:
        // Asia
        for( int i=26; i<38;i++){
            if (player->getCountries()[i]==false)
                T=false;
        }
        break;
    case 5:
        // Australia
        for( int i=38; i<42;i++){
            if (player->getCountries()[i]==false)
                T=false;
        }
        break;
    }
    return T;


}
bool Objective::isArmyDestroyed(Player* opponent){

    return !opponent->isAlive();
}



    void Objective::print(){

    cout <<"The goal is :";


}


    O1::O1(){
        this->PlayerID=0;
    }
    O1::O1(Player* PlayerID,int IDcard){
        this->PlayerID=PlayerID;
        this->IDcard =IDcard;

    }
    O1::~O1(){
    }

    bool O1::isAchieved(Player* Player,Map map){
        int compter=0;
        for (int i =0; i<42;i++){
            if (( Player->getCountries()[i]==true) && numberOfArmies(Player, i , map))
                compter++ ;
        }
        if (compter>=18) return true;
        else return false;

    }
    void print(){
        cout<<"You must conquer and occupy 18 territories each with at least two armies";


    }


    O2_6_7_8::O2_6_7_8(){

        this->PlayerID=0;
        this->IDcard=0;
        this->continent_1=0;
        this->continent_2=0;
    }
    O2_6_7_8::O2_6_7_8(Player* PlayerID,int IDcard){
        this->PlayerID=PlayerID;
        this->IDcard=IDcard;
        switch(IDcard){
        case 2:
            this->continent_1=0;
            this->continent_2=3;
            break;
        case 6:
            this->continent_1=0;
            this->continent_2=5;
            break;
        case 7:
            this->continent_1=4;
            this->continent_2=3;
            break;
        case 8:
            this->continent_1=4;
            this->continent_2=1;
            break;

        }


    }
    O2_6_7_8::~O2_6_7_8(){
    }

    bool O2_6_7_8::isAchieved(Player* Player){
        if ((isContinentConquered(Player, this->continent_1)==true)&&(isContinentConquered(Player, this->continent_2)==true))
        return true;
        else return false;

    }

        void O2_6_7_8::print(){
            switch(IDcard){

            case 2:
                cout<<"You must conquer all of North America and Africa ";
                break;
            case 6:
                cout<<"You must conquer all of North America and Oceania ";
                break;
            case 7:
                cout<<"You must conquer all of Asia and Africa ";
                break;
            case 8:
                cout<<"You must conquer all of Asia and South America";
                break;

            }


    }

        O3_4::O3_4(){

            this->PlayerID=0;
            this->IDcard=0;
            this->continent_1=0;
            this->continent_2=0;
        }
        O3_4::O3_4(Player* PlayerID,int IDcard){
            this->PlayerID=PlayerID;
            this->IDcard=IDcard;
            switch(IDcard){
            case 3:
                this->continent_1=2;
                this->continent_2=1;
                break;
            case 4:
                this->continent_1=2;
                this->continent_2=5;
                break;

            }


        }
        O3_4::~O3_4(){
        }

        bool O3_4::isAchieved(Player* Player){
            bool T(false);

            if ((isContinentConquered(Player, this->continent_1)==true)&&(isContinentConquered(Player, this->continent_2)==true))
              {
                for (int i =0; i<6; i++){

                    if ((i!=this->continent_1)&&(i!= this->continent_2))
                            {if (isContinentConquered(Player, i)) T= true;}
                                                                    }
                    }
             return T;




        }

            void O3_4::print(){
                switch(IDcard){

                case 3:
                    cout<<"You must conquer all of Europe and South America over a third continent  ";
                    break;
                case 4:
                    cout<<"You must conquer all of Europe and Oceania over a third continent ";
                    break;

                }


        }

            O5::O5(){
                this->PlayerID=0;
                this->IDcard=0;
            }
            O5::O5(Player* PlayerID,int IDcard){
                this->PlayerID=PlayerID;
                this->IDcard =IDcard;

            }
            O5::~O5(){
            }

            bool O5::isAchieved(Player* Player){

                return (numberOfCountriesConquered(Player)>=24);

                     }

            void print(){
            cout<<"You must conquer 24  territories";

            }

            O9_14::O9_14(){
                this->Opponent=0;
                this->PlayerID=0;
                this->IDcard=0;
            }
            O9_14::O9_14(Player* PlayerID, Player* Opponent,int IDcard){
                this->PlayerID=PlayerID;
                this->Opponent=Opponent;
                this->IDcard=IDcard;
            }
            O9_14::~O9_14(){
            }

            bool O9_14::isAchieved(){

                if( (Opponent==PlayerID)||( !(Opponent->isAlive()) )) // to finish with determi the killer

                {
                    if( numberOfCountriesConquered(PlayerID)>=24) return true;
                    else return false;
                }

                else{

                    if (Opponent->isAlive()) return false;
                    else return true;

                }

            }

                void O9_14::print(){
                    switch(IDcard){

                    case 9:
                        cout<<"You must destroy the yellow armies. If you are yourself the owner of the yellow army or the yellow is removed by another player, your goal becomes automatically to conquer 24 territories. ";
                        break;
                    case 10:
                        cout<<"You must destroy the red armies. If you are yourself the owner of the red army or the red is removed by another player, your goal becomes automatically to conquer 24 territories.  ";
                        break;
                    case 11:
                        cout<<"You must destroy the blue armies. If you are yourself the owner of the blue army or the blue is removed by another player, your goal becomes automatically to conquer 24 territories. ";
                        break;
                    case 12:
                        cout<<"You must destroy the black armies. If you are yourself the owner of the black army or the black is removed by another player, your goal becomes automatically to conquer 24 territories. ";
                        break;
                    case 13:
                        cout<<"You must destroy the violet armies. If you are yourself the owner of the violet army or the violet is removed by another player, your goal becomes automatically to conquer 24 territories. ";
                        break;
                    case 14:
                        cout<<"You must destroy the green armies. If you are yourself the owner of the green army or the green is removed by another player, your goal becomes automatically to conquer 24 territories. ";
                        break;
                    default:
                        break;
                    }


            }
