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
lll n;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    cin >> n;
    cin >> s;
    lll arr[n];
    for (lll i = 0; i < n; i++)
    {
        if (s[i] == 'M')
        {
            arr[i] = 1;
        }
        else if (s[i] == 'F')
        {
            arr[i] = 2;
        }
        else if (s[i] == 'B')
        {
            arr[i] = 3;
        }
    }
    lll dp[2][4][4][4][4];
    memset(dp, 0, sizeof dp);
    for (lll idx = n; idx >= 0; idx--)
    {
        for (lll t_a = 0; t_a < 4; t_a++)
        {
            for (lll t_b = 0; t_b < 4; t_b++)
            {
                for (lll t_c = 0; t_c < 4; t_c++)
                {
                    for (lll t_d = 0; t_d < 4; t_d++)
                    {
                        if (idx == n)
                        {
                            dp[idx % 2][t_a][t_b][t_c][t_d] = 0;
                            continue;
                        }
                        lll ans = 0;
                        lll curr = arr[idx];
                        lll res1 = dp[(idx + 1) % 2][t_b][curr][t_c][t_d];
                        lll res2 = dp[(idx + 1) % 2][t_a][t_b][t_d][curr];
                        lll a = t_a;
                        lll b = t_b;
                        lll c = t_c;
                        lll d = t_d;
                        if (a <= 0)
                        {
                            a = curr;
                        }
                        if (b <= 0)
                        {
                            b = curr;
                        }
                        if (c <= 0)
                        {
                            c = curr;
                        }
                        if (d <= 0)
                        {
                            d = curr;
                        }
                        if (curr != a && curr != b && a != b)
                        {
                            ans = max(ans, 3 + res1);
                        }
                        else if ((curr == a && curr != b) || (curr == b && curr != a) || (a == b && curr != a))
                        {
                            ans = max(ans, 2 + res1);
                        }
                        else if (curr == a && a == b)
                        {
                            ans = max(ans, 1 + res1);
                        }

                        if (curr != c && curr != d && c != d)
                        {
                            ans = max(ans, 3 + res2);
                        }
                        else if ((curr == c && curr != d) || (curr == d && curr != c) || (c == d && curr != c))
                        {
                            ans = max(ans, 2 + res2);
                        }
                        else if (curr == c && c == d)
                        {
                            ans = max(ans, 1 + res2);
                        }
                        dp[idx % 2][t_a][t_b][t_c][t_d] = ans;
                    }
                }
            }
        }
    }
    cout << dp[0][0][0][0][0];
}