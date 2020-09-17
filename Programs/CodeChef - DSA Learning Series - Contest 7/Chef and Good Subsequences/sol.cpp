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
lll dp[1012][1012];

lll recur(lll idx, lll len, vector<lll> &distinct, lll used, lll k)
{
    if (idx == len || used == k)
    {
        return 1;
    }
    if (dp[idx][used] != -1)
    {
        return dp[idx][used] % MOD;
    }
    return dp[idx][used] = ((distinct[idx] * recur(idx + 1, len, distinct, used + 1, k)) % MOD + (recur(idx + 1, len, distinct, used, k) % MOD)) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll n, k;
    cin >> n >> k;
    lll arr[n];s
    for (lll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    vector<lll> distinct;
    lll sum = 1;
    for (lll i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            distinct.emplace_back(sum);
            sum = 1;
        }
        else
        {
            sum++;
        }
    }
    distinct.emplace_back(sum);
    lll len = distinct.size();
    memset(dp, -1, sizeof dp);
    cout << recur(0, len, distinct, 0, min(k, len)) % MOD;
}