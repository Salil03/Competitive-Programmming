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
#define dbga(x, n) cerr << "\n" << (#x) << " is " << pretty_print_array(x, n) << endl
#define dbg(x) cerr << "\n" << (#x) << " is " << x << endl
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
    freopen("reorder.in", "r", stdin);
    freopen("reorder.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lll n;
    cin >> n;
    lll a[n], b[n];
    for (lll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (lll i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    lll cnt = 0, maximum = 0;
    for (lll i = 0; i < n; i++)
    {
        lll curr = a[i];
        if (b[i] != curr)
        {
            cnt++;
            lll len = 0;
            bool flag = true;
            while (flag)
            {
                for (int j = 0; j < n; j++)
                {
                    if (b[j] == curr)
                    {
                        swap(curr, a[j]);
                        if (j == i)
                        {
                            flag = false;
                        }
                        break;
                    }
                }
                len++;
            }
            maximum = max(maximum, len);
        }
    }
    if (cnt == 0)
    {
        cout << "0 -1";
    }
    else
    {
        cout << cnt << " " << maximum;
    }
}