#include <string>
#include <vector>
using namespace std;

#include "symboltable.h"


void SymbolTable::insert(string variable, int value)
{
    const Symbol& symbol = Symbol(variable, value);
    elements.push_back(symbol);
}

int SymbolTable::lookUp(string variable) const
{
    for (int i = 0; i < elements.size(); i++)
        if (elements[i].variable == variable)
             return elements[i].value;
    return -1;
}

void SymbolTable::init()
{
    elements.clear();
}
