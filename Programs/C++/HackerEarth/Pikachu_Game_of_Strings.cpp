#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += min((t[i] - s[i] + 26) % 26, 1 + (t[i] - (s[i] + 13) + 52) % 26);
    }
    cout << ans;
}