#ifndef BATTLERESULTSINTERMEDIATE_H
#define BATTLERESULTSINTERMEDIATE_H

#include <QDialog>
#include <QString>

/*
 * Author: @yaro2
 *
 * Description:
 * This dialog shows dice' throws and the number of troops killed during the battle
 * The dialog BattleResults is to be used for final results
 *
 * Signals:
 * returns accept() to show results of the next turn, reject() to skip and to show final results
 *
 * Example of initialization:
 * BattleResultsIntermediate* dial = new BattleResultsIntermediate(this);
 * int arr = {6,3,0,4,1}
 * dial->initialize("Red","Yellow",arr,0,2);
 * dial->show();
*/

namespace Ui {
class BattleResultsIntermediate;
}

class BattleResultsIntermediate : public QDialog
{
    Q_OBJECT

public:
    explicit BattleResultsIntermediate(QWidget *parent = 0);
    ~BattleResultsIntermediate();

    //dice contains the outcomes of dice throws
    //elements [0],[1],[2] are for attacker dice
    //elements [3],[4] are for defender dice
    //0 means that the attacker or the defender doesn't use this dice
    void initialize(const QString& attacker_name, const QString& defender_name,
                    int dice[5], const int attacker_troops_died, const int defender_troops_died);

private:
    Ui::BattleResultsIntermediate *ui;
};

#endif // BATTLERESULTSINTERMEDIATE_H
