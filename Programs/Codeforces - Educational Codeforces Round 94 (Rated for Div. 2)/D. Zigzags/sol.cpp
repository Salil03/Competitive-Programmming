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

lll MAX = 3004;

vector<vector<lll>> mp(MAX, vector<lll>(MAX, 0));
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
        lll n;
        cin >> n;
        vector<lll> arr(n);
        fill(mp.begin(), mp.end(), vector<lll>(MAX, 0));
        for (lll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        lll sum = 0;
        for (lll j = n - 1; j >= 0; j--)
        {
            for (lll i = 0; i < j; i++)
            {
                sum += mp[arr[i]][arr[j]];
            }
            for (lll l = j + 1; l < n; l++)
            {
                mp[arr[j]][arr[l]]++;
            }
        }
        cout << sum << "\n";
    }
}