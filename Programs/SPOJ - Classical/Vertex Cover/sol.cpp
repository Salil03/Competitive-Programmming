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

int table[100006][2] = {};

int dp(int node, int parent, bool include, vector<int> graph[])
{
	if (table[node][include] != -1)
	{
		return table[node][include];
	}
	if (include)
	{
		int ans = 1;
		for (auto u : graph[node])
		{
			if (u == parent)
			{
				continue;
			}
			ans += min(dp(u, node, 1, graph), dp(u, node, 0, graph));
		}
		return table[node][include] = ans;
	}
	else
	{
		int ans = 0;
		for (auto u : graph[node])
		{
			if (u == parent)
			{
				continue;
			}
			ans += dp(u, node, 1, graph);
		}
		return table[node][include] = ans;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> graph[n + 1];
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (int i = 0; i <= n + 1; i++)
	{
		table[i][0] = -1;
		table[i][1] = -1;
	}
	cout << min(dp(1, -1, 0, graph), dp(1, -1, 1, graph));
}