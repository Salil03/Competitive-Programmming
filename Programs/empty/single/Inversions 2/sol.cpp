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

void build_sum(vector<lll> &arr, vector<lll> &sum, lll idx, lll l, lll r)
{
    if (l == r - 1)
    {
        sum[idx] = arr[l];
        return;
    }
    lll m = (l + r) / 2;
    build_sum(arr, sum, 2 * idx + 1, l, m);
    build_sum(arr, sum, 2 * idx + 2, m, r);
    sum[idx] = sum[2 * idx + 1] + sum[2 * idx + 2];
}

void update(vector<lll> &sum, vector<lll> &tree, lll idx, lll curr, lll l, lll r)
{
    if (l == r - 1)
    {
        if (sum[curr] == 0)
        {
            sum[curr] = 1;
            tree[l] = 1;
        }
        else
        {
            sum[curr] = 0;
            tree[l] = 0;
        }
        return;
    }
    lll m = (l + r) / 2;
    if (idx < m)
    {
        update(sum, tree, idx, 2 * curr + 1, l, m);
    }
    else
    {
        update(sum, tree, idx, 2 * curr + 2, m, r);
    }
    sum[curr] = sum[2 * curr + 1] + sum[2 * curr + 2];
}

lll query(vector<lll> &sum, lll k, lll idx, lll l, lll r)
{
    if (l == r - 1)
    {
        return l;
    }
    lll m = (l + r) / 2;
    lll left = sum[2 * idx + 1];
    if (k <= left)
    {
        return query(sum, k, 2 * idx + 1, l, m);
    }
    else
    {
        return query(sum, k - left, 2 * idx + 2, m, r);
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
    for (lll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    reverse(arr.begin(), arr.end());
    vector<lll> sum(4 * n, 0);
    vector<lll> tree(n, 1);
    build_sum(tree, sum, 0, 0, n);
    dbg(sum);
    vector<lll> final(n);
    for (lll i = 0; i < n; i++)
    {
        lll res = query(sum, arr[i] + 1, 0, 0, n);
        final[n - i - 1] = n - res;
        update(sum, tree, res, 0, 0, n);
        dbg(tree);
        dbg(sum);
    }
    for (lll i : final)
    {
        cout << i << " ";
    }
}