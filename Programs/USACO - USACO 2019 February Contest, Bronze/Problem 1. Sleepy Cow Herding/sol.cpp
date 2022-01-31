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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution < lll>(low, high)(rng)
//uniform_real_distribution<double>(low, high)(rng)
#define cel(x, y) 1 + ((x - 1) / y)
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const long long int INF = 0x3f3f3f3f3f3f3f3f;

/*
$alil03

URL: url

Solution Begins here
*/

lll min_recur(vector<lll> cow)
{
    if (cow[0] == cow[1] - 1 && cow[1] == cow[2] - 1)
    {
        return 0;
    }

    if (cow[1] == cow[2] - 2)
    {
        return 1;
    }
    if (cow[0] == cow[1] - 2)
    {
        return 1;
    }
    return 1 + min(min_recur({cow[1], cow[1] + 2, cow[2]}), min_recur({cow[0], cow[1] - 2, cow[1]}));
}

lll max_recur(vector<lll> cow)
{
    if (cow[0] == cow[1] - 1 && cow[1] == cow[2] - 1)
    {
        return 0;
    }
    if (cow[0] == cow[1] - 1)
    {
        return (cow[2] - cow[1] - 1);
    }
    if (cow[1] == cow[2] - 1)
    {
        return (cow[1] - cow[0] - 1);
    }
    return 1 + max(max_recur({cow[1], cow[1] + 1, cow[2]}), max_recur({cow[0], cow[1] - 1, cow[1]}));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    vector<lll> cow(3);
    cin >> cow[0] >> cow[1] >> cow[2];
    sort(cow.begin(), cow.end());
    cout << min_recur(cow) << "\n"
         << max_recur(cow);
}