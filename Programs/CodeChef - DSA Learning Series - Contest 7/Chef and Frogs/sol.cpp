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

vector<lll> connected;

void dfs(vector<lll> graph[], lll node, bool visited[])
{
    if (visited[node])
    {
        return;
    }
    visited[node] = true;
    connected.push_back(node);
    for (auto u : graph[node])
    {
        dfs(graph, u, visited);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll n, k, p;
    cin >> n >> k >> p;
    lll arr[n];
    pair<lll, lll> sorted[n];
    for (lll i = 0; i < n; i++)
    {
        cin >> arr[i];
        sorted[i].first = arr[i];
        sorted[i].second = i;
    }
    sort(sorted, sorted + n);
    vector<lll> graph[n];
    if (abs(sorted[0].first - sorted[1].first) <= k)
    {
        graph[sorted[0].second].push_back(sorted[1].second);
    }
    for (lll i = 1; i < n - 1; i++)
    {
        if (abs(sorted[i].first - sorted[i + 1].first) <= k)
        {
            graph[sorted[i].second].push_back(sorted[i + 1].second);
        }
        if (abs(sorted[i - 1].first - sorted[i].first) <= k)
        {
            graph[sorted[i].second].push_back(sorted[i - 1].second);
        }
    }
    if (abs(sorted[n - 1].first - sorted[n - 2].first) <= k)
    {
        graph[sorted[n - 1].second].push_back(sorted[n - 2].second);
    }
    bool visited[n] = {0};
    vector<vector<lll>> components;
    for (lll i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            connected.clear();
            dfs(graph, i, visited);
            components.emplace_back(connected);
        }
    }
    lll final[n] = {0};
    for (lll i = 0; i < components.size(); i++)
    {
        for (lll j = 0; j < components[i].size(); j++)
        {
            final[components[i][j]] = i;
        }
    }
    while (p--)
    {
        lll x, y;
        cin >> x >> y;
        if (final[x - 1] == final[y - 1])
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}