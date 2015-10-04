#include "mapbox.h"
#include "../mainwindow.h"
#include "countrygui.h"
#include <QMouseEvent>
#include <QPainter>
#include <QColor>

/*
 * map box display functions, mouse detection functions, signal to infomation box when a country is selected,
 * display soldier number on the map...
 *
 * @author zhouwei42
 *
 * TODO : identify every owner by a color
 *
 *
 */

MapBox::MapBox(QWidget *parent) : QWidget(parent), isLoaded(false)
{
    setMouseTracking(true);
}

MapBox::~MapBox(){

}

bool MapBox::load(QString refFileName)
{
    if (isLoaded)
    {
        isLoaded = false;
        if (isHand)
            setCursor(Qt::ArrowCursor);
        countries.clear();
        map = QPixmap();
    }
    QString path = refFileName.left(refFileName.lastIndexOf(QChar('/')) + 1);
    QFile reffile(refFileName);
    if (!reffile.open(QIODevice::ReadOnly))
        return false;
    QTextStream stream(&reffile);
    QString mapPath = path + stream.readLine();
    map = QPixmap(mapPath);
    if (map.isNull())
    {
        reffile.close();
        return false;
    }
    int i = 0;
    while (stream.skipWhiteSpace(), !stream.atEnd())
    {
        QString filename, countryName;
        int continent, x, y;
        stream >> filename >> countryName >> continent >> x >> y;
        QImage *mask = new QImage(path + filename);
        if (mask->isNull()) continue;
        CountryGUI *to_add = new CountryGUI(countryName,mask, continent, x, y);
        to_add->setOwner(i%MainWindow::nbPlayer);
        to_add->setnArmies(1);
        i++;
        countries.append(to_add);
    }
    reffile.close();
    isHand = false;
    country = -1;
    isLoaded = true;
    update();
    return true;
}

void MapBox::unload()
{
    if (!isLoaded) return;
    isLoaded = false;
    if (isHand)
        setCursor(Qt::ArrowCursor);
    countries.clear();
    map = QPixmap();
}

void MapBox::paintEvent(QPaintEvent *)
{
    if (!isLoaded) return;
    QPainter painter(this);
    painter.drawPixmap(0, 0, width(), height(), map);
    for (int i=0; i < countries.size(); i++){
        int xi = countries.at(i)->getx()*width()/map.width();
        int yi = countries.at(i)->gety()*height()/map.height();
        int owner = countries.at(i)->getOwner();
        if (owner <7)
        {
            painter.setPen(MainWindow::colors[owner]);
            painter.drawText(xi, yi, QString::number(countries.at(i)->getnArmies()));
        }
    }
    if (country >= 0)
    {
        painter.setOpacity(0.4);
        painter.drawImage(QRect(0, 0, width(), height()), *(countries.at(country)->get_mask()));    
    }
}

void MapBox::mousePressEvent(QMouseEvent *evt)
{
    if (!isLoaded) return;
    if (isHand)
    {
        int mx = (evt->x() * map.width()) / width(), my = (evt->y() * map.height()) / height();
        for (int i = 0; i < countries.count(); ++i)
        {
            if (qAlpha(countries.at(i)->get_mask()->pixel(mx, my)) > 0)
            {
                country = i;
                update();
                if (MainWindow::isAddingTroops)
                {
                    countries.at(country) ->addArmy();
                    MainWindow::freeTroops --;
                }
                if (MainWindow::isFreeingTroops)
                {
                    countries.at(country)->removeArmy();
                    MainWindow::freeTroops ++;
                }
                emit countrySelected(countries.at(i)->get_name(), countries.at(i)->getContinent(),
                                     countries.at(i)->getnArmies(), countries.at(i)->getOwner(), MainWindow::freeTroops);

                return;
            }
        }
    }
    country = -1;
    update();
    emit countrySelected(QString(),0,0,0,0);
}

void MapBox::mouseMoveEvent(QMouseEvent *evt)
{
    if (!isLoaded) return;
    int mx = (evt->x() * map.width()) / width(), my = (evt->y() * map.height()) / height();
    for (int i = 0; i < countries.count(); ++i)
    {
        if (qAlpha(countries.at(i)->get_mask()->pixel(mx, my)) > 0)
        {
            if (!isHand)
            {
                setCursor(Qt::OpenHandCursor);
                isHand = true;
            }
            return;
        }
    }
    if (isHand)
    {
        setCursor(Qt::ArrowCursor);
        isHand = false;
    }
}
