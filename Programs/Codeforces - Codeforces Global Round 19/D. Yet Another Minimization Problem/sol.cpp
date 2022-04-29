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
// uniform_int_distribution < lll>(low, high)(rng)
// uniform_real_distribution<double>(low, high)(rng)
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
        vector<lll> a(n), b(n);
        for (lll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lll i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        if (n == 1)
        {
            cout << 0 << "\n";
            continue;
        }
        lll sum1 = 0, tot_sum = 0;
        for (lll i = 0; i < n; i++)
        {
            sum1 += a[i] * a[i] + b[i] * b[i];
            tot_sum += a[i] + b[i];
        }
        sum1 *= (n - 2);
        bool dp[n + 2][tot_sum + 2];
        memset(dp, 0, sizeof(dp));
        dp[0][a[0]] = true;
        dp[0][b[0]] = true;
        for (lll i = 1; i < n; i++)
        {
            for (lll j = 1; j <= tot_sum; j++)
            {
                if (j - a[i] >= 0)
                {
                    dp[i][j] |= dp[i - 1][j - a[i]];
                }
                if (j - b[i] >= 0)
                {
                    dp[i][j] |= dp[i - 1][j - b[i]];
                }
            }
        }
        lll sum2 = INT_MAX;
        for (lll i = 1; i <= tot_sum; i++)
        {
            if (dp[n - 1][i])
            {
                dbg(i);
                sum2 = min(sum2, i * i + (tot_sum - i) * (tot_sum - i));
            }
        }
        cout << sum1 + sum2 << "\n";
    }
}