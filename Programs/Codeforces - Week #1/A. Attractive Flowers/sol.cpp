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
    lll n;
    cin >> n;
    vector<lll> a(n);
    for (lll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n & 1)
    {
        lll sum = 0;
        for (lll i = 0; i < n; i++)
        {
            if (a[i] & 1)
            {
                sum += a[i];
            }
            else
            {
                sum += a[i] - 1;
            }
        }
        cout << sum << "\n";
    }
    else
    {
        lll sum = 0;
        for (lll i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0)
            {
                a[i] -= 1;
            }
        }
        sort(a.begin(), a.end());
        for (lll i = 1; i < n; i++)
        {
            sum += a[i];
        }
        cout << sum << "\n";
    }
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
}