#include <iostream>
#include <cstring>

// Follows the grammar '(' <operand> ':' <operand> '?' <operand> ')'
class Tern: public SubExpression
{
public:
    Expression *tern;
    char qmark;

    Tern(Expression* left, Expression* right, Expression *tern): SubExpression(left, right)
    {
        // There is alwasy an expression after the ? so we need to get it
        this->tern = tern;
    }
    int evaluate()
    {

        // upon creation get rid of ? and whitespace

        //cin >> qmark;
        // left = 1
        int tvalue = left->evaluate();
        // op = :
        // right = 2
        int fvalue = right->evaluate();
        // left (a > b)


        // parse the new expression
        // There is alwasy an expression after the ? so we need to get it
        //newExp = SubExpression::parse();

        // Ge object
        //newExp = SubExpression::parse();
        if(tern->evaluate() > 0) {

            return tvalue;
        }
        else {

            return fvalue;
        }




    }
};