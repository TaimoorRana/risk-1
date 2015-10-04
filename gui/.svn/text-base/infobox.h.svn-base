#ifndef INFOBOX_H
#define INFOBOX_H

#include <QWidget>

/*
 * information box for displaying country datas
 * @author zhouwei42
 * TODO: find owner and army size
 */

namespace Ui {
class InfoBox;
}

class InfoBox : public QWidget
{
    Q_OBJECT

public:
    explicit InfoBox(QWidget *parent = 0);
    ~InfoBox();
public slots:
    void country(QString,int,int,int,int);

private:
    Ui::InfoBox *ui;
};

#endif // INFOBOX_H
