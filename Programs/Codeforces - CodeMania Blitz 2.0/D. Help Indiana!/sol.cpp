#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef unsigned long long uu;
typedef long long int lll;
typedef unsigned long long int uuu;

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

typedef tree<lll, null_type, less<lll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pair<lll, lll>, null_type, less<pair<lll, lll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
// gp_hash_table<int, int> table; unordered map

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
    string s1, s2;
    while (t--)
    {
        cin >> s1 >> s2;
        lll dp[s2.length() + 2][2];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (lll i = 1; i <= (lll)s1.length(); i++)
        {
            for (lll j = 0; j <= (lll)s2.length(); j++)
            {
                if (j == 0 && s1[i - 1] == '?')
                {
                    dp[j][1] = (26 * dp[j][0]) % MOD;
                }
                else if (j == 0)
                {
                    dp[j][1] = dp[j][0] % MOD;
                }
                else if (s1[i - 1] != '?')
                {
                    if (s1[i - 1] == s2[j - 1])
                    {
                        dp[j][1] = (dp[j - 1][0] + dp[j][0]) % MOD;
                    }
                    else
                    {
                        dp[j][1] = dp[j][0] % MOD;
                    }
                }
                else if (s1[i - 1] == '?')
                {
                    dp[j][1] = (dp[j - 1][0] + 26 * dp[j][0]) % MOD;
                }
            }
            for (lll j = 0; j <= (lll)s2.length(); j++)
            {
                dp[j][0] = dp[j][1] % MOD;
            }
        }
        cout << dp[s2.length()][0] % MOD << "\n";
    }
}