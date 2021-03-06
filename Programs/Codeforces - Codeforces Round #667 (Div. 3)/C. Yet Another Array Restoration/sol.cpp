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
        lll n, x, y;
        cin >> n >> x >> y;
        lll diff = y - x;
        lll arr[n] = {0};
        bool flag = false;
        for (lll k = n; k >= 2; k--)
        {
            if (flag)
            {
                break;
            }
            for (lll i = 1; i < k; i++)
            {
                if (diff % (k - i) == 0 && y - (k - 1) * diff / (k - i) > 0)
                {
                    flag = true;
                    arr[k - 1] = y;
                    for (lll j = k - 2; j >= 0; j--)
                    {
                        arr[j] = arr[j + 1] - diff / (k - i);
                    }
                    for (lll j = k; j < n; j++)
                    {
                        arr[j] = arr[j - 1] + diff / (k - i);
                    }
                    break;
                }
            }
        }
        for (lll i : arr)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}