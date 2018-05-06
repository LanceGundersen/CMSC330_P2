class Times : public SubExpression
{
public:
	Times(Expression* left, Expression* right) : SubExpression(left, right)
	{
	}
	double evaluate()
	{
		return left->evaluate() * right->evaluate();
	}
};

