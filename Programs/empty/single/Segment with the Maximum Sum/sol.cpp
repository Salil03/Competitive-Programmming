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

const lll N = 100005;
lll sum[4 * N] = {0};
lll pref[4 * N] = {0};
lll suff[4 * N] = {0};
lll seg[4 * N] = {0};

void sum_build(vector<lll> &arr, lll idx, lll l, lll r)
{
    if (l == r - 1)
    {
        sum[idx] = arr[l];
        return;
    }
    lll m = (l + r) / 2;
    sum_build(arr, 2 * idx + 1, l, m);
    sum_build(arr, 2 * idx + 2, m, r);
    sum[idx] = sum[2 * idx + 1] + sum[2 * idx + 2];
}

void pref_build(vector<lll> &arr, lll idx, lll l, lll r)
{
    if (l == r - 1)
    {
        pref[idx] = max(arr[l], 0LL);
        return;
    }
    lll m = (l + r) / 2;
    pref_build(arr, 2 * idx + 1, l, m);
    pref_build(arr, 2 * idx + 2, m, r);
    pref[idx] = max(sum[2 * idx + 1] + pref[2 * idx + 2], pref[2 * idx + 1]);
}
void suff_build(vector<lll> &arr, lll idx, lll l, lll r)
{
    if (l == r - 1)
    {
        suff[idx] = max(arr[l], 0LL);
        return;
    }
    lll m = (l + r) / 2;
    suff_build(arr, 2 * idx + 1, l, m);
    suff_build(arr, 2 * idx + 2, m, r);
    suff[idx] = max(sum[2 * idx + 2] + suff[2 * idx + 1], suff[2 * idx + 2]);
}

void seg_build(vector<lll> &arr, lll idx, lll l, lll r)
{
    if (l == r - 1)
    {
        seg[idx] = max(arr[l], 0LL);
        return;
    }
    lll m = (l + r) / 2;
    seg_build(arr, 2 * idx + 1, l, m);
    seg_build(arr, 2 * idx + 2, m, r);
    seg[idx] = max({seg[2 * idx + 1], seg[2 * idx + 2], suff[2 * idx + 1] + pref[2 * idx + 2]});
}

void update(lll idx, lll curr, lll value, lll l, lll r)
{
    if (l == r - 1)
    {
        sum[curr] = value;
        pref[curr] = max(value, 0LL);
        suff[curr] = max(value, 0LL);
        seg[curr] = max(value, 0LL);
        return;
    }
    lll m = (l + r) / 2;
    if (idx < m)
    {
        update(idx, 2 * curr + 1, value, l, m);
    }
    else
    {
        update(idx, 2 * curr + 2, value, m, r);
    }
    sum[curr] = sum[2 * curr + 1] + sum[2 * curr + 2];
    pref[curr] = max(sum[2 * curr + 1] + pref[2 * curr + 2], pref[2 * curr + 1]);
    suff[curr] = max(sum[2 * curr + 2] + suff[2 * curr + 1], suff[2 * curr + 2]);
    seg[curr] = max({seg[2 * curr + 1], seg[2 * curr + 2], suff[2 * curr + 1] + pref[2 * curr + 2]});
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
    sum_build(arr, 0, 0, n);
    pref_build(arr, 0, 0, n);
    suff_build(arr, 0, 0, n);
    seg_build(arr, 0, 0, n);
    cout << seg[0] << "\n";
    while (m--)
    {
        lll index, v;
        cin >> index >> v;
        update(index, 0, v, 0, n);
        cout << seg[0] << "\n";
    }
}