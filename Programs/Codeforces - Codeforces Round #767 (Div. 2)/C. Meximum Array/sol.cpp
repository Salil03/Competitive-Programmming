#include "bits/stdc++.h"
typedef long long ll;
typedef unsigned long long uu;
typedef long long int lll;
typedef unsigned long long int uuu;
using namespace std;

#if defined(DEBUG)
#include "prettyprint.hpp"
#define dbga(x, n) cerr << "\n" \
                        << (#x) << " is " << pretty_print_array(x, n) << endl
#define dbg(x) cerr << "\n" \
                    << (#x) << " is " << x << endl
#endif

#if !defined(DEBUG)
#define dbga(x, n)
#define dbg(x)
#endif

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution < lll>(low, high)(rng)
//uniform_real_distribution<double>(low, high)(rng)
#define cel(x, y) 1 + ((x - 1) / y)
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const long long int INF = 0x3f3f3f3f3f3f3f3f;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll t;
    cin >> t;
    while (t--)
    {
        lll n;
        cin >> n;
        lll arr[n];
        bool seen[n + 1];
        lll seen_behind[n + 1];
        memset(seen, 0, sizeof(seen));
        memset(seen_behind, 0, sizeof(seen_behind));
        for (lll i = 0; i < n; i++)
        {
            cin >> arr[i];
            seen_behind[arr[i]]++;
        }
        lll prefix[n], curr = 0;
        vector<lll> ans;
        lll idx = 0;
        bool flag = true;
        while (idx != n)
        {
            seen_behind[arr[idx]]--;
            if (flag)
            {
                if (arr[idx] == 0)
                {
                    prefix[idx] = 1;
                    seen[0] = true;
                    curr = 1;
                }
                else
                {
                    prefix[idx] = 0;
                    seen[arr[idx]] = true;
                    curr = 0;
                }
                flag = false;
                if (seen_behind[curr] == 0)
                {
                    ans.emplace_back(curr);
                    seen[0] = false;
                    seen[arr[idx]] = false;
                    flag = true;
                }
                idx++;
                continue;
            }

            if (arr[idx] != prefix[idx - 1])
            {
                prefix[idx] = prefix[idx - 1];
                seen[arr[idx]] = true;
            }
            else
            {
                seen[arr[idx]] = true;
                while (seen[curr])
                {
                    curr++;
                }
                prefix[idx] = curr;
                if (seen_behind[curr] == 0 && idx != n - 1)
                {
                    ans.emplace_back(curr);
                    memset(seen, 0, sizeof(seen));
                    flag = true;
                }
                dbg(curr);
                dbg(idx);
            }
            idx++;
            if (idx == n)
            {
                ans.emplace_back(curr);
            }
        }
        cout << ans.size() << "\n";
        for (auto k : ans)
        {
            cout << k << " ";
        }
    }
}
