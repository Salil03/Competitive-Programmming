#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0, x = 0, y = 0, ans = 0;
    cin >> n;
    if (n % 2 == 0)
    {
        for (int i = 0; i < n / 2; i++)
        {
            cin >> x >> y;
            ans += min(x, y);
        }
    }
    else
    {
        for (int i = 0; i < (n - 1) / 2; i++)
        {
            cin >> x >> y;
            ans += min(x, y);
        }
        cin >> x;
        ans += x;
    }
    cout << ans;
}