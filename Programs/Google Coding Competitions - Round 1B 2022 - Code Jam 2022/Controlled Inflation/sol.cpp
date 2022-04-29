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
lll n, p;

lll table[1008][2];

lll dp(vector<vector<lll>> &arr, lll idx, bool last_rev) // last reversed
{
    if (idx == n + 1)
    {
        return 0;
    }
    if (table[idx][last_rev] != -1)
    {
        return table[idx][last_rev];
    }
    lll ans = 0;
    for (lll i = 1; i < p; i++)
    {
        ans += abs(arr[idx][i] - arr[idx][i - 1]);
    }
    if (last_rev)
    {
        ans += min(abs(arr[idx][0] - arr[idx - 1][0]) + dp(arr, idx + 1, 0), abs(arr[idx][p - 1] - arr[idx - 1][0]) + dp(arr, idx + 1, 1));
    }
    else
    {
        ans += min(abs(arr[idx][0] - arr[idx - 1][p - 1]) + dp(arr, idx + 1, 0), abs(arr[idx][p - 1] - arr[idx - 1][p - 1]) + dp(arr, idx + 1, 1));
    }
    return table[idx][last_rev] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll t;
    cin >> t;
    for (lll test = 1; test <= t; test++)
    {
        cin >> n >> p;
        for (lll i = 0; i <= n + 3; i++)
        {
            table[i][0] = -1;
            table[i][1] = -1;
        }
        vector<vector<lll>> arr(n, vector<lll>(p));
        for (lll i = 0; i < n; i++)
        {
            for (lll j = 0; j < p; j++)
            {
                cin >> arr[i][j];
            }
            sort(arr[i].begin(), arr[i].end());
        }
        arr.insert(arr.begin(), vector<lll>(p, 0));
        cout << "Case #" << test << ": " << dp(arr, 1, 0) << "\n";
    }
}