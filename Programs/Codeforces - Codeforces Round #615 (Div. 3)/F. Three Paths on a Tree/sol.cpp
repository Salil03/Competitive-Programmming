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

void dfs(vector<vector<lll>> &graph, lll distance[], lll parent, lll node)
{
    for (auto u : graph[node])
    {
        if (u != parent)
        {
            distance[u] = min(distance[u], distance[node] + 1);
            dfs(graph, distance, node, u);
        }
    }
}

vector<lll> path;

bool path_find(vector<vector<lll>> &graph, lll parent, lll node, lll target)
{
    if (node == target)
    {
        return true;
    }
    for (auto u : graph[node])
    {
        if (u != parent)
        {
            path.emplace_back(u);
            if (!path_find(graph, node, u, target))
            {
                path.pop_back();
            }
            else
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll n;
    cin >> n;
    vector<vector<lll>> graph(n, vector<lll>());
    for (lll i = 0; i < n - 1; i++)
    {
        lll u, v;
        cin >> u >> v;
        graph[u - 1].emplace_back(v - 1);
        graph[v - 1].emplace_back(u - 1);
    }
    lll distance[n];
    for (lll i = 0; i < n; i++)
    {
        distance[i] = INT_MAX;
    }
    distance[0] = 0;
    dfs(graph, distance, -1, 0);
    lll a = 0, maximum = -1;
    for (lll i = 0; i < n; i++)
    {
        if (distance[i] >= maximum)
        {
            maximum = distance[i];
            a = i;
        }
    }
    for (lll i = 0; i < n; i++)
    {
        distance[i] = INT_MAX;
    }
    distance[a] = 0;
    dfs(graph, distance, -1, a);
    lll b = 0;
    maximum = -1;
    for (lll i = 0; i < n; i++)
    {
        if (distance[i] >= maximum)
        {
            maximum = distance[i];
            b = i;
        }
    }
    path.emplace_back(a);
    path_find(graph, -1, a, b);
    if (path.size() == n)
    {
        cout << n - 1 << "\n";
        cout << path[0] + 1 << " " << path[1] + 1 << " " << path[n - 1] + 1 << "\n";
        return 0;
    }
    queue<lll> q;
    bool visited[n];
    lll dist[n];
    memset(visited, 0, sizeof(visited));
    for (lll i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    for (auto u : path)
    {
        visited[u] = true;
        dist[u] = 0;
        q.push(u);
    }
    while (!q.empty())
    {
        lll s = q.front();
        q.pop();
        for (auto u : graph[s])
        {
            if (visited[u])
                continue;
            visited[u] = true;
            dist[u] = min(dist[u], dist[s] + 1);
            q.push(u);
        }
    }
    lll c = 0;
    maximum = -1;
    for (lll i = 0; i < n; i++)
    {
        if (dist[i] >= maximum)
        {
            maximum = dist[i];
            c = i;
        }
    }
    cout << path.size() - 1 + maximum << "\n";
    cout << a + 1 << " " << b + 1 << " " << c + 1;
    return 0;
}