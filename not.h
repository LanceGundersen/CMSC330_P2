class Not: public SubExpression
{
public:
    Not(Expression* left, Expression* right): SubExpression(left, right)
    {
    }
    int evaluate()
    {
        if( ( (left->evaluate() > 0) || (right->evaluate() ) > 0)) {

            return 0;
        }

        return 1;
    }
};