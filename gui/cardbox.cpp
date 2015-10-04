#include "cardbox.h"
#include "ui_cardbox.h"

CardBox::CardBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CardBox)
{
    ui->setupUi(this);
    this->setModal(true);
    this->setWindowTitle("Card Box");
    ui->card1->setWindowOpacity(0);
    ui->card2->setWindowOpacity(0);
    ui->card3->setWindowOpacity(0);
    ui->card4->setWindowOpacity(0);
    ui->card5->setWindowOpacity(0);
    ui->card6->setWindowOpacity(0);
}

void CardBox::on_card1_clicked()
{   if(ui->info1->text()=="card 1"){
        ui->info1->setText("info 1");
    }
    else{
        ui->info1->setText("card 1");
    }
}
void CardBox::on_card2_clicked()
{   if(ui->info2->text()=="card 2"){
        ui->info2->setText("info 2");
    }
    else{
        ui->info2->setText("card 2");
    }
}
void CardBox::on_card3_clicked()
{   if(ui->info3->text()=="card 3"){
        ui->info3->setText("info 3");
    }
    else{
        ui->info3->setText("card 3");
    }
}
void CardBox::on_card4_clicked()
{   if(ui->info4->text()=="card 4"){
        ui->info4->setText("info 4");
    }
    else{
        ui->info4->setText("card 4");
    }
}
void CardBox::on_card5_clicked()
{   if(ui->info5->text()=="card 5"){
        ui->info5->setText("info 5");
    }
    else{
        ui->info5->setText("card 5");
    }
}
void CardBox::on_card6_clicked()
{   if(ui->info6->text()=="card 6"){
        ui->info6->setText("info 6");
    }
    else{
        ui->info6->setText("card 6");
    }
}

CardBox::~CardBox()
{
    delete ui;
}

void CardBox::on_exit_pressed()
{
    this->close();
}
