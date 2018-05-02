class Eq: public SubExpression
{
public:
    Eq(Expression* left, Expression* right): SubExpression(left, right)
    {
    }
    int evaluate()
    {
        const char *ltype = typeid(left).name();
        const char *rtype = typeid(right).name();

        if(std::strcmp(ltype, "Literal") > 0 && std::strcmp(rtype, "Literal") > 0)
        {
            if(left->evaluate() == right->evaluate()) {

                return 1;
            }
            else {

                return 0;
            }
        }


        return 0;
    }
};