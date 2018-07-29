#include "std_lib_facilities.h"
// simple program to excercise operators
int main()
{
    cout << "Please enter a integer value ";
    int n;
    cin >> n;
    cout << "n == " << n
         << "\nn+1 == " << n + 1
         << "\nthree times n == " << 3 * n
         << "\ntwice n == " << n + n
         << "\nn squared == " << n * n
         << "\nhalf of n == " << n / 2;
    double n_float = n;
    cout << "\nsquare root of n == " << sqrt(n_float)
         << "\n"; // another name for newline ("end of line") in output
}