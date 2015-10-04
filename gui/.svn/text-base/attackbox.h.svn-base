#ifndef ATTACKBOX_H
#define ATTACKBOX_H

#include <QWidget>
#include "attackshow.h"
namespace Ui {
class attackbox;
}

class attackbox : public QWidget
{
    Q_OBJECT

public:
    explicit attackbox(QWidget *parent = 0);
    ~attackbox();
protected:

    QString Attack_countryname;
    QString Target_countryname;
    int Attack_continent;
    int Target_continent;
    int Attack_nbArmy;
    int Target_nbArmy;
    int attack_target;//if 0 no selectionned, if 1 attacking country if 2 target country
    void attackMode(int);
    Attackshow* attackshow;
private slots:
    //void on_attackingbox_clicked();
    void on_targetbox_clicked();
    void on_pushButton_clicked();



  //  void on_pet_clicked();

public slots:
    void country(QString,int,int,int,int);


private:

    Ui::attackbox *ui;

};

#endif // ATTACKBOX_H
