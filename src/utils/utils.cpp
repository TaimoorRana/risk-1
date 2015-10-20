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
