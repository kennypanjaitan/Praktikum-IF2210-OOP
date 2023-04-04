#include "Expression.cpp"
#include "AddExpression.cpp"

int main() {
  Expression* e = new AddExpression(
    new TerminalExpression(4),
    new TerminalExpression(6)
  );
  e->solve();
}
