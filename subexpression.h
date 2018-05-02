#include <fstream>
#include <sstream>

class SubExpression: public Expression
{
public:
    SubExpression(Expression* left, Expression* right);
    static Expression* parse(stringstream &in);
protected: 
    Expression* left;
    Expression* right;
};    