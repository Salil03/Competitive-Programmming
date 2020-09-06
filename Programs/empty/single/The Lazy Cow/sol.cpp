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
lll arr[1000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);

    lll n, k, MAXX = 1000001;
    cin >> n >> k;
    for (lll i = 0; i < n; i++)
    {
        lll x, y;
        cin >> x >> y;
        arr[y] = x;
    }
    lll maximum = 0;
    for (lll i = 0; i <= min(2 * k, MAXX - 1); i++)
    {
        maximum += arr[i];
    }
    lll cnt = maximum;
    for (lll i = 2 * k + 1; i < MAXX; i++)
    {
        cnt += arr[i];
        cnt -= arr[i - 2 * k - 1];
        maximum = max(maximum, cnt);
    }
    cout << maximum;
}