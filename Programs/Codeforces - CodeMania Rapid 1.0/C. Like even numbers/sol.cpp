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
    bitset<32> arr[n];
    for (lll i = 0; i < n; i++)
    {
        arr[i].reset();
        for (lll j = 0; j < k; j++)
        {
            lll temp;
            cin >> temp;
            if (temp & 1)
            {
                arr[i].set(j);
            }
        }
    }
    lll ans = 0;
    bitset<32> prefix[n];
    unordered_map<bitset<32>, lll> mp;
    prefix[0] = arr[0];
    mp[arr[0]]++;
    if (arr[0].none())
    {
        ans++;
    }
    dbg(ans);
    for (lll i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] ^ arr[i];
        if (mp.find(prefix[i]) != mp.end())
        {
            ans += mp[prefix[i]];
        }
        if (prefix[i].none())
        {
            ans++;
        }
        mp[prefix[i]]++;
        dbg(ans);
    }
    cout << ans;
}