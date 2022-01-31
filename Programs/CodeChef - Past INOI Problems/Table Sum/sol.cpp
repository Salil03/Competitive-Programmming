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

void build(vector<lll> &arr, vector<lll> &tree, lll idx, lll l, lll r)
{
    if (l == r - 1)
    {
        tree[idx] = arr[l];
        return;
    }
    lll m = (l + r) / 2;
    build(arr, tree, 2 * idx + 1, l, m);
    build(arr, tree, 2 * idx + 2, m, r);
    tree[idx] = max(tree[2 * idx + 1], tree[2 * idx + 2]);
}

void update(vector<lll> &lazy, lll value, lll idx, lll l, lll r, lll t_l, lll t_r)
{
    if (l >= t_l && r <= t_r)
    {
        lazy[idx] += value;
        return;
    }
    lll m = (l + r) / 2;
    else if (!(l < t_l && r <= t_l) && !(r > t_r && l >= t_r))
    {
        update(lazy, value, 2 * idx + 1, l, m, t_l, t_r);
        update(lazy, value, 2 * idx + 2, m, r, t_l, t_r);
    }
}

lll query(vector<lll> &lazy, vector<lll> &tree, lll idx, lll l, lll r, lll t_l, lll t_r)
{
    if (l >= t_l && r <= t_r)
    {
        return tree[idx] + lazy[idx];
    }
    if (l < t_l && r <= t_l)
    {
        return 0;
    }
    if (l >= t_r && r > t_r)
    {
        return 0;
    }
    else
    {
        lll m = (l + r) / 2;
        return max(query(lazy, tree, 2 * idx + 1, l, m, t_l, t_r) + lazy[2 * idx + 1], query(lazy, tree, 2 * idx + 1, m, r, t_l, t_r) + lazy[2 * idx + 2]);
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll n;
    cin >> n;
    vector<lll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i] += i + 1;
    }
    vector<lll> tree(4 * n, 0);
    vector<lll> lazy(4 * n, 0);
    build(arr, tree, 0, 0, n);
    cout << tree[0];
    update(lazy, 1, 0, 0, n, 0, n - 1);
    update(lazy, 1 - n, 0, 0, n, n - 1, n);
    for (int i = 1; i < n; i++)
    {
        cout << tree[0] << " ";
        update(lazy, 1, 0, 0, n, 0, n - i - 1);
        update(lazy, 1, 0, 0, n, n - i, n);
        update(lazy, 1 - n, 0, 0, n, n - i - 1, n - i);
    }
}