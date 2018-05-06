class Minus : public SubExpression
{
public:
	Minus(Expression* left, Expression* right) : SubExpression(left, right)
	{
	}
	double evaluate()
	{
		return left->evaluate() - right->evaluate();
	}
};
