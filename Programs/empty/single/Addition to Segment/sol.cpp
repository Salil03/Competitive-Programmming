// OPTIMIZATIONS
//#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
//#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
// OPTIMIZATIONS
#include "bits/stdc++.h"
typedef long long ll;
typedef unsigned long long uu;
typedef long long int lll;
typedef unsigned long long int uuu;
using namespace std;

#if defined(DEBUG)
#include "prettyprint.hpp"
#define _GLIBCXX_DEBUG
#define dbga(x, n) cerr << "\n" \
                        << (#x) << " is " << pretty_print_array(x, n) << endl
#define dbg(x) cerr << "\n" \
                    << (#x) << " is " << x << endl
#endif

#if !defined(DEBUG)
#define dbga(x, n)
#define dbg(x)
#endif

#define cel(x, y) 1 + ((x - 1) / y)
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const long long int INF = 0x3f3f3f3f3f3f3f3f;

/*
$alil03

URL: url

Solution Begins here
*/

void update(vector<lll> &lazy, lll value, lll idx, lll l, lll r, lll t_l, lll t_r)
{
    if (l >= t_l && r <= t_r)
    {
        lazy[idx] += value;
    }
    else if (!(l < t_l && r <= t_l) && !(r > t_r && l >= t_r))
    {
        lll m = (l + r) / 2;
        update(lazy, value, 2 * idx + 1, l, m, t_l, t_r);
        update(lazy, value, 2 * idx + 2, m, r, t_l, t_r);
    }
}
lll query(vector<lll> &lazy, lll idx, lll curr, lll l, lll r)
{
    if (l == r - 1)
    {
        return lazy[curr];
    }
    lll m = (l + r) / 2;
    if (idx < m)
    {
        return lazy[curr] + query(lazy, idx, 2 * curr + 1, l, m);
    }
    else
    {
        return lazy[curr] + query(lazy, idx, 2 * curr + 2, m, r);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll n, m;
    cin >> n >> m;
    vector<lll> lazy(4 * n, 0);
    while (m--)
    {
        lll i;
        cin >> i;
        if (i == 1)
        {
            lll l, r, v;
            cin >> l >> r >> v;
            update(lazy, v, 0, 0, n, l, r);
            dbg(lazy);
        }
        else
        {
            lll idx;
            cin >> idx;
            cout << query(lazy, idx, 0, 0, n) << "\n";
        }
    }
}