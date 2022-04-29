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

unordered_map<lll, lll> mp;

lll recur(lll idx)
{
    if (idx == 0)
    {
        return 0;
    }
    if (idx == 1)
    {
        return 1;
    }
    if (idx == 2)
    {
        return 1;
    }
    if (mp.find(idx) != mp.end())
    {
        return mp[idx];
    }
    if (idx % 2 == 0)
    {
        mp[idx] = recur(idx / 2);
    }
    else
    {
        mp[idx] = 2 * recur(idx / 2) + 1;
    }
    return mp[idx];
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
        if (n == 0)
        {
            cout << 1 << "\n";
            continue;
        }
        cout << 4 * recur(n) << "\n";
    }
}