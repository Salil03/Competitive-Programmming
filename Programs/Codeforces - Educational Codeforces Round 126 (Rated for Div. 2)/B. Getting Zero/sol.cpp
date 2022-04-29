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
vector<lll> modu(32770, -1);
lll nextPowerOf2(lll n)
{
    lll p = 1;
    if (n && !(n & (n - 1)))
        return n;

    while (p < n)
        p <<= 1;

    return p;
}

lll dp(lll mod)
{
    dbg(mod);
    if (modu[mod] == -1)
    {
        if (mod > 32768 / 2)
        {
            modu[mod] = min(1 + dp((mod * 2) % 32768), 32768 - mod);
        }
        lll nextpow = nextPowerOf2(mod);
        modu[mod] = min(nextpow - mod + modu[nextpow], 1 + dp((mod * 2) % 32768));
    }
    return modu[mod];
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll n;
    cin >> n;
    modu[0] = 0;
    modu[32768 / 2] = 1;
    modu[32768] = 0;
    for (lll i = 32768 / 4; i > 0; i /= 2)
    {
        modu[i] = 1 + modu[i * 2];
    }
    for (lll i = 0; i < n; i++)
    {
        lll x;
        cin >> x;
        lll mod = x % 32768;
        cout << dp(mod) << " ";
    }
}