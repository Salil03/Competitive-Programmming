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

void build(vector<lll> &arr, vector<lll> &maximum, lll idx, lll l, lll r)
{
    if (l == r - 1)
    {
        maximum[idx] = arr[l];
        return;
    }
    lll m = (l + r) / 2;
    build(arr, maximum, 2 * idx + 1, l, m);
    build(arr, maximum, 2 * idx + 2, m, r);
    maximum[idx] = max(maximum[2 * idx + 1], maximum[2 * idx + 2]);
}

void update(vector<lll> &maximum, lll value, lll idx, lll curr, lll l, lll r)
{
    if (l == r - 1)
    {
        maximum[curr] = value;
        return;
    }
    lll m = (l + r) / 2;
    if (idx < m)
    {
        update(maximum, value, idx, 2 * curr + 1, l, m);
    }
    else
    {
        update(maximum, value, idx, 2 * curr + 2, m, r);
    }
    maximum[curr] = max(maximum[2 * curr + 1], maximum[2 * curr + 2]);
}

lll query(vector<lll> &maximum, lll val, lll idx, lll l, lll r)
{
    if (l == r - 1)
    {
        if (maximum[idx] >= val)
        {
            return l;
        }
        else
        {
            return INT_MAX;
        }
    }
    lll m = (l + r) / 2;
    lll left = maximum[2 * idx + 1];
    lll right = maximum[2 * idx + 2];
    if (left >= val)
    {
        return query(maximum, val, 2 * idx + 1, l, m);
    }
    else if (right >= val)
    {
        return query(maximum, val, 2 * idx + 2, m, r);
    }
    else
    {
        return INT_MAX;
    }
}

lll range(vector<lll> &maximum, lll value, lll idx, lll limit, lll l, lll r)
{
    lll ans = INT_MAX;
    lll m = (l + r) / 2;
    if (l >= limit)
    {
        ans = min(ans, query(maximum, value, idx, l, r));
    }
    else if (l < limit && r > limit)
    {
        ans = min({ans, range(maximum, value, 2 * idx + 1, limit, l, m), range(maximum, value, 2 * idx + 2, limit, m, r)});
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
    lll n, m;
    cin >> n >> m;
    vector<lll> arr(n);
    for (lll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<lll> maximum(4 * n, 0);
    build(arr, maximum, 0, 0, n);
    while (m--)
    {
        lll x;
        cin >> x;
        if (x == 1)
        {
            lll i, v;
            cin >> i >> v;
            update(maximum, v, i, 0, 0, n);
        }
        else
        {
            lll v, l;
            cin >> v >> l;
            lll res = range(maximum, v, 0, l, 0, n);
            if (res == INT_MAX)
            {
                cout << "-1\n";
            }
            else
            {
                cout << res << "\n";
            }
        }
    }
}