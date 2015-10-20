#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <time.h>
#include <set>
#include <stdlib.h>
#include <set>
#include <map>

using namespace std;

template<typename T> static void shuffle(vector<T> &in);

template<typename T> static vector<T> set_to_vector(const set<T> & the_set);

template<typename T> static set<T> get_n_random(const set<T> &the_set, int n);

template<typename T, typename V> static map<T, set<V>> deal(const vector<T> &receivers, const set<V> &cards);

template<typename T, typename V> static map<T, set<V>> deal_one(const vector<T> &receivers, const set<V> &cards);

#endif // UTILS_H
