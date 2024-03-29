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
double recur(lll mask, lll n, vector<vector<double>> &arr, lll idx, vector<double> &dp)
{
    dbg(idx);
    if (idx == n)
    {
        return 1;
    }
    if (dp[mask] != -1)
    {
        return dp[mask];
    }
    double ans = -10;
    for (lll i = 0; i < n; i++)
    {
        if (!(mask & (1 << i)))
        {
            ans = max(ans, recur(mask | (1 << i), n, arr, idx + 1, dp) * arr[idx][i]);
        }
    }
    return dp[mask] = ans;
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
    vector<vector<double>> arr(n);
    for (lll i = 0; i < n; i++)
    {
        arr[i].resize(n);
        for (lll j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            arr[i][j] /= 100;
        }
    }
    vector<double> dp(1 << n + 1, -1);
    cout << fixed << setprecision(10) << (double)recur(0, n, arr, 0, dp) * 100;
}