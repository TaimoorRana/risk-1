#include "attackshow.h"
#include "ui_attackshow.h"

attackshow::attackshow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::attackshow)
{
    ui->setupUi(this);
}

attackshow::~attackshow()
{
    delete ui;
}
