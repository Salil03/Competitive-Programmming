#include "std_lib_facilities.h"
int main()
{
    string previous = " "; // previous word; initialized to "not a word"
    string current;        //current word
    while (cin >> current)
    {
        if (previous == current)
            cout << "repeated word: " << current << "\n";
    previous = current;
    }
}