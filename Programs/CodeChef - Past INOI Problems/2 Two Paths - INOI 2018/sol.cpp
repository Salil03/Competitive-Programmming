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

lll arr[1002][1002];
lll pref[1002][1002];
lll n, m, k;
// lll max_recur(lll row, lll col, lll moves)
// {
//     if (row == -1)
//     {
//         return 0;
//     }
//     if (col < 0)
//     {
//         return INT_MIN;
//     }
//     if (table[row][col][moves][0] != -1)
//     {
//         return table[row][col][moves][0];
//     }
//     if (moves == k)
//     {
//         return table[row][col][moves][0] = pref[row][col] + max_recur(row - 1, col, moves);
//     }
//     return table[row][col][moves][0] = pref[row][col] + max(max_recur(row - 1, col - 1, moves + 1), max_recur(row - 1, col, moves));
// }

// lll min_recur(lll row, lll col, lll moves)
// {
//     if (row == -1)
//     {
//         return 0;
//     }
//     if (col < 0)
//     {
//         return INT_MAX;
//     }
//     if (table[row][col][moves][1] != -1)
//     {
//         return table[row][col][moves][1];
//     }
//     if (moves == k)
//     {
//         if (col == 0)
//         {
//             return table[row][col][moves][1] = min_recur(row - 1, col, moves);
//         }
//         return table[row][col][moves][1] = pref[row][col - 1] + min_recur(row - 1, col, moves);
//     }
//     if (col == 0)
//     {
//         return table[row][col][moves][1] = min(min_recur(row - 1, col - 1, moves + 1), min_recur(row - 1, col, moves));
//     }
//     return table[row][col][moves][1] = pref[row][col - 1] + min(min_recur(row - 1, col - 1, moves + 1), min_recur(row - 1, col, moves));
// }

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
        cin >> n >> m >> k;
        memset(arr, 0, sizeof arr);
        memset(pref, 0, sizeof pref);
        for (lll i = 0; i < n; i++)
        {
            for (lll j = 0; j < m; j++)
            {
                cin >> arr[i][j];
                if (j == 0)
                {
                    pref[i][j] = arr[i][j];
                }
                else
                {
                    pref[i][j] = arr[i][j] + pref[i][j - 1];
                }
            }
        }
        lll dp_min[m], dp_max[m];
        lll table[2][n][k + 1][2];
        memset(table, -1, sizeof table);
        for (lll row = 0; row < n; row++)
        {
            for (lll col = 0; col < n; col++)
            {
                for (lll moves = k; moves >= 0; moves--)
                {
                    if (row == 0)
                    {
                        table[row % 2][col][moves][0] = pref[row][col];
                    }
                    else if (col == 0 || moves == k)
                    {
                        table[row % 2][col][moves][0] = pref[row][col] + table[(row - 1) % 2][col][moves][0];
                    }
                    else
                    {
                        table[row % 2][col][moves][0] = pref[row][col] + max(table[(row - 1) % 2][col - 1][moves + 1][0], table[(row - 1) % 2][col][moves][0]);
                    }
                }
            }
        }
        for (lll row = 0; row < n; row++)
        {
            for (lll col = 0; col < n; col++)
            {
                for (lll moves = k; moves >= 0; moves--)
                {
                    lll curr = 0;
                    if (col != 0)
                    {
                        curr = pref[row][col - 1];
                    }
                    if (row == 0)
                    {
                        table[row % 2][col][moves][1] = curr;
                    }
                    else if (moves == k || col == 0)
                    {
                        table[row % 2][col][moves][1] = curr + table[(row - 1) % 2][col][moves][1];
                    }
                    else
                    {
                        table[row % 2][col][moves][1] = curr + min(table[(row - 1) % 2][col - 1][moves + 1][1], table[(row - 1) % 2][col][moves][1]);
                    }
                }
            }
        }
        for (lll i = 0; i < m; i++)
        {
            dp_min[i] = table[(n - 1) % 2][i][0][1];
            dp_max[i] = table[(n - 1) % 2][i][0][0];
        }
        lll maximum = INT_MIN;
        for (lll i = k + 1; i < m; i++)
        {
            for (lll j = 0; j <= i - k - 1; j++)
            {
                maximum = max(maximum, dp_max[i] - dp_min[j]);
            }
        }
        cout << maximum << "\n";
    }
}