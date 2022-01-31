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

lll binpow(lll pow)
{
    if (pow == 1)
    {
        return 2;
    }
    if (pow == 0)
    {
        return 1;
    }
    if (pow & 1)
    {
        return ((binpow(pow / 2) % MOD) * (binpow(pow / 2) % MOD) * 2) % MOD;
    }
    else
    {
        return ((binpow(pow / 2) % MOD) * (binpow(pow / 2) % MOD)) % MOD;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("help.in", "r", stdin);
    freopen("help.out", "w", stdout);
    lll n;
    cin >> n;
    pair<lll, lll> arr[n];
    for (lll i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    vector<lll> graph[n];
    for (lll i = 0; i < n; i++)
    {
        for (lll j = i + 1; j < n; j++)
        {
            if ((arr[i].first <= arr[j].first && arr[i].second >= arr[j].second) || (arr[i].first >= arr[j].first && arr[i].first <= arr[j].second) || (arr[j].first >= arr[i].first && arr[j].first <= arr[i].second) || (arr[j].first <= arr[i].first && arr[j].second >= arr[i].second))
            {
                graph[i].emplace_back(j);
                graph[j].emplace_back(i);
            }
        }
    }
    lll sum = 0;
    for (auto u : graph)
    {
        sum += binpow(u.size()) % MOD;
        sum %= MOD;
    }
    if (sum < 0)
    {
        cout << sum + MOD;
    }
    else
    {
        cout << sum;
    }
}