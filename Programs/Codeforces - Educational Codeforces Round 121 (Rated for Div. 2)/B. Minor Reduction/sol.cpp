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
#define dbga(x, n) cerr << "\n" \
                        << (#x) << " is " << pretty_print_array(x, n) << endl
#define dbg(x) cerr << "\n" \
                    << (#x) << " is " << x << endl
#endif

#if !defined(DEBUG)
#define dbga(x, n)
#define dbg(x)
#endif

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
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
        string s;
        cin >> s;
        lll n = s.length();
        string max1 = "", max2 = "";
        for (lll i = 0; i < n - 1; i++)
        {
            int new1 = s[i] - '0';
            int new2 = s[i + 1] - '0';
            string repl = to_string(new1 + new2);

            if (repl.length() == 1)
            {
                max1 = s;
                max1[i] = repl[0];
                max1.erase(i + 1, 1);
                break;
            }
        }
        for (lll i = n - 1; i > 0; i--)
        {
            int new1 = s[i] - '0';
            int new2 = s[i - 1] - '0';
            string repl = to_string(new1 + new2);

            if (repl.length() == 2)
            {
                max2 = s;
                max2[i - 1] = repl[0];
                max2[i] = repl[1];
                break;
            }
        }
        if (max2 != "")
        {
            cout << max2;
        }
        else
        {
            cout << max1;
        }
        cout << "\n";
    }
}