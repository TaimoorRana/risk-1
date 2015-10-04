#include "battleresults.h"
#include "ui_battleresults.h"

BattleResults::BattleResults(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BattleResults)
{
    ui->setupUi(this);
    this->setModal(true);
}

BattleResults::~BattleResults()
{
    delete ui;
}

void BattleResults::initialize(const QString& attacker_name, const QString& defender_name,
                               const int attacker_troops_died, const int defender_troops_died,
                               const bool attacker_wins)
{
    ui->label_4->setText(attacker_name);
    ui->label_5->setText(defender_name);
    ui->label_8->setText(QString::number(attacker_troops_died));
    ui->label_9->setText(QString::number(defender_troops_died));

    if (attacker_wins) ui->label_10->setText(attacker_name+" wins!");
    else ui->label_10->setText(defender_name+" wins!");
}
