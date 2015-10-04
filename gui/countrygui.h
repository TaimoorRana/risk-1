#ifndef COUNTRYGUI_H
#define COUNTRYGUI_H
#include <QObject>

/*
 * @author zhouwei42
 * different countries, containing name, mask of the region
 * TODO: adding position of the soldiers and more functions
 *
 */
class CountryGUI
{
public:
    CountryGUI(QString s, QImage *i, int c, int x, int y);
    ~CountryGUI();
    QString get_name();
    QImage *get_mask();
    int getx();
    int gety();
    int getOwner();
    int getnArmies();
    void setOwner(int owner);
    void addArmy();
    void removeArmy();
    void setnArmies(int);
    int getContinent();
private:
    QString name;
    QImage *mask;
    int continent;
    int x,y,owner,nArmies;
};

#endif // COUNTRY_H
