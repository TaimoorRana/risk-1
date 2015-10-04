#ifndef DICES_H
#define DICES_H

#include <QDialog>

namespace Ui {
class Dices;
}

class Dices : public QDialog
{
    Q_OBJECT

public:
    explicit Dices(QWidget *parent = 0);
    ~Dices();
    void updateDices(int a1,int a2,int a3,int d1,int d2);
private:
    Ui::Dices *ui;
};

#endif // DICES_H
