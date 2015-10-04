#include "battleresultsintermediate.h"
#include "ui_battleresultsintermediate.h"

BattleResultsIntermediate::BattleResultsIntermediate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BattleResultsIntermediate)
{
    ui->setupUi(this);
    this->setModal(true);
}

BattleResultsIntermediate::~BattleResultsIntermediate()
{
    delete ui;
}

void BattleResultsIntermediate::initialize(const QString& attacker_name, const QString& defender_name,
                                      int dice[5], const int attacker_troops_died, const int defender_troops_died)
{
    ui->label_4->setText(attacker_name);
    ui->label_5->setText(defender_name);
    ui->label_12->setText(QString::number(attacker_troops_died));
    ui->label_13->setText(QString::number(defender_troops_died));

    QString s = "";
    for (int i=0; i<3; i++)
    {
        if (dice[i]==0) s +="- ";
        else if ((0<dice[i])&&(dice[i]<7)) s += QString::number(dice[i]) + " ";
        else s +="# ";
    }
    ui->label_10->setText(s);

    s = "";
    for (int i=3; i<5; i++)
    {
        if (dice[i]==0) s +="- ";
        else if ((0<dice[i])&&(dice[i]<7)) s += QString::number(dice[i]) + " ";
        else s +="# ";
    }
    ui->label_11->setText(s);

}
