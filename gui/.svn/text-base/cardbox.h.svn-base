#ifndef CARDBOX_H
#define CARDBOX_H

#include <QDialog>

namespace Ui {
class CardBox;
}

class CardBox : public QDialog
{
    Q_OBJECT

public slots:
    void on_card1_clicked();
    void on_card2_clicked();
    void on_card3_clicked();
    void on_card4_clicked();
    void on_card5_clicked();
    void on_card6_clicked();

public:
    explicit CardBox(QWidget *parent = 0);
    ~CardBox();

private slots:
    void on_exit_pressed();

private:
    Ui::CardBox *ui;
};

#endif // CARDBOX_H
