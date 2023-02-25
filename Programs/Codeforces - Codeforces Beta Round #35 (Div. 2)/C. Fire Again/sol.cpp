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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    lll n, m;
    cin >> n >> m;
    lll k;
    cin >> k;
    bool visited[n][m];
    memset(visited, 0, sizeof(visited));
    queue<pair<lll, lll>> q;
    lll distance[n][m];
    for (lll i = 0; i < n; i++)
    {
        for (lll j = 0; j < m; j++)
        {
            distance[i][j] = INT_MAX;
        }
    }
    for (lll i = 0; i < k; i++)
    {
        lll x, y;
        cin >> x >> y;
        x--;
        y--;
        visited[x][y] = true;
        distance[x][y] = 0;
        q.push({x, y});
    }
    while (!q.empty())
    {
        lll x = q.front().first, y = q.front().second;
        q.pop();
        if (x > 0)
        {
            distance[x - 1][y] = min(distance[x - 1][y], distance[x][y] + 1);
            if (!visited[x - 1][y])
            {
                q.push({x - 1, y});
                visited[x - 1][y] = true;
            }
        }
        if (y > 0)
        {
            distance[x][y - 1] = min(distance[x][y - 1], distance[x][y] + 1);
            if (!visited[x][y - 1])
            {
                q.push({x, y - 1});
                visited[x][y - 1] = true;
            }
        }
        if (x < n - 1)
        {
            distance[x + 1][y] = min(distance[x + 1][y], distance[x][y] + 1);
            if (!visited[x + 1][y])
            {
                q.push({x + 1, y});
                visited[x + 1][y] = true;
            }
        }
        if (y < m - 1)
        {
            distance[x][y + 1] = min(distance[x][y + 1], distance[x][y] + 1);
            if (!visited[x][y + 1])
            {
                q.push({x, y + 1});
                visited[x][y + 1] = true;
            }
        }
    }
    pair<lll, lll> ans;
    lll maximum = 0;
    for (lll i = 0; i < n; i++)
    {
        for (lll j = 0; j < m; j++)
        {
            if (distance[i][j] >= maximum)
            {
                maximum = distance[i][j];
                ans = {i + 1, j + 1};
            }
        }
    }
    cout << ans.first << " " << ans.second;
}