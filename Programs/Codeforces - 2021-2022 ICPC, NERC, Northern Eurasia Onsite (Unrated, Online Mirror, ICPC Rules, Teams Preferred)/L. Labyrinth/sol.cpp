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
lll s;

lll dfs(lll node, lll parent, vector<lll> graph[], set<lll> &visited, set<lll> &visited_temp)
{
    dbg(node);
    visited_temp.insert(node);
    if (visited.find(node) != visited.end())
    {
        return node;
    }
    for (auto u : graph[node])
    {
        if (u == parent || visited_temp.find(u) != visited_temp.end())
        {
            continue;
        }
        lll temp = dfs(u, node, graph, visited, visited_temp);
        if (temp != -1)
        {
            return temp;
        }
    }
    return -1;
}

vector<lll> anss;

bool dfs2(lll node, lll parent, vector<lll> graph[], set<lll> &visited, lll target)
{
    anss.emplace_back(node);
    visited.insert(node);
    if (node == target)
    {
        return true;
    }
    for (auto u : graph[node])
    {
        if (u == parent || visited.find(u) != visited.end())
        {
            continue;
        }
        if (dfs2(u, node, graph, visited, target))
        {
            return true;
        }
    }
    anss.pop_back();
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll n, m;
    cin >> n >> m >> s;
    if (n == 2)
    {
        cout << "Impossible\n";
        return 0;
    }
    vector<lll> graph[n];
    for (lll i = 0; i < m; i++)
    {
        lll u, v;
        cin >> u >> v;
        graph[u - 1].emplace_back(v - 1);
    }
    set<lll> visited, visited_temp;
    visited.insert(s - 1);
    visited_temp.insert(s - 1);
    lll ans = -1;
    for (auto u : graph[s - 1])
    {
        visited_temp.clear();
        visited_temp.insert(s - 1);
        ans = dfs(u, s - 1, graph, visited, visited_temp);
        for (auto k : visited_temp)
        {
            visited.insert(k);
        }
        if (ans != -1)
        {
            break;
        }
    }
    visited.clear();
    visited.insert(s - 1);
    if (ans == -1)
    {
        cout << "Impossible\n";
    }
    else
    {
        lll cnt = 0;
        cout << "Possible\n";
        anss.push_back(s - 1);
        for (auto u : graph[s - 1])
        {
            if (dfs2(u, s - 1, graph, visited, ans))
            {
                cout << anss.size() << "\n";
                for (auto i : anss)
                {
                    cout << i + 1 << " ";
                }
                cout << "\n";
                cnt++;
            }
            visited.clear();
            visited.insert(s - 1);
            anss.clear();
            anss.push_back(s - 1);
            if (cnt == 2)
            {
                return 0;
            }
        }
    }
}