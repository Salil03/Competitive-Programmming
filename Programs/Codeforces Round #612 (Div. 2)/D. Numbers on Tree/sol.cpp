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
const long long int INF = 0x3f3f3f3f3f3f3f3f;

/*
$alil03

URL: url

Solution Begins here
*/

vector<lll> graph_new[2010];
lll ans[2010] = {};
void dfs(lll node, vector<lll> graph[], lll c[])
{
	for (auto u : graph[node])
	{
		if (c[u] >= c[node])
		{
			graph_new[u].push_back(node);
		}
		else
		{
			graph_new[node].push_back(u);
		}
		dfs(u, graph, c);
	}
}
void dfs2(lll node, lll curr)
{
	ans[node] = curr;
	for (auto u : graph_new[node])
	{
		dfs2(u, curr - 1);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	lll n;
	cin >> n;
	vector<lll> graph[n + 1];
	lll c[n + 1] = {};
	vector<lll> boss;
	for (lll i = 1; i <= n; i++)
	{
		lll x, y;
		cin >> x >> y;
		if (x != 0)
		{
			graph[x].push_back(i);
		}
		if (x == 0)
		{
			boss.push_back(i);
		}
		c[i] = y;
	}
	for (lll i : boss)
	{
		dfs(i, graph, c);
	}
	lll indegree[n + 1] = {};
	for (lll i = 1; i <= n; i++)
	{
		for (lll j : graph_new[i])
		{
			indegree[j]++;
		}
	}
	lll indegree2[n + 1] = {};
	for (lll i = 1; i <= n; i++)
	{
		for (lll j : graph_new[i])
		{
			indegree2[j]++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (indegree2[i] == 0)
		{
			q.push(i);
		}
	}
	int visited = 0;
	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		visited++;
		for (auto u : graph_new[a])
		{
			indegree2[u]--;
			if (indegree2[u] == 0)
			{
				q.push(u);
			}
		}
	}
	if (visited != n)
	{
		cout << "NO\n";
		return 0;
	}
	for (lll i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
		{
			dfs2(i, 100000);
		}
	}
	cout << "YES\n";
	for (lll i = 1; i <= n; i++)
	{
		cout << ans[i] << " ";
	}
}