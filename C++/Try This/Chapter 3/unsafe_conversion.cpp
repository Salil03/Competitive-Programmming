#include <std_lib_facilities.h>
int main()
{
    double d = 0;
    while (cin >> d)
    {                                  // repeat the statements below
                                       // as long as we type in numbers
        int i = d;                     // try to squeeze a double into an int
        char c = i;                    // try to squeeze an int into a char
        int i2 = c;                    // get the integer value of th char
        cout << "d==" << d             // get the double
             << "i==" << i             // converted to int
             << "i2==" << i2           // int value of char
             << "char(" << c << ")\n"; // the char
    }
}