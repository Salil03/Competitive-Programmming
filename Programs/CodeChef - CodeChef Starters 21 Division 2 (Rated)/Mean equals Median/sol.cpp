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
    lll t;
    cin >> t;
    while (t--)
    {
        lll n;
        cin >> n;
        lll arr[n], sum = 0;
        for (lll i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        sort(arr, arr + n);
        lll median = 0, curr = 0, original = 0;
        if (n & 1)
        {
            median = arr[(n - 1) / 2];
            curr = (n - 1) / 2;
            original = curr;
        }
        else
        {
            median = arr[(n / 2) - 1];
            curr = (n / 2) - 1;
            original = curr;
        }
        lll ans = 0;
        while (sum > n * median)
        {
            if (sum + (curr - original + 1) * (arr[curr + 1] - arr[curr]) > n * arr[curr + 1])
            {
                sum += (curr - original + 1) * (arr[curr + 1] - arr[curr]);
                ans += (curr - original + 1) * (arr[curr + 1] - arr[curr]);
                curr++;
                median = arr[curr];
            }
            else
            {
                lll p = 1 + ((sum - n * arr[curr] - 1) / (n + original - curr - 1));
                sum += (curr + 1 - original) * p;
                ans += (curr + 1 - original) * p;
                median = arr[curr] + p;
            }
        }
        cout << ans + (n * median - sum) << "\n";
    }
}