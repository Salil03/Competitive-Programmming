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

vector<lll> indices[201];
lll dp[300003][201];
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
        vector<lll> arr(n);
        for (lll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (lll i = 0; i <= 200; i++)
        {
            indices[i].clear();
        }
        indices[arr[0]].emplace_back(0);
        for (lll j = 0; j <= 200; j++)
        {
            dp[0][j] = 0;
        }
        dp[0][arr[0]] = 1;
        for (lll i = 1; i < n; i++)
        {
            for (lll j = 0; j <= 200; j++)
            {
                dp[i][j] = dp[i - 1][j];
            }
            dp[i][arr[i]] = 1;
            for (lll j = 0; j <= 200; j++)
            {
                for (lll k = indices[j].size() - 1; k >= 0; k--)
                {
                    if ((j ^ i) < (arr[i] ^ indices[j][k]))
                    {
                        dp[i][arr[i]] = max(dp[i][arr[i]], dp[indices[j][k]][j] + 1);
                        break;
                    }
                }
            }
            indices[arr[i]].emplace_back(i);
        }
        lll maximum = 0;
        for (lll i = 0; i < n; i++)
        {
            for (lll j = 0; j <= 200; j++)
            {
                maximum = max(maximum, dp[i][j]);
            }
        }
        cout << maximum << "\n";
    }
}