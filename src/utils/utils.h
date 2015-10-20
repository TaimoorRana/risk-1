#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <time.h>
#include <set>
#include <stdlib.h>
#include <set>

using namespace std;

template<typename T> static void shuffle(vector<T> &in);

template<typename T> static vector<T> set_to_vector(const set<T> & the_set);

#endif // UTILS_H
