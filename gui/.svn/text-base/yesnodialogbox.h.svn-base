#ifndef YESNODIALOGBOX_H
#define YESNODIALOGBOX_H

#include <QDialog>

namespace Ui {
class YesNoDialogBox;
}

class YesNoDialogBox : public QDialog
{
    Q_OBJECT

public:
    explicit YesNoDialogBox(QString text,QWidget *parent = 0);
    bool ask();
    ~YesNoDialogBox();

private:
    Ui::YesNoDialogBox *ui;
    bool answer;

signals:
    void reponse();

private slots:
    void on_yesButton_pressed();
    void on_noButton_pressed();
};
#endif // YESNODIALOGBOX_H
