#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 0;
    cin >> t;
    string e = "";
    while (t--)
    {
        cin >> e;
        int bracket = 0;
        string arr[e.size() + 5];
        for (auto i : e)
        {
            if (i == '(')
            {
                bracket++;
            }
            else if (i == ')')
            {
                bracket--;
                cout << arr[bracket];
                arr[bracket] = "";
            }
            else if (i == '+' || i == '*' || i == '/' || i == '-' || i == '^')
            {
                arr[bracket - 1] += i;
            }
            else
            {
                cout << i;
            }
        }
        cout << "\n";
    }
}