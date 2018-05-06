class GreaterThan : public SubExpression
{
public:
	GreaterThan(Expression* left, Expression* right) : SubExpression(left, right)
	{
	}
	double evaluate()
	{
		if (left->evaluate() > right->evaluate())
			return 1;

		return 0;
	}
};
