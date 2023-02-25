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

lll cnt(vector<lll> &table, lll n, lll d)
{
    lll length = d - table[n - 2] - 1;
    lll maximum = table[0] - 1;
    lll minimum = table[0] - 1;
    for (int i = 1; i < n - 1; i++)
    {
        maximum = max(maximum, table[i] - table[i - 1] - 1);
        minimum = min(minimum, table[i] - table[i - 1] - 1);
    }
    return min(minimum, max(length, (maximum - 1) / 2));
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
    while (t--)
    {
        lll n, d;
        cin >> n >> d;
        vector<lll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lll idx = 0, minimum = a[0] - 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] - a[i - 1] - 1 < minimum)
            {
                minimum = a[i] - a[i - 1] - 1;
                idx = i;
            }
        }
        lll ans = minimum;
        if (idx == 0)
        {
            vector<lll> table;
            for (lll i = 0; i < n; i++)
            {
                if (i != idx)
                {
                    table.emplace_back(a[i]);
                }
            }
            ans = max(ans, cnt(table, n, d));
        }
        else
        {
            vector<lll> table;
            for (lll i = 0; i < n; i++)
            {
                if (i != idx)
                {
                    table.emplace_back(a[i]);
                }
            }
            ans = max(ans, cnt(table, n, d));
            table[idx - 1] = a[idx];
            ans = max(ans, cnt(table, n, d));
        }
        cout << ans << "\n";
    }
}