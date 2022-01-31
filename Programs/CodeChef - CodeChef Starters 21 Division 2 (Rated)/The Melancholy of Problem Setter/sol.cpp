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
string c;

bool dfs_blue(vector<lll> graph[], lll node, lll parent, bool red)
{
    if (red)
    {
        if (c[node - 1] == 'G')
        {
            return true;
        }
        else if (c[node - 1] == 'B')
        {
            return false;
        }
        else
        {
            for (auto p : graph[node])
            {
                if (p == parent)
                {
                    continue;
                }
                bool flag = dfs_blue(graph, p, node, red);
                if (!flag)
                {
                    return false;
                }
            }
            return true;
        }
    }
    else
    {
        if (c[node - 1] == 'R')
        {
            return true;
        }
        else if (c[node - 1] == 'B')
        {
            return false;
        }
        else
        {
            for (auto p : graph[node])
            {
                if (p == parent)
                {
                    continue;
                }
                bool flag = dfs_blue(graph, p, node, red);
                if (!flag)
                {
                    return false;
                }
            }
            return true;
        }
    }
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
        cin >> n >> c;
        vector<lll> graph[n + 1];
        for (lll i = 1; i < n; i++)
        {
            lll u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        bool ans = true;
        for (lll i = 1; i <= n; i++)
        {
            if (c[i - 1] == 'B')
            {
                for (auto u : graph[i])
                {
                    ans = dfs_blue(graph, u, i, c[u - 1] == 'R');
                    if (!ans)
                    {
                        cout << "No\n";
                        break;
                    }
                }
            }
            if (!ans)
            {
                break;
            }
        }
        if (ans)
        {
            cout << "Yes\n";
        }
    }
}