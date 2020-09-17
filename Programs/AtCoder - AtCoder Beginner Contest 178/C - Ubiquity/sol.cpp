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
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll n;
    cin >> n;

    lll dp1[n] = {10};
    lll dp2[n] = {9};
    lll dp3[n] = {8};
    for (lll i = 1; i < n; i++)
    {
        dp1[i] = (dp1[i - 1] * 10) % MOD;
        dp2[i] = (dp2[i - 1] * 9) % MOD;
        dp3[i] = (dp3[i - 1] * 8) % MOD;
        cout << dp1[i] << " " << dp2[i] << " " << dp3[i] << "\n";
    }
    lll res = ((dp1[n - 1] % MOD) - ((2 * dp2[n - 1]) % MOD) + (dp3[n - 1] % MOD)) % MOD;
    if (res < 0)
    {
        cout << res + MOD;
    }
    else
    {
        cout << res;
    }
}