#include <cassert>

class Divide : public SubExpression
{
public:
	Divide(Expression* left, Expression* right) : SubExpression(left, right)
	{
	}
	double evaluate()
	{
		assert(right->evaluate() != 0);
		return left->evaluate() / right->evaluate();
	}
};
