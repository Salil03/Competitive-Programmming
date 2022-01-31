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
        lll n, k;
        cin >> n >> k;
        lll a[n], sum = 0;
        for (lll i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        if (sum <= k)
        {
            cout << 0 << "\n";
            continue;
        }
        if (n == 1)
        {
            cout << sum - k << "\n";
            continue;
        }
        lll diff = sum - k;
        dbg(diff);
        sort(a, a + n);
        vector<lll> auxi(n, 0);
        auxi[n - 1] = a[n - 1] - a[0];
        for (lll i = n - 2; i >= 0; i--)
        {
            auxi[i] = auxi[i + 1] + a[i] - a[0];
        }
        lll ans = 0;
        while (auxi[0] < diff)
        {
            diff -= n;
            ans++;
        }
        dbg(diff);
        dbg(auxi);
        dbga(a, n);
        dbg(sum);
        reverse(auxi.begin(), auxi.end());
        cout << ans + lower_bound(auxi.begin(), auxi.end(), diff) - auxi.begin() + 1 << "\n";
        continue;
    }
}
