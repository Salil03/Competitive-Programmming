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

void dfs(vector<lll> graph[], bool visited[], lll node, lll parent)
{
    visited[node] = true;
    for (auto u : graph[node])
    {
        if (u != parent && !visited[u])
        {
            dfs(graph, visited, u, node);
        }
    }
    return;
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
        set<tuple<lll, lll, lll>> red, blue, blue2;
        for (lll i = 0; i < n; i++)
        {
            lll c, l, r;
            cin >> c >> l >> r;
            if (c == 0)
            {
                red.insert(make_tuple(l, r, i));
            }
            else
            {
                blue.insert(make_tuple(l, r, i));
                blue2.insert(make_tuple(l, r, i));
            }
        }
        dbg(red);
        dbg(blue);
        vector<lll> graph[n];
        for (auto k : red)
        {
            auto it1 = lower_bound(blue.begin(), blue.end(), make_tuple(get<0>(k), -2, -2));
            while (it1 != blue.end())
            {
                if (get<0>(*it1) <= get<1>(k) && get<0>(*it1) >= get<0>(k))
                {
                    graph[get<2>(*it1)].emplace_back(get<2>(k));
                    graph[get<2>(k)].emplace_back(get<2>(*it1));
                    it1 = blue.erase(it1);
                }
                else
                {
                    break;
                }
            }
        }
        for (auto k : blue2)
        {
            auto it1 = lower_bound(red.begin(), red.end(), make_tuple(get<0>(k), -2, -2));
            while (it1 != red.end())
            {
                if (get<0>(*it1) <= get<1>(k) && get<0>(*it1) >= get<0>(k))
                {
                    graph[get<2>(*it1)].emplace_back(get<2>(k));
                    graph[get<2>(k)].emplace_back(get<2>(*it1));
                    it1 = red.erase(it1);
                }
                else
                {
                    break;
                }
            }
        }
        dbga(graph, n);
        lll connected = 0;
        bool visited[n];
        memset(visited, 0, sizeof(visited));
        for (lll i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                connected++;
                dfs(graph, visited, i, -1);
            }
        }
        cout << connected << "\n";
    }
}