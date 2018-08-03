#include "std_lib_facilities.h"
int main() {
  cout << "Enter a operation(+,-,/,*) and two operands(floats): \n";
  string operand;
  double val1, val2;
  cin >> operand >> val1 >> val2;
  if (operand == "+") {
    cout << val1 << " + " << val2 << " = " << val1 + val2;
  }
  if (operand == "-") {
    cout << val1 << " - " << val2 << " = " << val1 - val2;
  }
  if (operand == "*") {
    cout << val1 << " * " << val2 << " = " << val1 * val2;
  }
  if (operand == "/") {
    cout << val1 << " / " << val2 << " = " << val1 / val2;
  }
}