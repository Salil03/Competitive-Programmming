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
        lll n, q;
        cin >> n >> q;
        vector<lll> a(n);
        for (lll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lll cutoff = max_element(a.begin(), a.end()) - a.begin();
        vector<pair<lll, lll>> start_end(n, {1, 0});
        lll maximum = a[0], idx = 0;
        for (lll i = 1; i < n; i++)
        {
            if (maximum > a[i])
            {
                start_end[idx].second = i;
            }
            else
            {
                maximum = a[i];
                idx = i;
                start_end[idx] = make_pair(i, i);
            }
        }
        while (q--)
        {
            lll i, k;
            cin >> i >> k;
            if (k >= cutoff)
            {
                if (i == cutoff + 1)
                {
                    cout << k - cutoff + (cutoff != 0) << "\n";
                }
                else
                {
                    cout << max(0LL, start_end[i - 1].second - start_end[i - 1].first + 1) << "\n";
                }
            }
            else
            {
                if (k >= start_end[i - 1].first && k <= start_end[i - 1].second)
                {
                    cout << k - start_end[i - 1].first + 1 << "\n";
                }
                else
                {
                    cout << 0 << "\n";
                }
            }
        }
    }
}