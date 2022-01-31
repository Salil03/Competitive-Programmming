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
const int MOD = 998244353;
const long long int INF = 0x3f3f3f3f3f3f3f3f;

/*
$alil03

URL: url

Solution Begins here
*/

lll mod_exp(lll a, lll b)
{
    if (b == 1)
    {
        return a % MOD;
    }
    lll res = mod_exp(a, b / 2) % MOD;
    if (b % 2 == 1)
    {
        return (res * res * a) % MOD;
    }
    else
    {
        return (res * res) % MOD;
    }
}

lll nomod_exp(lll a, lll b)
{
    if (b == 1)
    {
        return a;
    }
    lll res = mod_exp(a, b / 2);
    if (b % 2 == 1)
    {
        return (res * res * a);
    }
    else
    {
        return (res * res);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll n, k, m;
    cin >> n >> k >> m;
    cout << mod_exp(m, nomod_exp(k, n)) % MOD;
}