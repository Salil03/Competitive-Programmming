#include "std_lib_facilities.h"
int main()
{
    cout << "Enter the spelling of a number\n";
    string number;
    cin >> number;
    if (number == "zero")
    {
        cout << 0;
        return 0;
    }
    if (number == "one")
    {
        cout << 1;
        return 0;
    }
    if (number == "two")
    {
        cout << 2;
        return 0;
    }
    if (number == "three")
    {
        cout << 3;
        return 0;
    }
    if (number == "four")
    {
        cout << 4;
        return 0;
    }
    else
    {
        cout << "not a number I know";
        return 0;
    }
}