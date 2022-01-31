#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v[2];
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (i & 1)
            {
                v[1].push_back(x);
            }
            else
                v[0].push_back(x);
        }

        sort(v[0].begin(), v[0].end());
        sort(v[1].begin(), v[1].end(), greater<int>());

        int cnt0 = 0, ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (i & 1)
            {
                ans += cnt0 * v[1].back();
                cout << v[1].back() << " ";
                v[1].pop_back();
            }
            else
            {
                cnt0 += v[0].back();
                cout << v[0].back() << " ";
                v[0].pop_back();
            }
        }
        cout << endl;
        cout << ans << endl;
    }

    return 0;
}