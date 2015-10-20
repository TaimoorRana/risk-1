#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

using namespace std;


class TextUtils
{
public:

    TextUtils();
    ~TextUtils();

    vector<string> split(const string &s, char delimiter);
    void remove_empty_spaces(string &input);

};

#endif // UTILS_H
