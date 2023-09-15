#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef unsigned long long uu;
typedef long long int lll;
typedef unsigned long long int uuu;

#if defined(DEBUG)
#include "prettyprint.hpp"
#define dbga(x, n) cerr << "\n" \
                        << (#x) << " is " << pretty_print_array(x, n) << endl
#define dbg(x) cerr << "\n" \
                    << (#x) << " is " << x << endl
#endif

#if !defined(DEBUG)
#define dbga(x, n)
#define dbg(x)
#endif

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution < lll>(low, high)(rng)
// uniform_real_distribution<double>(low, high)(rng)

typedef tree<lll, null_type, less<lll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pair<lll, lll>, null_type, less<pair<lll, lll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
// gp_hash_table<int, int> table; unordered map

#define cel(x, y) 1 + ((x - 1) / y)
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const long long int INF = 0x3f3f3f3f3f3f3f3f;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll m, n;
    cin >> m >> n;
    lll grid[m + 2][n + 2] = {0};
    grid[1][1] = 1;
    grid[m][n] = 1;
    pair<lll, lll> start = {1, 1}, end = {m, n};
    string prefix = "", suffix = "";
    while (prefix.length() + suffix.length() < m + n - 2)
    {
        bool found = true;
        for (lll i = start.first + 1; i <= end.first; i++)
        {
            for (lll j = start.second; j < end.second; j++)
            {
                if (grid[i][j] != -1)
                {
                    found = false;
                }
            }
        }
        if (found)
        {
            for (lll i = start.second; i < end.second; i++)
            {
                prefix += 'R';
            }
            for (lll i = start.first; i < end.first; i++)
            {
                prefix += 'D';
            }
            break;
        }
        found = true;
        for (lll i = start.first; i < end.first; i++)
        {
            for (lll j = start.second + 1; j <= end.second; j++)
            {
                if (grid[i][j] != -1)
                {
                    found = false;
                }
            }
        }
        if (found)
        {
            for (lll i = start.first; i < end.first; i++)
            {
                prefix += 'D';
            }
            for (lll i = start.second; i < end.second; i++)
            {
                prefix += 'R';
            }
            break;
        }
        string mid = "";
        bool flag = true;
        for (lll i = start.second; i <= end.second; i++)
        {
            if (grid[start.first][i] == -1)
            {
                flag = false;
                break;
            }
        }
        for (lll i = start.first; i <= end.first; i++)
        {
            if (grid[i][end.second] == -1)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            for (lll i = start.second; i < end.second; i++)
            {
                mid += 'R';
            }
            for (lll i = start.first; i < end.first; i++)
            {
                mid += 'D';
            }
            cout << "? " << prefix + mid + suffix << endl;
            lll t;
            cin >> t;
            while (t--)
            {
                lll r, c;
                cin >> r >> c;
                grid[r][c] = 1;
            }
            bool flag2 = true;
            for (lll i = start.second + 1; i <= end.second; i++)
            {
                if (grid[start.first][i] == 1 && flag2)
                {
                    prefix += 'R';
                    start = {start.first, i};
                }
                else
                {
                    grid[start.first][i] = -1;
                    flag2 = false;
                }
            }
            flag2 = true;
            for (lll i = end.first - 1; i >= start.first; i--)
            {
                if (grid[i][end.second] == 1 && flag2)
                {
                    suffix = 'D' + suffix;
                    end = {i, end.second};
                }
                else
                {
                    grid[i][end.second] = -1;
                    flag2 = false;
                }
            }
        }
        else
        {
            for (lll i = start.first; i < end.first; i++)
            {
                mid += 'D';
            }
            for (lll i = start.second; i < end.second; i++)
            {
                mid += 'R';
            }
            cout << "? " << prefix + mid + suffix << endl;
            lll t;
            cin >> t;
            while (t--)
            {
                lll r, c;
                cin >> r >> c;
                grid[r][c] = 1;
            }
            bool flag2 = true;
            for (lll i = start.first + 1; i <= end.first; i++)
            {
                if (grid[i][start.second] == 1 && flag2)
                {
                    prefix += 'D';
                    start = {i, start.second};
                }
                else
                {
                    grid[i][start.second] = -1;
                    flag2 = false;
                }
            }
            flag2 = true;
            for (lll i = end.second - 1; i >= start.second; i--)
            {
                if (grid[end.first][i] == 1 && flag2)
                {
                    suffix = 'R' + suffix;
                    end = {end.first, i};
                }
                else
                {
                    grid[end.first][i] = -1;
                    flag2 = false;
                }
            }
        }
    }
    cout << "! " << prefix + suffix << endl;
}