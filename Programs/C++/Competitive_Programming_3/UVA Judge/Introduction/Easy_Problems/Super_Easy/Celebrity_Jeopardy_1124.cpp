#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string input = "";
    while(getline(cin, input))
    {
        cout << input << "\n";
    }
    return 0;
}
