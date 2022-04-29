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
// uniform_int_distribution < lll>(low, high)(rng)
// uniform_real_distribution<double>(low, high)(rng)
#define cel(x, y) 1 + ((x - 1) / y)
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const long long int INF = 0x3f3f3f3f3f3f3f3f;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    string s, t;
    cin >> s >> t;
    lll len1 = s.length(), len2 = t.length();
    lll maximum = 0;
    for (lll l = 0; l < len1; l++)
    {
        for (lll r = l; r < len1; r++)
        {
            lll curr = 0;
            for (lll i = 0; i < len1; i++)
            {
                if (curr == len2)
                {
                    break;
                }
                if (i >= l && i <= r)
                {
                    continue;
                }
                if (s[i] == t[curr])
                {
                    curr++;
                }
            }
            if (curr == len2)
            {
                maximum = max(maximum, r - l + 1);
            }
        }
    }
    cout << maximum;
}