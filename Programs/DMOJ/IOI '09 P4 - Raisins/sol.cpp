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

lll arr[60][60];
lll dp[55][55][55][55];
lll sum_arr(lll t_r, lll b_r, lll l_c, lll r_c)
{
    lll sum = 0;
    for (lll i = t_r; i <= b_r; i++)
    {
        for (lll j = l_c; j <= r_c; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}
lll recur(lll t_r, lll b_r, lll l_c, lll r_c)
{
    if (t_r == b_r && l_c == r_c)
    {
        return 0;
    }
    if (dp[t_r][b_r][l_c][r_c] != -1)
    {
        return dp[t_r][b_r][l_c][r_c];
    }
    lll ans = INT_MAX;
    for (lll i = l_c; i < r_c; i++)
    {
        ans = min(ans, recur(t_r, b_r, l_c, i) + recur(t_r, b_r, i + 1, r_c));
    }
    for (lll i = t_r; i < b_r; i++)
    {
        ans = min(ans, recur(t_r, i, l_c, r_c) + recur(i + 1, b_r, l_c, r_c));
    }
    return dp[t_r][b_r][l_c][r_c] = (ans + sum_arr(t_r, b_r, l_c, r_c));
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
    for (lll i = 0; i < n; i++)
    {
        for (lll j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    cout << recur(0, n - 1, 0, m - 1);
}