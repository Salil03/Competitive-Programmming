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

lll cnt = 0, in = 0;
lll recur(lll node, lll parent, vector<lll> graph_un[], vector<lll> graph_dir[], lll source)
{
    if (node == source)
    {
        for (auto u : graph_un[node])
        {
            if (!binary_search(graph_dir[node].begin(), graph_dir[node].end(), u))
            {
                in++;
            }
            recur(u, node, graph_un, graph_dir, source);
        }
    }
    else
    {
        for (auto u : graph_un[node])
        {
            if (u != parent)
            {
                if (!binary_search(graph_dir[node].begin(), graph_dir[node].end(), u))
                {
                    cnt++;
                }
                recur(u, node, graph_un, graph_dir, source);
            }
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
        cin >> n;
        vector<lll> graph_un[n + 1], graph_dir[n + 1];
        for (lll i = 0; i < n - 1; i++)
        {
            lll u, v;
            cin >> u >> v;
            graph_dir[u].push_back(v);
            graph_un[u].push_back(v);
            graph_un[v].push_back(u);
        }
        for (lll i = 1; i <= n; i++)
        {
            sort(graph_dir[i].begin(), graph_dir[i].end());
            sort(graph_un[i].begin(), graph_un[i].end());
        }
        lll minimum = INT_MAX;
        for (lll i = 1; i <= n; i++)
        {
            cnt = 0;
            in = 0;
            recur(i, -1, graph_un, graph_dir, i);
            minimum = min(minimum, cnt + max(0LL, in - 1));
        }
        cout << minimum << "\n";
    }
}