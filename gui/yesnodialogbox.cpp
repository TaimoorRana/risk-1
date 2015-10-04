#include "yesnodialogbox.h"
#include "ui_yesnodialogbox.h"

YesNoDialogBox::YesNoDialogBox(QString text, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::YesNoDialogBox)
{
    ui->setupUi(this);
    ui->dialog->setText(text);
}

bool YesNoDialogBox::ask(){
    this->show();
    QEventLoop loop;
    QObject::connect(this, SIGNAL(reponse()), &loop, SLOT(quit()));

    loop.exec();
    return answer;
}

YesNoDialogBox::~YesNoDialogBox()
{
    delete ui;
}

void YesNoDialogBox::on_yesButton_pressed()
{
    answer=true;
    emit reponse();
    this->close();
}

void YesNoDialogBox::on_noButton_pressed()
{
    answer=false;
    emit reponse();
    this->close();
}
