#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int t = 0, n = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << int(sqrt(n)) << "\n";
    }
}