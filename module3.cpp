#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#include "main.h"
#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

SymbolTable symbolTable;

int main()
{
	const int SIZE = 256;
	Expression* expression;
	char paren, comma, line[SIZE];

	ifstream fin("expression.txt");

	while (fin.good())
	{
		symbolTable = SymbolTable();
		fin.getline(line, SIZE);

		stringstream in(line, ios_base::in);
		in >> paren;
		cout << line << " ";

		try
		{
			expression = SubExpression::parse(in);
			in >> comma;
			parseVars(in);
			double result = expression->evaluate();
			cout << "Value = " << result << endl;
		}
		catch (int expressionException) {
			cout << "Invalid Expression" << endl;
			break;
		}
	}
	return 0;
}

void parseVars(stringstream& in)
{
	char assignop, delim;
	string var;
	double value;
	do
	{
		var = parseName(in);
		in >> ws >> assignop >> value >> delim;
		symbolTable.insert(var, value);
	} while (delim == ',');
}

