
// Problem : B. Power Sequence
// Contest : Codeforces - Codeforces Round #666 (Div. 2)
// URL : https://codeforces.com/contest/1397/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

double kthRoot(lll n, lll k)
{
    return pow(k, (1.0 / k) * (log(n) / log(k)));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lll n;
    cin >> n;
    lll arr[n];
    for (lll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    lll minimum = INT_MAX;
    lll limit = kthRoot(10e9, n - 1);
    dbg(limit);
    for (lll c = 1; c <= limit + 3; c++)
    {
        lll sum = 0;
        lll curr = 1;
        for (lll i = 0; i < n; i++)
        {
            sum += abs(arr[i] - curr);
            curr *= c;
        }
        minimum = min(minimum, sum);
    }
    cout << minimum << "\n";
}