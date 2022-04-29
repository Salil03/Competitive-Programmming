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
    lll cost[1006];
    cost[1] = 0;
    for (lll i = 2; i <= 1000; i++)
    {
        cost[i] = INT_MAX;
        for (lll j = max(i / 2, 1LL); j < i; j++)
        {
            if (j < i - j)
            {
                continue;
            }
            lll val = j / (i - j);
            if (j / val == i - j)
            {
                cost[i] = min(cost[i], cost[j] + 1);
            }
        }
    }
    while (t--)
    {
        lll n, k;
        cin >> n >> k;
        lll b[n], c[n];
        for (lll i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        for (lll i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        if (k > 12 * n)
        {
            lll sum = 0;
            for (lll i = 0; i < n; i++)
            {
                sum += c[i];
            }
            cout << sum << "\n";
            continue;
        }
        lll dp[k + 1];
        memset(dp, 0, sizeof(dp));
        for (lll i = 0; i < n; i++)
        {
            for (lll j = k; j >= cost[b[i]]; j--)
            {
                dp[j] = max(dp[j], c[i] + dp[j - cost[b[i]]]);
            }
        }

        cout << dp[k] << "\n";
    }
}