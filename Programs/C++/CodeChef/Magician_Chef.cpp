#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n, x, s;
        cin >> n >> x >> s;
        int ans = x;
        int p = 0, q = 0;
        while (s--)
        {
            cin >> p >> q;
            if (p == ans)
            {
                ans = q;
            }
            else if (q == ans)
            {
                ans = p;
            }
        }
        cout << ans << "\n";
    }
}