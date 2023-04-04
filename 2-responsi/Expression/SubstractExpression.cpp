#include <iostream>
#include "SubstractExpression.hpp"
using namespace std;

SubstractExpression::SubstractExpression(Expression* left, Expression* right) : 
    BinaryExpression::BinaryExpression(left, right) {}

int SubstractExpression::solve() {
    return x->solve() - y->solve();
}