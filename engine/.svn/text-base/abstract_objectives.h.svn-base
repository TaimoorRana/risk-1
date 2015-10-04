#ifndef ABSTRACT_OBJECTIVES
#define ABSTRACT_OBJECTIVES

class Abtract_Objectives : public objective {
public:
    Player* PlayerID;
    Abtract_Objectives();
    Abtract_Objectives (Player* PlayerID);
    ~Abtract_Objectives();
    virtual bool isAchieved();
};

// the 1st objective card
//You must conquer and occupy 18 territories each with at least two armies

class O1 : public Abstract_Objectives {
public:
     O1();
    ~O1();
    virtual bool isAchieved(Game_State* gamestate);

};


// the 2nd,6st,7st,8st objective cards
//You must conquer all of X and Y continents .

class O2_6_7_8 : public Abstract_Objectives {

public:

    string name_continent_1;
    string name_continent_2;

    O2_6_7_8();
    O2_6_7_8(string name_continent_1,string name_continent_2);
    ~O2_6_7_8();

    virtual bool isAchieved(Game_State* gamestate);

};

// the 3rd,4st objective cards
//You must conquer all of X and Y continents over a third continent
class O3_4 : public Objective {
public:
    string name_continent_1;
    string name_continent_2;
    O3_4();
    ~O3_4();
    O3_4(string name_continent_1, string name_continent_2 );
    virtual bool isAchieved(Game_State* gamestate);
};



// the 5st Objective card
//You must conquer 24  territories
class O5 : public Objective {
    public:
    O5();
    ~O5();

    virtual bool isAchieved(Game_State* gamestate);
};



// Objective cards from 9 to 14
//"You must destroy the color X armies. If you are yourself the owner of the X army or the X army is removed by another player, your goal becomes automatically to conquer 24 territories. "
class O9_14 : public Abstract_Objective{

Player* Opponent;
public:
    O9_14();
    ~O9_14();
    O9_14::O9_14(Player* Opponent);
    virtual bool isAchieved();
};


#endif // ABSTRACT_OBJECTIVES
