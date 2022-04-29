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

void dfs(lll node, lll parent, vector<lll> graph[], vector<lll> tree[], bool visited[])
{
    if (!visited[node])
    {
        visited[node] = true;
    }
    for (auto u : graph[node])
    {
        if (u != parent)
        {
            if (visited[u])
            {
                tree[node].emplace_back(u);
            }
            else
            {
                tree[node].emplace_back(u);
                tree[u].emplace_back(node);
                dfs(u, node, graph, tree, visited);
            }
        }
    }
}

vector<lll> ans;

void backtrack(lll node, lll parent, lll target, lll)
{
}

lll dfs2(lll node, lll parent, vector<lll> tree[], bool visited[])
{
    if (!visited[node])
    {
        visited[node] = true;
    }
    for (auto u : tree[node])
    {
        if (u == parent)
        {
            continue;
        }
        if (visited[u])
        {
            return node;
        }
        else
        {
            lll ans = dfs2(u, node, tree, visited);
            if (ans != -1)
            {
                return ans;
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll n, m, s;
    cin >> n >> m >> s;
    vector<lll> graph[n], tree[n];
    for (lll i = 0; i < m; i++)
    {
        lll u, v;
        cin >> u >> v;
        graph[u - 1].emplace_back(v - 1);
        graph[v - 1].emplace_back(u - 1);
    }
    bool visited[n];
    memset(visited, 0, sizeof(visited));
    dfs(s - 1, -1, graph, tree, visited);
    memset(visited, 0, sizeof(visited));
    dbga(tree, n);
    cout << dfs2(s - 1, -1, tree, visited);
}