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
lll n, s;
lll recur(lll idx, lll time, lll cost, pair<lll, lll> arr[])
{
    if (idx == n)
    {
        return 0;
    }
    lll ans = INT_MAX;
    if (idx == 0)
    {
        ans = min(ans, (s + time + arr[idx].first) * arr[idx].second + recur(idx + 1, s + time + arr[idx].first, arr[idx].second, arr));
        return ans;
    }
    ans = min(ans, (s + time + arr[idx].first) * arr[idx].second + recur(idx + 1, s + time + arr[idx].first, arr[idx].second, arr));
    ans = min(ans, (time + arr[idx].first) * arr[idx].second + cost * arr[idx].first + recur(idx + 1, time + arr[idx].first, cost + arr[idx].second, arr));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    cin >> n >> s;
    pair<lll, lll> arr[n]; //time, cost
    for (lll i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    lll dp[2][300][300];

    cout << recur(0, 0, 0, arr);
}