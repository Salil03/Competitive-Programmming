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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll n, c;
    cin >> n >> c;
    lll dp[2][c + 3]; // length i with j confusions
    memset(dp, 0, sizeof dp);
    for (lll i = 0; i < 2; i++)
    {
        dp[i][0] = 1;
    }
    for (lll i = 1; i <= n; i++)
    {
        for (lll j = 1; j <= c; j++)
        {
            if (j >= i)
            {
                dp[i % 2][j] = ((dp[i % 2][j - 1] % MOD) + (dp[(i - 1) % 2][j] % MOD) - (dp[(i - 1) % 2][j - i] % MOD)) % MOD;
            }
            else
            {
                dp[i % 2][j] = ((dp[i % 2][j - 1] % MOD) + (dp[(i - 1) % 2][j] % MOD)) % MOD;
            }
        }
    }
    if (dp[n % 2][c] % MOD < 0)
    {
        cout << dp[n % 2][c] % MOD + MOD;
    }
    else
    {
        cout << dp[n % 2][c] % MOD;
    }
}