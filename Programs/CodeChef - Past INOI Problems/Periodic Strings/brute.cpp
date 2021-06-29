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

lll binary(lll pow, lll n, lll m)
{
    if (pow == 1)
    {
        return n % m;
    }
    if (pow & 1)
    {
        return ((binary(pow / 2, n, m) % m) * (binary(pow / 2, n, m) % m) * (n % m) % m);
    }
    else
    {
        return ((binary(pow / 2, n, m) % m) * (binary(pow / 2, n, m) % m) % m);
    }
}

lll dp(lll len, lll m)
{
    if (len == 1)
    {
        return 2;
    }
    lll ans = 0;
    for (lll i = 2; i <= len; i++)
    {
        if (len % i == 0)
        {
            ans += dp(len / i, m) % m;
        }
    }
    return (binary(len, 2, m) - ans) % m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lll n, m;
    cin >> n >> m;
    if (dp(n, m) % m < 0)
    {
        cout << (dp(n, m) % m) + m;
    }
    else
    {
        cout << dp(n, m) % m;
    }
}