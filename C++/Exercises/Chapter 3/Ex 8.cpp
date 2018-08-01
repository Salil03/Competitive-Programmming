#include <std_lib_facilities.h>
int main()
{
    cout << "Enter a integer: ";
    int number;
    cin >> number;
    if (number % 2 == 0)
    {
        cout << number << " is an even number.";
    }
    else
    {
        cout << number << " is an odd number.";
    }
}
