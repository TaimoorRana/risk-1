#include<iostream>
#include "dices.h"
#include "ui_dices.h"
#include "attackbox.h"
#include "ui_attackbox.h"

attackbox::attackbox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::attackbox)
{
    setMouseTracking(true);
    ui->setupUi(this);
    attack_target = 0;
    attackshow = new Attackshow;
    ui->troops->setMinimum(0);
}

attackbox::~attackbox()
{
    delete ui;
}





void attackbox::country(QString countryname, int continent, int nbArmy, int occup ,int nbfree){
    std::cout<<"country cliked"<<attack_target<<std::endl;

    if(attack_target == 1){
        Attack_countryname = countryname;
        Attack_continent = continent;
        Attack_nbArmy = nbArmy;
        ui->troops->setMaximum(nbArmy);
        ui->attackingcountrydisplay->setText(countryname);

    }
    if(attack_target == 2){

        Target_countryname = countryname;
        Target_continent = continent;
        Target_nbArmy = nbArmy;
        ui->targetcountrydisplay->setText(countryname);

    }
}
void attackbox::attackMode(int i){
    attack_target = i;

}
/*
void attackbox::on_attackingbox_clicked()
{

    this->attackMode(1);

}*/

void attackbox::on_targetbox_clicked()
{
    switch (attack_target) {
    case 0:
        attackMode(1);
        ui->targetbox->setText("Target");
        break;
    case 1:
        attackMode(2);
        ui->targetbox->setText("Attack");
        break;
    case 2:
        attackMode(1);
        ui->targetbox->setText("Target");
        break;
    default:
        break;
    }


}

void attackbox::on_pushButton_clicked()
{
    this->attackMode(0);
    ui->targetcountrydisplay->setText(" ");
    ui->attackingcountrydisplay->setText(" ");
    ui->troops->setValue(0);


    attackshow->update(1,2,3,4,5, Attack_countryname, Target_countryname,Attack_continent, Target_continent,ui->troops->value(), Target_nbArmy);
    attackshow->show();
}


