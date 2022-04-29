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
    lll t;
    cin >> t;
    for (lll test = 1; test <= t; test++)
    {
        cout << "Case #" << test << ": ";
        lll ink[3][4];
        for (lll i = 0; i < 3; i++)
        {
            for (lll j = 0; j < 4; j++)
            {
                cin >> ink[i][j];
            }
        }
        lll minimum[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
        for (lll i = 0; i < 4; i++)
        {
            for (lll j = 0; j < 3; j++)
            {
                minimum[i] = min(minimum[i], ink[j][i]);
            }
        }
        lll sum = accumulate(minimum, minimum + 4, 0);
        if (sum < 1000000)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        lll curr = 0;
        while (sum > 1000000)
        {
            if (sum - minimum[curr] >= 1000000)
            {
                sum -= minimum[curr];
                minimum[curr] = 0;
                curr++;
            }
            else
            {
                minimum[curr] -= sum - 1000000;
                curr++;
                sum = 1000000;
            }
        }
        for (lll i = 0; i < 4; i++)
        {
            cout << minimum[i] << " ";
        }
        cout << "\n";
    }
}