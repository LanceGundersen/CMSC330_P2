class IsEqual : public SubExpression
{
public:
	IsEqual(Expression* left, Expression* right) : SubExpression(left, right)
	{
	}
	double evaluate()
	{
		if (left->evaluate() == right->evaluate())
			return 1;

		return 0;
	}
};
