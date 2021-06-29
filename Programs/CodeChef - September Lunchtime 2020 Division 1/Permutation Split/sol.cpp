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

bool inversions(lll mask1, lll mask2, lll arr[], lll n)
{
    vector<lll> v1, v2;
    for (lll i = 0; i < n; i++)
    {
        if (mask1 & (1 << i))
        {
            v1.emplace_back(arr[i]);
        }
        else if (mask2 & (1 << i))
        {
            v2.emplace_back(arr[i]);
        }
    }
    lll cnt1 = 0, cnt2 = 0, len1 = v1.size(), len2 = v2.size();
    for (lll i = 1; i < len1; i++)
    {
        for (lll j = 0; j < i; j++)
        {
            if (v1[j] > v1[i])
            {
                cnt1++;
            }
        }
    }
    for (lll i = 1; i < len2; i++)
    {
        for (lll j = 0; j < i; j++)
        {
            if (v2[j] > v2[i])
            {
                cnt2++;
            }
        }
    }
    return (cnt1 == cnt2);
}

bool recur(lll mask1, lll mask2, lll idx, lll n, lll arr[])
{
    if (idx == n)
    {
        return inversions(mask1, mask2, arr, n);
    }
    return (recur(mask1 | (1 << idx), mask2, idx + 1, n, arr) || recur(mask1, mask2 | (1 << idx), idx + 1, n, arr));
}

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
        lll arr[n];
        for (lll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (recur(0, 0, 0, n, arr))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}