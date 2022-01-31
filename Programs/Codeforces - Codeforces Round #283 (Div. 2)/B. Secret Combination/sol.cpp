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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll n;
    cin >> n;
    string s;
    cin >> s;
    string minimum = s;
    for (lll i = 1; i <= 10; i++)
    {
        for (lll j = 0; j < n; j++)
        {
            if (s[j] == '9')
            {
                s[j] = '0';
            }
            else
            {
                s[j]++;
            }
        }
        for (lll j = 1; j <= n; j++)
        {
            rotate(s.begin(), s.begin() + 1, s.end());
            for (lll k = 0; k < n; k++)
            {
                if (s[k] - '0' > minimum[k] - '0')
                {
                    break;
                }
                else if (minimum[k] - '0' > s[k] - '0')
                {
                    minimum = s;
                    break;
                }
            }
        }
    }
    cout << minimum;
}