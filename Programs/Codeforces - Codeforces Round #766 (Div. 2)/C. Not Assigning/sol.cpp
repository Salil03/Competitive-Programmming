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
map<pair<lll, lll>, lll> mp;
void dfs(lll cnt, lll idx, pair<lll, lll> graph[], lll ans[], lll parent)
{
    // dbg(idx);
    // dbg(cnt);
    // dbg(graph[idx]);
    if (graph[idx].first == parent && graph[idx].second != 0)
    {
        ans[mp[make_pair(idx, graph[idx].second)]] = cnt;
        if (cnt == 2)
        {
            dfs(3, graph[idx].second, graph, ans, idx);
        }
        else
        {
            dfs(2, graph[idx].second, graph, ans, idx);
        }
    }
    if (graph[idx].second == parent && graph[idx].first != 0)
    {
        ans[mp[make_pair(idx, graph[idx].first)]] = cnt;
        if (cnt == 2)
        {
            dfs(3, graph[idx].first, graph, ans, idx);
        }
        else
        {
            dfs(2, graph[idx].first, graph, ans, idx);
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
        mp.clear();
        lll n;
        cin >> n;
        pair<lll, lll> graph[n + 1];
        for (lll i = 0; i <= n; i++)
        {
            graph[i] = make_pair(0, 0);
        }
        bool flag = false;
        lll ans[n - 1] = {0};

        for (lll i = 0; i < n - 1; i++)
        {
            lll u, v;
            cin >> u >> v;
            mp[make_pair(u, v)] = i;
            mp[make_pair(v, u)] = i;
            if (graph[u].first == 0)
            {
                graph[u].first = v;
            }
            else if (graph[u].second == 0)
            {
                graph[u].second = v;
            }
            else
            {
                flag = true;
            }

            if (graph[v].first == 0)
            {
                graph[v].first = u;
            }
            else if (graph[v].second == 0)
            {
                graph[v].second = u;
            }
            else
            {
                flag = true;
            }
        }
        if (flag)
        {
            cout << -1 << "\n";
            continue;
        }
        for (lll i = 1; i <= n; i++)
        {
            if (graph[i].first == 0 || graph[i].second == 0)
            {
                dfs(2, i, graph, ans, 0);
                break;
            }
        }
        for (lll i = 0; i < n - 1; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}