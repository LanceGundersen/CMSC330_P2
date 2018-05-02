#include <cctype>
#include <iostream>
#include <string>
using namespace std;

#include "parse.h"
#include <sstream>
#include <fstream>

string parseName(stringstream &in)
{
    char alnum;
    string name = "";

    in >> ws;
    while (isalnum(in.peek()))
    {
        in >> alnum;
        name += alnum;
    }
    return name;
}