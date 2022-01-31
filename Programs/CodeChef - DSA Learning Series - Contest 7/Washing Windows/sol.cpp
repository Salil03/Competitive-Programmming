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
#define _GLIBCXX_DEBUG
#define dbga(x, n) cerr << "\n" \
                        << (#x) << " is " << pretty_print_array(x, n) << endl
#define dbg(x) cerr << "\n" \
                    << (#x) << " is " << x << endl
#endif

#if !defined(DEBUG)
#define dbga(x, n)
#define dbg(x)
#endif

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
        lll n, m;
        cin >> n >> m;
        lll arr[n][m];
        for (lll i = 0; i < n; i++)
        {
            for (lll j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        lll final[n][m];
        for (lll j = 0; j < m; j++)
        {
            final[0][j] = 1;
        }
        for (lll i = 1; i < n; i++)
        {
            for (lll j = 0; j < m; j++)
            {
                lll maximum = max(arr[i][j], arr[i - 1][j]);
                if (j > 0)
                {
                    maximum = max(maximum, arr[i - 1][j - 1]);
                }
                if (j < m - 1)
                {
                    maximum = max(maximum, arr[i - 1][j + 1]);
                }
                if (maximum > arr[i][j])
                {
                    final[i][j] = 0;
                    arr[i][j] = maximum;
                }
                else
                {
                    final[i][j] = 1;
                }
            }
        }
        for (lll i = 0; i < n; i++)
        {
            for (lll j = 0; j < m; j++)
            {
                cout << final[i][j];
            }
            cout << "\n";
        }
    }
}