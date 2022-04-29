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

lll n, m;
void dfs(vector<vector<char>> &graph, vector<vector<bool>> &visited, lll x, lll y)
{
    if (visited[x][y])
    {
        return;
    }
    visited[x][y] = true;
    if (x > 0)
    {
        if (graph[x - 1][y] == '.')
        {
            dfs(graph, visited, x - 1, y);
        }
    }
    if (x < n - 1)
    {
        if (graph[x + 1][y] == '.')
        {
            dfs(graph, visited, x + 1, y);
        }
    }
    if (y > 0)
    {
        if (graph[x][y - 1] == '.')
        {
            dfs(graph, visited, x, y - 1);
        }
    }
    if (y < m - 1)
    {
        if (graph[x][y + 1] == '.')
        {
            dfs(graph, visited, x, y + 1);
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
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (lll i = 0; i < n; i++)
    {
        for (lll j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    lll ans = 0;
    for (lll i = 0; i < n; i++)
    {
        for (lll j = 0; j < m; j++)
        {
            if (arr[i][j] == '.' && !visited[i][j])
            {
                dfs(arr, visited, i, j);
                ans++;
            }
        }
    }
    cout << ans;
}