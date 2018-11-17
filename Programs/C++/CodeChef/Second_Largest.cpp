#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 0, a = 0, b = 0, c = 0;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        cout << (a + b + c) - max({a, b, c}) - min({a, b, c}) << "\n";
    }
}