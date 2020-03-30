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
int dp(int node, int parent, vector<pair<int, int>> graph[], int table[])
{
	if (table[node] != -1)
	{
		return table[node];
	}
	int ans = 0;
	for (auto u : graph[node])
	{
		if (u.first != parent)
		{
			ans = max(ans, u.second + dp(u.first, node, graph, table));
		}
	}
	return table[node] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> graph[n + 1];
	for (int i = 1; i < n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
	}
	int idx = 1, minimum = INT_MAX, table[n + 1];
	for (int i = 1; i <= n; i++)
	{
		memset(table, -1, sizeof table);
		if (dp(i, -1, graph, table) <= minimum)
		{
			minimum = dp(i, -1, graph, table);
			idx = i;
		}
	}
	cout << idx << " " << minimum;
}