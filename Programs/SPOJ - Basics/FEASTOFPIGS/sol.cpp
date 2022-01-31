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
    lll n, k;
    cin >> n >> k;
    lll arr[k];
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }
    if (k <= 20)
    {
        lll ans = 0;
        for (int b = 0; b < (1 << k); b++)
        {
            lll length = __builtin_popcount(b);
            lll lcm = 1;
            bool flag = false;
            for (int i = 0; i < k; i++)
            {
                if (lcm >= n)
                {
                    flag = true;
                    break;
                }
                if (b & (1 << i))
                {
                    lcm *= arr[i] / __gcd(lcm, arr[i]);
                }
            }
            if (flag)
            {
                continue;
            }
            if (length & 1)
            {
                ans -= (n - 1) / lcm;
            }
            else
            {
                ans += (n - 1) / lcm;
            }
        }
        cout << ans;
    }
    else
    {
        lll ans = 0;
        for (lll i = 0; i <= n - 1; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (i % arr[j] == 0)
                {
                    ans++;
                    break;
                }
            }
        }
        cout << n - ans;
    }
}