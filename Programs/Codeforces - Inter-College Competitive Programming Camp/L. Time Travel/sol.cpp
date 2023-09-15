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

void dfs(lll source, lll node, lll parent, vector<vector<lll>> &graph, vector<vector<lll>> &distance, vector<vector<lll>> &total_distance)
{
    for (auto &u : graph[node])
    {
        if (u != parent)
        {
            distance[source][u] += distance[source][node] + 1;
            total_distance[source][u] += distance[source][u];
            dfs(source, u, node, graph, distance, total_distance);
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
    lll n, k;
    cin >> n >> k;
    vector<vector<lll>> distance(n + 1, vector<lll>(n + 1, 0));
    vector<vector<lll>> temp_distance(n + 1, vector<lll>(n + 1, 0));
    vector<vector<lll>> graph(n + 1, vector<lll>());
    for (lll year = 0; year < k; year++)
    {
        for (lll i = 0; i <= n; i++)
        {
            fill(temp_distance[i].begin(), temp_distance[i].end(), 0);
            graph[i].clear();
        }
        for (lll i = 0; i < n - 1; i++)
        {
            lll x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        for (lll source = 1; source <= n; source++)
        {
            dfs(source, source, -1, graph, temp_distance, distance);
        }
    }
    lll curr = 0;
    for (lll i = 1; i <= n; i++)
    {
        for (lll j = 1; j <= n; j++)
        {
            curr = 0;
            for (lll mid = 1; mid <= n; mid++)
            {
                curr += distance[i][j] == (distance[i][mid] + distance[mid][j]);
            }
            cout << curr << " ";
        }
        cout << "\n";
    }
}