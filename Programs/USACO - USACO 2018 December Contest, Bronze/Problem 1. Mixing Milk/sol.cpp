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
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    vector<pair<lll, lll>> milk(3); // capacity, milk
    for (lll i = 0; i < 3; i++)
    {
        cin >> milk[i].first >> milk[i].second;
    }
    for (lll i = 0; i < 100; i++)
    {

        if (milk[(i + 1) % 3].second + milk[i % 3].second <= milk[(i + 1) % 3].first)
        {
            milk[(i + 1) % 3].second += milk[i % 3].second;
            milk[i % 3].second = 0;
        }
        else
        {
            milk[i % 3].second -= milk[(i + 1) % 3].first - milk[(i + 1) % 3].second;
            milk[(i + 1) % 3].second = milk[(i + 1) % 3].first;
        }
    }
    cout << milk[0].second << "\n"
         << milk[1].second << "\n"
         << milk[2].second;
}