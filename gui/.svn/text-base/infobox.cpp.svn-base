#include "infobox.h"
#include "ui_infobox.h"
#include "QWidget"
#include "../mainwindow.h"

/* information box when a country is selected
 *  @author zhouwei42
 *  TODO: find owner from a list
 */

InfoBox::InfoBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InfoBox)
{
    ui-> setupUi(this);
    ui-> freeTroop->setText(QString::number(MainWindow::freeTroops));
}

InfoBox::~InfoBox()
{
    delete ui;
}

void InfoBox::country(QString countryname, int continent, int nbArmy, int occup ,int nbfree){
    ui->countryname->setText(countryname);
    ui->army->setText(QString::number(nbArmy));
    ui->freeTroop->setText(QString::number(nbfree));
    if (occup < 7)
    {
        ui->occupant->setText(MainWindow::playersList[occup]);
    }
    else
    {
         ui->occupant->setText("None");
    }
    switch (continent) {
        case 1:
            ui->continent->setText("North America");
            break;
        case 2:
            ui->continent->setText("South America");
            break;
        case 3:
            ui->continent->setText("Europe");
            break;
        case 4:
            ui->continent->setText("Africa");
            break;
        case 5:
            ui->continent->setText("Asia");
            break;
        case 6:
            ui->continent->setText("Australia");
            break;
    default:
        ui->continent->setText("");
    }
}
