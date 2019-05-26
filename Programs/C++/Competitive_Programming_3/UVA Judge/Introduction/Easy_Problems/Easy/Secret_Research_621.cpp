#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        if(s == "1" || s == "4" || s=="78")
        {
            cout << "+\n";
        }
        else if(s.at(s.length() - 1) == '5' && s.at(s.length() - 2) == '3')
        {
            cout << "-\n";
        }
        else if(s[0] == '9' && s.at(s.length() - 1) == '4')
        {
            cout << "*\n";
        }
        else
        {
            cout << "?\n";
        }
    }
}
