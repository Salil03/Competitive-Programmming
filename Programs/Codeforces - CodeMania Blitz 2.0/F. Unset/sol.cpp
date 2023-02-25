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

vector<lll> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

lll check(lll num)
{
    lll maximum = (1 << 15);
    lll ans = 0;
    for (lll i = 1; i < maximum; i++)
    {
        lll lowest = 1;
        lll cnt = 0;
        for (lll j = 0; j < 15; j++)
        {
            if (i & (1 << j))
            {
                cnt++;
                lowest = lcm(lowest, primes[j]);
            }
        }
        if (cnt & 1)
        {
            ans += num / lowest;
        }
        else
        {
            ans -= num / lowest;
        }
    }
    return ans;
}

lll last_true(lll lo, lll hi, lll val)
{
    // if none of the values in the range work, return lo - 1
    lll ans = -1;
    while (lo <= hi)
    {
        lll mid = (lo + hi) / 2;
        if (check(mid) <= val)
        {
            ans = max(ans, mid);
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll x;
    cin >> x;
    long long int high = 1e18;
    high += 6;
    cout << last_true(1, high, x);
}