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

bool check(double arr[], double time, lll n, double d)
{
    double next = 0.0;
    for (lll i = 0; i < n; i++)
    {
        if (next < arr[i])
        {
            next = arr[i] + time;
        }
        else if (next > arr[i] + d)
        {
            return false;
        }
        else
        {
            next += time;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lll t;
    cin >> t;
    while (t--)
    {
        double d;
        lll n;
        cin >> n >> d;
        double arr[n];
        for (lll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        double low = 0.0, high = 10000000000.0;
        double mid = (low + high) / 2, ans = 0.0;
        while (fabs(high - low) > 1e-6)
        {
            mid = (low + high) / 2.0;
            dbg(mid);
            if (check(arr, mid, n, d))
            {
                ans = mid;
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
        cout << fixed << setprecision(10) << ans << "\n";
    }
}