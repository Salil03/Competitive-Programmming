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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll n, s;
    cin >> n >> s;
    vector<lll> req(n), points(n);
    for (lll i = 0; i < n; i++)
    {
        cin >> req[i];
    }
    for (lll i = 0; i < n; i++)
    {
        cin >> points[i];
    }
    vector<vector<lll>> graph(n, vector<lll>(0));
    vector<vector<lll>> unlock(n, vector<lll>(0));
    priority_queue<pair<lll, lll>> process;
    for (lll i = 0; i < n; i++)
    {
        lll m;
        cin >> m;
        if (m == 0)
        {
            process.push(make_pair(-req[i], i));
        }
        while (m--)
        {
            lll temp;
            cin >> temp;
            graph[i].emplace_back(temp - 1);
            unlock[temp - 1].emplace_back(i);
        }
    }
    bool visited[n];
    memset(visited, 0, sizeof(visited));
    vector<lll> ans;
    while (!process.empty())
    {
        pair<lll, lll> curr = process.top();
        curr.first *= -1;
        process.pop();
        if (s < curr.first)
        {
            cout << -1;
            return 0;
        }
        visited[curr.second] = true;
        s += points[curr.second];
        ans.emplace_back(curr.second);
        for (auto u : unlock[curr.second])
        {
            bool flag = true;
            for (auto k : graph[u])
            {
                if (!visited[k])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                process.push(make_pair(-req[u], u));
            }
        }
    }
    for (lll i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cout << -1;
            return 0;
        }
    }
    for (auto u : ans)
    {
        cout << u + 1 << " ";
    }
}