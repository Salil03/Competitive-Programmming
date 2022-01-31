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
lll final[100002] = {0};
lll n, m, c;
map<lll, vector<pair<lll, lll>>> mp;
lll recur(lll idx, lll s[])
{
    if (final[idx] != -1)
    {
        return final[idx];
    }
    lll date = 0;
    if (mp.find(idx) != mp.end())
    {
        for (auto u : mp[idx])
        {
            date = max(date, recur(u.first, s) + u.second);
        }
    }
    return final[idx] = max(s[idx], date);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);
    cin >> n >> m >> c;
    lll s[n];
    for (lll i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    while (c--)
    {
        lll a, b, x;
        cin >> a >> b >> x;
        mp[b - 1].push_back(make_pair(a - 1, x));
    }
    memset(final, -1, sizeof final);
    for (lll i = 0; i < n; i++)
    {
        if (final[i] == -1)
        {
            recur(i, s);
        }
    }
    for (lll i = 0; i < n; i++)
    {
        cout << final[i] << "\n";
    }
}