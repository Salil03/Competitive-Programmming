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

vector<vector<lll>> connected;
vector<lll> newgraph;

void dfs(lll node, lll idx, bool visited[], vector<lll> graph[])
{
	if (visited[node])
	{
		return;
	}
	visited[node] = true;
	connected[idx].push_back(node);
	for (auto k : graph[node])
	{
		if (binary_search(newgraph.begin(), newgraph.end(), k))
		{
			dfs(k, idx, visited, graph);
		}
	}
	return;
}

int main()
{
	lll t;
	cin >> t;
	while (t--)
	{
		newgraph.clear();
		connected.clear();
		lll n, m;
		cin >> n >> m;
		lll a[n + 1], b[n + 1];
		for (lll i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (lll i = 1; i <= n; i++)
		{
			cin >> b[i];
		}
		vector<lll> graph[n + 1];
		for (lll i = 0; i < m; i++)
		{
			lll u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		double maximum = a[1] / b[1];
		for (lll i = 1; i <= n; i++)
		{
			if (fabs(maximum - (double)(a[i] / b[i])) < maximum * .0001)
			{
				newgraph.push_back(i);
			}
			else if (maximum < (double)(a[i] / b[i]))
			{
				newgraph.clear();
				newgraph.push_back(i);
			}
		}
		sort(newgraph.begin(), newgraph.end());
		bool visited[n + 1] = {0};
		lll idx = 0;
		for (lll i = 1; i <= n; i++)
		{
			if (!visited[i] && binary_search(newgraph.begin(), newgraph.end(), i))
			{
				connected.push_back({});
				dfs(i, idx, visited, graph);
				idx++;
			}
		}
		lll max_len = 0;
		vector<lll> final;
		for (auto k : connected)
		{
			if (k.size() > max_len)
			{
				max_len = k.size();
				final = k;
			}
		}
		cout << max_len << "\n";
		for (lll i : final)
		{
			cout << i << " ";
		}
		cout << "\n";
	}
}