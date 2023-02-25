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

vector<lll> path;

bool cycle(lll node, lll parent, vector<lll> graph[], bool visited[], lll k)
{
    visited[node] = true;
    for (auto u : graph[node])
    {
        if (u == parent)
        {
            continue;
        }
        if (visited[u])
        {
            lll length = path.size();
            for (lll idx = 0; idx < length; idx++)
            {
                if (path[idx] == u)
                {
                    if (length - idx <= k)
                    {
                        path.emplace_back(u);
                        return true;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            continue;
        }
        path.emplace_back(u);
        if (cycle(u, node, graph, visited, k))
        {
            return true;
        }
    }
    path.pop_back();
    return false;
}

bool cycle_2(lll node, lll parent, vector<lll> graph[], bool visited[])
{
    visited[node] = true;
    for (auto u : graph[node])
    {
        if (u == parent)
        {
            continue;
        }
        if (visited[u])
        {
            path.emplace_back(u);
            return true;
        }
        path.emplace_back(u);
        if (cycle_2(u, node, graph, visited))
        {
            return true;
        }
    }
    path.pop_back();
    return false;
}

void bipartite(lll node, lll parent, vector<lll> graph[], bool color[], bool visited[])
{
    if (parent >= 0)
    {
        color[node] = !color[parent];
    }
    visited[node] = true;
    for (auto u : graph[node])
    {
        if (!visited[u] && u != parent)
        {
            bipartite(u, node, graph, color, visited);
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
    lll n, m, k;
    cin >> n >> m >> k;
    vector<lll> graph[n];
    while (m--)
    {
        lll u, v;
        cin >> u >> v;
        graph[u - 1].emplace_back(v - 1);
        graph[v - 1].emplace_back(u - 1);
    }
    bool visited[n];
    memset(visited, 0, sizeof visited);
    path.emplace_back(0);
    if (cycle(0, -1, graph, visited, k))
    {
        cout << 2 << "\n";
        lll length = path.size();
        for (lll i = 0; i < length; i++)
        {
            if (path[i] == path[length - 1])
            {
                cout << length - i - 1 << "\n";
                for (lll j = i; j < length - 1; j++)
                {
                    cout << path[j] + 1 << " ";
                }
                break;
            }
        }
    }
    else
    {
        memset(visited, 0, sizeof visited);
        path.clear();
        path.emplace_back(0);
        if (cycle_2(0, -1, graph, visited))
        {
            cout << 1 << "\n";
            lll length = path.size();
            for (lll i = length - 1, num = 0; i >= 0 && num < (k + 1) / 2; i -= 2, num++)
            {
                cout << path[i] + 1 << " ";
            }
            return 0;
        }
        memset(visited, 0, sizeof visited);
        bool color[n];
        memset(color, 0, sizeof color);
        bipartite(0, -1, graph, color, visited);
        vector<lll> blue, red;
        for (lll i = 0; i < n; i++)
        {
            if (color[i])
            {
                blue.emplace_back(i);
            }
            else
            {
                red.emplace_back(i);
            }
        }
        cout << 1 << "\n";
        if (red.size() > blue.size())
        {
            for (lll i = 0; i < (k + 1) / 2; i++)
            {
                cout << red[i] + 1 << " ";
            }
        }
        else
        {
            for (lll i = 0; i < (k + 1) / 2; i++)
            {
                cout << blue[i] + 1 << " ";
            }
        }
    }
}