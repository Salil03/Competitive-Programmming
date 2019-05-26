#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 0;
    cin >> t;
    string n = "";
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << int(n.front() - '0') + int(n.back() - '0') << "\n";
    }
}