#include "bits/stdc++.h"
typedef long long ll;
typedef unsigned long long uu;
typedef long long int lll;
typedef unsigned long long int uuu;
using namespace std;

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
#define cel(x, y) 1 + ((x - 1) / y)
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const long long int INF = 0x3f3f3f3f3f3f3f3f;
lll n, m;
vector<tuple<lll, lll, lll>> edges;
vector<pair<lll, lll>> div_graph[100001];

void dfs(lll node, lll parent, vector<lll> temp_graph[], vector<bool> &visited)
{
    visited[node] = true;
    for (auto u : temp_graph[node])
    {
        if (u == parent || visited[u])
        {
            continue;
        }
        dfs(u, node, temp_graph, visited);
    }
}

bool check(lll ans)
{
    vector<lll> temp_graph[n];
    for (auto u : div_graph[ans])
    {
        temp_graph[u.first].emplace_back(u.second);
        temp_graph[u.second].emplace_back(u.first);
    }
    vector<bool> visited(n, 0);
    dfs(0, -1, temp_graph, visited);
    for (lll i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    cin >> n >> m;
    for (lll i = 0; i < m; i++)
    {
        lll u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(make_tuple(u - 1, v - 1, w));
        for (lll j = 1; j * j <= w; j++)
        {
            if (w % j == 0)
            {
                if (j * j == w)
                {
                    div_graph[j].emplace_back(make_pair(u - 1, v - 1));
                }
                else
                {
                    div_graph[j].emplace_back(make_pair(u - 1, v - 1));
                    div_graph[w / j].emplace_back(make_pair(u - 1, v - 1));
                }
            }
        }
    }
    // bool removed[100005];
    // memset(removed, 0, sizeof(removed));
    // lll maximum = -1;
    for (lll u = 100000; u >= 1; u--)
    {
        if (check(u))
        {
            cout << u;
            return 0;
        }
    }
    cout << -1;
}