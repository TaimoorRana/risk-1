#ifndef FORM_H
#define FORM_H

/*
 * test commit
 * @author zhouwei42
 */
#include <QDialog>

namespace Ui {
class Form;
}

class Form : public QDialog
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

private slots:
    void on_OUI_pressed();

    void on_OUI_2_pressed();

private:
    Ui::Form *ui;
};

#endif // FORM_H
