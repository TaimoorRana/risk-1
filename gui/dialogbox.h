#ifndef DIALOGBOX_H
#define DIALOGBOX_H

#include <QDialog>

namespace Ui {
class DialogBox;
}

class DialogBox : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBox(QString text,QWidget *parent = 0);
    void tell();
    ~DialogBox();

private:
    Ui::DialogBox *ui;
signals:
    void read();
private slots:
    void on_okButton_pressed();
};

#endif // DIALOGBOX_H
