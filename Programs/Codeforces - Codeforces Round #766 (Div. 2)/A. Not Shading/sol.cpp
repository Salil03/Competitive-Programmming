// OPTIMIZATIONS
//#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
//#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
// OPTIMIZATIONS
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

/*
$alil03

URL: url

Solution Begins here
*/

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
        lll n, m, r, c;
        cin >> n >> m >> r >> c;
        r--;
        c--;
        string grid[n];
        for (lll i = 0; i < n; i++)
        {
            cin >> grid[i];
        }
        bool flag = false;
        if (grid[r][c] == 'B')
        {
            cout << 0 << "\n";
            continue;
        }
        for (lll i = 0; i < n; i++)
        {
            if (grid[i][c] == 'B')
            {
                cout << 1 << "\n";
                flag = true;
                break;
            }
        }
        if (flag)
        {
            continue;
        }
        for (lll i = 0; i < m; i++)
        {
            if (grid[r][i] == 'B')
            {
                cout << 1 << "\n";
                flag = true;
                break;
            }
        }
        if (flag)
        {
            continue;
        }
        for (lll i = 0; i < n; i++)
        {
            for (lll j = 0; j < m; j++)
            {
                if (grid[i][j] == 'B')
                {
                    cout << 2 << "\n";
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }
        if (flag)
        {
            continue;
        }
        cout << -1 << "\n";
    }
}
