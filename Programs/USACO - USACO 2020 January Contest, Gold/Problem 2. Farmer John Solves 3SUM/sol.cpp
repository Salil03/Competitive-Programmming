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
    freopen("threesum.in", "r", stdin);
    freopen("threesum.out", "w", stdout);
    lll n, q;
    cin >> n >> q;
    lll final[n][n];
    memset(final, 0, sizeof final);
    lll num[n][n];
    memset(num, 0, sizeof num);
    lll arr[n];
    for (lll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<lll, lll> mp;
    for (lll i = 0; i < n; i++)
    {
        mp.clear();
        mp[arr[i + 1]]++;
        for (lll j = i + 2; j < n; j++)
        {
            if (mp.find(-arr[j] - arr[i]) != mp.end())
            {
                num[i][j] = mp[-arr[j] - arr[i]];
            }
            mp[arr[j]]++;
        }
    }
    for (lll i = n - 1; i >= 0; i--)
    {
        for (lll j = i + 2; j < n; j++)
        {
            final[i][j] = final[i + 1][j] + final[i][j - 1] - final[i + 1][j - 1] + num[i][j];
        }
    }
    while (q--)
    {
        lll a, b;
        cin >> a >> b;
        cout << final[a - 1][b - 1] << "\n";
    }
}