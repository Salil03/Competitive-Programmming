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
    lll n;
    cin >> n;
    vector<lll> arr(n), bits(22);
    for (lll i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (lll j = 0; j < 22; j++)
        {
            if (arr[i] & (1 << j))
            {
                bits[j]++;
            }
        }
    }
    vector<lll> ans(n, 0);
    for (lll i = 0; i < 22; i++)
    {
        for (lll j = n - 1; j > n - 1 - bits[i]; j--)
        {
            ans[j] += (1 << i);
        }
    }
    lll sum = 0;
    for (lll i = 0; i < n; i++)
    {
        sum += ans[i] * ans[i];
    }
    cout << sum;
}