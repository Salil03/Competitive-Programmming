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

void build(vector<lll> &a, vector<lll> &tree, lll idx, lll l, lll r)
{
    if (l == r - 1)
    {
        if (l < a.size())
        {
            tree[idx] = a[l];
            return;
        }
    }

    lll m = (l + r) / 2;
    build(a, tree, 2 * idx + 1, l, m);
    build(a, tree, 2 * idx + 2, m, r);
    tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
}

void update(vector<lll> &tree, lll idx, lll curr, lll value, lll l, lll r)
{
    if (l == r - 1)
    {
        tree[curr] = value;
        return;
    }
    lll m = (l + r) / 2;
    if (idx < m)
    {
        update(tree, idx, 2 * curr + 1, value, l, m);
    }
    else
    {
        update(tree, idx, 2 * curr + 2, value, m, r);
    }
    tree[curr] = tree[2 * curr + 1] + tree[2 * curr + 2];
}

lll query(vector<lll> &tree, lll idx, lll l, lll r, lll t_l, lll t_r)
{
    if (l >= t_l && r <= t_r)
    {
        return tree[idx];
    }
    else if (l < t_l && r <= t_l)
    {
        return 0;
    }
    else if (l >= t_r && r > t_r)
    {
        return 0;
    }
    else
    {
        lll m = (l + r) / 2;
        return query(tree, 2 * idx + 1, l, m, t_l, t_r) + query(tree, 2 * idx + 2, m, r, t_l, t_r);
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
    vector<lll> arr(n);
    vector<lll> tree(4 * n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(arr, tree, 0, 0, n);
    while (m--)
    {
        lll x, y, z;
        cin >> x >> y >> z;
        if (x == 1)
        {
            update(tree, y, 0, z, 0, n);
        }
        else
        {
            cout << query(tree, 0, 0, n, y, z) << "\n";
        }
    }
}