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
    while (t--)
    {
        lll m;
        cin >> m;
        char arr[2][m];
        for (lll i = 0; i < 2; i++)
        {
            for (lll j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        if (m == 1)
        {
            cout << "YES\n";
            continue;
        }
        bool dp[2][m];
        memset(dp, 0, sizeof dp);
        dp[0][0] = (arr[0][0] == 'B');
        dp[1][0] = (arr[1][0] == 'B');
        for (lll i = 1; i < m - 1; i++)
        {
            if (arr[0][i] == 'W')
            {
                dp[0][i] = 0;
            }
            else
            {
                if ((arr[0][i - 1] == 'B' && arr[1][i - 1] == 'B' && dp[1][i - 1]) || (arr[0][i - 1] == 'B' && arr[1][i - 1] == 'W' && dp[0][i - 1]))
                {
                    dp[0][i] = 1;
                }
                else
                {
                    dp[0][i] = 0;
                }
            }
            if (arr[1][i] == 'W')
            {
                dp[1][i] = 0;
            }
            else
            {
                if ((arr[1][i - 1] == 'B' && arr[0][i - 1] == 'B' && dp[0][i - 1]) || (arr[1][i - 1] == 'B' && arr[0][i - 1] == 'W' && dp[1][i - 1]))
                {
                    dp[1][i] = 1;
                }
                else
                {
                    dp[1][i] = 0;
                }
            }
        }
        if ((arr[0][m - 1] == 'B' && arr[1][m - 1] == 'B' && (dp[0][m - 2] || dp[1][m - 2])) || (arr[0][m - 1] == 'B' && arr[1][m - 1] == 'W' && ((dp[0][m - 2] && arr[1][m - 2] == 'W') || (dp[1][m - 2] && arr[0][m - 2] == 'B'))) || (arr[1][m - 1] == 'B' && arr[0][m - 1] == 'W' && ((dp[1][m - 2] && arr[0][m - 2] == 'W') || (dp[0][m - 2] && arr[1][m - 2] == 'B'))))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}