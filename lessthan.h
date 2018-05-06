class LessThan : public SubExpression
{
public:
	LessThan(Expression* left, Expression* right) : SubExpression(left, right)
	{
	}
	double evaluate()
	{
		if (left->evaluate() < right->evaluate())
			return 1;

		return 0;
	}
};
