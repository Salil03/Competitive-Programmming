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
    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);
    lll n;
    cin >> n;
    pair<lll, lll> check[n];
    for (lll i = 0; i < n; i++)
    {
        cin >> check[i].first >> check[i].second;
    }
    pair<lll, lll> dist[n];
    lll sum = 0;
    for (lll i = 0; i < n - 1; i++)
    {
        dist[i].first = abs(check[i + 1].first - check[i].first) + abs(check[i + 1].second - check[i].second);
        sum += dist[i].first;
    }
    for (lll i = 0; i < n - 2; i++)
    {
        dist[i].second = abs(check[i + 2].first - check[i].first) + abs(check[i + 2].second - check[i].second);
    }
    lll minimum = sum;
    for (lll i = 1; i < n - 1; i++)
    {
        minimum = min(minimum, sum - dist[i - 1].first - dist[i].first + dist[i - 1].second);
    }
    cout << minimum << "\n";
}