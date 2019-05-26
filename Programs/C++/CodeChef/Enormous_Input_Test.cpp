#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = 0, k = 0, t = 0, ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        ans += t % k == 0;
    }
    cout << ans;
}