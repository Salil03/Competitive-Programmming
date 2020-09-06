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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("piggyback.in", "r", stdin);
    freopen("piggyback.out", "w", stdout);
    lll b, e, p, n, m;
    cin >> b >> e >> p >> n >> m;
    vector<lll> graph[n + 1];
    while (m--)
    {
        lll x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    lll distance_1[n + 1], distance_2[n + 1], distance_n[n + 1];
    for (lll i = 0; i <= n; i++)
    {
        distance_1[i] = INT_MAX;
        distance_2[i] = INT_MAX;
        distance_n[i] = INT_MAX;
    }
    bool visited[n + 1];
    queue<lll> q;
    memset(visited, 0, sizeof visited);
    visited[1] = 1;
    distance_1[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        lll s = q.front();
        q.pop();
        for (auto u : graph[s])
        {
            if (!visited[u])
            {
                visited[u] = true;
                distance_1[u] = distance_1[s] + 1;
                q.push(u);
            }
        }
    }
    memset(visited, 0, sizeof visited);
    visited[2] = 1;
    distance_2[2] = 0;
    q.push(2);
    while (!q.empty())
    {
        lll s = q.front();
        q.pop();
        for (auto u : graph[s])
        {
            if (!visited[u])
            {
                visited[u] = true;
                distance_2[u] = distance_2[s] + 1;
                q.push(u);
            }
        }
    }
    memset(visited, 0, sizeof visited);
    visited[n] = 1;
    distance_n[n] = 0;
    q.push(n);
    while (!q.empty())
    {
        lll s = q.front();
        q.pop();
        for (auto u : graph[s])
        {
            if (!visited[u])
            {
                visited[u] = true;
                distance_n[u] = distance_n[s] + 1;
                q.push(u);
            }
        }
    }
    dbga(distance_1, n + 1);
    dbga(distance_2, n + 1);
    dbga(distance_n, n + 1);
    lll minimum = INF;
    for (lll i = 1; i <= n; i++)
    {
        minimum = min(minimum, b * distance_1[i] + e * distance_2[i] + p * distance_n[i]);
    }
    cout << minimum;
}