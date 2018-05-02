class Or: public SubExpression
{
public:
    Or(Expression* left, Expression* right): SubExpression(left, right)
    {
    }
    int evaluate()
    {
        if( (left->evaluate() || right->evaluate() > 0)) {

            return 1;
        }

        return 0;
    }
};