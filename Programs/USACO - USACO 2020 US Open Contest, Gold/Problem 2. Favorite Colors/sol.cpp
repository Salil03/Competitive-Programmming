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

void merger(lll a, lll b, vector<lll> graph[])
{
    sort(graph[a].begin(), graph[a].end());
    sort(graph[b].begin(), graph[b].end());
    vector<lll> res(graph[a].size() + graph[b].size());
    merge(graph[a].begin(), graph[a].end(), graph[b].begin(), graph[b].end(), res.begin());
    graph[b].clear();
    graph[a].clear();
    graph[a].emplace_back(res[0]);
    for (lll i = 1; i < res.size(); i++)
    {
        if (res[i] != res[i - 1])
        {
            graph[a].emplace_back(res[i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("fcolor.in", "r", stdin);
    freopen("fcolor.out", "w", stdout);
    lll n, m;
    cin >> n >> m;
    vector<lll> graph[n + 1];
    while (m--)
    {
        lll a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
    }
    for (auto u : graph)
    {
        sort(u.begin(), u.end());
    }
    vector<lll> merged[n + 1];
    queue<lll> q;
    for (lll i = 1; i <= n; i++)
    {
        if (graph[i].size() > 1)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        lll s = q.front();
        if (graph[s].size() <= 1)
        {
            q.pop();
            continue;
        }
        merger(graph[s][0], graph[s][1], graph);
        merged[graph[s][0]].emplace_back(graph[s][1]);
        graph[s].erase(graph[s].begin() + 1);
        if (graph[graph[s][0]].size() > 1)
        {
            q.push(graph[s][0]);
        }
    }
    lll final[n + 1];
    memset(final, 0, sizeof final);
    lll curr = 0;
    for (lll i = 1; i <= n; i++)
    {
        if (!merged[i].empty() && final[i] == 0)
        {
            curr++;
            final[i] = curr;
            for (lll u : merged[i])
            {
                final[u] = curr;
            }
        }
    }
    for (lll i = 1; i <= n; i++)
    {
        cout << final[i] << "\n";
    }
}