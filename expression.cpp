#include "expression.h"


double Number::evaluate ()const
{
    return value;
}


double BinaryOperation::Addition()const
{
    return left->evaluate() + right->evaluate();
}
double BinaryOperation::Subtraction()const
{
    return left->evaluate() - right->evaluate();
}
double BinaryOperation::Multiplication()const
{
    return left->evaluate() * right->evaluate();
}
double BinaryOperation::Division()const
{
    return left->evaluate() / right->evaluate();
}
double BinaryOperation::evaluate ()const
{
    switch(op)
    {
        case '+': return Addition();
        case '-': return Subtraction();
        case '*': return Multiplication();
        case '/': return Division();
    }
}
BinaryOperation::~BinaryOperation()
{
    delete left;
    delete right;
}
