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
lll dp[54][54][1384];
lll recur(lll idx, lll curr, lll sum, lll s)
{
    if (idx == 0)
    {
        if (sum == s && curr == 52)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (dp[idx][curr][sum] != -1)
    {
        return dp[idx][curr][sum];
    }
    return dp[idx][curr][sum] = (recur(idx - 1, curr + 1, sum + curr, s) + recur(idx - 1, curr, sum, s));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll t;
    cin >> t;
    for (int test = 1; test <= t; test++)
    {
        for (lll i = 0; i < 54; i++)
        {
            for (lll j = 0; j < 54; j++)
            {
                for (lll k = 0; k < 1384; k++)
                {
                    dp[i][j][k] = -1;
                }
            }
        }
        lll l, s;
        cin >> l >> s;
        lll res = 0;
        if (l > 52 || s > 1381)
        {
            res = 0;
        }
        else
        {
            res = recur(l, 1, 0, s);
        }
        cout << "Case " << test << ": " << res << "\n";
    }
}