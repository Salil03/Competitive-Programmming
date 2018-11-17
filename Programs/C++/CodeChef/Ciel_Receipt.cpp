#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 0, p = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int ans = 0;
        cin >> p;
        while (p != 0)
        {
            if ((p & -p) > 2045)
            {
                ans += (p & -p) / 2048;
            }
            else
            {
                ans++;
            }
            p = p & (p - 1);
        }
        cout << ans << "\n";
    }
}