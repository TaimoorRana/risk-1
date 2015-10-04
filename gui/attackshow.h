#ifndef ATTACKSHOW_H
#define ATTACKSHOW_H

#include <QDialog>

namespace Ui {
class Attackshow;
}

class Attackshow : public QDialog
{
    Q_OBJECT

public:
    explicit Attackshow(QWidget *parent = 0);
    ~Attackshow();
     void update(int a1,int a2,int a3,int d1,int d2,QString Attack_countryname, QString Target_countryname,int Attack_continent,int Target_continent,int Attack_nbArmy,int Taget_nbArmy);
private:
    Ui::Attackshow *ui;
};

#endif // ATTACKSHOW_H
