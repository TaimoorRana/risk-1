#include "gui/attackshow.h"
#include "ui_attackshow.h"

Attackshow::Attackshow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Attackshow)
{
    ui->setupUi(this);
}
void Attackshow::update(int a1,int a2,int a3,int d1,int d2,QString Attack_countryname, QString Target_countryname,int Attack_continent,int Target_continent,int Attack_nbArmy,int Target_nbArmy){

    ui->attack_dice1->setText(QString::number(a1));
    ui->attack_dice2->setText(QString::number(a2));
    ui->attack_dice3->setText(QString::number(a3));
    ui->target_dice1->setText(QString::number(d1));
    ui->target_dice2->setText(QString::number(d2));
    ui->attack_results->setText("<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Attack : </span>"+ Attack_countryname+"</p><p>Number of troops : "+QString::number(Attack_nbArmy)+" </p></body></html>");
    ui->target_results->setText("<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Target : </span>"+ Target_countryname+"</p><p>Number of troops : "+QString::number(Target_nbArmy)+" </p></body></html>");
}
Attackshow::~Attackshow()
{
    delete ui;
}
