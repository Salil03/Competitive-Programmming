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
    lll t;
    cin >> t;
    while (t--)
    {
        lll n, a, b, c;
        cin >> n >> a >> b >> c;
        lll lcm1 = (a * b) / gcd(a, b), lcm2 = (b * c) / gcd(b, c), lcm3 = (a * c) / gcd(a, c);
        lll lcm4 = (lcm1 * c) / gcd(lcm1, c);
        cout << (n / a) + (n / b) + (n / c) - 2 * (n / lcm1 + n / lcm2 + n / lcm3) + 3 * (n / lcm4) << "\n";
    }
}