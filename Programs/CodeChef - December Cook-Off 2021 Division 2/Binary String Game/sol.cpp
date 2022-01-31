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
        lll n, ans = 0, l = -1, r = -1;
        cin >> n;
        string s;
        cin >> s;
        while (l < 0 && r < 0)
        {
            for (lll i = 0; i < n - 1; i++)
            {
                if (s[i] == s[i + 1])
                {
                    if (l < 0)
                    {
                        l = i + 1;
                    }
                }
            }
            if (l < 0)
            {
                break;
            }
            for (lll i = l; i < n; i++)
            {
                if (s[i] == s[i - 1])
                {
                    if (r < 0)
                    {
                        r = i - 1;
                    }
                }
            }
            if (r < 0)
            {
                break;
            }
            if (r < l)
            {
                if (s[l] == '1')
                {
                    s[l] = '0';
                }
                else
                {
                    s[l] = '1';
                }
            }
            else
            {
                for (lll i = l; i <= r; i++)
                {
                    if (s[i] == '1')
                    {
                        s[i] = '0';
                    }
                    else
                    {
                        s[i] = '1';
                    }
                }
            }

            l = -1;
            r = -1;
            ans++;
        }
        cout << ans << "\n";
    }
}