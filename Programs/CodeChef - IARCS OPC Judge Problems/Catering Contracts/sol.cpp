//OPTIMIZATIONS
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
//#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//OPTIMIZATIONS
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long uu;
typedef long long int lll;
typedef unsigned long long int uuu;
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
#define cel(x, y) 1 + ((x - 1) / y)
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;

/*
$alil03

URL: url

Solution Begins here
*/

lll table[100000][2];

lll dp(lll node, lll parent, vector<lll> graph[], bool skip, lll traffic[])
{
	if (table[node][skip] != -1)
	{
		return table[node][skip];
	}
	if (skip)
	{
		lll ans = 0;
		for (auto u : graph[node])
		{
			if (u != parent)
			{
				ans += max(dp(u, node, graph, 0, traffic), dp(u, node, graph, 1, traffic));
			}
		}
		return table[node][skip] = ans;
	}
	else
	{
		lll ans = traffic[node];
		for (auto u : graph[node])
		{
			if (u != parent)
			{
				ans += dp(u, node, graph, 1, traffic);
			}
		}
		return table[node][skip] = ans;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	lll n;
	cin >> n;
	lll traffic[n + 1];
	for (lll i = 1; i <= n; i++)
	{
		cin >> traffic[i];
	}
	vector<lll> graph[n + 1];
	for (lll i = 1; i < n; i++)
	{
		lll x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	memset(table, -1, sizeof table);
	cout << max(dp(1, -1, graph, 0, traffic), dp(1, -1, graph, 1, traffic));
}