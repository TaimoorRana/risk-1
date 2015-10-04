//
//  GlobalSettings.h
//  
//
//  Created by Maud Doumergue on 03/02/2015.
//
//

#ifndef ____GlobalSettings__
#define ____GlobalSettings__

#include <stdio.h>
#include <string>
#include <fstream>
#include "continent.hpp"
#include "country.hpp"
#include "map.h"
#include "objective.h"

class GlobalSettings{
    public:
    
    static map World;
    // continents, pays
    
    static int CavalryState[14]={4,6,8,10,15,20,25,30,35,40,45,50,55,60};
    // cf cavalier doré pointeur dans ce tableau
    
    static Objectives[20];
    //nombre total d'objectifs à définir: 20?
    
    //static card Cards[44];
    //Cartes pays/régiment à définir : 42 pays plus 2 jokers
    
    GlobalSettings();
    ~GlobalSettings();
    
};

