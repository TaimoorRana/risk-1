#include "textutils.h"
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <sstream>


TextUtils::TextUtils()
{

}

TextUtils::~TextUtils()
{

}


vector<string> TextUtils::split(const string &input, char delimiter)
{
    vector<string> elements;
    string token;
    stringstream input_stringstream(input);

    while(getline(input_stringstream,token,delimiter))
    {
         elements.push_back(token);
    }

    return elements;
}

void TextUtils::remove_empty_spaces(string &input)
{
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
}


