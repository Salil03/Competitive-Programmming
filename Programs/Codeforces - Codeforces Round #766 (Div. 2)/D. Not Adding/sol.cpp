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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
    lll n;
    cin >> n;
    lll arr[n];
    for (lll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    lll minimum = arr[0];
    lll maximum = arr[n - 1];
    lll ans = 0;
    for (lll i = 2; i <= maximum; i++)
    {
        if (binary_search(arr, arr + n, i))
        {
            continue;
        }
        lll left = (minimum + i - 1) / i;
        left *= i;
        lll right = maximum;
        bool flag = false;
        for (lll j = left; j <= right; j += i)
        {
            for (lll k = left; k <= right; k += i)
            {
                if (binary_search(arr, arr + n, j) && binary_search(arr, arr + n, k) && __gcd(j, k) == i)
                {
                    dbg(i);
                    ans++;
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }
    }
    if (binary_search(arr, arr + n, 1))
    {
        cout << ans;
    }
    else
    {
        cout << ans + 1;
    }
}