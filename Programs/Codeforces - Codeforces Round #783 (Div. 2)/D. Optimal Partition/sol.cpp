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
lll n;

lll table[500003];

lll dp(lll idx, vector<lll> &arr, vector<lll> &prefix)
{
    if (table[idx] != INT_MIN)
    {
        return table[idx];
    }
    lll ans = 0;
    if (prefix[idx] > 0)
    {
        ans = (idx - 0 + 1);
    }
    else if (prefix[idx] == 0)
    {
        ans = 0;
    }
    else
    {
        ans = -(idx - 0 + 1);
    }
    for (lll i = 1; i <= idx; i++)
    {
        if (prefix[idx] - prefix[i - 1] > 0)
        {
            ans = max(ans, (idx - i + 1) + dp(i - 1, arr, prefix));
        }
        else if (prefix[idx] - prefix[i - 1] == 0)
        {
            ans = max(ans, dp(i - 1, arr, prefix));
        }
        else
        {
            ans = max(ans, -(idx - i + 1) + dp(i - 1, arr, prefix));
        }
    }
    table[idx] = ans;
    return ans;
}

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
        cin >> n;
        vector<lll> arr(n), prefix(n);
        for (lll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        prefix[0] = arr[0];
        for (lll i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        for (lll i = 0; i <= n; i++)
        {
            table[i] = INT_MIN;
        }
        cout << dp(n - 1, arr, prefix) << "\n";
    }
}