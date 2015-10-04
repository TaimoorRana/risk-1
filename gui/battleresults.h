#ifndef BATTLERESULTS_H
#define BATTLERESULTS_H

#include <QDialog>

/*
 * Author: @yaro2
 *
 * Description:
 * This dialog shows final results of the battle
 * The dialog BattleResultsIntermediate is to be used for intermediate results
 *
 * Signals:
 * returns accept() on exit
 *
 * Example of initialization:
 *  BattleResults* dial = new BattleResults();
 *  dial->initialize("Red","Yellow",0,2,true);
 *  dial->show();
 */

namespace Ui {
class BattleResults;
}

class BattleResults : public QDialog
{
    Q_OBJECT

public:
    explicit BattleResults(QWidget *parent = 0);
    ~BattleResults();

    void initialize(const QString& attacker_name, const QString& defender_name,
                    const int attacker_troops_died, const int defender_troops_died,
                    const bool attacker_wins);

private:
    Ui::BattleResults *ui;
};

#endif // BATTLERESULTS_H
