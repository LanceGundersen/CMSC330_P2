#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"
#include <sstream>
#include <fstream>

SymbolTable symbolTable;

void parseAssignments(stringstream &in);

int main()
{
    const int SIZE = 256;
    Expression* expression;
    char paren, comma, line[SIZE];

    ifstream fin("input.txt");
    fin.open("input.txt");

    while(true) {

        symbolTable.init();

        fin.getline(line, SIZE);

        if(!fin) {

            break;
        }

        stringstream in(line, ios_base::in);

        in >> paren;
        cout << line << " ";
        expression = SubExpression::parse(in);
        in >> comma;
        parseAssignments(in);
        int result = expression->evaluate();
        cout << "Value = " << result << endl;


    }
    return 0;
}

void parseAssignments(stringstream &in)
{
    char assignop, delimiter, junk;
    string variable;
    int value;

    symbolTable.init();
    do
    {
        variable = parseName(in);
         in >> ws >> assignop >> value >> delimiter;
        symbolTable.insert(variable, value);
    }
    while (delimiter == ',');
}

