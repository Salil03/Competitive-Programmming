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
lll arr[1503][1503];
lll n;
lll dp[1503][1503];
lll recur(lll row, lll col)
{
    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }
    lll ans = 0;
    if (arr[row + 1][col] > arr[row][col])
    {
        ans = max(ans, 1 + recur(row + 1, col));
    }
    if (arr[row][col + 1] > arr[row][col])
    {
        ans = max(ans, 1 + recur(row, col + 1));
    }
    if (row > 0)
    {
        if (arr[row - 1][col] > arr[row][col])
        {
            ans = max(ans, 1 + recur(row - 1, col));
        }
    }
    if (col > 0)
    {
        if (arr[row][col - 1] > arr[row][col])
        {
            ans = max(ans, 1 + recur(row, col - 1));
        }
    }
    return dp[row][col] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    cin >> n;
    memset(arr, 0, sizeof arr);
    memset(dp, -1, sizeof dp);
    for (lll i = 0; i < n; i++)
    {
        for (lll j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    lll ans = INT_MIN;
    for (lll i = 0; i < n; i++)
    {
        for (lll j = 0; j < n; j++)
        {
            ans = max(ans, recur(i, j));
            dbg(ans);
            dbg(i);
            dbg(j);
        }
    }
    cout << ans;
}