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
    lll h, w;
    cin >> h >> w;
    string grid[h];
    bool flag = false;
    for (lll i = 0; i < h; i++)
    {
        cin >> grid[i];
    }
    for (lll i = 0; i < h; i++)
    {
        for (lll j = 0; j < w; j++)
        {
            if (grid[i][j] != '.')
            {
                flag = true;
                break;
            }
        }
    }
    if (!flag)
    {
        grid[0][0] = '1';
        flag = true;
    }
    bool color[h][w][5];
    for (lll i = 0; i < h; i++)
    {
        for (lll j = 0; j < w; j++)
        {
            for (lll k = 0; k < 5; k++)
            {
                color[i][j][k] = true;
            }
        }
    }
    bool visited[h][w] = {0};
    memset(visited, 0, sizeof(visited));
    while (flag)
    {
        // dbga(grid, h);
        flag = false;
        for (lll i = 0; i < h; i++)
        {
            for (lll j = 0; j < w; j++)
            {
                if (grid[i][j] == '.')
                {
                    flag = true;
                }
                else
                {
                    int value = grid[i][j] - '1';
                    // dbg(value);
                    // dbg(i);
                    // dbg(j);
                    if (i - 1 >= 0)
                    {
                        color[i - 1][j][value] = false;
                        visited[i - 1][j] = true;
                    }
                    if (j - 1 >= 0)
                    {
                        color[i][j - 1][value] = false;
                        visited[i][j - 1] = true;
                    }
                    if (i + 1 < h)
                    {
                        color[i + 1][j][value] = false;
                        visited[i + 1][j] = true;
                    }
                    if (j + 1 < w)
                    {
                        color[i][j + 1][value] = false;
                        visited[i][j + 1] = true;
                    }
                }
            }
        }
        for (lll i = 0; i < h; i++)
        {
            for (lll j = 0; j < w; j++)
            {
                if (grid[i][j] == '.' && visited[i][j])
                {
                    for (lll k = 0; k < 5; k++)
                    {
                        if (color[i][j][k])
                        {
                            bool make = true;
                            if (i - 1 >= 0 && grid[i - 1][j] == '1' + k)
                            {
                                make = false;
                            }
                            if (j - 1 >= 0 && grid[i][j - 1] == '1' + k)
                            {
                                make = false;
                            }
                            if (i + 1 < h && grid[i + 1][j] == '1' + k)
                            {
                                make = false;
                            }
                            if (j + 1 < w && grid[i][j + 1] == '1' + k)
                            {
                                make = false;
                            }
                            if (make)
                            {
                                grid[i][j] = '1' + k;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    for (lll i = 0; i < h; i++)
    {
        cout << grid[i] << "\n";
    }
}