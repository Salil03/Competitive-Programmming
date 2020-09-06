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

void build_one(vector<lll> &last_one, vector<lll> &arr, lll idx, lll l, lll r)
{
    if (l == r - 1)
    {
        if (arr[l] == 1)
        {
            last_one[idx] = l;
        }
        return;
    }
    lll m = (l + r) / 2;
    build_one(last_one, arr, 2 * idx + 1, l, m);
    build_one(last_one, arr, 2 * idx + 2, m, r);
    last_one[idx] = max(last_one[2 * idx + 1], last_one[2 * idx + 2]);
}

void update(vector<lll> &sum, vector<lll> &last_one, lll idx, lll curr, lll l, lll r)
{
    if (l == r - 1)
    {
        if (sum[curr] == 0)
        {
            sum[curr] = 1;
            last_one[curr] = l;
        }
        else
        {
            sum[curr] = 0;
            last_one[curr] = -1;
        }
        return;
    }
    lll m = (l + r) / 2;
    if (idx < m)
    {
        update(sum, last_one, idx, 2 * curr + 1, l, m);
    }
    else
    {
        update(sum, last_one, idx, 2 * curr + 2, m, r);
    }
    sum[curr] = sum[2 * curr + 1] + sum[2 * curr + 2];
    last_one[curr] = max(last_one[2 * idx + 1], last_one[2 * idx + 2]);
}

lll query(vector<lll> &sum, vector<lll> &last_one, lll k, lll idx, lll l, lll r)
{
    dbg(idx);
    dbg(l);
    dbg(r);
    dbg(sum[idx]);
    lll m = (l + r) / 2;
    if (sum[idx] == k)
    {
        return last_one[idx];
    }
    else if (sum[idx] > k)
    {
        return query(sum, last_one, k, 2 * idx + 1, l, m);
    }
    else if (sum[idx] < k)
    {
        return query(sum, last_one, k - sum[idx], idx + 1, r, 2 * r - l);
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
    for (lll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<lll> sum(4 * n, 0);
    vector<lll> last_one(4 * n, -1);
    build_sum(arr, sum, 0, 0, n);
    build_one(last_one, arr, 0, 0, n);
    dbg(last_one);
    dbg(sum);
    while (m--)
    {
        lll x, y;
        cin >> x >> y;
        if (x == 1)
        {
            update(sum, last_one, y, 0, 0, n);
            dbg(last_one);
            dbg(sum);
        }
        else
        {
            cout << query(sum, last_one, y + 1, 0, 0, n) << "\n";
        }
    }
}