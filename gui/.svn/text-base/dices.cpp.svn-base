#include<QString>
#include<iostream>
#include "dices.h"
#include "ui_dices.h"
using namespace std;

Dices::Dices(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dices)
{
    ui->setupUi(this);

}
void Dices::updateDices(int a1,int a2,int a3,int d1,int d2){

    ui->results->setText("<html><head/><body><p><span style=\"font-size:20pt; font-weight:600;\">Attack : </span></p><p>Dice 1 :"+ QString::number(a1) +"  Dice 2 : "+ QString::number(a2) +" Dice 3 : "+ QString::number(a3) +"</p><p><span style=\" font-size:18pt; font-weight:600;\">Defence :</span></p><p>Dice 1 : "+ QString::number(d1) +" Dice 2 : "+ QString::number(d2) +"</p><p><span style=\" font-size:18pt; font-weight:600;\">Comments :</span></p></body></html>");
//
//("<html><head/><body><p><span style=\"font-size:20pt; font-weight:600;\">Attack : </span></p><p>Dice 1 :*  Dice 2 : * Dice 3 : * </p><p><span style=\" font-size:18pt; font-weight:600;\">Defence :</span></p><p>Dice 1 : * Dice 2 : * </p><p><span style=\" font-size:18pt; font-weight:600;\">Comments :</span></p></body></html>"
    //+"\n This program is brea"
}
Dices::~Dices()
{
    delete ui;
}
