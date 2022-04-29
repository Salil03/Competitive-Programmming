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
    vector<lll> arr(n);
    for (lll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<lll>> seq;
    seq.push_back({arr[0]});
    vector<lll> last;
    last.push_back(arr[0]);
    for (lll i = 1; i < n; i++)
    {
        if (arr[i] < last.back())
        {
            last.push_back(arr[i]);
            seq.push_back({arr[i]});
        }
        else
        {
            auto itr = upper_bound(last.begin(), last.end(), arr[i], [](lll a, lll b)
                                   { return a > b; });
            lll idx = itr - last.begin();
            last[idx] = arr[i];
            seq[idx].push_back(arr[i]);
        }
    }
    for (auto i : seq)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}