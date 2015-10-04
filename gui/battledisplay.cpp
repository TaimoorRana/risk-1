#include "battledisplay.h"
//see .h to see what is to be implemented
BattleDisplay::BattleDisplay()
{
    //This constructor can't be used. can we remove it?
}

BattleDisplay::BattleDisplay(Color defColor, Color attColor, bool att, int attTroops, int defTroops){
    this->defColor = defColor;
    this->attColor = attColor;
    this->att = att;
    this->attTroops = attTroops;
    this->defTroops = defTroops;
}

void BattleDisplay::updateBattleStep(int dices[], int attTroops, int defTroops){
    //Display new round
    //this->dices = dices; ne marche pas
    //make animation to draw the dices #elodie
    //make animation to draw the matching between the dices
    this->attTroops = attTroops;
    //update the number of attacking troops
    this->defTroops = defTroops;
    //update the number of defTroops
}

void BattleDisplay::displayEndOfBattle(){
    //Redraw window with outcome of the battle and a OK button


}

int BattleDisplay::moveTroops(int attTroops){
    //In case of victory, display a frienly interface (with a plus and minus?) to choose how many troops are moved to the conquered territory.
    return 0;

}

BattleDisplay::~BattleDisplay()
{

}

