#ifndef BATTLEDISPLAY_H
#define BATTLEDISPLAY_H

#include <QWidget>
#include <QObject>

//To be put elsewhere, but for now it is here
enum Color { RED, GREEN, BLUE};

class BattleDisplay : public QWidget
    //This class embodies a little window popping up at each battle, making an animation of the battle (dices, survivors etc...)
{
    Q_OBJECT

public:
    BattleDisplay();
    BattleDisplay(Color defColor, Color attColor, bool att, int attTroops, int defTroops);
    ~BattleDisplay();
    void updateBattleStep(int dices[], int attTroops, int defTroops); //Update the battle status with the new dice launch
    void displayEndOfBattle(); //Display Victory or defeat and the number of resulting troops according to the outcome.
    int moveTroops(int attTroops); //In case of Victory, let the user choose how many troops are transfered.



private:
    Color defColor; //color of the defendant
    Color attColor; //color of the attaquant
    bool att; //is the player the attaquant
    int dices[5]; //outcome of the dices, the 3 first are for the attaquant, the other for the defendant. A value of 7 represent a dice that is not rolled
    int attTroops; //Number of troops on each side.
    int defTroops;
};

#endif // BATTLEDISPLAY_H
