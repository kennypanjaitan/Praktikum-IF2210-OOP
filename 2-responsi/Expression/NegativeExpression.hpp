#ifndef __NEGATIVEEXPRESSION_HPP__
#define __NEGATIVEEXPRESSION_HPP__

#include "Expression.hpp"

class NegativeExpression : public UnaryExpression {
public:
    NegativeExpression(Expression* x);
    int solve();
};

#endif