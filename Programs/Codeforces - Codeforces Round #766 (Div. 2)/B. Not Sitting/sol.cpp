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
        lll n, m;
        cin >> n >> m;
        bool grid[n][m];
        memset(grid, 0, sizeof(grid));
        if (n & 1 && m & 1)
        {
            lll start = n / 2 + m / 2;
            queue<pair<lll, lll>> q1, q2;
            q1.push(make_pair(n / 2, m / 2));
            grid[n / 2][m / 2] = true;
            while (!q1.empty())
            {
                while (!q1.empty())
                {
                    q2.push(q1.front());
                    q1.pop();
                }
                while (!q2.empty())
                {
                    pair<lll, lll> curr = q2.front();
                    q2.pop();
                    cout << start << " ";
                    if (curr.first - 1 >= 0)
                    {
                        if (!grid[curr.first - 1][curr.second])
                        {
                            q1.push(make_pair(curr.first - 1, curr.second));
                            grid[curr.first - 1][curr.second] = true;
                        }
                    }
                    if (curr.first + 1 < n)
                    {
                        if (!grid[curr.first + 1][curr.second])
                        {
                            q1.push(make_pair(curr.first + 1, curr.second));
                            grid[curr.first + 1][curr.second] = true;
                        }
                    }
                    if (curr.second - 1 >= 0)
                    {
                        if (!grid[curr.first][curr.second - 1])
                        {
                            q1.push(make_pair(curr.first, curr.second - 1));
                            grid[curr.first][curr.second - 1] = true;
                        }
                    }
                    if (curr.second + 1 < m)
                    {
                        if (!grid[curr.first][curr.second + 1])
                        {
                            q1.push(make_pair(curr.first, curr.second + 1));
                            grid[curr.first][curr.second + 1] = true;
                        }
                    }
                }
                start++;
            }
        }
        else if (n & 1)
        {
            lll start = n / 2 + m / 2;
            queue<pair<lll, lll>> q1, q2;
            q1.push(make_pair(n / 2, m / 2 - 1));
            q1.push(make_pair(n / 2, m / 2));
            grid[n / 2][m / 2 - 1] = true;
            grid[n / 2][m / 2] = true;
            while (!q1.empty())
            {
                while (!q1.empty())
                {
                    q2.push(q1.front());
                    q1.pop();
                }
                while (!q2.empty())
                {
                    pair<lll, lll> curr = q2.front();
                    q2.pop();
                    cout << start << " ";
                    if (curr.first - 1 >= 0)
                    {
                        if (!grid[curr.first - 1][curr.second])
                        {
                            q1.push(make_pair(curr.first - 1, curr.second));
                            grid[curr.first - 1][curr.second] = true;
                        }
                    }
                    if (curr.first + 1 < n)
                    {
                        if (!grid[curr.first + 1][curr.second])
                        {
                            q1.push(make_pair(curr.first + 1, curr.second));
                            grid[curr.first + 1][curr.second] = true;
                        }
                    }
                    if (curr.second - 1 >= 0)
                    {
                        if (!grid[curr.first][curr.second - 1])
                        {
                            q1.push(make_pair(curr.first, curr.second - 1));
                            grid[curr.first][curr.second - 1] = true;
                        }
                    }
                    if (curr.second + 1 < m)
                    {
                        if (!grid[curr.first][curr.second + 1])
                        {
                            q1.push(make_pair(curr.first, curr.second + 1));
                            grid[curr.first][curr.second + 1] = true;
                        }
                    }
                }
                start++;
            }
        }
        else if (m & 1)
        {
            lll start = n / 2 + m / 2;
            queue<pair<lll, lll>> q1, q2;
            q1.push(make_pair(n / 2 - 1, m / 2));
            q1.push(make_pair(n / 2, m / 2));
            grid[n / 2 - 1][m / 2] = true;
            grid[n / 2][m / 2] = true;
            while (!q1.empty())
            {
                while (!q1.empty())
                {
                    q2.push(q1.front());
                    q1.pop();
                }
                while (!q2.empty())
                {
                    pair<lll, lll> curr = q2.front();
                    q2.pop();
                    cout << start << " ";
                    if (curr.first - 1 >= 0)
                    {
                        if (!grid[curr.first - 1][curr.second])
                        {
                            q1.push(make_pair(curr.first - 1, curr.second));
                            grid[curr.first - 1][curr.second] = true;
                        }
                    }
                    if (curr.first + 1 < n)
                    {
                        if (!grid[curr.first + 1][curr.second])
                        {
                            q1.push(make_pair(curr.first + 1, curr.second));
                            grid[curr.first + 1][curr.second] = true;
                        }
                    }
                    if (curr.second - 1 >= 0)
                    {
                        if (!grid[curr.first][curr.second - 1])
                        {
                            q1.push(make_pair(curr.first, curr.second - 1));
                            grid[curr.first][curr.second - 1] = true;
                        }
                    }
                    if (curr.second + 1 < m)
                    {
                        if (!grid[curr.first][curr.second + 1])
                        {
                            q1.push(make_pair(curr.first, curr.second + 1));
                            grid[curr.first][curr.second + 1] = true;
                        }
                    }
                }
                start++;
            }
        }
        else
        {
            lll start = n / 2 + m / 2;
            queue<pair<lll, lll>> q1, q2;
            q1.push(make_pair(n / 2 - 1, m / 2 - 1));
            q1.push(make_pair(n / 2 - 1, m / 2));
            q1.push(make_pair(n / 2, m / 2));
            q1.push(make_pair(n / 2, m / 2 - 1));
            grid[n / 2 - 1][m / 2 - 1] = true;
            grid[n / 2 - 1][m / 2] = true;
            grid[n / 2][m / 2] = true;
            grid[n / 2][m / 2 - 1] = true;
            while (!q1.empty())
            {
                while (!q1.empty())
                {
                    q2.push(q1.front());
                    q1.pop();
                }
                while (!q2.empty())
                {
                    pair<lll, lll> curr = q2.front();
                    q2.pop();
                    cout << start << " ";
                    if (curr.first - 1 >= 0)
                    {
                        if (!grid[curr.first - 1][curr.second])
                        {
                            q1.push(make_pair(curr.first - 1, curr.second));
                            grid[curr.first - 1][curr.second] = true;
                        }
                    }
                    if (curr.first + 1 < n)
                    {
                        if (!grid[curr.first + 1][curr.second])
                        {
                            q1.push(make_pair(curr.first + 1, curr.second));
                            grid[curr.first + 1][curr.second] = true;
                        }
                    }
                    if (curr.second - 1 >= 0)
                    {
                        if (!grid[curr.first][curr.second - 1])
                        {
                            q1.push(make_pair(curr.first, curr.second - 1));
                            grid[curr.first][curr.second - 1] = true;
                        }
                    }
                    if (curr.second + 1 < m)
                    {
                        if (!grid[curr.first][curr.second + 1])
                        {
                            q1.push(make_pair(curr.first, curr.second + 1));
                            grid[curr.first][curr.second + 1] = true;
                        }
                    }
                }
                start++;
            }
        }
        cout << "\n";
    }
}