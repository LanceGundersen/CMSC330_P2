class Negate : public SubExpression
{
public:
	Negate(Expression* left, Expression* right) : SubExpression(left, right)
	{
	}
	double evaluate()
	{
		if (left->evaluate() == 0)
			return 1;

		return 0;
	}
};
