#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t = 0, a = 0, b = 0;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        cout << __gcd(a, b) << " " << (a * b) / __gcd(a, b) << "\n";
    }
}