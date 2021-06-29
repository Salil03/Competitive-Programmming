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

void update(lll tree[], lll value, lll idx, lll curr, lll l, lll r)
{
    if (l == r - 1)
    {
        tree[curr] = value;
        return;
    }
    lll m = (l + r) / 2;
    if (idx < m)
    {
        update(tree, value, idx, 2 * curr + 1, l, m);
    }
    else
    {
        update(tree, value, idx, 2 * curr + 2, m, r);
    }
    tree[curr] = tree[2 * curr + 1] + tree[2 * curr + 2];
}

lll query(lll tree[], lll idx, lll l, lll r, lll t_l, lll t_r)
{
    if (l >= t_l && r <= t_r)
    {
        return tree[idx];
    }
    if (l < t_l && r <= t_l)
    {
        return 0;
    }
    if (l >= t_r && r > t_r)
    {
        return 0;
    }
    lll m = (l + r) / 2;
    return query(tree, 2 * idx + 1, l, m, t_l, t_r) + query(tree, 2 * idx + 2, m, r, t_l, t_r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w", stdout);
    lll n;
    cin >> n;
    lll arr[n];
    for (lll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    lll freq[n + 1];
    lll tree[4 * (n + 1)];
    lll final[n + 1];
    memset(freq, 0, sizeof freq);
    memset(tree, 0, sizeof tree);
    memset(final, 0, sizeof final);
    for (lll i = 0; i < n; i++)
    {
        freq[arr[i]]++;
        update(tree, freq[arr[i]], arr[i], 0, 0, n + 1);
        final[arr[i]] += query(tree, 0, 0, n + 1, arr[i] + 1, n + 1);
    }
    cout << 0 << "\n";
    lll sum = 0;
    for (lll i = 0; i < n - 1; i++)
    {
        sum += final[i];
        cout << sum << "\n";
    }
}