#ifndef MAPBOX_H
#define MAPBOX_H
/*
 * display the map box, mouse detection, choosing a country by clicking
 * @author zhouwei42
 * TODO : display soldiers and the owner
 *
 */
#include <QWidget>
#include <QtCore>
#include <QColor>
#include "countrygui.h"

class MapBox : public QWidget
{
    Q_OBJECT
public:
    explicit MapBox(QWidget *parent = 0);
    ~MapBox();
    bool load(QString);
    void unload();

signals:
    void countrySelected(QString name, int continent, int nbArmy, int occup, int);

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

private:
    bool isHand, isLoaded;
    int country;
    QPixmap map;
    QList<CountryGUI*> countries;

};

#endif // MAPBOX_H
