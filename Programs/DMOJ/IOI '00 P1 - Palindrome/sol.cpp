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

// int dp(int l, int r, string s)
// {
//     if (table[l][r] != -1)
//     {
//         return table[l][r];
//     }
//     if (l == r)
//     {
//         return table[l][r] = 0;
//     }
//     if (l == r - 1)
//     {
//         if (s[l] == s[r])
//         {
//             return table[l][r] = 0;
//         }
//         else
//         {
//             return table[l][r] = 1;
//         }
//     }
//     if (s[l] == s[r])
//     {
//         return table[l][r] = dp(l + 1, r - 1, s);
//     }
//     else
//     {
//         return table[l][r] = min(dp(l + 1, r, s), dp(l, r - 1, s)) + 1;
//     }
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lll n;
    cin >> n;
    string s;
    cin >> s;
    lll dp[2][n];
    for (lll i = n - 1; i >= 0; i--)
    {
        for (lll j = i; j < n; j++)
        {
            if (i >= j)
            {
                dp[i % 2][j] = 0;
            }
            else if (i == j - 1)
            {
                if (s[i] == s[j])
                {
                    dp[i % 2][j] = 0;
                }
                else
                {
                    dp[i % 2][j] = 1;
                }
            }
            else if (s[i] == s[j])
            {
                dp[i % 2][j] = dp[(i + 1) % 2][j - 1];
            }
            else
            {
                dp[i % 2][j] = min(dp[(i + 1) % 2][j], dp[i % 2][j - 1]) + 1;
            }
        }
    }
    cout << dp[0][n - 1];
}
