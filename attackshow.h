#ifndef ATTACKSHOW_H
#define ATTACKSHOW_H

#include <QDialog>

namespace Ui {
class attackshow;
}

class attackshow : public QDialog
{
    Q_OBJECT

public:
    explicit attackshow(QWidget *parent = 0);
    ~attackshow();

private:
    Ui::attackshow *ui;
};

#endif // ATTACKSHOW_H
