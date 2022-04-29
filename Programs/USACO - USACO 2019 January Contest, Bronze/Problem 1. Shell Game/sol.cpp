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
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    lll N;
    cin >> N;
    lll maximum = -1;
    lll pebble = 1;
    vector<vector<lll>> moves(N, vector<lll>(3));
    for (lll i = 0; i < N; i++)
    {
        cin >> moves[i][0] >> moves[i][1] >> moves[i][2];
    }
    for (lll i = 1; i <= 3; i++)
    {
        lll ans = 0;
        pebble = i;
        for (lll j = 0; j < N; j++)
        {
            if (moves[j][0] == pebble)
            {
                pebble = moves[j][1];
            }
            else if (moves[j][1] == pebble)
            {
                pebble = moves[j][0];
            }
            if (pebble == moves[j][2])
            {
                ans++;
            }
        }
        maximum = max(maximum, ans);
    }
    cout << maximum;
}