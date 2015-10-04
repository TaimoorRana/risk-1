#ifndef BID_H
#define BID_H

class Path;

//il faut mettre des majuscules au nom des classes
class Bid
{

public:
    Bid();
    Bid(Path* path, float b, int a);
    ~Bid();
    void set_bid_value(float b){m_bid_value=b;}
    float get_bid_value(){return m_bid_value;}
    void set_army_requested(int a){m_armies_requested=a;}
    float get_army_requested(){return m_armies_requested;}
    void set_path(Path* p) {m_path=p;}
    Path* get_path(){return m_path;}

    void affiche();



//il faut mettre des m_ devant le nom des variables membres (ok je suis relou)
protected:
    Path* m_path;
    float m_bid_value;
    int m_armies_requested;
};

#endif // BID_H
