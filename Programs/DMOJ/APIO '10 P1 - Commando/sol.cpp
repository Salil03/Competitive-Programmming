// OPTIMIZATIONS
//#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
//#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
// OPTIMIZATIONS
#include "bits/stdc++.h"
typedef long long ll;
typedef unsigned long long uu;
typedef long long int lll;
typedef unsigned long long int uuu;
using namespace std;

#if defined(DEBUG)
#include "prettyprint.hpp"
#define _GLIBCXX_DEBUG
#define dbga(x, n) cerr << "\n" \
                        << (#x) << " is " << pretty_print_array(x, n) << endl
#define dbg(x) cerr << "\n" \
                    << (#x) << " is " << x << endl
#endif

#if !defined(DEBUG)
#define dbga(x, n)
#define dbg(x)
#endif

#define cel(x, y) 1 + ((x - 1) / y)
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const long long int INF = 0x3f3f3f3f3f3f3f3f;

/*
$alil03

URL: url

Solution Begins here
*/
lll n, a, b, c;
// lll recur(lll idx, lll start_idx, lll arr[], lll pref[])
// {
//     if (idx == n)
//     {
//         return 0;
//     }
//     if (dp[idx][start_idx] != -1)
//     {
//         return dp[idx][start_idx];
//     }
//     lll ans = -10;
//     lll curr = arr[idx];
//     if (idx == 0)
//     {
//         ans = max(ans, a * curr * curr + b * curr + c + recur(idx + 1, idx, arr, pref));
//         return dp[idx][start_idx] = ans;
//     }
//     lll eff = 0;
//     if (start_idx == 0)
//     {
//         eff = pref[idx - 1];
//     }
//     else
//     {
//         eff = pref[idx - 1] - pref[start_idx - 1];
//     }
//     ans = max(ans, a * curr * curr + b * curr + c + recur(idx + 1, idx, arr, pref));
//     ans = max(ans, a * curr * curr + 2 * a * eff * curr + b * curr + recur(idx + 1, start_idx, arr, pref));
//     return dp[idx][start_idx] = ans;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    cin >> n >> a >> b >> c;
    lll arr[n], pref[n] = {0};
    for (lll i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i == 0)
        {
            pref[i] = arr[i];
        }
        else
        {
            pref[i] = arr[i] + pref[i - 1];
        }
    }
    lll dp[2][n + 2];
    memset(dp, 0, sizeof dp);
    for (lll idx = n; idx >= 0; idx--)
    {
        lll curr = arr[idx];
        if (idx == 0)
        {
            dp[idx % 2][0] = a * curr * curr + b * curr + c + dp[(idx + 1) % 2][idx];
            continue;
        }
        for (lll start_idx = idx - 1; start_idx >= 0; start_idx--)
        {

            if (idx == n)
            {
                dp[idx % 2][start_idx] = 0;
                continue;
            }
            lll ans = -10;
            lll eff = 0;
            if (start_idx == 0)
            {
                eff = pref[idx - 1];
            }
            else
            {
                eff = pref[idx - 1] - pref[start_idx - 1];
            }
            ans = max(ans, a * curr * curr + b * curr + c + dp[(idx + 1) % 2][idx]);
            ans = max(ans, a * curr * curr + 2 * a * eff * curr + b * curr + dp[(idx + 1) % 2][start_idx]);
            dp[idx % 2][start_idx] = ans;
        }
    }
    cout << dp[0][0];
}