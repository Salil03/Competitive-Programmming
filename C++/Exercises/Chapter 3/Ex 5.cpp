#include "std_lib_facilities.h"

int main()
{
  cout << "Enter two floats: ";
  double val1, val2;
  cin >> val1 >> val2;
  if (val1 > val2)
  {
    cout << val1 << " is greater than " << val2 << "\n";
  }
  if (val2 > val1)
  {
    cout << val2 << " is greater than " << val1 << "\n";
  }
  if (val2 == val1)
  {
    cout << "Both integers are equal"
         << "\n";
  }

  cout << "Sum is " << val1 + val2 << "\n"
       << "Difference is " << val1 - val2 << "\n"
       << "Product is " << val1 * val2 << "\n"
       << "Ratio is " << val1 / val2 << "\n";
}