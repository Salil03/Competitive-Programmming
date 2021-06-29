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

lll table[10004][61];

lll recur(lll arr[], lll n, lll curr_gcd, lll idx)
{
    if (idx == n && curr_gcd == 1)
    {
        return 1;
    }
    if (idx == n && curr_gcd != 1)
    {
        return 0;
    }
    if (table[curr_gcd][idx] != -1)
    {
        return table[curr_gcd][idx];
    }
    return table[curr_gcd][idx] = recur(arr, n, curr_gcd, idx + 1) + recur(arr, n, __gcd(curr_gcd, arr[idx]), idx + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll t;
    cin >> t;
    while (t--)
    {
        lll n;
        cin >> n;
        lll arr[n];
        for (lll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        lll ans = 0;
        memset(table, -1, sizeof table);
        for (int i = 0; i < n - 1; i++)
        {
            ans += recur(arr, n, arr[i], i + 1);
        }
        cout << ans << "\n";
    }
}