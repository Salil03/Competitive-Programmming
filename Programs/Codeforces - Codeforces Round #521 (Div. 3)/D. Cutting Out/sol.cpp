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
    lll n, k;
    cin >> n >> k;
    vector<lll> cnt(200004, 0);
    for (lll i = 0; i < n; i++)
    {
        lll temp;
        cin >> temp;
        cnt[temp]++;
    }
    lll low = 1, high = n / k, ans = 1;
    while (low <= high)
    {
        lll mid = (low + high) / 2;
        lll sum = 0;
        for (lll i = 1; i <= 200000; i++)
        {
            sum += cnt[i] / mid;
        }
        if (sum >= k)
        {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    for (lll i = 1; i <= 200000; i++)
    {
        for (lll j = 1; j <= cnt[i] / ans; j++)
        {
            if (k == 0)
            {
                return 0;
            }
            cout << i << " ";
            k--;
        }
    }
}