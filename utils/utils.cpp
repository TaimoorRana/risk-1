#include "utils.h"

template<typename T> static void shuffle(vector<T> & in)
{
    for(int i = 0; i<in.size(); i++)
    {
        int idx = rand()%(in.size()-i);
        T temp = in[i];
        in[i] = in[idx];
        in[idx] = temp;
    }
}

template<typename T> static vector<T> set_to_vector(const set<T> & the_set)
{
    vector<T> the_vector;
    for(typename set<T>::iterator it = the_set.begin(); it != the_set.end(); ++it)
        the_vector.push_back(*it);
    return the_vector;
}

template<typename T> static set<T> get_n_random(const set<T> &the_set, int n) {
    vector<T> the_vector = set_to_vector(the_set);
    shuffle(the_vector);
    set<T> answer_set;
    for(int i = 0; i < n; ++i) {
        answer_set.insert(the_vector[i]);
    }
    return answer_set;
}

template<typename T, typename V> static map<T, set<V>> deal(const vector<T> &receivers, const set<V> &cards) {
    vector<V> shuffled_cards = set_to_vector(cards);
    shuffle(shuffled_cards);
    int n = receivers.size();
    map<T, set<V>> answer_map;
    int i = 0;
    for(V card : shuffled_cards) {
        if(answer_map.find(receivers[i]) == answer_map.end()) {
            set<V> s;
            answer_map[receivers[i]] = s;
        }
        answer_map[receivers[i]].insert(card);
        i = (i + 1) % n;
    }
    return answer_map;
}

template<typename T, typename V> static map<T, V> deal_one(const vector<T> &receivers, const set<V> &cards) {
    vector<V> shuffled_cards = set_to_vector(cards);
    shuffle(shuffled_cards);
    map<T, V> answer_map;
    for(int i = 0; i < receivers.size(); ++i) {
        answer_map[receivers[i]] = shuffled_cards[i];
    }
    return answer_map;
}
