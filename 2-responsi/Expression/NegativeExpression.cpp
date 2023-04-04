#include <iostream>
#include "NegativeExpression.hpp"

using namespace std;

NegativeExpression::NegativeExpression(Expression* x) : 
    UnaryExpression::UnaryExpression(x) {}

int NegativeExpression::solve() {
    return -x->solve();
}