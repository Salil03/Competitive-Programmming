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

lll root(uuu d)
{
    uuu low = 0, high = d;
    while (low <= high)
    {
        uuu mid = (high + low) / 2;
        // dbg(mid);
        if (mid == 0 && d != 0)
        {
            low = mid + 1;
        }
        else if (mid == 0 && d == 0)
        {
            return 0;
        }
        else if (d % mid == 0 && mid * mid == d)
        {
            return (lll)mid;
        }
        else if (d % mid == 0)
        {
            if (mid < d / mid)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        else
        {
            if (mid < (d / mid) + 1)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

lll cnt(vector<lll> &arr, lll x)
{
    auto low = lower_bound(arr.begin(), arr.end(), x);
    if (low == arr.end() || (*low) != x)
    {
        return 0;
    }
    auto high = upper_bound(low, arr.end(), x);
    return (high - low);
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
        lll n;
        cin >> n;
        vector<lll> arr(n);
        for (lll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        lll q;
        cin >> q;
        while (q--)
        {
            lll x, y;
            cin >> x >> y;
            uuu d = 0;
            d += x * x;
            if ((lll)d < 4 * y)
            {
                cout << 0 << " ";
                continue;
            }
            d -= 4 * y;
            // dbg(d);
            lll deter = root(d);
            // dbg(deter);
            if (deter == -1 || (x + deter) % 2 != 0)
            {
                cout << 0 << " ";
                continue;
            }
            lll r1 = (x + deter) / 2;
            lll r2 = (x - deter) / 2;
            // dbg(r1);
            // dbg(r2);
            lll cnt1 = cnt(arr, r1);
            lll cnt2 = cnt(arr, r2);
            if (r1 == r2)
            {
                cout << (cnt1 * (cnt1 - 1)) / 2 << " ";
            }
            else
            {
                cout << cnt1 * cnt2 << " ";
            }
        }
        cout << "\n";
    }
}