#include "game.h"
#include "../shared_structures/country.h"
#include "../shared_structures/army.h"
#include "../interfaces/player.h"
#include "../shared_structures/steps.h"
#include "../shared_structures/global_settings.h"
#include "../shared_structures/initial_settings.h"
#include "../shared_structures/game_state.h"
#include "../shared_structures/continent.h"
#include "../shared_structures/moves.h"
#include "../shared_structures/card.h"
#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <set>
#include <map>
#include <vector>
#include <stdlib.h>

Game::Game(){
}

Game::~Game(){
}

<<<<<<< .mine
=======
Game::Game(InterfaceEngineNetwork* joueurs, Map carte, Deck tas){
    players=joueurs;
    map=carte;
    deck=tas;
}

Game::setnbplayers(int n){
    m_nbplayers=n;
}

>>>>>>> .r822
void Game::displacement(Country* origin, Country* destination, int number_of_armies)
{
    Army* a_or = m_game_state.get_army(origin);
    Army* a_de = m_game_state.get_army(destination);

    if(a_or->get_owner()==a_de->get_owner()) //the player owns th two countries
    //if(origin.getArmy().getOwner().getId() == destination.getArmy().getOwner().getId())
    {
<<<<<<< .mine
        if ((this->m_global_settings.get_neighbors(origin)).count(destination)<1) //the countries are neighbors
=======
        if ((this->m_global_settings.get_neibors(origin)).count(destination)>0) //the countries are neighbors
>>>>>>> .r822
        {
            //if((this->m_map.neighbors)[origin.getId()][destination.getId()]){
            if(a_or->get_number_of_armies()>number_of_armies) //after the displacement on origin there must be at least 1 army
            {
                a_or->modify_army(-number_of_armies);
                a_de->modify_army(+number_of_armies);
            }
            else
            {
                throw std::logic_error("Error: you are attempting to move more armies then you can!");
            }
        }
        else
        {
            throw std::logic_error("Error: the countries are not neighbors!");
        }
    }
    else
    {
        throw std::logic_error("Error: the two countries do NOT belong to the SAME player! Move not allowed");
    }


}

////////////////////////////////////////////////////////
///////////////////  Beginning, Initial settings  /////////////
////////////////////////////////////////////////////////

int Game::giveArmies(){
    int n;
    switch(m_nbplayers){
        case 3:{n=35;break;}
        case 4:{n=30;break;}
        case 5:{n=25;break;}
        case 6:{n=20;break;}
    }
    /*for(i=0;i<m_nbplayers;i++){
        m_players[i].setLeftArmies(n);
    }*/
    return n;
}

void Game::giveTerritories(Initial_Settings* In_Set){
    int i;
    int vect[42];
    for (i=0;i<42;i++){
        vect[i]=i;
    }
    for(int j=0;j<100;j++){
        int index1 = rand()%42;
        int index2 = rand()%42;
        int tmp1 = vect[index1];
        int tmp2 = vect[index2];
        vect[index1]=tmp2;
        vect[index2]=tmp1;
    }
    i=0;
    for(i=0;i<42;i++){
        Country* country = Country::get_country(vect[i]);
        int idplayer = i %m_nbplayers;
        In_Set->territories[In_Set->all_players[idplayer]].insert(country);
    }
}

//This function allows you input number of origin army (attack army) and destination army and output the number of army left of each side, it's easy to use, enjoy it!
//In this function we use randam number and we need other functions to get the troupnumber_origin and troupnumber_destination and we return the number of armies of each side left.
int* Game::Attack(int troupnumber_origin,int troupnumber_destination) {
        int i=0, t=0, origin_dice[3], destination_dice[2];
        int *temp=new int[2];
        srand(time(0));

   if(troupnumber_origin>=3&&troupnumber_destination>=2){
                for(i=0;i<3;i++){

                origin_dice[i]=rand()%6+1;}

                if(origin_dice[0]<origin_dice[1]){
                        t=origin_dice[0];origin_dice[0]=origin_dice[1];origin_dice[1]=t;
                }

                if(origin_dice[1]<origin_dice[2]){
                        t=origin_dice[1];origin_dice[1]=origin_dice[2];origin_dice[2]=t;
                }

                if(origin_dice[0]<origin_dice[1]){
                        t=origin_dice[0];origin_dice[0]=origin_dice[1];origin_dice[1]=origin_dice[2];
                }


                for(i=0;i<2;i++){

                destination_dice[i]=rand()%6+1;}

                if(destination_dice[0]<destination_dice[1]){
                        t=destination_dice[0];destination_dice[0]=destination_dice[1];destination_dice[1]=t;
                }

        //Compare
        if(origin_dice[0]>destination_dice[0]) troupnumber_destination--;
        else troupnumber_origin--;

        if(origin_dice[1]>destination_dice[1]) troupnumber_destination--;
        else troupnumber_origin--;
    }

    if(troupnumber_origin>=3&&troupnumber_destination==1){

                for(i=0;i<3;i++){

                origin_dice[i]=rand()%6+1;}

                if(origin_dice[0]<origin_dice[1]){
                        t=origin_dice[0];origin_dice[0]=origin_dice[1];origin_dice[1]=t;
                }

                if(origin_dice[1]<origin_dice[2]){
                        t=origin_dice[1];origin_dice[1]=origin_dice[2];origin_dice[2]=t;
                }

                if(origin_dice[0]<origin_dice[1]){
                        t=origin_dice[0];origin_dice[0]=origin_dice[1];origin_dice[1]=origin_dice[2];
                }

                destination_dice[0]=rand()%6+1;

                if(origin_dice[0]>destination_dice[0]) troupnumber_destination--;
        else troupnumber_origin--;}

     if(troupnumber_origin==2&&troupnumber_destination>=2){

                for(i=0;i<2;i++){

                origin_dice[i]=rand()%6+1;}

                if(origin_dice[0]<origin_dice[1]){
                        t=origin_dice[0];origin_dice[0]=origin_dice[1];origin_dice[1]=t;
                }

                for(i=0;i<2;i++){

                destination_dice[i]=rand()%6+1;}

                if(destination_dice[0]<destination_dice[1]){
                        t=destination_dice[0];destination_dice[0]=destination_dice[1];destination_dice[1]=t;
                }

                if(origin_dice[0]>destination_dice[0]) troupnumber_destination--;
        else troupnumber_origin--;

        if(origin_dice[1]>destination_dice[1]) troupnumber_destination--;
        else troupnumber_origin--;}

    if(troupnumber_origin==2&&troupnumber_destination==1){

                for(i=0;i<2;i++){

                origin_dice[i]=rand()%6+1;}

                if(origin_dice[0]<origin_dice[1]){
                        t=origin_dice[0];origin_dice[0]=origin_dice[1];origin_dice[1]=t;
                }

                destination_dice[0]=rand()%6+1;

                if(origin_dice[0]>destination_dice[0]) troupnumber_destination--;
        else troupnumber_origin--;}

    if(troupnumber_origin==1&&troupnumber_destination>=2){

                origin_dice[0]=rand()%6+1;

                for(i=0;i<2;i++){

                destination_dice[i]=rand()%6+1;}

                if(destination_dice[0]<destination_dice[1]){
                        t=destination_dice[0];destination_dice[0]=destination_dice[1];destination_dice[1]=t;
                }


                if(origin_dice[0]>destination_dice[0]) troupnumber_destination--;
        else troupnumber_origin--;}

    if(troupnumber_origin==1&&troupnumber_destination==1){

                origin_dice[0]=rand()%6+1;

                destination_dice[0]=rand()%6+1;

                if(origin_dice[0]>destination_dice[0]) troupnumber_destination--;
        else troupnumber_origin--;}



        temp[0]=troupnumber_origin;
        temp[1]=troupnumber_destination;
        return temp;
}

//beginning central loop
void Game::main_loop (list<Player*> players, Game_State game_state)
{
    bool game_is_on = true;

    //temporary steps
    Step* tmp_step = new Step();
    Dispatch_Step* tmp_D_step = new Dispatch_Step();
    tmp_D_step->id = 3; //always
    tmp_D_step->number_of_troops = 0;

    //temporary moves
    Move* tmp_move = new Move();
    //Change_Cards_Move* tmp_CC_move = new Change_Cards_Move();
    Dispatch_Move* tmp_D_move = new Dispatch_Move();
    Attack_Move* tmp_A_move = new Attack_Move();
    Displacement_Move* tmp_Dpl_move = new Displacement_Move();

    //flag for the attack phase
    bool won_countries = false;

    Player* cp = m_game_state.get_current_player();

    while(game_is_on)
    {
        cards_changed = false;
////////////////////////////////////////////////////////
///////////////////  Changing cards phase  /////////////
////////////////////////////////////////////////////////

        tmp_D_step->number_of_troops = bonus_backups(cp);
        int nb_bcu;

        if(m_game_state.get_hand(cp).size()<5) //#cards<5 the players chooses if change cards or not
        {
            tmp_step->id = 1;
            m_game_state.set_step(tmp_step);//ask if player wants change
            tmp_move = cp->next_move(&m_game_state); //I'm not sure if correct
            if( tmp_move->id==1) //he wants //make it public
            {
              int nb_bcu = change_loop();
              if (nb_bcu != -1)
              {
                  tmp_D_step->number_of_troops += nb_bcu;
                  m_game_state.update_reward_index(*m_global_settings); //update reward index (game round)
              }
              else
              { //throw error
              }

            }
        }else
        {
            do
            {//#cards>=5 player has to change cards
                nb_bcu = change_loop();
                if (nb_bcu != -1)
                {
                    tmp_D_step->number_of_troops += nb_bcu;
                     m_game_state.update_reward_index(*m_global_settings); //update reward index (game round)
                }
                else
                { //throw error
                }
            }while( m_game_state.get_hand(cp).size()<5);
        }

        if(tmp_D_step->number_of_troops > 0) //player has to dispatch backups
        {
            m_game_state.set_step((Step*) tmp_D_step); //I'm not sure if correct
            tmp_move = cp->next_move(&m_game_state);//ask for Dispatch Move
            if(tmp_move->id != 3)
            {//throw error
            }
            tmp_D_move = (Dispatch_Move*) tmp_move;
            dispatch_backups(tmp_D_move->distribution,nb_bcu);
            tmp_D_step->number_of_troops = 0;
        }


////////////////////////////////////////////////////////
///////////////////////   Attack phase  ////////////////
////////////////////////////////////////////////////////
        won_countries = false;

        tmp_step->id = 4;
        m_game_state.set_step(tmp_step);
        tmp_move=cp->next_move(&m_game_state);//ask for a Attack_Move
        while(tmp_move->id==4)
        {
          tmp_A_move = (Attack_Move*) tmp_move;

          //temporary pointer used to modify the country
          Army* a_or = m_game_state.get_army(tmp_A_move->origin); //**
          Army* a_de = m_game_state.get_army(tmp_A_move->destination);
          int troupnumber_origin=a_or->get_number_of_armies();
          int troupnumber_destination=a_de->get_number_of_armies();

          int* losses; //losses[0]=attacker's armies destroyed [1]=defender's
          losses=Attack(troupnumber_origin,troupnumber_destination); //not coded yet
          int att_armies_left=losses[0];//not coded yet  //attacker's armies not destroyed in the attack
          int def_armies_destroyed=troupnumber_destination-losses[1];//not coded yet  //defender's armies destroyed in the attack

          if(losses[0]== -1)
          {
              //throw error
              tmp_move = cp->next_move(&m_game_state);
          }
          else
          {
              //temporary pointer used to modify the country
              Army* a_or = m_game_state.get_army(tmp_A_move->origin);
              Army* a_de = m_game_state.get_army(tmp_A_move->destination);
              int att_armies_left= tmp_A_move->number_of_armies - losses[0];//not coded yet  //attacker's armies not destroyed in the attack
              int def_armies_destoyed=losses[1];//not coded yet  //defender's armies destroyed in the attack

              if(won_battle(a_de, def_armies_destoyed))
              {
                won_countries = true;
                a_or->modify_army(- tmp_A_move->number_of_armies);  //armies that attacked moved from the origin
                a_de->set_number_of_armies(att_armies_left);          //armies not destroyed moved in the new country
                Player* tmp_pl = a_de->get_owner();
                a_de->set_owner(cp);                               //setting the new owner of the country

                if(m_game_state.countries_owned_by(tmp_pl).empty()) //cp killed an ennemy
                 {
                      m_game_state.add_into_defeated(tmp_pl,cp);
                      won_cards(tmp_pl); //the current player get the cards of the other player
                 }

                Objective* cp_objective=In_Set->players_objectives[cp];

                if(cp_objective->isAchieved(&m_game_state))//not coded yet
                {
                      game_is_on = false;
                      //tell to the other players that the game is over
                      break;
                 }

               }
                else
                {
                    a_or->modify_army(att_armies_left - (tmp_A_move->number_of_armies));
                    a_de->modify_army(-def_armies_destoyed);
                }
          }
            tmp_move = cp->next_move(&m_game_state); //ask player if he wants to attack again
        }//end of while

        //if here, cp doesn't want to attack anymore
        if(won_countries)
        {
            m_game_state.draw(cp);//not coded yet
        }


////////////////////////////////////////////////////////
//////////////////  Displacement phase  ////////////////
////////////////////////////////////////////////////////
        tmp_step->id = 5;
        m_game_state.set_step(tmp_step);
        tmp_move = cp->next_move(&m_game_state); //ask player if he wants to move troops
        if( tmp_move->id==5)
        {
            tmp_Dpl_move = (Displacement_Move*) tmp_move;
            displacement(tmp_Dpl_move->origin,tmp_Dpl_move->destination,tmp_Dpl_move->number_of_armies);
        }



////////////////////////////////////////////////////////
//////////////////  Round ending phase  ////////////////
////////////////////////////////////////////////////////
        tmp_step->id = 6;
        m_game_state.set_step(tmp_step);
        tmp_move = cp->next_move(&m_game_state); //say to cp that his turn is over

        if((In_Set->players_objectives)[cp]->is_accomplished(&m_game_state,cp)) //not coded yet
        {
            game_is_on = false;
            //tell to the other players that the game is over
            break;
        }
        //next player & update
        do{
            cp = get_and_set_next_player(m_game_state.get_initial_settings());
        }while(m_game_state.get_defeated_players().count(cp)<1);

<<<<<<< .mine

        if(cards_changed)
        {
             m_game_state.update_reward_index(&m_global_settings); //update reward index (game round)
        }


=======
>>>>>>> .r822
    }
}//end of main_loop



int Game::change_loop ()
{
    Step* tmp_step = new Step();
    Move* tmp_move = new Move();
    Change_Cards_Move* tmp_CC_move = new Change_Cards_Move();
    tmp_step->id = 2;
    m_game_state.set_step(tmp_step);
    Player* cp = m_game_state.get_current_player();
    tmp_move = cp->next_move(&m_game_state);//ask for a Change_Cards_Move
    if(tmp_move->id!=2)
    {
        return -1;
    }
    tmp_CC_move = (Change_Cards_Move*) tmp_move;
    int tmp_bcu = change_cards(*tmp_CC_move);//calculate backups
    if(tmp_bcu != -1)
    {
        update_cards(*tmp_CC_move);
        return tmp_bcu;
    }
    else
    {
        return -1;
    }

}//end of change_loop



int Game::bonus_backups(Player* player)
{
    int bonus = 0;
    int nb_of_owned_countries = m_game_state.countries_owned_by(player).size();

    //bonus for the owned countries
    bonus = (int) nb_of_owned_countries / 3;

    //bonus for the owned countries
    set<Continent*> continents = m_global_settings.get_continents();

    for(set<Continent*>::iterator it = continents.begin(); it != continents.end(); ++it)
    {
        if((*it)->is_owned_by(player, &m_game_state))
        {
            bonus += (*it)->get_troop_bonus();
        }
    }

    return bonus;
}//end of bonus_backups

void Game::won_cards (Player* loser)
{
    Player* winner = this->m_game_state.get_current_player();
    set<Card*> winners_cards = m_game_state.get_hand(winner);
    set<Card*> losers_cards = m_game_state.get_hand(loser);

    for(set<Card*>::iterator it = losers_cards.begin(); it != losers_cards.end(); ++it)
    {
        winners_cards.insert(*it);
    }

    losers_cards.erase(losers_cards.begin(),losers_cards.end());

}

bool Game::won_battle(Army* defender, int destroyed_armies)
{
    if((defender->get_number_of_armies() - destroyed_armies) <1)
        return true;
    else
        return false;
}

void bubble_sort(int arr[],int len) {
        int i, j, temp;
      for (i=0;i<len-1;i++)
                for (j=0;j <len-1-i;j++)
                        if (arr[j] < arr[j+1]){
                                temp=arr[j];
                                arr[j]=arr[j+1];
                                arr[j+1]=temp;
                        }
}

int min(int a, int b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}


<<<<<<< .mine
//Description:
//Input: A change cards move
//Output: The reward (number of backup armies) for trading the cards
=======
//int* Game::attack(){
//   int loss[2];
//   for(int l=0;l<2;l++){
//       loss[l]=0;
//   }

//   int attacker[3];
//   int defender[2];
//   for(int i=0;i<3;i++){
//       srand(time(NULL));
//       attacker[i]=rand()%6+1;
//   }
//   for(int j=0;j<2;j++){
//       srand(time(NULL));
//       defender[j]=rand()%6+1;
//   }
//   bubble_sort(attacker,origin.getArmy().getNumberOfArmys());
//   bubble_sort(defender,destination.getArmy().getNumberOfArmys());

//   for(k=0;k<min(origin.getArmy().getNumberOfArmys(),destination.getArmy().getNumberOfArmys());k++){
//       if(attacker[k]>defender[k]){
//           loss[1]++;
//       }
//       else{
//           loss[0]++;
//       }
//   }
//   return loss;
//}

int* Game::attack(Attack_Move* at)
{
   int losses[2];
   losses[0] = -1; losses[1]= -1;
   Army* def = m_game_state.get_army(at->destination);
   if (this->m_global_settings.get_neibors(at->origin).count(at->destination) <1 )
       return losses;
   else
   {
       losses[0]=0; losses[1]=0;
   }

   int def_troops;
   int att_troops;

   if (at->number_of_armies > 2)
       att_troops = 3;
   else
       att_troops = at->number_of_armies;

   if (def->get_number_of_armies() >1 )
       def_troops=2;
   else
       def_troops=1;

   int attacker[att_troops];
   int defender[def_troops];
   for(int i=0; i<att_troops; i++){
       srand(time(NULL));
       attacker[i]=rand()%6+1;
   }
   for(int j=0; j<def_troops; j++){
       srand(time(NULL));
       defender[j]=rand()%6+1;
   }
   bubble_sort(attacker,att_troops);
   bubble_sort(defender,def_troops);

   for(k=0; k<min(att_troops,def_troops); k++){
       if(attacker[k]>defender[k]){
           losses[1]++;
       }
       else{
           losses[0]++;
       }
   }
   return losses;
}


}

>>>>>>> .r822
int Game::change_cards(Change_Cards_Move cards_change_move)
{
    set <Card*> change = cards_change_move.change;
    int armyCount[4];
    bool flag = false;
    for(int i=0;i<4;i++){
        armyCount[i]=0;
    }

    for (std::set<Card*>::iterator it=change.begin(); it!=change.end(); ++it)
    {
        int s = (*it)->get_symbol();
        if(s==(*it)->Infantry) armyCount[0]++;
        if(s==(*it)->Artillery) armyCount[1]++;
        if(s==(*it)->Cavalry) armyCount[2]++;
        if(s==(*it)->Joker) armyCount[3]++;
    }
    // 3 same cards
    for(int i=0;i<3;i++){
        if(armyCount[i]==3)
            flag=true;
    }
    // 3 different cards
    if(armyCount[0]>0&&armyCount[1]>0&&armyCount[2]>0)
        flag=true;
    // 1 joker + 2 other cards
    if(armyCount[3]==1)
        flag=true;

    if(!flag)
        return -1;
    else
    {
        int round = m_game_state.get_reward_index();
        vector <int> reward_values = m_global_settings.get_reward_values();
        return reward_values.at(round);
    }
}

void Game::update_cards(Change_Cards_Move cards_change_move)
{
    //std::set <Card*> change = cards_change_move.change;
    //map <Player*, set<Card*> > hands = m_game_state.get_hands();

    Player* current_player = m_game_state.get_current_player();
    set<Card*> player_cards = m_game_state.get_hand(current_player);

    set<Card*> cards_to_erase = cards_change_move.change;
    set<Card*>::iterator itFind;
    for(set<Card*>::iterator it=cards_to_erase.begin();it!=cards_to_erase.end();it++){
        itFind=player_cards.find(*it);
        player_cards.erase(itFind);
    }
}

Player* Game::get_and_set_next_player(Initial_Settings* is){
        Player* current_player=m_game_state.get_current_player();
        is->all_players.push_back(current_player);
        Player* p = is->all_players.front();
        this->m_game_state.set_player(p);
        is->all_players.erase(is->all_players.begin());
        return p;
}



bool Game::dispatch_backups(map <Country*,int> to_dispatch,int total_backup_armies){
    bool correct_dispatch=true;
    Player* cp = m_game_state.get_current_player();
    //verification bon nombre d'armées et placées sur les bons pays
    //compteur_armies pour calculer le nb total d'armées placées
    int compteur_armies=0;
    int put_armies;
    list<Country*> cp_countries;
    cp_countries=m_game_state.countries_owned_by(cp);
    bool found;

    for(map<Country*,int>::iterator it=to_dispatch.begin();it!=to_dispatch.end();++it){
        put_armies=it->second;
        found = false;
        for(list<Country*>::iterator it1=cp_countries.begin();it1!=cp_countries.end();++it1){
            if((it->first)->get_id()==(*it1)->get_id()) found=true;
        }
        if(!found){
            throw std::logic_error("You do not own some of these countries or incorrect input !");
            correct_dispatch=false;
            break;
        }
        else if(put_armies<0){
            throw std::logic_error("You didn't dispatch your armies");
            correct_dispatch=false;
            break;
        }
        else if(compteur_armies>total_backup_armies){
            throw std::logic_error("You exceed the number of armies that you had");
            correct_dispatch=false;
            break;
        }
        else {
            compteur_armies=compteur_armies+put_armies;
            int nb_armies=m_game_state.get_army(it->first)->get_number_of_armies();
            m_game_state.get_army(it->first)->set_number_of_armies(nb_armies+put_armies);
        }
    }
    return correct_dispatch;
}
