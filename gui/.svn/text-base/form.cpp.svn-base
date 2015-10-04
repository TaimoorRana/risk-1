#include "form.h"
#include "ui_form.h"

/*  standard style of the dialogs to the user
 *  @author zhouwei42
 *  TODO : adapt the style to different game status
 *
 */
Form::Form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    this->setModal(true);
}

Form::~Form()
{
    delete ui;
    this->deleteLater();
}

void Form::on_OUI_pressed()
{
    close();
}

void Form::on_OUI_2_pressed()
{
    close();
}
