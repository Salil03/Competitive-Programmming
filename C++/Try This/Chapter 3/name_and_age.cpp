#include "std_lib_facilities.h"
// read name and age and print both(age in months)
int main() {
  cout << "Please enter your first name and age\n";
  string first_name = "Nothing"; // string variable
  double age = -1;               // integer variable
  cin >> first_name >> age;      // read a string followed by an integer
  cout << "Hello, " << first_name << "(age " << age * 12 << " months)\n";
}