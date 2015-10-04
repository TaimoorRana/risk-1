#include "bid.h"
#include "path.h"

#include<iostream>
#include<string>

using namespace std;

Bid::Bid()
{
    m_path=new Path();
    m_bid_value=0;
    m_armies_requested=0;
}


Bid::Bid(Path *path, float bid_value, int armies_requested)
{
    this->m_path=path;
    this->m_bid_value=bid_value;
    this->m_armies_requested=armies_requested;
}

Bid::~Bid()
{
    delete m_path;
}

void Bid::affiche()
{
    cout<<"Affichage du Bid"<<endl;
    cout<<"   value: "<<m_bid_value<<endl;
    cout<<"   armies requested: "<<m_armies_requested<<endl;
    cout<<"   path: "<<endl;
    m_path->affiche();
}


