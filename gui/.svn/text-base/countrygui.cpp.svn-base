#include "countrygui.h"
#include <QMessageBox>
#include "../mainwindow.h"
/*
 * basic functions for country class
 * @author zhouwei42
 */
CountryGUI::CountryGUI(QString s, QImage *mask, int c, int x, int y)
{
    this->name = s;
    this->mask = mask;
    this->x = x;
    this->y = y;
    this->nArmies = 0;
    this->owner = 7;
    this->continent = c;
}

CountryGUI::~CountryGUI()
{
}

QString CountryGUI::get_name()
{
    return this->name;
}

QImage* CountryGUI::get_mask()
{
    return this->mask;
}

int CountryGUI::getx()
{
    return this->x;
}

int CountryGUI::gety()
{
    return this->y;
}

int CountryGUI::getOwner()
{
    return this->owner;
}

int CountryGUI::getnArmies()
{
    return this->nArmies;
}

void CountryGUI::setnArmies(int nArmies)
{
    this->nArmies = nArmies;
}

void CountryGUI::setOwner(int owner)
{
    this->owner = owner;
}

int CountryGUI::getContinent()
{
    return this->continent;
}

void CountryGUI::addArmy()
{
    this->nArmies +=1;
}

void CountryGUI::removeArmy()
{
        this->nArmies -=1;
}
