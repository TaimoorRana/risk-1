#include "dialogbox.h"
#include "ui_dialogbox.h"

DialogBox::DialogBox(QString text, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogBox)
{
    ui->setupUi(this);
    ui->dialog->setText(text);
}

void DialogBox::tell(){
    this->show();
    QEventLoop loop;
    QObject::connect(this, SIGNAL(read()), &loop, SLOT(quit()));

    loop.exec();
    return;
}

DialogBox::~DialogBox()
{
    delete ui;
}

void DialogBox::on_okButton_pressed()
{
    emit read();
    this->close();
}
