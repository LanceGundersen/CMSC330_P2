class And : public SubExpression {
	public:
		And(Expression* left, Expression* right) : SubExpression(left, right)
		{
		}
		double evaluate()
		{
			if (left->evaluate() == 0 || right->evaluate() == 0)
				return 0;

			return 1;
		}
};

