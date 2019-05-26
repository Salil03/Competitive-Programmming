#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 0;
    cin >> t;
    string s = "";
    for (int i = 0; i < t; i++)
    {
        cin >> s;
        reverse(s.begin(), s.end());
        cout << stoi(s) << "\n";
    }
}