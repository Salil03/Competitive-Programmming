// Indian Currency Modification
#include "std_lib_facilities.h"
int main()
{
    cout << "How many rupee(s) do you have ? \n";
    double rupees;
    cin >> rupees;
    cout << "How many paise(s) do you have ? \n";
    double paise;
    cin >> paise;
    cout << "You have " << rupees << " rupee(s).\n"
         << "You have " << paise << " paise(s).\n"
         << "The value of all your coins is " << rupees + (paise / 100)
         << " rupees.\n";
}