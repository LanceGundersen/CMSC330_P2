#include <iostream>
#include <sstream>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "greaterthan.h"
#include "lessthan.h"
#include "or.h"
#include "and.h"
#include "isequal.h"
#include "negate.h"

SubExpression::SubExpression(Expression* left, Expression* right)
{
	this->left = left;
	this->right = right;
}

Expression* SubExpression::parse(stringstream &in)
{
	Expression* left;
	Expression* right;
	char op, paren;

	left = Operand::parse(in);
	in >> op;

	if (op == '!')
	{
		in >> paren;
		return new Negate(left, NULL);
	}

	right = Operand::parse(in);

	if (op == ':')
	{
		in >> op;
		Expression* rightMost = Operand::parse(in);
		in >> paren;

		if ((int)rightMost->evaluate() == 0)
			return left;

		return right;
	}

	in >> paren;

	switch (op)
	{
		case '+':
			return new Plus(left, right);
		case '-':
			return new Minus(left, right);
		case '*':
			return new Times(left, right);
		case '/':
			return new Divide(left, right);
		case '>':
			return new GreaterThan(left, right);
		case '<':
			return new LessThan(left, right);
		case '|':
			return new Or(left, right);
		case '&':
			return new And(left, right);
		case '=':
			return new IsEqual(left, right);
	}
	return 0;
}
