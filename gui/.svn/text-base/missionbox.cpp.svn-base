#include "missionbox.h"
#include "ui_missionbox.h"

missionbox::missionbox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::missionbox)
{
    ui->setupUi(this);
    ui->missiondescription->setText("Description de la mission du joeur. À completer");
    QWidget::setWindowFlags(Qt::FramelessWindowHint);

}



missionbox::~missionbox()
{
    delete ui;
}

void missionbox::on_quit_clicked()
{
    close();
}
