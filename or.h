class Or : public SubExpression
{
public:
	Or(Expression* left, Expression* right) : SubExpression(left, right)
	{
	}
	double evaluate()
	{
		if (left->evaluate() != 0 || right->evaluate() != 0)
			return 1;

		return 0;
	}
};
